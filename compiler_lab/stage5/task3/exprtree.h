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
#define LT_ 11
#define GT_ 12
#define EQ_ 13
#define LE_ 14
#define GE_ 15
#define NE_ 16
#define If_t_Else 17
#define If_then 18
#define inttype 19
#define booltype 20
#define while_ 21
#define break_ 22
#define continue_ 23
#define repeatUntil_ 24
#define doWhile_ 25
#define stringtype 26
#define STR_VAL_ 27
#define POI_ADD_ 28
#define POI_VAL_ 29
#define PRNT_ 30
#define MOD_ 31
#define FUNC_ 32
#define RET_ 33
#define BODY_ 34
#define FCALL_ 35

char *currFunc;

typedef struct tnode{
     int val; // value of a number for NUM nodes.
     int type;  //type of variable
     char *str_val; //to store string 
     char *varname;  //name of a variable for ID nodes
     int nodetype;  //information about non-leaf node - read/write/connector/+/* etc
     struct tnode *left,*right,*argList; //left and right branches
     struct Gsymbol *Gentry;  //pointer to GST entry for global variables and functions
     struct Lsymbol *Lentry;  //pointer to LST entry for local variables and functions
     struct tnode *cond //conditional expression 
}tnode;

/*create a node tnode*/
//struct tnode* createTree(int val,int type,char* c,struct tnode *l,struct tnode *r);

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int nodetype,int n);

/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(int nodetype,int type,struct tnode *l,struct tnode *r);

/*Make a tnode with variable,left and right are null*/
struct tnode* makeVariableNode(int nodetype,char *c,char *text);

/*Make a tnode for Read and Write instructions*/
struct tnode* makeWrite_ReadNode(int nodetype,struct tnode* l);

/*Make connected node as specified in tutorial*/
struct tnode* makecConnectedNode(int nodetype,struct tnode* l,struct tnode* r);

struct tnode* makeConditionalNode(int nodetype,struct tnode*cond,struct tnode* l,struct tnode* r);

int dataTypeCheck(struct tnode* l,struct tnode* r);

void push_registers(FILE* target_file);

void pop_registers(FILE* target_file);
//int RegNo = 0; //register number that is free

int getReg(); //To allocate a free register

void freeReg(); // To free the register

FILE *target_file;

int codeGen(struct tnode *t,FILE* fptr);

void infix_form(struct tnode *t);

int evaluate(struct tnode *t);