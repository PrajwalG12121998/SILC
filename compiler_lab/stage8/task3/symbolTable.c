struct Gsymbol *Ghead = NULL;
struct localTable *lTablehead = NULL;
struct TypeTable *tTablehead = NULL;
struct Classtable *tClasshead = NULL;

int flabel = -1;
int fieldCount = 1;
int classIndex = 0;
int functionPos = 0;

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

struct Classtable *CLookup(char *name){
   struct Classtable *temp = (struct Classtable*)malloc(sizeof(struct Classtable));
   temp = tClasshead;
   while(temp!=NULL){
    if(strcmp(temp->name,name)==0){
      return temp;
    }
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
    newnode->Ctype = CLookup(type);
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

void lTableInstall(char *funcname,struct Classtable *Cptr,char *type){
    struct Gsymbol *node = GLookup(funcname);
    struct Memberfunclist *mfunc = Class_MLookup(Cptr,funcname);
    if(node!=NULL || strcmp(funcname,"main")==0 || mfunc!=NULL){
       struct localTable *newFunc = (struct localTable*)malloc(sizeof(struct localTable));
       struct localTable *last = lTablehead;
       newFunc->funcname = malloc(sizeof(char));
       strcpy(newFunc->funcname,funcname);
       newFunc->type = TLookup(type);
       newFunc->Ctype = Cptr;
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
   char *currentClass = malloc(sizeof(char));
   temp = lTablehead;
   if(Cptr==NULL){
    
    while(temp!=NULL){
     if(strcmp(temp->funcname,funcname) == 0){
       printf("fname found: %s\n",temp->funcname );
       break;
      }
     //printf("fname: %s\n",temp->funcname );
     temp = temp->next;

   } 
   return temp;  
  }
   
   while(temp!=NULL){
     if(strcmp(temp->funcname,funcname) == 0){
      if(temp->Ctype!=NULL && Cptr!=NULL){
        if(strcmp(temp->Ctype->name,Cptr->name)==0){
          break;
        }
      }
     }
     temp = temp->next;
   } 
   return temp;
  
}

void LInstall(char *funcname,char *type,char *varname,int binding){
     struct localTable *temp = lTableLookup(funcname);
     if(temp!=NULL){
        //printf("func: %s %s\n",Cptr->name,temp->Ctype->name); 
     }
     
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
   if(name==NULL){
    return NULL;
   }
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



struct Classtable *CInstall(char *name,char *parent_name){
     struct Classtable *newnode = (struct Classtable*)malloc(sizeof(struct Classtable));
     struct Classtable *last = tClasshead;
     newnode->name = malloc(sizeof(char));
     strcpy(newnode->name,name);
     if(parent_name!=NULL){
        newnode->Parentptr = CLookup(parent_name); 
     }
     fieldCount = 1;
     functionPos = 0;
     newnode->next = NULL;
     newnode->Memberfield = NULL;
     newnode->Vfuncptr = NULL;
     newnode->Class_index = classIndex++;
     if(tClasshead==NULL){
      tClasshead = newnode;
     return newnode;
     }

     while(last->next!=NULL){
       last = last->next;
     }

     last->next = newnode;
     return newnode;
}

void Child_Class_FInstall(struct Classtable *cptr,char *parent_name){
    struct Classtable *parentptr = CLookup(parent_name);
    if(parentptr==NULL){
      printf("Parent class not declared\n");
      exit(1);
    }
    struct Fieldlist *flist = parentptr->Memberfield;
    while(flist!=NULL){
      Class_FInstall(cptr,flist->type->name,flist->name);
      flist = flist->next;
    }
}

int search_child_functionslist(struct Classtable *cptr,char *funcname,struct Classtable *pcptr){
    struct Memberfunclist *mlist = cptr->Vfuncptr;
    struct Memberfunclist *mlook = Class_MLookup(pcptr,funcname);
    while(mlist!=NULL){
      if(strcmp(mlist->name,funcname)==0){
         struct tnode *plist_child = mlist->paramlist;
         struct tnode *plist_parent = mlook->paramlist;
         while(plist_child!=NULL || plist_parent!=NULL){
           if(strcmp(plist_child->type->name,plist_parent->type->name)!=0){
             printf("Arguments doesn't match 3\n");
             exit(1);
           }
        plist_child = plist_child->left;
        plist_parent = plist_parent->left;
   }
   
      if((plist_child!=NULL && plist_parent==NULL) || (plist_child==NULL && plist_parent!=NULL)){
            printf("Too Less or More Arguments\n");
            exit(1);
      }
        return 1;
      }
      mlist = mlist->next;
    } 
    return 0;
}

void Child_Class_MInstall(struct Classtable *cptr,char *parent_name){
    struct Classtable *parentptr = CLookup(parent_name);
    if(parentptr==NULL){
      printf("Parent class not declared\n");
      exit(1); 
    }
    int flag;
    struct Memberfunclist *mlist1 = parentptr->Vfuncptr;
    while(mlist1!=NULL){
      //int r = search_child_functionslist(cptr,mlist1->name,parentptr);

         flag=0;
         struct Memberfunclist *mlist = cptr->Vfuncptr;
         struct Memberfunclist *node = (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
         node->name = malloc(sizeof(char));
         strcpy(node->name,mlist1->name);
         node->next = NULL;
         node->type = mlist1->type;
         node->paramlist = mlist1->paramlist;
         node->flabel = mlist1->flabel;
         node->Funcposition = functionPos++;

         if(mlist==NULL){
            cptr->Vfuncptr = node;
            flag=1;
         }

        if(flag!=1){
         while(mlist->next!=NULL){
          mlist = mlist->next;
         }

         mlist->next = node;
         }   
      mlist1 = mlist1->next;
    }
}

void Class_FInstall(struct Classtable *cptr,char *typename,char *name){
     struct Fieldlist *flist = cptr->Memberfield;
     struct Fieldlist *node = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
     node->name = malloc(sizeof(char));
     strcpy(node->name,name);
     node->next = NULL;

     node->type = TLookup(typename);
     if(TLookup(typename)==NULL){
      node->Ctype = CLookup(typename);
     }
     else{
       node->Ctype = cptr; 
     }
     printf("\n%s %s yes you can do it\n\n",name,node->Ctype->name );
     node->fieldIndex = fieldCount++;
     if(cptr->Memberfield==NULL){
        cptr->Memberfield = node;
        return ;
     }

     while(flist->next!=NULL){
      flist = flist->next;
     }

     flist->next = node;
     return ;
}

void Class_MInstall(struct Classtable *cptr,char *name,char *type,struct tnode *Paramlist){
     struct Memberfunclist *mlist = cptr->Vfuncptr;
     struct Memberfunclist *mlist1 = cptr->Vfuncptr;
     struct Memberfunclist *node = (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
     //check whether already present
     while(mlist1!=NULL){
        if(strcmp(name,mlist1->name)==0){
          mlist1->type = TLookup(type);
          mlist1->paramlist = Paramlist;
          mlist1->flabel = getFuncLabel();
          return;     
        }
        mlist1 = mlist1->next;
     }
     node->name = malloc(sizeof(char));
     strcpy(node->name,name);
     node->next = NULL;
     node->type = TLookup(type);
     node->paramlist = Paramlist;
     node->flabel = getFuncLabel();
     node->Funcposition = functionPos++;

     if(mlist==NULL){
        cptr->Vfuncptr = node;
        return ;
     }

     while(mlist->next!=NULL){
      mlist = mlist->next;
     }

     mlist->next = node;
     return ;
}

struct Memberfunclist *Class_MLookup(struct Classtable *Ctype,char *name){
     if(Ctype!=NULL){
        struct Memberfunclist *temp = Ctype->Vfuncptr;
      while(temp!=NULL){
       if(strcmp(temp->name,name)==0){
         return temp;
       }
       temp = temp->next;
      }
      return temp; 
     }
     return NULL;
   
}

struct Fieldlist *Class_FLookup(struct Classtable* Ctype,char* name){
  if(Ctype!=NULL){
     struct Fieldlist *temp = Ctype->Memberfield;
     while(temp!=NULL){
       if(strcmp(temp->name,name)==0){
         return temp;
       }
       temp = temp->next;
     }
   return temp;
 }
 return NULL;
}

void addField_and_Method_count(struct Classtable *Cptr,int fcount,int mcount){
     
    struct Fieldlist *flist = Cptr->Memberfield;
    Cptr->classFieldcount = 0;
    while(flist!=NULL){
      Cptr->classFieldcount++;
      flist = flist->next;
    } 
    struct Memberfunclist *mlist = Cptr->Vfuncptr;
    Cptr->Methodcount = 0;
    while(mlist!=NULL){
      Cptr->Methodcount++;
      mlist = mlist->next;
    }  
     
     return;
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
		printf("%s %d %d %d\n",temp->name,temp->size,temp->binding,temp->flabel);
    if(temp->paramlist!=NULL){
      //printf("Has paramlist\n");
      struct tnode *test = temp->paramlist;
      while(test!=NULL){
        printf("%s\n",test->varname);
        test = test->left;
      }
    }
		temp = temp->next;
	}
  printf("\nlocal table \n" );
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
    printf("\n");
    test = test->next;
  }
}

void printClassTable(){
  struct Classtable *temp = tClasshead;
  while(temp!=NULL){
    printf("%s %d %d %d\n",temp->name,temp->classFieldcount,temp->Methodcount,temp->Class_index);
    if(temp->Parentptr!=NULL){
      printf(" Parent pointer:  %s\n",temp->Parentptr->name);
    }
    struct Fieldlist *flist = temp->Memberfield;
    while(flist!=NULL){
      printf("%s %d\n",flist->name,flist->fieldIndex);
      flist = flist->next;
    }
    struct Memberfunclist *mlist = temp->Vfuncptr;
    while(mlist!=NULL){
      printf("%s %d %d\n",mlist->name,mlist->flabel,mlist->Funcposition);
      mlist = mlist->next;
    }
    temp = temp->next;
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
void printLocalTable(){
   struct localTable *lTable = lTablehead;
   while(lTable!=NULL){
    printf("%s\n",lTable->funcname);
    lTable = lTable->next;
   }
   return ;
}
