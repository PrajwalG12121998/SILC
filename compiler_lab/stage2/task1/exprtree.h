#define NUM_ 1
#define PLUS_ 2
#define MINUS_ 3
#define MUL_ 4
#define DIV_ 5
#define ASSIGN_ 6
#define READ_ 7
#define WRITE_ 8
#define CONN_ 9
#define VAR_ 10

typedef struct tnode{
     int val; // value of a number for NUM nodes.
     int type;  //type of variable
     char *varname;  //name of a variable for ID nodes
     int nodetype;  //information about non-leaf node - read/write/connector/+/* etc
     struct tnode *left,*right; //left and right branches
}tnode;

/*create a node tnode*/
//struct tnode* createTree(int val,int type,char* c,struct tnode *l,struct tnode *r);

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int type,int n);

/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(int type,struct tnode *l,struct tnode *r);

/*Make a tnode with variable,left and right are null*/
struct tnode* makeVariableNode(int type,char *c);

/*Make a tnode for Read and Write instructions*/
struct tnode* makeWrite_ReadNode(int type,struct tnode* l);

/*Make connected node as specified in tutorial*/
struct tnode* makecConnectedNode(int type,struct tnode* l,struct tnode* r);

//int RegNo = 0; //register number that is free

int getReg(); //To allocate a free register

void freeReg(); // To free the register

FILE *target_file;

int codeGen(struct tnode *t,FILE* fptr);

void infix_form(struct tnode *t);