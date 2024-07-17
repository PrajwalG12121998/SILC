%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE tnode *
#include "exprtree.h"
#include "exprtree.c"	
int yylex(void);
extern FILE *yyin;
FILE *fptr;
%}
%token BEGINS END READ WRITE ID PLUS MINUS MUL DIV NUM ASSIGN SEMICOLON LT GT EQ NE LE GE IF THEN Else WHILE DO
%token ENDWHILE ENDIF
%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT EQ LE GE NE
%%
Program : BEGINS Slist END SEMICOLON {printf("Executed successfully\n"); //fptr = fopen("target_file.xsm","w+");
                                      //fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
                                      //fprintf(fptr, "MOV SP, 4121\n");
                                      //codeGen($2,fptr);
                                      //fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
                                      evaluate($2);
                                      exit(1);}
   | BEGINS END SEMICOLON            {printf("Executed successfully\n"); exit(1);} 
   ; 

Slist : Slist Stmt {$$ = makeConnectedNode(CONN_,$1,$2);}
      | Stmt       {$$ = $1;}
      ; 
                                                                                                                                          
Stmt : InputStmt   {$$ = $1;}
     | OutputStmt  {$$ = $1;}
     | AsgStmt     {$$ = $1;}
     | Ifstmt      {$$ = $1;}
     | Whilestmt   {$$ = $1;}
     ; 

Ifstmt : IF '('expr')' THEN Slist Else Slist ENDIF SEMICOLON {$$ = makeConditionalNode(If_t_Else,$3,$6,$8);}
| IF '('expr')' THEN Slist ENDIF SEMICOLON {$$ = makeConditionalNode(If_t_Else,$3,$6,NULL);}
       ; 
Whilestmt : WHILE '('expr')' DO Slist ENDWHILE SEMICOLON {$$ = makeWhileNode(while_,$3,$6);}
          ;
InputStmt : READ '('ID')' SEMICOLON  {$$ = makeWrite_ReadNode(READ_,$3);}
          ; 
OutputStmt : WRITE'('expr')' SEMICOLON {$$ = makeWrite_ReadNode(WRITE_,$3);}
           ;

AsgStmt : ID ASSIGN expr SEMICOLON {$$ = makeOperatorNode(ASSIGN_,booltype,$1,$3);}
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
| ID    {$$ = $1;}
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
