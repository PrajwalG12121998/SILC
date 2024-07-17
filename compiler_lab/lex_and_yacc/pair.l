%{
   #include "y.tab.h"
   #include <stdio.h>
   #include <stdlib.h>
%}
number [0-9]+

%%
{number} {  yylval = atoi(yytext);
            return DIGIT;}
\n       return NL;
.        return *yytext;
%%

int yywrap(){
    return 1;
}
