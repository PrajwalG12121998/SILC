%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
%}

%union {char* str;}
%token STRING NL
%type <str> STRING expr
%left '+' '-'
%left '*' '/'

%%
start: expr NL {printf("%s\n",$1);exit(1);}
     ;
expr: expr '+' expr  { char *str = (char*)malloc(40*sizeof(char*));strcat(str,"+");strcat(str,$1);strcat(str,$3);strcpy($$,str);}
    | expr '-' expr  {char *str = (char*)malloc(40*sizeof(char*));strcat(str,"-");strcat(str,$1);strcat(str,$3);strcpy($$,str);}
    | expr '*' expr  {char *str = (char*)malloc(40*sizeof(char*));strcat(str,"*");strcat(str,$1);strcat(str,$3);strcpy($$,str);}
    | expr '/' expr  {char *str = (char*)malloc(40*sizeof(char*));strcat(str,"/");strcat(str,$1);strcat(str,$3);strcpy($$,str);}
    | '('expr')'  {$$=$2;}
    | STRING   {$$=$1;}
    ;
%%

int yyerror(){
    printf("ERROR\n");
    exit(1);
}

int main(){
    yyparse();
}
