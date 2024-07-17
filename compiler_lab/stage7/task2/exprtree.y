%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE tnode *
#include "exprtree.h"
#include "symbolTable.h"
#include "exprtree.c"	
#include "symbolTable.c"
int yylex(void);
extern FILE *yyin;
FILE *fptr;
int datatype=0,paramDatatype=0;
struct Classtable *Cptr = NULL;
%}
%token BEGINS END READ WRITE ID PLUS MINUS MUL DIV NUM ASSIGN SEMICOLON LT GT EQ NE LE GE IF THEN Else WHILE DO
%token ENDWHILE ENDIF BREAK CONTINUE UNTIL REPEAT DECL ENDDECL INTEGER STR STRING DQUOTES MOD RETURN MAIN AND OR
%token TYPE ENDTYPE  CLASS ENDCLASS SELF EXTENDS DELETE NEW
%left PLUS MINUS
%left MUL DIV AND OR
%left LT GT EQ LE GE NE MOD 
%%

Program : TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock  {/* $$=makeConnectedNode(CONN_,$3,$4);
                                            fptr = fopen("target_file.xsm","w+");
                                            fprintf(fptr, "%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,0,0);
                                            //fprintf(fptr, "BRKP\n");
                                            //print_typeTable();
                                            printf("\n");
                                            //printSymbolTable();
                                            //infix_form($$);
                                            printf("\n");
                                            codeGen($$,fptr); 
                                            printf("Executed successfully\n");
                                            fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                            */
                                          } 
        | TypeDefBlock ClassDefBlock GDeclBlock MainBlock { fptr = fopen("target_file.xsm","w+");
                                              fprintf(fptr, "%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,0,0);
                                              $$ = makeConnectedNode(CONN_,$2,$4);
                                              //printf("almost Executed %d\n",$2->nodetype);
                                              //infix_form($2);
                                              //codeGen($$,fptr);
                                              codeGen($$,fptr);
                                              fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                              /*print_typeTable();
                                              printf("\n");
                                              printSymbolTable();*/
                                              //printf("\n");
                                              //printClassTable();
                                              //printf("\n");
                                              //printSymbolTable();
                                              printf("Executed successfully\n");}                    
        ;

ClassDefBlock : CLASS ClassDefList ENDCLASS  { $$ = $2; Cptr = NULL;}
              |
              ;

ClassDefList : ClassDefList ClassDef  {$$ = makeConnectedNode(CONN_,$1,$2);}
             | ClassDef                {$$ = $1;}
             ;

ClassDef      : Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}' { addField_and_Method_count(Cptr,classFieldcount,Methodcount);$$=$7; }
              ;

Cname         : ID              {Cptr = CInstall($1->varname,NULL); classFieldcount=0; Methodcount=0;TInstall($1->varname,1,NULL);}         
              | ID EXTENDS ID   {Cptr = CInstall($1->varname,$3->varname);classFieldcount=0; Methodcount=0;TInstall($1->varname,1,NULL);}
              ;

Fieldlists  : Fieldlists Fld    {classFieldcount++;}
            |
            ;

Fld         : ID ID SEMICOLON  {Class_FInstall(Cptr,$1->varname,$2->varname);} //Installing the field to the class
            | STR ID SEMICOLON {Class_FInstall(Cptr,"str",$2->varname);}
            | INTEGER ID SEMICOLON  {Class_FInstall(Cptr,"int",$2->varname);}
            ;

MethodDecl  : MethodDecl MDecl   {Methodcount++;}
            | MDecl              {Methodcount++;}
            ;

MDecl      : ID ID '(' ParamList ')' SEMICOLON  {Class_MInstall(Cptr,$2->varname,$1->varname,$4);} 
           | STR ID '(' ParamList ')' SEMICOLON {Class_MInstall(Cptr,$2->varname,"str",$4);LInstall($2->varname,"str","self",getArgOffset());}
           | INTEGER ID '(' ParamList ')' SEMICOLON {Class_MInstall(Cptr,$2->varname,"int",$4);LInstall($2->varname,"int","self",getArgOffset());}
           ; 

MethodDefns : MethodDefns FDef  {$$ = makeConnectedNode(CONN_,$1,$2);}
            | FDef                  {$$ = $1;}
            ;

TypeDefBlock  : TYPE TypeDefList ENDTYPE   
              |                                            
              ;

TypeDefList   : TypeDefList TypeDef
              | TypeDef
              ;

TypeDef       : TID '{' FieldDeclList '}'   { /*Tptr = TInstall(tname,size,$3);*/ }
              ;

TID : ID       {currUserDef = strdup($1->varname); TInstall($1->varname,1,NULL);}
    ;

FieldDeclList : FieldDeclList FieldDecl
              | FieldDecl
              ;

FieldDecl    : TypeName ID SEMICOLON  { addField(currUserDef,$2->varname,$1->varname);}
             ;

GDeclBlock : DECL GDeclList ENDDECL
           |
           ;

GDeclList  : GDeclList GDecl
           | GDecl
           ;

GDecl      : TypeName Gidlist SEMICOLON      
           ;

Gidlist    : Gidlist ',' Gid
           | Gid                     
           ;

Gid        :   ID                      { GInstall($1->varname,currType, 1, 1,NULL);}
           |   ID '(' newParamList ')'      { GInstall($1->varname,currType, 0,0, $3);  }
           |   ID '[' NUM ']'          { GInstall($1->varname,currType, $3->val,1, NULL);}
           ;

newParamList : newParamList ',' newParam  {$3->left = $1; $$ = $3;}
             | newParam                   {$1->left = NULL; $$=$1;}
             |                         {$$=NULL;}
             ;

newParam : Type ID {$2->type1 = paramDatatype;$2->type = TLookup(currType1);$$ = $2;}
         ;


FDefBlock  : FDefBlock FDef { $$=makeConnectedNode(CONN_,$1,$2);}
           | FDef           { $$ = $1;}
           ;

FDef : TypeF FID '(' ParamList ')' '{' LDeclBlock Body '}'  { $$=makeFuncDefNode(currType2,currFunc,$8,$4,Cptr);
                                                                                         
                                                              /*printf("This is Function\n");*/ }                                
     ;

TypeF :  INTEGER {$$ = makeTypeNode(inttype);currType2 = strdup("int");}
      |  STR     {$$ = makeTypeNode(stringtype);currType2 = strdup("str");}
      |  ID      {$$ = $1;currType2 = strdup($1->varname);}
      ;

FID : ID    {currFunc = strdup($1->varname); lTableInstall($1->varname,Cptr,currType2);
             localOffset = 1; argOffset = -3;}
    ;

ParamList : ParamList ',' Param      {LInstall(currFunc,currType1,$3->varname,getArgOffset()); $3->left = $1; $$=$3;$3->type = TLookup(currType1);}
          | Param                    {LInstall(currFunc,currType1,$1->varname,getArgOffset()); $$ = $1; $1->left=NULL;$1->type = TLookup(currType1);}
          |                          {$$=NULL;}
          ;

Param : Type ID  {$2->type = paramDatatype;$$ = $2;}     
      ;

Type : INTEGER  {currType1 = strdup("int");}
     | STR      {currType1 = strdup("str");}
     | ID       {currType1 = strdup($1->varname);}
     ;

LDeclBlock : DECL LDecList ENDDECL {LInstall(currFunc,currType1,"self",getArgOffset());}
           | DECL ENDDECL {LInstall(currFunc,currType1,"self",getArgOffset());}
           ;
LDecList : LDecList LDecl 
         | LDecl
         ;
LDecl : TypeName IdList SEMICOLON {}
      ;
IdList : IdList ',' ID  {LInstall(currFunc,currType,$3->varname,getlocalOffset());}
       | ID             {LInstall(currFunc,currType,$1->varname,getlocalOffset());}
       ;

TypeName     : INTEGER {$$ = makeTypeNode(inttype);currType = strdup("int");}
             | STR     {$$ = makeTypeNode(stringtype);currType = strdup("str");}
             | ID      {$$ = $1;currType = strdup($1->varname);}
             ;

MainBlock : Main '(' ')' '{' LDeclBlock Body '}' { $$ = makeFuncDefNode("int","main",$6,NULL,NULL);printf("Functionnode done\n");}
          ;

Main : INTEGER MAIN   {currFunc = strdup("main");lTableInstall("main",NULL,"int");GInstall("main","int",0,0,NULL);
                       localOffset = 1; argOffset = -3;}
     ;
Body      : BEGINS Slist Retstmt END     {$$ = makeFuncBodyNode(BODY_,$2,$3);printf("Bodynode done\n"); }
          ;

/*Program : BEGINS Declarations Slist END SEMICOLON {printf("Executed successfully\n"); fptr = fopen("target_file.xsm","w+");
                                      printSymbolTable();
                                      fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
                                      fprintf(fptr, "BRKP\n");
                                      fprintf(fptr, "MOV SP, 4400\n");
                                      codeGen($3,fptr);
                                      fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                      //evaluate($2);
                                      //infix_form($2);
                                      exit(1);}
   | BEGINS END SEMICOLON            {printf("Executed successfully\n"); exit(1);} 
   ; 
Declarations : DECL DeclList ENDDECL | DECL ENDDECL
             ;
DeclList : DeclList Decl | Decl
         ;
Decl : Type VarList SEMICOLON {}
     ;
Type : INTEGER {datatype=inttype;}
     | STR  {datatype = stringtype;}
     ;
VarList : VarList ',' ID  {Install($3->varname,datatype,1,1);} 
        | VarList ',' ID'['NUM']' {Install($3->varname,datatype,$5->val,1);}
        | VarList ',' ID'['NUM']''['NUM']' {Install($3->varname,datatype,$5->val,$8->val);}
        | ID '['NUM ']' {Install($1->varname,datatype,$3->val,1);}
        | ID'['NUM']''['NUM']' {Install($1->varname,datatype,$3->val,$6->val);}
        | ID  {Install($1->varname,datatype,1,1);}
        | VarList ',' MUL ID {Install($4->varname,datatype,1,1);}
        ;
        */


Slist : Slist Stmt {$$ = makeConnectedNode(CONN_,$1,$2);}
      | Stmt         {$$=$1;}
      ; 
                                                                                                                                          
Stmt : InputStmt   {$$ = $1;}
     | OutputStmt  {$$ = $1;}
     | AsgStmt     {$$ = $1;}
     | Ifstmt      {$$ = $1;}
     | Whilestmt   {$$ = $1;}
     | Repeatstmt  {$$ = $1;}
     | Dowhilestmt {$$ = $1;}
     | newAsgStmt  {$$ = $1;}
     | DELETE '(' FIELD ')' SEMICOLON
     | BREAK SEMICOLON {$$ = makeConnectedNode(break_,NULL,NULL);}
     | CONTINUE SEMICOLON {$$ = makeConnectedNode(continue_,NULL,NULL);}
     | Retstmt {$$=$1;}
     ; 

FIELD : SELF '.' ID  { $1 = makeVariableNode(VAR_,"self",NULL); $1->cond = $3; $3->cond=NULL;  $$ = $1; 
                       if(Cptr==NULL){ 
                         printf("Self cannot be used outside class\n"); exit(1);
                       }else{
                         if(Class_FLookup(Cptr,$3->varname)==NULL){
                          printf("%s Field not declared in %s class\n",$3->varname,Cptr->name);
                          exit(1);
                         }  
                      }
                     }
      | SELF '.' FIELD {  $1 = makeVariableNode(VAR_,"self",NULL); $1->cond = $3; $$ = $1; 
                       if(Cptr==NULL){ 
                         printf("Self cannot be used outside class\n"); exit(1);
                       }
                       }
      | ID'.' FIELD {printf("Hi in field 3\n");$1->cond = $3; $$ = $1;}
      | ID '.' ID    {$1->cond = $3; $3->cond=NULL; $$=$1;printf("Hi in field 4\n");}
      ;

FieldFunction : SELF '.' ID '(' ArgList ')' {$$=makeMethodCallNode(makeVariableNode(VAR_,"self",NULL),$3->varname,$5);}
              | SELF '.' FieldFunction { $$ = $3;}
              | ID '.' ID '(' ArgList ')'  {$$=makeMethodCallNode($1,$3->varname,$5);printf("fcall %s\n",$3->varname);}
              | ID '.' FIELD '(' ArgList ')'  {$1->cond = $3; $$=$1;}

Retstmt : RETURN expr SEMICOLON {printf("I m in ret node %s \n",$2->type->name);$$ = makeRetNode($2);printf("Retnode done\n");}
        ;
Repeatstmt : REPEAT Slist UNTIL '(' expr ')' SEMICOLON {$$ = makeWhileNode(repeatUntil_,$5,$2);}
           ;
Dowhilestmt : DO Slist WHILE '(' expr ')' SEMICOLON {$$ = makeWhileNode(doWhile_,$5,$2);}
            ;
Ifstmt : IF '('expr')' THEN Slist Else Slist ENDIF SEMICOLON {$$ = makeConditionalNode(If_t_Else,$3,$6,$8);}
       | IF '('expr')' THEN Slist ENDIF SEMICOLON {$$ = makeConditionalNode(If_then,$3,$6,NULL);}
       ; 
Whilestmt : WHILE '('expr')' DO Slist ENDWHILE SEMICOLON {$$ = makeWhileNode(while_,$3,$6);}
          ;
InputStmt : READ '('loc')' SEMICOLON  {$$ = makeWrite_ReadNode(READ_,$3);}
          ; 
OutputStmt : WRITE'('expr')' SEMICOLON {$$ = makeWrite_ReadNode(WRITE_,$3);}
           ;

AsgStmt : loc ASSIGN expr SEMICOLON {$$ = makeOperatorNode(ASSIGN_,"void",$1,$3);}
        ;

newAsgStmt : loc ASSIGN NEW '(' ID ')' SEMICOLON    { $3=makeFuncCallNode("new",$5);
                                                      $$ = makeOperatorNode(ASSIGN_,"void",$1,$3); }
           ;
expr : expr AND expr {$$ = makeOperatorNode(AND_,"bool",$1,$3);}
| expr OR expr  {$$ = makeOperatorNode(OR_,"bool",$1,$3);} 
| expr PLUS expr {$$ = makeOperatorNode(PLUS_,"int",$1,$3);}
| expr MINUS expr {$$ = makeOperatorNode(MINUS_,"int",$1,$3);}
| expr MUL expr	{$$ = makeOperatorNode(MUL_,"int",$1,$3);}
| expr DIV expr	{$$ = makeOperatorNode(DIV_,"int",$1,$3);}
| expr LT expr  {$$ = makeOperatorNode(LT_,"bool",$1,$3);}   
| expr GT expr  {$$ = makeOperatorNode(GT_,"bool",$1,$3);}
| expr EQ expr  {$$ = makeOperatorNode(EQ_,"bool",$1,$3);}
| expr GE expr  {$$ = makeOperatorNode(GE_,"bool",$1,$3);}
| expr LE expr  {$$ = makeOperatorNode(LE_,"bool",$1,$3);}
| expr NE expr  {$$ = makeOperatorNode(NE_,"bool",$1,$3);}
| expr MOD expr {$$ = makeOperatorNode(MOD_,"int",$1,$3);}
| ID '('ArgList')'   {printf("I am in FCALL %s\n",$1->varname);$$=makeFuncCallNode($1->varname,$3);}
| '(' expr ')'	{$$ = $2;}
| '&' ID {$2->nodetype = POI_ADD_; $$ = $2;}
| NUM	{$$ = $1;}
| loc {$$=$1;}
| STRING {$$ = $1;}
| FieldFunction 
;

ArgList : ArgList ',' expr  { $3->middle = $1;$$=$3;}
        | expr    {$1->middle=NULL;$$ = $1;}
        |         {$$=NULL;}
        ;

loc : ID  {$1->left = NULL;$$ = $1;/*printf("%s\n",$1->varname);*/}
    | MUL ID {$2->nodetype = POI_VAL_; $$ = $2;}
    | ID '[' expr ']' {$1->left = $3; $$->right=NULL; $$=$1;}
    | ID '['expr']''['expr']' {$1->left = $3; $1->right = $6; $$=$1;} 
    | FIELD {$$ = makeUserDefinedNode($1); printf("In field 2\n");}
    ;
%%

yyerror(char const* s){
	printf("yyerror %s\n",s);
}

int main(int argc,char *argv[]){ 
  yyin = fopen(argv[1],"r");
  TypeTableCreate();
	yyparse();
	return 0;
}
