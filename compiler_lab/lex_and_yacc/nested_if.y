%{
   #include<stdio.h>
   #include<stdlib.h>
   int count=0;
%}

%token IF relop s id digit nl

%%
stmt: if_stmt nl {printf("Number of nested if statements is %d\n",count); exit(1);}
    ;
if_stmt: IF'('cond')''{'if_stmt'}' {count++;}
       | s
       ;

cond: x relop x
    ;
x: id | digit
 ;
%%

int yyerror(){
    printf("wrong syntax for if statements\n");
    return 0;
}

int main(){
    yyparse();
    return 1;
}
