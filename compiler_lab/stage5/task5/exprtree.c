//#include "symbolTable.h"
//#include "symbolTable.c"
int RegNo = 0;

int labelNo = 0;
int tempCount = 0;
int staticAddress = 4095;

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
          printf("Variable NOT declared 1\n");
          exit(1);
      }
      printf("Type Mismatch 1\n");
      //printf("%d %d %d %d %d\n",l->type,r->type,type,nodetype,r->nodetype);
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
   struct Lsymbol *lvar = LLookup(currFunc,temp->varname);
   if(lvar!=NULL){
      temp->type = lvar->type;
      temp->Lentry = lvar;
      temp->Gentry = NULL; 
   }
   else{
     struct Gsymbol *gvar = GLookup(temp->varname);
     if(gvar!=NULL){
        temp->type = gvar->type;
        temp->Gentry = gvar;
        temp->Lentry = NULL;
     }
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
    printf("Type Mismatch 2\n");
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
    printf("Type Mismatch 3\n");
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

struct tnode* makeTypeNode(int type){
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->type = type;
    temp->left = temp->right = temp->cond = NULL;
    return temp;
}

struct tnode* makeWhileNode(int nodetype,struct tnode* cond,struct tnode* l){
   if(cond->type!=booltype){
      printf("Type Mismatch 4\n");
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

struct tnode* makeFuncDefNode(int retType,char *name,struct tnode* body,struct tnode* plist){
   struct Gsymbol *gfunc = GLookup(name);
   struct localTable *lTable = lTableLookup(name);
   struct tnode* paramlist = gfunc->paramlist;
   while(plist!=NULL && paramlist!=NULL){
        if(plist->type != paramlist->type){
          printf("Argument type doesnt match\n");
          exit(1);
        }
        plist = plist->left;
        paramlist = paramlist->left;
   }
   if((plist!=NULL && paramlist==NULL) || (plist==NULL && paramlist!=NULL)){
            printf("Too Less or More Arguments\n");
            exit(1);
          }
   if(retType==gfunc->type){
     struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
     temp->left=NULL;temp->right=NULL;
     temp->cond = body;
     temp->varname = malloc(sizeof(char));
     strcpy(temp->varname,name);
     temp->type = retType;
     temp->nodetype = FUNC_;
     temp->Lentry = lTable;
     temp->Gentry = gfunc;
     temp->argList = NULL;
     return temp; 
   }
   else{
    printf("Type Mismatch 5 %s %d\n",gfunc->name,retType);
    exit(1);
   }
   
}

struct tnode* makeFuncCallNode(char *funcname,struct tnode* argList){
       struct Gsymbol *func = GLookup(funcname);
       struct tnode* pList,*arg;
       arg = argList;
       if(argList->nodetype==PLUS_){
        printf("PLUS\n");
       }
       pList = func->paramlist;
       if(func!=NULL){
          struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
          temp->varname = malloc(sizeof(char));
          strcpy(temp->varname,funcname);
          temp->argList = arg;
          temp->type = func->type;
          temp->nodetype = FCALL_;
          temp->Gentry = func;
          temp->left=NULL;temp->right =NULL;
          while(pList!=NULL && argList!=NULL){
             if(pList->type!=argList->type){
                printf("Arguments type don't match\n");
                exit(1);
             }
             pList = pList->left;
             argList = argList->cond;
          }
          if((pList!=NULL && argList==NULL) || (pList==NULL && argList!=NULL)){
            printf("Too Less or More Arguments\n");
            exit(1);
          }
          //printf("%d %d world\n",temp->argList->nodetype,temp->nodetype);
          return temp;
       }
       else{
        printf("Function definition not declared\n");
        exit(1);
       }
}

struct tnode* makeFuncBodyNode(int nodetype,struct tnode* l,struct tnode* r){
      struct tnode *newnode = (struct tnode*)malloc(sizeof(struct tnode));
      newnode->nodetype = nodetype;
      newnode->left = l;
      newnode->right = r;
      newnode->type=NULL;
      newnode->cond =NULL;
      return newnode;
}

struct tnode* makeRetNode(struct tnode *expr){
     struct Gsymbol *temp = GLookup(currFunc);
     struct localTable *test = lTableLookup(currFunc);
     if(expr->type == temp->type){
      struct tnode *newnode = (struct tnode*)malloc(sizeof(struct tnode));
       newnode->left = expr;
       newnode->Gentry = temp;
       newnode->Lentry = test;
       newnode->right = NULL;newnode->cond = NULL;
       newnode->nodetype = RET_;
       return newnode;
     }
     else{
      printf("Type Mismatch\n");
      exit(1);
     }
}


void popLocalVar(struct tnode* t,FILE* target_file){
    struct localTable *test = t->Lentry;
    struct Lsymbol *temp = test->lentry;
    int p = getReg();
    while(temp!=NULL){
      if(temp->binding>0){
        fprintf(target_file, "POP R%d\n",p);
      }
      temp = temp->next;
    } 
    freeReg();
}

int getAddress(int size){
    int start_address = staticAddress + 1;
    staticAddress = staticAddress + size;
    return start_address;
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
    if(RegNo>19){
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
      case VAR_ : printf("%s",t->varname);break;
      case READ_: printf("read ");break;
      case WRITE_: printf("write ");break;
      case ASSIGN_: printf("= ");break;
      case NUM_: printf("%d ",t->val);break;
      case break_:printf("Break ");break;
      case FUNC_ :printf("%s ",t->varname);
     }
     infix_form(t->cond);
     infix_form(t->right);
}

int getMemoryAddress(struct tnode *t,FILE *target_file){
    int address,r1,offset1,offset2;
    r1 = getReg();
    //struct Gsymbol *temp = GLookup(t->varname);
    struct Gsymbol *temp = t->Gentry;
    struct Lsymbol *test = t->Lentry;
    if(temp!=NULL && test==NULL){//global variables
      address = temp->binding;
      fprintf(target_file, "MOV R%d,%d\n",r1,address);
      if(t->left!=NULL && t->right==NULL){/*This is for 1D array*/printf("This is array\n");
        offset1 = codeGen(t->left,target_file);
        fprintf(target_file, "ADD R%d, R%d\n",r1,offset1);
      }
      else if(t->left!=NULL && t->right!=NULL){printf("This is 2d array\n");
        int no_col = temp->no_col;
        offset1 = codeGen(t->left,target_file);
        offset2 = codeGen(t->right,target_file);
        fprintf(target_file, "MUL R%d, %d\n",offset1,no_col);
        fprintf(target_file, "ADD R%d, R%d\n",offset1,offset2);
        fprintf(target_file, "ADD R%d, R%d\n",r1,offset1);
      }
    }
    else if(test!=NULL && temp==NULL){//this is for local variables

      address = test->binding;
      fprintf(target_file, "MOV R%d,BP\n",r1);
      fprintf(target_file, "ADD R%d,%d\n",r1,address);
    }
    freeReg();
    return r1;
}

/*int getStackAddress(struct tnode* t,FILE* target_file){
    int p,address;
    p = getReg();
    if(t->Lentry!=NULL){
      address = t->Lentry->binding;
    }
    else if(t->Gentry!=NULL)
      address = t->Gentry->binding;

    fprintf(target_file, "MOV R%d,BP\n",p);
    fprintf(target_file, "ADD R%d,%d\n",p,address);
    return p;
}
*/
void freeAllReg(){
  RegNo = 0;
}

void push_registers(FILE* target_file){
     int i = 0;
     /*while(temp_regNo>=0){
      fprintf(target_file, "PUSH R%d\n",temp_regNo);
      temp_regNo--;
     }*/
     for(i=0;i<RegNo;i++){
      fprintf(target_file, "PUSH R%d\n",i);
     }
     tempCount = RegNo;
}

void pop_registers(FILE* target_file){
     int i;
     RegNo = tempCount;
     for(i=tempCount-1;i>=0;i--){
          fprintf(target_file, "POP R%d\n",i );
     }
     tempCount=0;
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
    		             //push_registers(target_file);
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
                   //pop_registers(target_file);
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
                     printf("%d reg\n",RegNo );
    	               freeReg();
                     printf("%d reg\n",RegNo );
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
      case AND_ :{ p = codeGen(t->left,target_file);
                   q = codeGen(t->right,target_file);
                   fprintf(target_file, "ADD R%d,R%d\n",p,q);
                   r = getReg();
                   fprintf(target_file, "MOV R%d,2\n",r);
                   fprintf(target_file, "EQ R%d,R%d\n",p,r);
                   freeReg();
                   freeReg();
                   break;
                 }
      case OR_ :{  p = codeGen(t->left,target_file);
                   q = codeGen(t->right,target_file);
                   fprintf(target_file, "ADD R%d,R%d\n",p,q);
                   r = getReg();
                   fprintf(target_file, "MOV R%d,0\n",r);
                   fprintf(target_file, "NE R%d,R%d\n",p,r);
                   freeReg();
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
    	case ASSIGN_ :{ printf("I am in assign\n");
    		            q = codeGen(t->right,target_file);
                    p = getMemoryAddress(t->left,target_file);
                    if(t->left->nodetype==POI_VAL_){
                      fprintf(target_file, "MOV R%d, [R%d]\n",p,p);
                    }
                    //fprintf(target_file, "MOV R%d, R%d\n",p,q);
    		            fprintf(target_file, "MOV [R%d], R%d\n",p,q);
    		            //freeReg();
    		            break;
    	              }
    	case CONN_ : { //printf("I am in conn\n");
                     p = codeGen(t->left,target_file);
                     freeAllReg();
    		             q = codeGen(t->right,target_file);
                     freeAllReg();
                     break;
    	            }
      case FCALL_ :{ 
                     push_registers(target_file);
                     freeAllReg();
                     struct tnode *temp = t->argList;
                     while(temp!=NULL){
                       //printf("%d %s\n",temp->nodetype,temp->varname);
                       p = codeGen(temp,target_file);
                       fprintf(target_file, "PUSH R%d\n",p);

                       temp = temp->cond;
                     }
                     //push empty space for return value
                     
                     fprintf(target_file, "PUSH R0\n",q);
                     
                     fprintf(target_file, "CALL F%d\n",t->Gentry->flabel);
                     
                     q = tempCount + 1;
                     fprintf(target_file, "POP R%d\n",q);
                     temp = t->argList;
                     while(temp!=NULL){
                      fprintf(target_file,"POP R0\n");
                      temp = temp->cond;
                     }
                     p = q;
                     pop_registers(target_file);
                     RegNo = q + 1;
                     break;
                   }
      case FUNC_ :{ if(strcmp(t->varname,"main")==0){
                           fprintf(target_file, "MAIN:\n");
                           fprintf(target_file, "BRKP\n");
                           fprintf(target_file, "MOV SP,%d\n",staticAddress+1);
                           fprintf(target_file, "MOV BP,%d\n",staticAddress+1);
                      }
                      else{
                        fprintf(target_file, "F%d:\n",t->Gentry->flabel);
                      }

                      fprintf(target_file, "PUSH BP\n");
                      fprintf(target_file, "MOV BP,SP\n");

                      struct localTable *lTable = t->Lentry;
                      struct Lsymbol *lList = lTable->lentry;
                      while(lList!=NULL){
                        if(lList->binding>0){
                          fprintf(target_file, "PUSH R0\n");
                        }
                        lList = lList->next;
                      }
                      codeGen(t->cond,target_file);
                      break;
                  }
      case BODY_ :{  //p = getReg();
                     codeGen(t->left,target_file);
                     codeGen(t->right,target_file);
                     break;
                  }
      case RET_ :{  p = getReg();
                  if(strcmp(t->Gentry->name,"main")!=0){
                    q = codeGen(t->left,target_file);

                    popLocalVar(t,target_file);

                    fprintf(target_file,"MOV R%d,BP\n",p);
                    fprintf(target_file, "SUB R%d,2\n",p);
                    fprintf(target_file, "MOV [R%d],R%d\n",p,q);
                    fprintf(target_file, "POP BP\n" );
                    fprintf(target_file, "RET\n");
                  }
                     
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