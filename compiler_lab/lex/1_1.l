%option noyywrap
%{
    #include<stdio.h>
    #include<stdlib.h>
    int num_word=0,num_char=0,num_newline=0,num_no=0;
%}

word [a-zA-Z]*
charac ['|"|(|)|.|,|?|/|-]
newline [\n]

%%

{word} {num_word++;num_char = num_char + yyleng;}
{charac} {num_char++;}
{newline} {num_newline++;}
.  
%%

int main(){
    yyin = fopen("financial_aid","r");
    yylex();
    printf("%d %d %d %d\n",num_word,num_char,num_newline);
    return 1;
}
