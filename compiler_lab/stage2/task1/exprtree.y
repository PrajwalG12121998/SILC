%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE tnode *
#include "exprtree.h"
#include "exprtree.c"	
extern FILE* yyin;
int yylex(void);
FILE *fptr;
%}
%token BEGINS END READ WRITE ID PLUS MINUS MUL DIV NUM ASSIGN SEMICOLON
%left PLUS MINUS
%left MUL DIV
%%
Program : BEGINS Slist END {printf("Executed successfully\n"); infix_form($2); exit(1);}
   | BEGINS END            {printf("Executed successfully\n"); exit(1);} 
   ; 

Slist : Slist Stmt {$$ = makeConnectedNode(CONN_,$1,$2);}
      | Stmt       {$$ = $1;}
      ; 
                                                                                                                                       
Stmt : InputStmt   {$$ = $1;}
     | OutputStmt  {$$ = $1;}
     | AsgStmt     {$$ = $1;} 
     ; 
 
InputStmt : READ '('ID')' SEMICOLON {$$ = makeWrite_ReadNode(READ_,$3);}
          ;
OutputStmt : WRITE'('expr')' SEMICOLON {$$ = makeWrite_ReadNode(WRITE_,$3);}
           ;

AsgStmt : ID ASSIGN expr SEMICOLON {$$ = makeOperatorNode(ASSIGN_,$1,$3);}
        ;
expr : expr PLUS expr {$$ = makeOperatorNode(PLUS_,$1,$3);}
| expr MINUS expr {$$ = makeOperatorNode(MINUS_,$1,$3);}
| expr MUL expr	{$$ = makeOperatorNode(MUL_,$1,$3);}
| expr DIV expr	{$$ = makeOperatorNode(DIV_,$1,$3);}
| '(' expr ')'	{$$ = $2;}
| NUM	{$$ = $1;}
| ID    {$$ = $1;}
;

%%

yyerror(char const* s){
	printf("yyerror %s",s);
}

int main(){
  yyin = fopen("test","r");
	yyparse();
	return 0;
}
