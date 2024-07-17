%{
    #include "y.tab.h"
    YYSTYPE yylval;
    char *str;
%}

%%

[a-zA-Z_][a-zA-Z0-9_]* { str = (char*)malloc(sizeof(char)); strcpy(str,yytext);
                         yylval.str = str;
                         return STRING;}
"+"	  return *yytext;
"*"	  return *yytext;
"-"       return *yytext;
"/"       return *yytext;
[()]	  return *yytext;
[\n]      return NL;
.         {}

%%  

int yywrap(){
    return 1;
}
