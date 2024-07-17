

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

int codeGen(struct tnode *t,FILE *target_file){
    
    int p,q;
    if(t->op==NULL){
    	p = getReg();
    	fprintf(target_file, "MOV R%d, %d\n",p,t->val);
    }
    switch(*(t->op)){
       case '+':{ p = codeGen(t->left);
       	          q = codeGen(t->right);
       	          fprintf(target_file, "ADD R%d, R%d\n",p,q);
       	          freeReg();
       	          break;
                }
       }

    return p;
}