int RegNo = 0;

struct tnode* makeLeafNode(int type,int n){
struct tnode *temp;
temp = (struct tnode*)malloc(sizeof(struct tnode));
temp->varname = NULL;
temp->nodetype = type;
temp->val = n;
temp->left = NULL;
temp->right = NULL;
return temp;
}

struct tnode* makeOperatorNode(int type,struct tnode* l,struct tnode* r){
struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
temp->varname = NULL;
temp->nodetype = type;
temp->left = l;
temp->right = r;
temp->val = NULL;
return temp;
}

struct tnode* makeVariableNode(int type,char *c){
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->varname = malloc(sizeof(char));
   strcpy(temp->varname,c);
   temp->val = NULL;
   temp->nodetype = type;
   temp->left = NULL;
   temp->right = NULL;
   return temp; 
}

struct tnode* makeWrite_ReadNode(int type,struct tnode* l){
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->val = NULL;
   temp->varname = NULL;
   temp->nodetype = type;
   temp->left = l;
   temp->right = NULL;
   return temp;
}

struct tnode* makeConnectedNode(int type,struct tnode* l,struct tnode* r){
   struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->val = NULL;
   temp->varname = NULL;
   temp->nodetype = type;
   temp->left = l;
   temp->right = r;
   return temp;
}

int getReg(){
    if(RegNo>=19){
        printf("All registers are occupied\n");
        exit(0);
    }
    int reg = RegNo;
    RegNo++;
    return reg;
}

void freeReg(){
    if(RegNo==0){
        printf("No Registers are allocated\n");
        exit(0);
    }
    RegNo--;
}

int getMemoryAddress(char *c){
    int memory = 4096 + (*c - 'a');
    return memory;
}

void infix_form(struct tnode *t){
     if(t==NULL){
      return ;
     }
     infix_form(t->left);
     switch(t->nodetype){
      case PLUS_: printf("+ ");break;
      case MINUS_: printf("- ");break;
      case MUL_ : printf("* ");break;
      case DIV_ : printf("\\ ");break;
      case VAR_ : printf("%c ",*(t->varname));break;
      case READ_: printf("read ");break;
      case WRITE_: printf("write ");break;
      case ASSIGN_: printf("= ");break;
      case NUM_: printf("%d ",t->val);break;
     }
     infix_form(t->right);
}


int codeGen(struct tnode* t,FILE *target_file){
    int p,q,r;

    switch(t->nodetype){
    	case READ_ :{ q = getReg(); r = getReg();
    		          int memory = getMemoryAddress(t->left->varname);
    		          fprintf(target_file, "MOV R%d,\"Read\"\n",q);
    		          fprintf(target_file, "PUSH R%d\n",q);	
    		          fprintf(target_file, "MOV R%d,-1\n",q);	
    		          fprintf(target_file, "PUSH R%d\n",q);	
                  fprintf(target_file, "MOV R%d, %d\n",q, memory);
                  fprintf(target_file, "PUSH R%d\n",q);
                  fprintf(target_file, "PUSH R%d\n",r);
                  fprintf(target_file, "PUSH R%d\n",r);
                  fprintf(target_file, "CALL 0\n");
                  freeReg();
                  freeReg();
    		          break;
    	            }
    	case WRITE_ :{ p = codeGen(t->left,target_file);
    		             q = getReg();
    		           fprintf(target_file, "MOV R%d,\"Write\"\n",q);
    		           fprintf(target_file, "PUSH R%d\n",q);
    		           fprintf(target_file, "MOV R%d,-2\n",q);
    		           fprintf(target_file, "PUSH R%d\n",q);
    		           fprintf(target_file, "PUSH R%d\n",p);
    		           fprintf(target_file, "PUSH R0\n");
    		           fprintf(target_file, "PUSH R0\n");
    		           fprintf(target_file, "CALL 0\n");
    		           fprintf(target_file, "POP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
    		           freeReg();
    		           freeReg();
                   break;
    	             }
    	case PLUS_ :{ p = codeGen(t->left,target_file);
    	              q = codeGen(t->right,target_file);
    	              fprintf(target_file,"ADD R%d, R%d\n",p,q);
    	              freeReg();
    	              break; 
    	          }
    	case MINUS_ :{ p = codeGen(t->left,target_file);
    	               q = codeGen(t->right,target_file);
    	               fprintf(target_file,"SUB R%d, R%d\n",p,q);
    	               freeReg();
    	               break;  
    	           }
    	case MUL_ : { p = codeGen(t->left,target_file);
    	              q = codeGen(t->right,target_file);
    	              fprintf(target_file,"MUL R%d, R%d\n",p,q);
    	              freeReg();
    	              break; 
    	            }
    	case DIV_ : { p = codeGen(t->left,target_file);
    	              q = codeGen(t->right,target_file);
    	              fprintf(target_file,"DIV R%d, R%d\n",p,q);
    	              freeReg();
    	              break; 
    	            }
    	case NUM_ : { p = getReg();
    		          fprintf(target_file, "MOV R%d, %d\n",p,t->val);
                      break;
    	            }
    	case VAR_ : { p = getReg();
    		          int memory = getMemoryAddress(t->varname);
    		          fprintf(target_file, "MOV R%d, [%d]\n",p,memory);
    		          break;
    	            }
    	case ASSIGN_ :{ p = codeGen(t->left,target_file);
    		            q = codeGen(t->right,target_file);
    		            fprintf(target_file, "MOV R%d, R%d\n",p,q);
    		            int memory = getMemoryAddress(t->left->varname);
    		            fprintf(target_file, "MOV [%d], R%d\n",memory,p);
    		            freeReg();
    		            break;
    	              }
    	case CONN_ : { p = codeGen(t->left,target_file);
    		             q = codeGen(t->right,target_file);
                       break;
    	            }
    }
    return p;
}
int arr[26];
int evaluate(struct tnode *t){
    switch(t->nodetype){
      case PLUS_:{ 
                   return evaluate(t->left) + evaluate(t->right);
                   break;
                }
      case MINUS_:{
                   return evaluate(t->left) - evaluate(t->right);
                   break;
                 }
      case MUL_:{
                   return evaluate(t->left)*evaluate(t->right);
                   break;
                 }
      case DIV_:{
                   return evaluate(t->left)/evaluate(t->right);
                   break;
                 }
      case READ_ :{ scanf("%d",&arr[*(t->left->varname)-'a']);
                    break;
                  }
      case WRITE_ :{ printf("%d\n",evaluate(t->left));
                     break;
                   }
      case ASSIGN_ :{ arr[*(t->left->varname) - 'a'] = evaluate(t->right);
                      return ;
                      break;
                    }
      case VAR_ :{ return arr[*(t->varname) - 'a'];
                   break;
                 }
      case NUM_ :{
                   return t->val;
                   break;
                  }
      case CONN_ : {
                   evaluate(t->left);
                   evaluate(t->right);
                   return;
                   break;
                   }
      default : printf("error\n");
                break;
    }

}