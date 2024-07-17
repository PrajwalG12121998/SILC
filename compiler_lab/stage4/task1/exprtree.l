%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
#include "exprtree.h"
#include "symbolTable.h"
int number,type=0;
%}
%%
[0-9]+	{number = atoi(yytext); yylval = makeLeafNode(NUM_,number); return NUM;}
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
"," {return *yytext;}
[ \t]	{}
[()]	{return *yytext;}
"begin" {return BEGINS;}
"read"  {return READ;}
"write" {return WRITE;}
"end"	{return END;}
"if"    {return IF;}
"decl"  {return DECL;}
"enddecl" {return ENDDECL;}
"int"   {type = 1; return INTEGER;}
"str"   {type = 2; return STR;}
"do"    {return DO;}
"else"  {return Else;}
"break" {return BREAK;}
"repeat" {return REPEAT;}
"until"  {return UNTIL;}
"continue" {return CONTINUE;}
"while" {return WHILE;}
"then"  {return THEN;}
"endif" {return ENDIF;}
"endwhile" {return ENDWHILE;}
[a-zA-Z_][a-zA-Z_0-9]*  {yylval = makeVariableNode(VAR_,yytext); return ID;}
[\n]    {}
.	{yyerror("unknown character\n");exit(1);}
%%
int yywrap(void) {
return 1;
}