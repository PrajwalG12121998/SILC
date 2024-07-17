struct Gsymbol *Ghead = NULL;
struct localTable *lTablehead = NULL;
int address = 4095;

int getAddress(int size){
    int start_address = address + 1;
    address = address + size;
    return start_address;
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

void GInstall(char *name,int type,int size1,int size2,struct Paramstruct *node){
	struct Gsymbol *check = GLookup(name);
	if(check!=NULL){
		printf("The variable is already present\n");
		exit(1);
	}
    struct Gsymbol *newnode = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    struct Gsymbol *last = Ghead;
    newnode->name = malloc(sizeof(char));
    strcpy(newnode->name,name);
    newnode->type = type;
    newnode->size = size1*size2;
    newnode->no_col = size2;
    newnode->binding = getAddress(newnode->size);
    newnode->paramlist = node;
    newnode->flabel = NULL;
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

void LInstall(char *funcname,int type,char *varname){
     struct localTable *temp = lTableLookup(funcname);
     if(temp!=NULL){
        struct Lsymbol *newnode = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
        newnode->name = malloc(sizeof(char));
        strcpy(newnode->name,varname);
        newnode->type = type;
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

void printSymbolTable(){
	struct Gsymbol *temp = Ghead;
	while(temp!=NULL){
		printf("%s %d %d %d\n",temp->name,temp->type,temp->size,temp->binding);
    if(temp->paramlist!=NULL){
      struct tnode *test = temp->paramlist;
      while(test!=NULL){
        printf("%s %d\n",test->varname,test->type);
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
        printf("%s %d\n",Llist->name,Llist->type);
        Llist = Llist->next;
      }
    }
    test = test->next;
  }
}

/*struct Paramstruct *makeParamNode(char *name,int datatype){
    struct Paramstruct *newnode = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    strcpy(newnode->name,name);
    newnode->type = datatype;
    return newnode;
}*/