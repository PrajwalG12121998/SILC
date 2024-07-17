%{
#include "y.tab.h"
int yylval;
%}
ID [a-zA-Z]
%%
{ID} {yylval=*yytext;return ID;}
[\n \t] {}
. {return *yytext;}
%%

int yywrap(){
  return 1;
}

