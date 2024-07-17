struct Gsymbol *Ghead = NULL;
struct localTable *lTablehead = NULL;
struct TypeTable *tTablehead = NULL;

int flabel = -1;
int fieldCount = 1;

int localOffset = 1;
int argOffset = -3;

int getFuncLabel(){
    flabel++;
    return flabel;
}

int getArgOffset(){
  return argOffset--;
}

int getlocalOffset(){
  return localOffset++; 
}

struct Gsymbol *GLookup(char *name){
   struct Gsymbol *temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
   temp = Ghead;
   while(temp!=NULL){
   	 if(strcmp(temp->name,name) == 0)
   	 	break;
   	 temp = temp->next;
   } 
   return temp;
}

void GInstall(char *name,char *type,int size1,int size2,struct tnode *node){
	struct Gsymbol *check = GLookup(name);
	if(check!=NULL){
		printf("The variable is already present\n");
		exit(1);
	}
    struct Gsymbol *newnode = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    struct Gsymbol *last = Ghead;
    newnode->name = malloc(sizeof(char));
    strcpy(newnode->name,name);
    newnode->type = TLookup(type);
    newnode->size = size1*size2;
    newnode->no_col = size2;
    if(size1==0 && size2==0){
      newnode->binding = NULL;
    }
    else{
      newnode->binding = getAddress(newnode->size);  
    }
    newnode->paramlist = node;
    int f;
    if(size1==0 && size2==0){
       f = getFuncLabel();  
    }
    else{
       f = -1;
    }
    newnode->flabel = f;
    newnode->next = NULL;

    if(Ghead ==NULL){
    	Ghead = newnode;
    	return ;
    }
    while(last->next!=NULL){
    	last = last->next;
    }

    last->next = newnode;
    return;
}

void lTableInstall(char *funcname){
    struct Gsymbol *node = GLookup(funcname);
    if(node!=NULL || strcmp(funcname,"main")==0){
       struct localTable *newFunc = (struct localTable*)malloc(sizeof(struct localTable));
       struct localTable *last = lTablehead;
       newFunc->funcname = malloc(sizeof(char));
       strcpy(newFunc->funcname,funcname);
       newFunc->lentry = NULL;
       newFunc->next = NULL;  

       if(lTablehead == NULL){
        lTablehead = newFunc;
        return;
       }
       while(last->next!=NULL){
         last = last->next;
       }

       last->next = newFunc;
       return ;
    }
    else{
      printf("Function not declared\n");
      exit(1);
    }
  return ;
}

struct localTable *lTableLookup(char *funcname){
   struct localTable *temp = (struct localTable*)malloc(sizeof(struct localTable));
   temp = lTablehead;
   while(temp!=NULL){
     if(strcmp(temp->funcname,funcname) == 0)
      break;
     temp = temp->next;
   } 
   return temp;
}

void LInstall(char *funcname,char *type,char *varname,int binding){
     struct localTable *temp = lTableLookup(funcname);
     if(temp!=NULL){
        struct Lsymbol *newnode = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
        newnode->name = malloc(sizeof(char));
        strcpy(newnode->name,varname);
        newnode->type = TLookup(type);
        newnode->binding = binding;
        newnode->next = NULL;
        struct Lsymbol *Llist = temp->lentry;

        if(Llist==NULL){
          temp->lentry = newnode;
          return ;
        }
        while(Llist->next!=NULL){
          Llist = Llist->next;
        }

        Llist->next = newnode;
        return ;
     }
}

struct Lsymbol *LLookup(char *funcname,char *name){
     struct localTable *temp = lTableLookup(funcname);
     if(temp!=NULL){
        struct Lsymbol *node = temp->lentry;
        while(node!=NULL){
          if(strcmp(node->name,name)==0)
            break;
          node = node->next;
        }
        return node;
     }
     return NULL;
}

void TypeTableCreate(){
   struct TypeTable *integer = (struct TypeTable*)malloc(sizeof(struct TypeTable));
   integer->name = malloc(sizeof(char));
   strcpy(integer->name,"int"); 
   integer->fields = NULL;
   tTablehead = integer;

   struct TypeTable *string = (struct TypeTable*)malloc(sizeof(struct TypeTable));
   string->name = malloc(sizeof(char));
   strcpy(string->name,"str");
   string->fields = NULL;

   struct TypeTable *boolean = (struct TypeTable*)malloc(sizeof(struct TypeTable));
   boolean->name = malloc(sizeof(char));
   strcpy(boolean->name,"bool");
   boolean->fields = NULL;

   struct TypeTable *void_ = (struct TypeTable*)malloc(sizeof(struct TypeTable));
   void_->name = malloc(sizeof(char));
   strcpy(void_->name,"void");
   void_->fields = NULL;
   
   struct TypeTable *null_ = (struct TypeTable*)malloc(sizeof(struct TypeTable));
   null_->name = malloc(sizeof(char));
   strcpy(null_->name,"NULL");
   null_->fields = NULL;
   
   integer->next = string;
   string->next = boolean;
   boolean->next = void_;
   void_->next = null_;
   null_->next = NULL;
   return;
}

void TInstall(char *name,int size,struct Fieldlist *fields){
   struct TypeTable *newnode = (struct TypeTable*)malloc(sizeof(struct TypeTable));
   struct TypeTable *last = tTablehead;
   newnode->name = malloc(sizeof(char));
   strcpy(newnode->name,name);
   newnode->size = size;
   newnode->fields = fields;
   newnode->next = NULL;
   fieldCount = 1;
   if(tTablehead==NULL){
    tTablehead = newnode;
    return ;
   }

   while(last->next!=NULL){
    last = last->next;
   }

   last->next = newnode;
   return ;
}

struct TypeTable *TLookup(char *name){
   struct TypeTable *temp = (struct TypeTable*)malloc(sizeof(struct TypeTable));
   temp = tTablehead;
   while(temp!=NULL){
    if(strcmp(temp->name,name)==0){
      return temp;
    }
    temp = temp->next;
   }
   return temp;
}

struct Fieldlist *FLookup(char *type,char *name){
    struct TypeTable *temp = TLookup(type);
    struct Fieldlist *flist = temp->fields;
    while(flist!=NULL){
      if(strcmp(flist->name,name)==0){
        return flist;
      }
      flist = flist->next;
    }
    return flist;
}

void addField(char *typename,char *name,char *type){
     struct TypeTable *tTable = TLookup(typename);
     struct Fieldlist *flist = tTable->fields;
     struct Fieldlist *node = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
     node->name = malloc(sizeof(char));
     strcpy(node->name,name);
     node->fieldIndex = fieldCount++;
     node->next = NULL;
     node->type = TLookup(type);
     
     if(tTable->fields==NULL){
       tTable->fields = node;
       return ;
     }

     while(flist->next!=NULL){
      flist = flist->next;
     }

     flist->next = node;
     return ;
}

void printSymbolTable(){
	struct Gsymbol *temp = Ghead;
	while(temp!=NULL){
		printf("%s %s %d %d %d\n",temp->name,temp->type->name,temp->size,temp->binding,temp->flabel);
    if(temp->paramlist!=NULL){
      struct tnode *test = temp->paramlist;
      while(test!=NULL){
        printf("%s %s\n",test->varname,test->type->name);
        test = test->left;
      }
    }
		temp = temp->next;
	}
  struct localTable *test = lTablehead;
  while(test!=NULL){
    printf("%s\n",test->funcname);
    if(test->lentry!=NULL){
      struct Lsymbol *Llist = test->lentry;
      while(Llist!=NULL){
        printf("%s %s %d\n",Llist->name,Llist->type->name,Llist->binding);
        Llist = Llist->next;
      }
    }
    test = test->next;
  }
}

void print_typeTable(){
    struct TypeTable *tTable = tTablehead;
    while(tTable!=NULL){
      printf("%s\n",tTable->name);
      struct Fieldlist *flist = tTable->fields;
      if(flist!=NULL){
        while(flist!=NULL){ 
         printf("%s %s %d\n",flist->name,flist->type->name,flist->fieldIndex);
         flist = flist->next;
        }
      }
      tTable = tTable->next;
    }
}
