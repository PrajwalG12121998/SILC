%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror();
    #define YYSTYPE char 
%}

%token CHARACTER NEWLINE

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
	| CHARACTER	   {printf("%c ",$1);}
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

