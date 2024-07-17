%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    FILE *fptr;
%}

word  [A][A-Za-z]*

%%

{word}  {if(yyleng==3){fprintf(fptr,"%s ",yytext);}}
\n
.
%%

int main(){
    yyin = fopen("financial_aid","r");
    fptr = fopen("output","a");
    yylex();
    return 1;
}
