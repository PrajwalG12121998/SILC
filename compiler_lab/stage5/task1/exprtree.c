int RegNo = 0;

int labelNo = 0;

struct tnode* makeLeafNode(int nodetype,int n){
struct tnode *temp;
temp = (struct tnode*)malloc(sizeof(struct tnode));
temp->varname = NULL;
temp->nodetype = nodetype;
temp->type = inttype;
temp->val = n;
temp->left = NULL;
temp->right = NULL;
temp->cond = NULL;
return temp;
}

struct tnode* makeOperatorNode(int nodetype,int type,struct tnode* l,struct tnode* r){
int check = dataTypeCheck(l,r);
   if(check==1){
      struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
      temp->varname = NULL;
      temp->nodetype = nodetype;
      temp->left = l;
      temp->right = r;
      temp->type = type;
      temp->val = NULL;
      temp->cond = NULL;
      return temp;  
   }
   else{
      if(l->type==NULL || r->type==NULL){
          printf("Variable NOT declared\n");
          exit(1);
      }
      printf("Type Mismatch\n");
      exit(1);
   }

}

struct tnode* makeVariableNode(int nodetype,char *c,char *text){
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->varname = malloc(sizeof(char));
   temp->str_val = malloc(sizeof(char));
   if(c!=NULL){
     strcpy(temp->varname,c); 
   }
   if(text!=NULL){
     strcpy(temp->str_val,text);
     temp->type = stringtype; 
   }
   temp->val = NULL;
   temp->nodetype = nodetype;
   struct Gsymbol *test = GLookup(temp->varname);
   if(test!=NULL){
      temp->type = test->type;
      temp->Gentry = test; 
   }
   temp->left = NULL;
   temp->right = NULL;
   temp->cond = NULL;
   return temp; 
}

struct tnode* makeWrite_ReadNode(int nodetype,struct tnode* l){
   if(l->type==NULL){
      printf("Variable not declared\n");
      exit(1);
   }
   if(l->type!=inttype && l->type!=stringtype){
    printf("Type Mismatch\n");
    exit(1);
   }
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->val = NULL;
   temp->varname = NULL;
   temp->nodetype = nodetype;
   temp->left = l;
   temp->right = NULL;
   temp->cond = NULL;
   return temp;
}

struct tnode* makeConnectedNode(int nodetype,struct tnode* l,struct tnode* r){
   struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->val = NULL;
   temp->varname = NULL;
   temp->nodetype = nodetype;
   temp->left = l;
   temp->right = r;
   temp->cond = NULL;
   return temp;
}

struct tnode* makeConditionalNode(int nodetype,struct tnode* cond,struct tnode* l,struct tnode* r){
   if(cond->type!=booltype){
    printf("Type Mismatch\n");
    exit(1);
   }
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->val = NULL;
   temp->varname = NULL;
   temp->left = l;
   temp->right = r;
   temp->cond = cond;
   temp->nodetype = nodetype;
   temp->type = NULL;
   return temp;

}

struct tnode* makeWhileNode(int nodetype,struct tnode* cond,struct tnode* l){
   if(cond->type!=booltype){
      printf("Type Mismatch\n");
      exit(1);
   }
   struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->left = l;
   temp->cond = cond;
   temp->nodetype = nodetype;
   temp->val= NULL;
   temp->type = NULL;
   return temp;
}


int dataTypeCheck(struct tnode* l,struct tnode* r){
    if(l->type == r->type){
      return 1;
    }
    else{
      return 0;
    }
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

/*int getMemoryAddress(char *c){
    int memory = 4096 + (*c - 'a');
    return memory;
}*/

int getLabel(){
    labelNo++;
    return labelNo;
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
      case break_:printf("Break ");break;
     }
     infix_form(t->right);
}

int getMemoryAddress(struct tnode *t,FILE *target_file){
    int address,r1,offset1,offset2;
    r1 = getReg();
    //struct Gsymbol *temp = GLookup(t->varname);
    struct Gsymbol *temp = t->Gentry;
    if(temp!=NULL){
      address = temp->binding;
      fprintf(target_file, "MOV R%d,%d\n",r1,address);
      if(t->left!=NULL && t->right==NULL){/*This is for 1D array*/
        offset1 = codeGen(t->left,target_file);
        fprintf(target_file, "ADD R%d, R%d\n",r1,offset1);
      }
      else if(t->left!=NULL && t->right!=NULL){
        int no_col = temp->no_col;
        offset1 = codeGen(t->left,target_file);
        offset2 = codeGen(t->right,target_file);
        fprintf(target_file, "MUL R%d, %d\n",offset1,no_col);
        fprintf(target_file, "ADD R%d, R%d\n",offset1,offset2);
        fprintf(target_file, "ADD R%d, R%d\n",r1,offset1);
      }
    }
    freeReg();
    return r1;
}

void push_registers(FILE* target_file){
     int temp_regNo = RegNo - 1;
     while(temp_regNo>=0){
      fprintf(target_file, "PUSH R%d\n",temp_regNo);
      temp_regNo--;
     }
}

void pop_registers(FILE* target_file){
     int temp_regNo = 0;
     while(temp_regNo<RegNo){
        fprintf(target_file, "POP R%d\n",temp_regNo);
        temp_regNo++;
     }
}
int gcheckBreak=-1,gcheckContinue = -1,gcheckLoop=-1;
int codeGen(struct tnode* t,FILE *target_file){
    int p,q,r,lcheckBreak = gcheckBreak,lcheckContinue = gcheckContinue,lcheckLoop = gcheckLoop;
    //lcheckBreak = gcheckBreak;
    switch(t->nodetype){
    	case READ_ :{ q = getReg(); r = getReg();
                  int r1 = getMemoryAddress(t->left,target_file);
    		          fprintf(target_file, "MOV R%d,\"Read\"\n",q);
    		          fprintf(target_file, "PUSH R%d\n",q);	
    		          fprintf(target_file, "MOV R%d,-1\n",q);	
    		          fprintf(target_file, "PUSH R%d\n",q);	
                  fprintf(target_file, "MOV [R%d], R%d\n",r1, r);
                  fprintf(target_file, "PUSH R%d\n",r1);
                  fprintf(target_file, "PUSH R%d\n",q);
                  fprintf(target_file, "PUSH R%d\n",q);
                  fprintf(target_file, "CALL 0\n");
                  fprintf(target_file, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",r,r,r,r,r);
                  freeReg();
                  freeReg();
    		          break;
    	            }
    	case WRITE_ :{ p = codeGen(t->left,target_file);
    		             push_registers(target_file);
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
                   pop_registers(target_file);
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
      case MOD_ : { p = codeGen(t->left,target_file);
                    q = codeGen(t->right,target_file);
                    fprintf(target_file,"MOD R%d, R%d\n",p,q);
                    freeReg();
                    break;
                  }
      case LT_ : {  p = codeGen(t->left,target_file);
                    q = codeGen(t->right,target_file);
                    fprintf(target_file, "LT R%d, R%d\n",p,q);
                    freeReg();
                    break;
                 }
      case GT_ : {  p = codeGen(t->left,target_file);
                    q = codeGen(t->right,target_file);
                    fprintf(target_file, "GT R%d, R%d\n",p,q);
                    freeReg();
                    break;
                 }
      case LE_ : {  p = codeGen(t->left,target_file);
                    q = codeGen(t->right,target_file);
                    fprintf(target_file, "LE R%d, R%d\n",p,q);
                    freeReg();
                    break;
                 }
      case GE_ : {  p = codeGen(t->left,target_file);
                    q = codeGen(t->right,target_file);
                    fprintf(target_file, "GE R%d, R%d\n",p,q);
                    freeReg();
                    break;
                 }
      case NE_ : {  p = codeGen(t->left,target_file);
                    q = codeGen(t->right,target_file);
                    fprintf(target_file, "NE R%d, R%d\n",p,q);
                    freeReg();
                    break;
                 }
      case EQ_ : {  p = codeGen(t->left,target_file);
                    q = codeGen(t->right,target_file);
                    fprintf(target_file, "EQ R%d, R%d\n",p,q);
                    freeReg();
                    break;
                 }            
    	case NUM_ : { p = getReg();
    		          fprintf(target_file, "MOV R%d, %d\n",p,t->val);
                      break;
    	            }
    	case VAR_ : { p = getReg();
                  int r1 = getMemoryAddress(t,target_file);           
    		          fprintf(target_file, "MOV R%d, [R%d]\n",p,r1);
    		          break;
    	            }
      case POI_ADD_ : { p = getReg();
                   int r1 = getMemoryAddress(t,target_file);
                   fprintf(target_file, "MOV R%d, R%d\n",p,r1);
                   break;
                  }
      case POI_VAL_ :{ p = getReg();
                       int r1 = getMemoryAddress(t,target_file);
                       fprintf(target_file, "MOV R%d, [R%d]\n",p,r1);
                       fprintf(target_file, "MOV R%d, [R%d]\n",p,p);
                       break;
                     }
      case PRNT_ : {  p = getReg();
                      fprintf(target_file, "MOV R%d, %s\n",p,t->str_val);
                      break;
                    }
    	case ASSIGN_ :{ 
    		            q = codeGen(t->right,target_file);
                    p = getMemoryAddress(t->left,target_file);
                    if(t->left->nodetype==POI_VAL_){
                      fprintf(target_file, "MOV R%d, [R%d]\n",p,p);
                    }
                    //fprintf(target_file, "MOV R%d, R%d\n",p,q);
    		            fprintf(target_file, "MOV [R%d], R%d\n",p,q);
    		            freeReg();
    		            break;
    	              }
    	case CONN_ : { p = codeGen(t->left,target_file);
    		             q = codeGen(t->right,target_file);
                       break;
    	            }
      case while_ :{ int label_1 = getLabel();
                     int label_2 = getLabel();
                     lcheckBreak=label_2;lcheckContinue = label_1;lcheckLoop = 1;
                     gcheckBreak = lcheckBreak;
                     gcheckContinue = lcheckContinue;
                     gcheckLoop = lcheckLoop;
                     fprintf(target_file, "L%d:\n",label_1);
                     p = codeGen(t->cond,target_file);
                     fprintf(target_file, "JZ R%d, L%d\n",p,label_2);
                     freeReg();
                     codeGen(t->left,target_file);
                     fprintf(target_file, "JMP L%d\n",label_1);
                     fprintf(target_file, "L%d:\n",label_2);
                     lcheckLoop = -1;
                     break;
                   }
      case If_t_Else : { int label_1 = getLabel();
                         if(t->right!=NULL){
                                int label_2 = getLabel();
                                p = codeGen(t->cond,target_file);
                                fprintf(target_file, "JZ R%d, L%d\n",p,label_1);
                                freeReg();
                                codeGen(t->left,target_file);
                                fprintf(target_file,"JMP L%d\n",label_2);
                                fprintf(target_file, "L%d:\n",label_1);
                                codeGen(t->right,target_file);
                                fprintf(target_file, "L%d:\n",label_2);
                          }
                          break;
                       }
        case If_then : { int label_1 = getLabel();
                         p = codeGen(t->cond,target_file);
                         fprintf(target_file, "JZ R%d, L%d\n",p,label_1);
                         freeReg();
                         codeGen(t->left,target_file);
                         fprintf(target_file, "L%d:\n",label_1);
                         break;
                       }
        case continue_ : { if(gcheckLoop==1)
                           fprintf(target_file, "JMP L%d\n",gcheckContinue);
                           break;
                         }
        case break_ : {   if(gcheckLoop==1) 
                          fprintf(target_file, "JMP L%d\n",gcheckBreak);
                          break;
                      }
        case doWhile_ : { int label_1 = getLabel();
                          int label_2 = getLabel();
                          int label_3 = getLabel();
                          lcheckBreak=label_3;lcheckContinue = label_2;lcheckLoop = 1;
                          gcheckBreak = lcheckBreak;
                          gcheckContinue = lcheckContinue;
                          gcheckLoop = lcheckLoop;
                          fprintf(target_file, "L%d:\n",label_1 );
                          codeGen(t->left,target_file);
                          fprintf(target_file, "L%d:\n",label_2);
                          p = codeGen(t->cond,target_file);
                          fprintf(target_file, "JNZ R%d, L%d\n",p,label_1);
                          lcheckLoop = -1;
                          fprintf(target_file, "L%d:\n",label_3 );
                          freeReg();
                          break;
                        }
        case repeatUntil_ : { int label_1 = getLabel();
                              int label_2 = getLabel();
                              int label_3 = getLabel();
                              lcheckBreak=label_3;lcheckContinue = label_2;lcheckLoop = 1;
                              gcheckBreak = lcheckBreak;
                              gcheckContinue = lcheckContinue;
                              gcheckLoop = lcheckLoop;
                              fprintf(target_file, "L%d:\n",label_1 );
                              codeGen(t->left,target_file);
                              fprintf(target_file, "L%d:\n",label_2);
                              p = codeGen(t->cond,target_file);
                              fprintf(target_file, "JZ R%d, L%d\n",p,label_1);
                              lcheckLoop=-1;
                              fprintf(target_file, "L%d:\n",label_3);
                              freeReg();
                              break; 
                            }
    }
    gcheckBreak = lcheckBreak;
    gcheckContinue = lcheckContinue;
    gcheckLoop = lcheckLoop;
    return p;
}
int arr[26];
int evaluate(struct tnode *t){
    int p;
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
      case LT_ : { return evaluate(t->left) < evaluate(t->right);
                   break;
                  }
      case GT_ : { return evaluate(t->left) > evaluate(t->right);
                   break;
                 }
      case LE_ : { return evaluate(t->left) <= evaluate(t->right);
                   break;
                }
      case GE_ : { return evaluate(t->left) >= evaluate(t->right);
                   break;
                 }
      case NE_ : { return evaluate(t->left) != evaluate(t->right);
                   break;
                 }
      case EQ_ : { return evaluate(t->left) == evaluate(t->right);
                   break;
                 }
      case If_t_Else: { if(evaluate(t->cond)){
                           evaluate(t->left);
                           return ;
                         }
                         else{
                           evaluate(t->right);
                           return ;
                         }
                         break;
                       }
      case If_then :{ if(evaluate(t->cond)){
                          evaluate(t->left);
                          return ;
                      }
                      break;

                    }
      case while_ : { while(evaluate(t->cond)){
                            evaluate(t->left); 
                       }
                       return ;
                       break;
                    }
      case break_ : return ;
      default : printf("error\n");
                break;
    }

}