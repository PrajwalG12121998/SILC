#define INTEGER_ 1
#define STRING_ 2

struct TypeTable{
    char *name;                //type name
    int size;                  //size of the type
    struct Fieldlist *fields;  //pointer to the head of fields list
    struct TypeTable *next;    // pointer to the next type table entry
};

struct Fieldlist{
    char *name;              //name of the field
    int fieldIndex;          //the position of the field in the field list
    struct TypeTable *type;  //pointer to type table entry of the field's type
    struct Classtable *Ctype; //pointer to the class containing the field
    struct Fieldlist *next;  //pointer to the next field
};

struct localTable{
    char *funcname;  //name of the function
    struct Typetable *type; //retType of the function
    struct Classtable *Ctype; //pointer to the class
    struct Lsymbol *lentry; //all the arguments and the defined variables list
    struct localTable *next; //pointer to the next function
};

struct Lsymbol{
   char *name;  //name of the variable
   struct TypeTable *type;  //type of the variable:(Integer / String) 
   int binding; //local binding of the variable
   struct Lsymbol *next; //points to the next Local Symbol Table entry
};

struct Gsymbol{
   char* name; //name of variable
   int size;  //size of the type of variable
   int binding;  //stores the static memory address of the variable
   int no_col;  //to store number of columns for 2d array
   struct TypeTable *type;  //pointer to the Typetable entry of variable type/return type of the function
   struct Classtable *Ctype; //pointer to the class
   struct tnode *paramlist; //pointer to the head of the formal parameter list
                                  //in case of functions
   int flabel; //a label for identifying the starting address of a function's code  	
   struct Gsymbol *next;  //points to the next Global Symbol Table entry
};

struct Classtable {
  char *name;                           //name of the class
  struct Fieldlist *Memberfield;        //pointer to Fieldlist 
  struct Memberfunclist *Vfuncptr;      //pointer to Memberfunclist
  struct Classtable *Parentptr;         //pointer to the parent's class table
  int Class_index;                      //position of the class in the virtual function table
  int classFieldcount;                  //count of fields
  int Methodcount;                      //count of methods
  struct Classtable *next;              //pointer to next class table entry
};

struct Memberfunclist {
  char *name;                      //name of the member function in the class
  struct Typetable *type;          //pointer to typetable
  struct tnode *paramlist;   //pointer to the head of the formal parameter list
  int Funcposition;                //position of the function in the class table
  int flabel;                      //A label for identifying the starting address of the function's code in the memory
  struct Memberfunclist *next;     //pointer to next Memberfunclist entry
};

struct Gsymbol *GLookup(char *name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(char *name,int type,int size,int size2);  // Creates a symbol table entry.

void printSymbolTable();  //prints all contents of the symbol table

void groupGInstall(struct tnode *node,int type);

void lTableInstall(char *funcname,struct Classtable *Cptr,char *type);

struct localTable *lTableLookup(char *funcname);

struct Lsymbol *LLookup(char *funcname,char *name);

struct TypeTable* TLookup(char *name);

void TypeTableCreate();

struct Fieldlist *FLookup(char *type,char *name);

struct Memberfunclist *Class_MLookup(struct Classtable *Ctype,char *name);

struct Fieldlist *Class_FLookup(struct Classtable* Ctype,char* name);

struct Classtable *CLookup(char *name);