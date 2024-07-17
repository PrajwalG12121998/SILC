typedef struct tnode{
int val;	//value of for the expression tree
char *op;	//indicates the opertor branch
struct tnode *left,*right; //left and right branches
}tnode;
/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);
/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
/*To evaluate an expression tree*/
int evaluate(struct tnode *t);
/*To evaluate the postfix expression of the input expression*/
void postfix_form(struct tnode *t);
/*To evaluate the prefix expression of the input expression*/
void prefix_form(struct tnode *t);

int RegNo = 0; //register number that is free

int getReg(); //To allocate a free register

void freeReg(); // To free the register

FILE *target_file;

int codeGen(struct tnode *t,FILE* fptr);

