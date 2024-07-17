struct tnode* makeLeafNode(int n){
struct tnode *temp;
temp = (struct tnode*)malloc(sizeof(struct tnode));
temp->op = NULL;
temp->val = n;
temp->left = NULL;
temp->right = NULL;
return temp;
}
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
struct tnode *temp;
temp = (struct tnode*)malloc(sizeof(struct tnode));
temp->op = malloc(sizeof(char));
*(temp->op) = c;
temp->left = l;
temp->right = r;
return temp;
}
int evaluate(struct tnode *t){
if(t->op == NULL){
return t->val;
}
else{
switch(*(t->op)){
case '+' : return evaluate(t->left) + evaluate(t->right);
break;
case '-' : return evaluate(t->left) - evaluate(t->right);
break;
case '*' : return evaluate(t->left) * evaluate(t->right);
break;
case '/' : return evaluate(t->left) / evaluate(t->right);
break;
}
}
}

void postfix_form(struct tnode *t){
    if(t==NULL){
          return ;
        }
    postfix_form(t->left);
    postfix_form(t->right);
    if(t->op==NULL){
        printf("%d ",t->val);
    }
    else{
        printf("%c ",*(t->op));
    }
}

void prefix_form(struct tnode *t){
    if(t==NULL){
         return ;
    }
    if(t->op==NULL){
         printf("%d ",t->val);
    }
    else{
         printf("%c ",*(t->op));
    }
    prefix_form(t->left);
    prefix_form(t->right);    
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

int codeGen(struct tnode *t,FILE * target_file){
    
    int p,q;
    if(t==NULL){
        return ;
    }
    if(t->op==NULL){
        p = getReg();
        fprintf(target_file,"MOV R%d, %d\n",p,t->val);
    }
    else{
    switch(*(t->op)){
       case '+':{ p = codeGen(t->left,target_file);
                  q = codeGen(t->right,target_file);
                  fprintf(target_file, "ADD R%d, R%d\n",p,q);
                  freeReg();
                  break;
                }
       }
    }

    return p;
}