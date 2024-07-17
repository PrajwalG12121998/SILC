%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror();
    #define YYSTYPE char* 
%}

%token STRING NEWLINE

%left '+' '-'
%left '*' '/'

%%

start : expr NEWLINE {printf("\nComplete\n");exit(1);}
	;

expr:  expr '+' expr	{printf("+ ");}
	| expr '*' expr	{printf("* ");}
        | expr '-' expr	{printf("- ");}
        | expr '/' expr	{printf("/ ");}
	| '(' expr ')'
	| STRING	   {printf("%s ",$1);}
	;

%%

int yyerror()
{
	printf("Error");
}

int main()
{
  yyparse();
  return 1;
}

