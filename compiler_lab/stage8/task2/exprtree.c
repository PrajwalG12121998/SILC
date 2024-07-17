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
temp->type = TLookup("int");
temp->val = n;
temp->left = NULL;
temp->right = NULL;
temp->cond = NULL;
temp->middle = NULL;
return temp;
}

struct tnode* makeOperatorNode(int nodetype,char *type,struct tnode* l,struct tnode* r){
int check = dataTypeCheck(l,r);
  printf("%d\n",check);
   if(l->Ctype!=NULL && r->Ctype!=NULL){
    if(strcmp(l->Ctype->name,r->Ctype->name)==0){
      check=1;
    }else{
      struct Classtable *rclass = r->Ctype;
      //TODO  
    }
   }
   if(check==1){
      struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
      temp->varname = NULL;
      temp->nodetype = nodetype;
      temp->left = l;
      temp->right = r;
      temp->type = TLookup(type);
      temp->val = NULL;
      temp->cond = NULL;
      printf("checkpoint 1 %s\n",currFunc);
      return temp;  
   }
   else{
      if(l->type==NULL || r->type==NULL){
          printf("%d %d %s %s %s\n",l->nodetype,r->nodetype,l->varname,l->type,r->type->name);
          printf("Variable NOT declared 1\n");
          exit(1);
      }
      printf("Type Mismatch 1\n");
      printf("%s %s %d %d\n",l->type->name,r->type->name,l->nodetype,r->nodetype);
      exit(1);
   }

}

struct tnode* makeVariableNode(int nodetype,char *c,char *text){
   
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->varname = malloc(sizeof(char));
   temp->str_val = malloc(sizeof(char));
   if(c!=NULL){
     if(strcmp(c,"null")==0){
       printf("here in null\n");
        nodetype = NULL_;
        strcpy(temp->varname,c); 
        temp->type = TLookup("NULL");
        temp->left = NULL;
        temp->right = NULL;
        temp->cond = NULL;
        temp->middle = NULL;
        temp->nodetype = NULL_;
       return temp;
     }
    strcpy(temp->varname,c);
    //printf("%s name\n",temp->varname );
   }
   if(text!=NULL){
     strcpy(temp->str_val,text);
     temp->val = NULL;
     temp->nodetype = nodetype;
     temp->type = TLookup("str"); 
     temp->left = NULL;
     temp->right = NULL;
     temp->cond = NULL;
     temp->middle = NULL;
    return temp;
   }


   temp->val = NULL;
   temp->nodetype = nodetype;
   temp->type =NULL;
   struct Lsymbol *lvar = LLookup(currFunc,temp->varname);
   struct Gsymbol *gvar = GLookup(temp->varname);
   struct localTable *lTable = lTableLookup(temp->varname);
   struct Fieldlist *cvar;

   /*if(strcmp(temp->varname,"self")==0){
        printf("self lvar: %s\n",lvar);
      }
*/

   if(lvar!=NULL){
      printf("In local variable\n");
      temp->type = lvar->type;
      temp->Ctype = Cptr;
      temp->Lentry = lvar;
      temp->Gentry = NULL; 
   }
   else if(gvar!=NULL){
    //printf("In global variable %s %s\n",temp->varname,gvar->Ctype->name);
     
        temp->type = gvar->type;
        temp->Gentry = gvar;
        temp->Lentry = NULL;
        temp->Ctype = gvar->Ctype;
        printf("\n");
        //printSymbolTable();
        //printf(" I am in gvar %s %s\n",temp->varname,temp->type->name);
     
   }
   else if(lTable!=NULL){
     temp->type = lTable->type;
     temp->Ctype = lTable->Ctype;
     temp->Gentry = NULL;
     temp->Lentry = NULL;
   }
   else{
       printf("In local variable 2 %d\n",temp->nodetype);
        struct TypeTable *tTable = TLookup("int");
        while(tTable!=NULL){
          struct Fieldlist *flist = tTable->fields;
          while(flist!=NULL){
            if(strcmp(temp->varname,flist->name)==0){
              temp->type = flist->type;
            }
            flist = flist->next;
          }
          tTable = tTable->next;
        }
        temp->Ctype = Cptr;
        temp->Gentry = NULL;
   }

   if(Cptr!=NULL && temp->type==NULL){
     cvar = Class_FLookup(Cptr,temp->varname);

     if(cvar==NULL){
       temp->type = NULL; 
     }
     else{
      temp->type = cvar->type;
     }
     
     temp->Ctype = Cptr;
     temp->Gentry = NULL;
     temp->Lentry = NULL;
   }
   
   temp->left = NULL;
   temp->right = NULL;
   temp->cond = NULL;
   temp->middle = NULL;
   return temp; 
}

struct tnode* makeWrite_ReadNode(int nodetype,struct tnode* l){
   /*if(strcmp(l->type==NULL)){
    printf("Variable not declared 10\n");
    exit(1);
   }*/
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->val = NULL;
   temp->varname = NULL;
   temp->nodetype = nodetype;
   temp->left = l;
   temp->right = NULL;
   temp->cond = NULL;
   temp->type = TLookup("void");
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
   if(strcmp(cond->type->name,"bool")!=0){
      printf("Type Mismatch 3\n");
      exit(1);
   }
   printf("I am in conditional node\n");
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->val = NULL;
   temp->varname = NULL;
   temp->left = l;
   temp->right = r;
   temp->cond = cond;
   temp->nodetype = nodetype;
   temp->type = TLookup("void");
   return temp;

}

struct tnode* makeTypeNode(int type){
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    if(type==inttype){
       strcpy(temp->varname,"int");  
    }
    else{
       strcpy(temp->varname,"str");
    }
    temp->type = type;
    temp->left = temp->right = temp->cond = NULL;
    return temp;
}

struct tnode* makeWhileNode(int nodetype,struct tnode* cond,struct tnode* l){
   if(strcmp(cond->type->name,"bool")!=0){
      printf("Type Mismatch 4\n");
      exit(1);
   }
   printf("I am in while node\n");
   //printf("%s\n",l->varname);
   struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->left = l;
   temp->cond = cond;
   temp->nodetype = nodetype;
   temp->val= NULL;
   temp->type = TLookup("void");
   return temp;
}

struct tnode* makeFuncDefNode(char *retType,char *name,struct tnode* body,struct tnode* plist,struct Classtable *Cptr){
   struct Gsymbol *gfunc = GLookup(name);
   struct localTable *lTable = lTableLookup(name);
   if(gfunc!=NULL){
     struct tnode* paramlist = gfunc->paramlist;
     while(plist!=NULL && paramlist!=NULL){
        //printf(" %s %s\n",temp->varname,paramlist->type->name);
        if(strcmp(plist->type->name,paramlist->type->name)!=0){
          printf("Argument type doesnt match 1\n");
          exit(1);
        }
        plist = plist->left;
        paramlist = paramlist->left;
   }
   if((plist!=NULL && paramlist==NULL) || (plist==NULL && paramlist!=NULL)){
            printf("Too Less or More Arguments\n");
            exit(1);
          }
   }
   else if(Cptr!=NULL){
     struct Memberfunclist *mfunc = Class_MLookup(Cptr,name);
     if(mfunc==NULL){
      printf("Function not declared\n");
      exit(1);
     }
   }
    
     struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
     temp->left=NULL;temp->right=NULL;
     temp->cond = body;
     temp->varname = malloc(sizeof(char));
     strcpy(temp->varname,name);
     temp->type = TLookup(retType);
     temp->nodetype = FUNC_;
     temp->Lentry = lTable;
     temp->Gentry = gfunc;
     temp->argList = NULL;
     temp->Ctype = Cptr;
     return temp; 
   
   
}

struct tnode* makeMethodCallNode(struct tnode *classVar,char *methodname,struct tnode *argList){
   struct Gsymbol *gvar = GLookup(classVar->varname);
   struct Fieldlist *fvar =NULL;
   struct Classtable *cvar =NULL;
   if(gvar==NULL){
     fvar = Class_FLookup(Cptr,classVar->varname);
   }
   /*if(gvar==NULL && strcmp(classVar->varname,"self")!=0){
    printf("class variable not declared globally\n");
    exit(1);
   }*/
   //printf("%s %s\n",classVar->varname,fvar->type->name);
   struct Memberfunclist *mlist;
   //printf("%s\n",methodname);
   //printf("%s\n",gvar->Ctype->name);
   if(Cptr!=NULL && strcmp(classVar->varname,"self")==0){
     mlist = Class_MLookup(Cptr,methodname);  
   }
   else{
     if(gvar!=NULL){
       mlist = Class_MLookup(gvar->Ctype,methodname); 
     }
     else if(gvar==NULL){
       cvar = CLookup(classVar->type->name);
       mlist = Class_MLookup(cvar,methodname);
     }
     
     if(mlist==NULL){
       printf("Function not declared in this class\n");
       exit(1);
    } 
   }
   
   struct tnode *paramlist = mlist->paramlist;
   struct tnode *alist = argList;

   while(paramlist!=NULL || alist!=NULL){
    if(strcmp(paramlist->type->name,alist->type->name)!=0){
      printf("Arguments doesn't match\n");
      exit(1);
    }
    paramlist = paramlist->left;
    alist = alist->middle;
   }
   
   if((alist!=NULL && paramlist==NULL) || (alist==NULL && paramlist!=NULL)){
            printf("Too Less or More Arguments\n");
            exit(1);
     }
   
   struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
   temp->left=NULL;temp->right=classVar;
   temp->cond = NULL;
   temp->varname = malloc(sizeof(char));
   strcpy(temp->varname,methodname);
   temp->type = mlist->type;
   temp->nodetype = MCALL_;
   temp->Lentry = NULL;
   temp->Gentry = gvar;
   if(gvar!=NULL){
     temp->Ctype = gvar->Ctype;
   }
   else if(strcmp(classVar->varname,"self")==0){
    temp->Ctype = Cptr;
   }
   else{
    temp->Ctype = Cptr;
   }
   temp->argList = argList;
   return temp;
}

struct tnode* makeFuncCallNode(char *funcname,struct tnode* argList){
       struct Gsymbol *func = GLookup(funcname);
       if(strcmp("alloc",funcname)==0 || strcmp("initialize",funcname)==0 || strcmp("free",funcname)==0 || strcmp("new",funcname)==0){
        struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
        node->varname = malloc(sizeof(char));
          strcpy(node->varname,funcname);
          node->type = NULL;
          if(strcmp("new",funcname)==0){
            node->Ctype = CLookup(argList->varname);
          }

          node->nodetype = FCALL_;
          node->Gentry = func;
          node->left=NULL;node->right =NULL;
          node->argList = argList;
        return node;
       }
       
       struct tnode* pList,*arg;
       arg = argList;
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
             struct tnode *temp1 = argList;
             //printf("%s %d %s\n",argList->varname,argList->nodetype,temp1->cond);
             while(temp1->cond!=NULL){
                  temp1 = temp1->cond;
            }
            //printf("%s %s %s %s\n",pList->type->name,temp1->type->name,pList->varname,temp1->varname);
             if(strcmp(pList->type->name,temp1->type->name)!=0){
                printf("Arguments type don't match 2\n");
                exit(1);
             }
             pList = pList->left;
             argList = argList->middle;
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
     //printf("%s %s\n",currFunc,temp);
     struct TypeTable *t;

     if(temp==NULL){
      printf("%s\n",Cptr->name);
      struct Memberfunclist *temp1 = Class_MLookup(Cptr,currFunc); 
      t = temp1->type; 
     }
     else{
      t = temp->type;
      printf("type %s\n",t->name );
     }
     //printf("%s %s\n",expr->varname,t->name );
     struct localTable *test = lTableLookup(currFunc);
     if(strcmp(expr->type->name,t->name)==0){
      printf("Inside if\n");
      struct tnode *newnode = (struct tnode*)malloc(sizeof(struct tnode));
       newnode->varname = malloc(sizeof(char));
       strcpy(newnode->varname,currFunc);
       newnode->left = expr;
       newnode->Gentry = temp;
       newnode->Lentry = test;
       newnode->right = NULL;newnode->cond = NULL;
       newnode->nodetype = RET_;
       return newnode;
     }
     else{
      printf("Type Mismatch 6\n");
      exit(1);
     }
}

struct tnode* makeUserDefinedNode(struct tnode *node){
     struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
     temp->nodetype = USERDEF_;
     temp->varname = malloc(sizeof(char));
     strcpy(temp->varname,"user");
     temp->cond = node;
     temp->left = NULL;
     temp->right = NULL;
     struct TypeTable *tTable;
     struct tnode* temp1 = node;
     printf("%s hello\n",temp1->varname);

     if(strcmp(temp1->varname,"self")==0){
      struct Fieldlist *flist = Class_FLookup(Cptr,temp1->cond->varname);
      if(flist==NULL){
        printf("Field not declared\n");
        exit(1);
      }
      printf("%s lol\n",flist->name );
      temp->type = flist->type;
      return temp;
     }

     while(temp1->cond!=NULL){
          temp1 = temp1->cond;
          //printf("%s\n",temp1->type->name );
     }
     temp->type = temp1->type;
     return temp;
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
    printf("data check\n");
    //printf("%s %s name \n",l->varname,r->varname);
    if(r->varname!=NULL){
       if(strcmp(r->varname,"null")==0 || strcmp(r->varname,"alloc")==0 || strcmp(r->varname,"initialize")==0 || strcmp(r->varname,"free")==0 ||strcmp(r->varname,"new")==0){
      return 1;
      }  
    }
    while(l->cond!=NULL){
      l = l->cond;
      printf("I m here\n");
    }
    while(r->cond!=NULL){
      r = r->cond;
      printf("I m here 1\n");
    }
    //printf("%s %s %s %s name \n",l->varname,r->varname,l->type->name,r->type);
    if(l->type==NULL || r->type==NULL){
      return 0;
    }
    if(strcmp(l->type->name,r->type->name)==0){
      printf("I m here 2\n");
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
    //  printf("I am in getMemoryAddress\n");
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

int getUserDefinedAddress(struct tnode* t,FILE* target_file){
        int p;
        p = getReg();
        t = t->cond;
        struct TypeTable *tTable;
        tTable = t->type;
        p = getMemoryAddress(t,target_file);
        fprintf(target_file, "MOV R%d, [R%d]\n",p,p);
       // printf("%s %s %s hit\n",tTable->name,t->cond->varname,t->cond->cond);
        
        struct Classtable *cvar =NULL;
        if(strcmp(t->varname,"self")==0){
          cvar = t->Ctype;
        }              
      
        while(t->cond->cond!=NULL){

            struct Fieldlist *flist = FLookup(tTable->name,t->cond->varname);
            if(flist==NULL){
              flist = Class_FLookup(cvar,t->cond->varname);  
            }
            int findex = flist->fieldIndex;
            fprintf(target_file, "ADD R%d, %d\n",p,findex);
            fprintf(target_file, "MOV R%d, [R%d]\n",p,p);
            tTable = flist->type;
            t = t->cond; 
            printf("IN user address\n");
          }

           if(t->cond->cond==NULL){
                if(strcmp(t->varname,"self")==0){
                  struct Fieldlist *flist = Class_FLookup(t->Ctype,t->cond->varname);
                  int findex = flist->fieldIndex;
                  fprintf(target_file, "ADD R%d, %d\n",p,findex);
                }
                else{
                  struct Fieldlist *flist = FLookup(tTable->name,t->cond->varname);
                  int findex = flist->fieldIndex;
                  fprintf(target_file, "ADD R%d, %d\n",p,findex);
                  printf("In not self\n");  
                }
                
             }

        freeReg();
        return p;

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

int initCodeGen(FILE* target_file){
    int p;
    p = getReg();
    fprintf(target_file, "MOV R%d,\"Init\"\n",p);
    fprintf(target_file, "PUSH R%d\n",p);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n",p);
    return p;
}

int allocCodeGen(FILE* target_file){
    int p;
    p = getReg();
    fprintf(target_file, "MOV R%d,\"Alloc\"\n",p);
    fprintf(target_file, "PUSH R%d\n",p);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n",p);
    return p;
}

int freeCodeGen(FILE* target_file,int a){
    int p = getReg(); 
    fprintf(target_file, "MOV R%d,\"Free\"\n",p);
    fprintf(target_file, "PUSH R%d\n",p);
    fprintf(target_file, "PUSH R%d\n",a);
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R%d\n",p);
    fprintf(target_file, "POP R%d\n",p);
    freeReg();
    return p;
}


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
    	case READ_ :{ q = getReg(); r = getReg(); int r1;
                  if(t->left->nodetype==USERDEF_){
                     r1 = getUserDefinedAddress(t,target_file);
                  }
                  else{
                     r1 = getMemoryAddress(t->left,target_file);  
                  }
                  
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
                    /* printf("%d\n",t->left->nodetype);
                     struct tnode *g = t->left;
                     while(g!=NULL){
                        printf("%s\n",g->varname);
                        g = g->cond;
                     }*/
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
      case NULL_ :{ p = getReg();
                    printf("I am in NULL\n");
                    fprintf(target_file, "MOV R%d,-1\n",p);
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
                     //printf("%d reg\n",RegNo );
    	               freeReg();
                     //printf("%d reg\n",RegNo );
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
      case USERDEF_ :{ p = getReg();
                       p = getUserDefinedAddress(t,target_file);
                       fprintf(target_file, "MOV R%d, [R%d]\n",p,p);
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
    	case ASSIGN_ :{ //printf("I am in assign %d\n",t->right->nodetype);
    		            q = codeGen(t->right,target_file);
                    
                    if(t->left->nodetype==POI_VAL_){
                      fprintf(target_file, "MOV R%d, [R%d]\n",p,p);
                    }

                    if(t->left->cond!=NULL){
                      p = getUserDefinedAddress(t->left,target_file);
                    }
                    else{
                      p = getMemoryAddress(t->left,target_file);
                    }
                    //fprintf(target_file, "MOV R%d, R%d\n",p,q);
    		            fprintf(target_file, "MOV [R%d], R%d\n",p,q);

                    if(t->left->Ctype!=NULL && t->left->type==NULL){
                      int vptr = 4095 + 8*(t->right->Ctype->Class_index) + 1;
                      fprintf(target_file, "ADD R%d,1\n",p);
                      fprintf(target_file, "MOV [R%d],%d\n",p,vptr);
                    }
    		            //freeReg();
    		            break;
    	              }
    	case CONN_ : { //printf("I am in conn\n");
                     if(t->left!=NULL){
                       printf("%d\n",t->left->nodetype );
                       printf("%d\n",t->right->nodetype); 
                     }
                     else if(t->left==NULL){
                      printf("NULL\n");
                      if(t->right!=NULL){
                        printf("%d\n",t->right->nodetype );
                      }
                      if(t->right->left==NULL && t->right->right==NULL){
                        printf("both null\n");
                      }
                     }
                     
                     p = codeGen(t->left,target_file);
                     freeAllReg();
                     //printf("reached left\n");
    		             q = codeGen(t->right,target_file);
                     freeAllReg();
                     //printf("reached right\n");
                     break;
    	            }
      case FCALL_ :{ 
                      printf("I am in fcall codeGen %s\n",t->varname);
                     if(strcmp(t->varname,"initialize")==0){
                         p = initCodeGen(target_file);
                         return p;
                     }
                     else if(strcmp(t->varname,"alloc")==0){
                         p = allocCodeGen(target_file);
                         return p;
                     }
                     else if(strcmp(t->varname,"free")==0){
                         //printf("%s\n",t->argList->varname);
                         p = freeCodeGen(target_file,codeGen(t->argList,target_file));
                         printf("In free func\n");
                         return p;
                     }
                     else if(strcmp(t->varname,"new")==0){
                         p = allocCodeGen(target_file);
                         return p;
                     }
                     
                     //push_registers
                     int i=0;
                     while(i<RegNo){
                      fprintf(target_file, "PUSH R%d\n",i);
                      i++;
                     }


                     struct tnode *temp = t->argList;
                     while(temp!=NULL){
                       //printf("%d %s\n",temp->nodetype,temp->varname);
                       p = codeGen(temp,target_file);
                       fprintf(target_file, "PUSH R%d\n",p);

                       temp = temp->middle;
                     }
                     //push empty space for return value
                     p = getReg();
                     fprintf(target_file, "PUSH R%d\n",p);
                     
                     fprintf(target_file, "CALL F%d\n",t->Gentry->flabel);
                     
                     fprintf(target_file, "POP R%d\n",p);
                     q = getReg();
                     temp = t->argList;
                     while(temp!=NULL){
                      fprintf(target_file,"POP R%d\n",q);
                      temp = temp->middle;
                     }
                     freeReg();
                     //pop registers
                     while(i>0){
                      i--;
                      fprintf(target_file, "POP R%d\n",i);
                     }
                     break;
                   }
      case FUNC_ :{   //printf("I am in func codeGen\n");
                      if(strcmp(t->varname,"main")==0){
                           fprintf(target_file, "MAIN:\n");
                           fprintf(target_file, "BRKP\n");
                           fprintf(target_file, "MOV SP,%d\n",staticAddress+1);
                           fprintf(target_file, "MOV BP,%d\n",staticAddress+1);
                      }
                      else if(t->Gentry!=NULL){
                        fprintf(target_file, "F%d:\n",t->Gentry->flabel);
                        fprintf(target_file, "PUSH BP\n");
                        fprintf(target_file, "MOV BP,SP\n");
                      }
                      else if(t->Ctype!=NULL){
                        struct Memberfunclist *mlist = Class_MLookup(t->Ctype,t->varname);
                        fprintf(target_file, "F%d:\n",mlist->flabel);
                        fprintf(target_file, "PUSH BP\n");
                        fprintf(target_file, "MOV BP,SP\n");
                      }

                      
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
      case MCALL_ : {  //push_registers
                     printf("I am in MCALL codeGen\n");
                     printf("%s %s\n",t->right->varname,t->Ctype->name );
                     int i=0;
                     while(i<RegNo){
                      fprintf(target_file, "PUSH R%d\n",i);
                      i++;
                     }
                     p = getReg();
                     if(strcmp(t->right->varname,"self")==0){
                       q = getMemoryAddress(t->right,target_file);
                       fprintf(target_file, "MOV R%d,[R%d]\n",p,q);
                       fprintf(target_file, "PUSH R%d\n",p);
                       q = 4095 + (t->Ctype->Class_index)*8 + 1;
                       fprintf(target_file, "MOV R%d,%d\n",p,q);
                       fprintf(target_file, "PUSH R%d\n",p);
                       freeReg();
                     }
                     else{
                       //printf("In global mcall\n");
                       struct Gsymbol *gtemp = GLookup(t->right->varname);
                       if(gtemp!=NULL){
                         fprintf(target_file, "MOV R%d,[%d]\n",p,gtemp->binding);
                         fprintf(target_file, "PUSH R%d\n",p);
                         fprintf(target_file, "MOV R%d,[%d]\n",p,gtemp->binding+1);
                         fprintf(target_file, "PUSH R%d\n",p);
                         freeReg(); 
                       }
                       else{
                        //printf("In local mcall %s\n",t->Ctype->name);
                         struct Fieldlist *ftemp = Class_FLookup(t->Ctype,t->right->varname);
                         fprintf(target_file, "MOV R%d,BP\n",q);
                         fprintf(target_file, "ADD R%d,%d\n",q,ftemp->fieldIndex);
                         fprintf(target_file, "MOV R%d,[R%d]\n",p,q );
                         fprintf(target_file, "PUSH R%d\n",p);
                         freeReg();
                       }
                     }

                     
                     struct tnode *temp = t->argList;
                     while(temp!=NULL){
                       //printf("%d %s\n",temp->nodetype,temp->varname);
                       printf("Inside MCALL Arguments\n");
                       p = codeGen(temp,target_file);
                       fprintf(target_file, "PUSH R%d\n",p);

                       temp = temp->middle;
                     }
                     //push empty space for return value
                     p = getReg();
                     fprintf(target_file, "PUSH R%d\n",p);
                     
                     /*struct Memberfunclist *mlist = Class_MLookup(t->Ctype,t->varname);
                     if(mlist==NULL){
                      //printf("%s\n",t->right->type->name);
                      struct Classtable *cvar = CLookup(t->right->Ctype->name);
                      mlist = Class_MLookup(cvar,t->varname);
                     }
                     fprintf(target_file, "CALL F%d\n",mlist->flabel);
                     */
                     struct Memberfunclist *mlist = Class_MLookup(t->Ctype,t->varname);
                     struct Gsymbol *gtemp = GLookup(t->right->varname);
                     if(gtemp!=NULL){
                       fprintf(target_file, "MOV R%d,%d\n",p,gtemp->binding+1);
                       fprintf(target_file, "MOV R%d,[R%d]\n",p,p);
                       fprintf(target_file, "ADD R%d,%d\n",p,mlist->Funcposition);
                       fprintf(target_file, "MOV R%d,[R%d]\n",p,p);
                       fprintf(target_file, "CALL R%d\n",p);
                     }
                     else{
                       q = 4095 + (t->Ctype->Class_index)*8 + 1;
                       fprintf(target_file, "MOV R%d,%d\n",p,q);
                       fprintf(target_file, "ADD R%d,%d\n",p,mlist->Funcposition);
                       fprintf(target_file, "MOV R%d,[R%d]\n",p,p);
                       fprintf(target_file, "CALL R%d\n",p);
                     }
                     

                     fprintf(target_file, "POP R%d\n",p);
                     q = getReg();
                     temp = t->argList;
                     while(temp!=NULL){
                      fprintf(target_file,"POP R%d\n",q);
                      temp = temp->middle;
                     }
                     freeReg();

                     fprintf(target_file, "POP R%d\n",q); //pop virtual function table pointer
                     fprintf(target_file, "POP R%d\n",q); //pop the self or the object pushed 
                     //pop registers
                     while(i>0){
                      i--;
                      fprintf(target_file, "POP R%d\n",i);
                     }
                     break;
                    }
      case BODY_ :{  //p = getReg();
                     printf("I am in body codeGen\n");
                     printf("%d\n",t->left->nodetype);
                     codeGen(t->left,target_file);
                     codeGen(t->right,target_file);
                     break;
                  }
      case RET_ :{  p = getReg();
                  printf("I am in ret codeGen %s\n",t->varname);
                  if(t->left!=NULL && strcmp(t->varname,"main")!=0){
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
                        printf("If then else\n");
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