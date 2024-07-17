%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE tnode *
#include "exprtree.h"
#include "exprtree.c"
int yylex(void);
FILE * fptr;
%}
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV
%%
program : expr END	{
$$ = $2;
printf("Answer :");fptr = fopen("target_file.xsm","w+");prefix_form($1);
fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
fprintf(fptr, "MOV SP,4096\n");
codeGen($1,fptr);
fprintf(fptr,"MOV [4096],R0\nMOV R2,5\nPUSH R2\nMOV R2,-2\nPUSH R2\nPUSH R0\nPUSH R2\nPUSH R2\nINT 7\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
fprintf(fptr,"MOV R2,10\nPUSH R2\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nINT 10\n");
exit(1);
}
;
expr : expr PLUS expr	{$$ = makeOperatorNode('+',$1,$3);}
| expr MINUS expr {$$ = makeOperatorNode('-',$1,$3);}
| expr MUL expr	{$$ = makeOperatorNode('*',$1,$3);}
| expr DIV expr	{$$ = makeOperatorNode('/',$1,$3);}
| '(' expr ')'	{$$ = $2;}
| NUM	{$$ = $1;}
;
%%
yyerror(char const *s)
{
printf("yyerror %s",s);
}
int main(void) {
yyparse();
return 0;
}
