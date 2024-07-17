%{
  char Estring[20];
  char Tstring[20];
  char Fstring[1];
%}
%token ID
%%
S:E {printf("%s",Estring);}
E : E '+' T {strcat(Estring,Tstring);strcat(Estring,"+");}
|T {strcpy(Estring,Tstring);}
;
T: T '*' F {strcat(Tstring,Fstring);strcat(Tstring,"*");}
|F {strcpy(Tstring,Fstring);};
;
F:ID {Fstring[0]=$1;}
%%
main() {
  yyparse();
}
yyerror() {
  printf("Error");
}


