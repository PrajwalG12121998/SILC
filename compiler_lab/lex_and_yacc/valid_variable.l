%{
    #include "y.tab.h";
%}

%%
[a-zA-Z_][a-zA-Z0-9]* {return var;}

[0-9]+ return digit;

. return yytext[0];

\n return nl;

%%

int yywrap(){

   return 1;
}


