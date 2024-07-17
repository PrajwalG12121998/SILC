%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>

%}

single_line "//"[^\n]*[\n]
multi_line ^("/*")[^\r]*("*/")$

%%

{single_line} {printf("Found :%s",yytext);}
{multi_line} {printf("Found_mul : %s",yytext);}    
%%

int main(){
	yyin = fopen("comment","r");
	yylex();
	return 1;
}
