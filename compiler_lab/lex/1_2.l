%option noyywrap
%{
   #include <stdio.h>
   #include <stdlib.h>
   int num_int=0,num_float=0;
%}

integer [0-9]+
float_num [0-9]+[.][0-9]+

%%
{integer} {num_int++;}
{float_num} {num_float++;}

%%

int main(){
    yyin = fopen("test","r");
    yylex();
    printf("%d %d",num_int,num_float);
    return 1;
}
