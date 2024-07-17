#define INTEGER_ 1
#define STRING_ 2

struct Gsymbol{
   char* name; //name of variable
   int size;  //size of the type of variable
   int type;  //type of the variable
   int binding;  //stores the static memory address of the variable
   int no_col;  //to store number of columns for 2d array 	
   struct Gsymbol *next;  
};

struct Gsymbol *Lookup(char *name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(char *name,int type,int size,int size2);  // Creates a symbol table entry.

void printSymbolTable();  //prints all contents of the symbol table

void groupGInstall(struct tnode *node,int type);