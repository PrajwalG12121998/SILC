%{
    #include <stdio.h> 
    #include "y.tab.h"
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*	{
          yylval = yytext;
          return STRING;
        }
"+"	  return *yytext;
"*"	  return *yytext;
"-"       return *yytext;
"/"       return *yytext;
[()]	  return *yytext;
[\n]      return NEWLINE;
.         {}
%%

yywrap()
{
	return 1;
}
