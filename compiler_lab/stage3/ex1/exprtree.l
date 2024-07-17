%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
#include "exprtree.h"
int number;
%}
%%
[0-9]+	{number = atoi(yytext); yylval = makeLeafNode(NUM_,number); return NUM;}
[a-z]   {yylval = makeVariableNode(VAR_,yytext); return ID;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"=" {return ASSIGN;}
"<" {return LT;}
">" {return GT;}
"==" {return EQ;}
"<=" {return LE;}
">=" {return GE;}
"!=" {return NE;}
";" {return SEMICOLON;}
[ \t]	{}
[()]	{return *yytext;}
"begin" {return BEGINS;}
"read"  {return READ;}
"write" {return WRITE;}
"end"	{return END;}
"if"    {return IF;}
"do"    {return DO;}
"else"  {return Else;}
"while" {return WHILE;}
"then"  {return THEN;}
"endif" {return ENDIF;}
"endwhile" {return ENDWHILE;}
[\n]    {}
.	{yyerror("unknown character\n");exit(1);}
%%
int yywrap(void) {
return 1;
}