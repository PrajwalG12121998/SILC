struct Gsymbol *head = NULL;
int address = 4095;

int getAddress(int size){
    int start_address = address + 1;
    address = address + size;
    return start_address;
}

struct Gsymbol *Lookup(char *name){
   struct Gsymbol *temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
   temp = head;
   while(temp!=NULL){
   	 if(strcmp(temp->name,name) == 0)
   	 	break;
   	 temp = temp->next;
   } 
   return temp;
}

void Install(char *name,int type,int size){
	struct Gsymbol *check = Lookup(name);
	if(check!=NULL){
		printf("The variable is already present\n");
		exit(1);
	}
    struct Gsymbol *newnode = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    struct Gsymbol *last = head;
    newnode->name = malloc(sizeof(char));
    strcpy(newnode->name,name);
    newnode->type = type;
    newnode->size = size;
    newnode->binding = getAddress(size);
    newnode->next = NULL;

    if(head ==NULL){
    	head = newnode;
    	return ;
    }
    while(last->next!=NULL){
    	last = last->next;
    }

    last->next = newnode;
    return;
}

/*void groupGInstall(struct tnode *node,int type){
     struct tnode *temp; 
     temp =  node;
     printf("reached at groupgInstall\n");
     while(temp!=NULL){
      Install(temp->varname,type,1);
      temp = temp->left;
     }
     return ;
}*/

void printSymbolTable(){
	struct Gsymbol *temp = head;
	while(temp!=NULL){
		printf("%s %d %d %d\n",temp->name,temp->type,temp->size,temp->binding);
		temp = temp->next;
	}
}