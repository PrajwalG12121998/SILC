%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}
	
even [0-9]*(0|2|4|6|8)
odd [0-9]*(1|3|5|7|9)
 
%%
 
{even} {printf("Even : %d\n",atoi(yytext));}
{odd} {printf("Odd : %d\n",atoi(yytext));}
 
%%
 
int main()
{
	int num = yylex();
        printf("%d\n",num);
	return 1;
}
