%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
#include "exprtree.h"
#include "symbolTable.h"
int number,type=0,line_no=0;
%}
%%
[0-9]+	{number = atoi(yytext); yylval = makeLeafNode(NUM_,number); return NUM;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"%" {return MOD;}
"=" {return ASSIGN;}
"<" {return LT;}
">" {return GT;}
"==" {return EQ;}
"<=" {return LE;}
">=" {return GE;}
"!=" {return NE;}
";" {return SEMICOLON;}
"," {return *yytext;}
"." {return *yytext;}
[ \t]	{}
[()]	{return *yytext;}
[{}]    {return *yytext;}
"["  {return *yytext;}
"]"  {return *yytext;}
"&"  {return *yytext;}
"begin" {return BEGINS;}
"read"  {return READ;}
"write" {return WRITE;}
"type"  {return TYPE;}
"endtype" {return ENDTYPE;}
"end"	{return END;}
"if"    {return IF;}
"and"   {return AND;}
"or"    {return OR;}
"decl"  {return DECL;}
"return" {return RETURN;}
"enddecl" {return ENDDECL;}
"int"   {type = 1; return INTEGER;}
"main"  {return MAIN;}
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
["][^\n]*["] {yylval = makeVariableNode(PRNT_,NULL,yytext); return STRING;}
[a-zA-Z_][a-zA-Z_0-9]*  {yylval = makeVariableNode(VAR_,yytext,NULL); return ID;}
[\n]    {line_no++;}
.	{yyerror("unknown character\n");}
%%
int yywrap(void) {
return 1;
}