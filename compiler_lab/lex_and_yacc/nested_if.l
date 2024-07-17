%{
    #include "y.tab.h"
%}

%%
"if"  return IF;
[sS] return s;
"<"|">"|"=="|"<="|">=" return relop;
[a-zA-z_][a-zA-Z0-9_]* return id;
[0-9]+ return digit;
\n return nl;
. return yytext[0];
%%

int yywrap(){
    return 1;	
}
