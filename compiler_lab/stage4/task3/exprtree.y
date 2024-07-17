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
int datatype=0;
%}
%token BEGINS END READ WRITE ID PLUS MINUS MUL DIV NUM ASSIGN SEMICOLON LT GT EQ NE LE GE IF THEN Else WHILE DO
%token ENDWHILE ENDIF BREAK CONTINUE UNTIL REPEAT DECL ENDDECL INTEGER STR 
%left PLUS MINUS
%left MUL DIV
%left LT GT EQ LE GE NE
%%
Program : BEGINS Declarations Slist END SEMICOLON {printf("Executed successfully\n"); fptr = fopen("target_file.xsm","w+");
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
        ;
Slist : Slist Stmt {$$ = makeConnectedNode(CONN_,$1,$2);}
      | Stmt       {$$ = $1;}
      ; 
                                                                                                                                          
Stmt : InputStmt   {$$ = $1;}
     | OutputStmt  {$$ = $1;}
     | AsgStmt     {$$ = $1;}
     | Ifstmt      {$$ = $1;}
     | Whilestmt   {$$ = $1;}
     | Repeatstmt  {$$ = $1;}
     | Dowhilestmt {$$ = $1;}
     | BREAK SEMICOLON {$$ = makeConnectedNode(break_,NULL,NULL);}
     | CONTINUE SEMICOLON {$$ = makeConnectedNode(continue_,NULL,NULL);}
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
InputStmt : READ '('expr')' SEMICOLON  {$$ = makeWrite_ReadNode(READ_,$3);}
          ; 
OutputStmt : WRITE'('expr')' SEMICOLON {$$ = makeWrite_ReadNode(WRITE_,$3);}
           ;

AsgStmt : loc ASSIGN expr SEMICOLON {$$ = makeOperatorNode(ASSIGN_,inttype,$1,$3);}
        ;
expr : expr PLUS expr {$$ = makeOperatorNode(PLUS_,inttype,$1,$3);}
| expr MINUS expr {$$ = makeOperatorNode(MINUS_,inttype,$1,$3);}
| expr MUL expr	{$$ = makeOperatorNode(MUL_,inttype,$1,$3);}
| expr DIV expr	{$$ = makeOperatorNode(DIV_,inttype,$1,$3);}
| expr LT expr  {$$ = makeOperatorNode(LT_,booltype,$1,$3);}   
| expr GT expr  {$$ = makeOperatorNode(GT_,booltype,$1,$3);}
| expr EQ expr  {$$ = makeOperatorNode(EQ_,booltype,$1,$3);}
| expr GE expr  {$$ = makeOperatorNode(GE_,booltype,$1,$3);}
| expr LE expr  {$$ = makeOperatorNode(LE_,booltype,$1,$3);}
| expr NE expr  {$$ = makeOperatorNode(NE_,booltype,$1,$3);}
| '(' expr ')'	{$$ = $2;}
| NUM	{$$ = $1;}
| loc {$$=$1;}
;

loc : ID  {$$ = $1;}
    | ID '[' expr ']' {$1->left = $3; $$=$1;}
    | ID '['expr']''['expr']' {$1->left = $3; $1->right = $6; $$=$1;}
    ;
%%

yyerror(char const* s){
	printf("yyerror %s\n",s);
}

int main(){ 
  yyin = fopen("test","r");
	yyparse();
	return 0;
}
