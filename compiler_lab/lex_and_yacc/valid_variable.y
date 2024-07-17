%{
    #include<stdio.h>
    #include<stdlib.h>
    int valid = 1;
%}

%token var digit nl

%%
start:var s  
      ;
s:var s
  | digit s
  | nl    {return 1;}
  ;
%%

int yyerror(){
    
    printf("It is not a valid variable\n");
    valid = 0;
    return 0;
}

int main(){
    yyparse();
    if(valid){
       printf("It is valid variable\n");
    }
    return 1;
}


