#define INTEGER_ 1
#define STRING_ 2

struct localTable{
    char *funcname;  //name of the function
    struct Lsymbol *lentry; //all the arguments and the defined variables list
    struct localTable *next; //pointer to the next function
};

struct Lsymbol{
   char *name;  //name of the variable
   int type;    //type of the variable:(Integer / String) 
   int binding; //local binding of the variable
   struct Lsymbol *next; //points to the next Local Symbol Table entry
};

struct Gsymbol{
   char* name; //name of variable
   int size;  //size of the type of variable
   int type;  //type of the variable
   int binding;  //stores the static memory address of the variable
   int no_col;  //to store number of columns for 2d array
   struct tnode *paramlist; //pointer to the head of the formal parameter list
                                  //in case of functions
   int flabel; //a label for identifying the starting address of a function's code  	
   struct Gsymbol *next;  //points to the next Global Symbol Table entry
};

struct Gsymbol *GLookup(char *name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(char *name,int type,int size,int size2);  // Creates a symbol table entry.

void printSymbolTable();  //prints all contents of the symbol table

void groupGInstall(struct tnode *node,int type);

void lTableInstall(char *funcname);

struct localTable *lTableLookup(char *funcname);

struct Lsymbol *LLookup(char *funcname,char *name);