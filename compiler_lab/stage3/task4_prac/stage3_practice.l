%{
   #include <stdio.h>
   #include <stdlib.h>
   int count_line = 2040,label_num,i;
   FILE* fptr;
   struct Node{
     int label;
     int address;
     struct Node *next;
   };
   struct Node *head = NULL;
   int var=1,num1,j,num;
%}

get_anything [^\n]
new_line [\n]
label "L"[0-9]+[:][\n]
jmp_label "L"[0-9]+

%%
{get_anything} {fprintf(fptr,"%s",yytext);}
{new_line}     {fprintf(fptr,"%s",yytext);if(var==1){count_line = count_line + 2;}}
{label}        {if(var==1){
                                                            j=1;num1=0;
                                                             while(yytext[j]!=':'){
                                                             num = yytext[j]-'0';
                                                             num1 = num1*10 + num; 
                                                             j = j + 1;
                                                           }
                                                             printf("%c",yytext[2]);
                                                             insert(&head,count_line,num1);
                }else{printf("Found\n");} }
{jmp_label}    {if(var==2){ j=1;num1=0;
                            while(yytext[j]!='\0'){
                              num = yytext[j] - '0';
                              num1 = num1*10 + num;
                              j = j + 1;
                            }
                            i=search(&head,num1);if(i!=-1){fprintf(fptr,"%d",i);}else{printf("Token Not Found\n");}
               }else{fprintf(fptr,"%s",yytext);}}
%%

int convert_to_int(char *s[]){
  int j=1,num1=0,num;
  while(s[j]!=':'||s[j]!='\0'){
    num = s[j]-'0';
    num1 = num1*10 + num;
    j++;
  }
  return num1;
}

int search(struct Node **head_ref,int label){
    /*char c = ':';
    size_t len = strlen(label);
    char *str2 = malloc(len + 1 + 1);
    strcpy(str2,label);
    str2[len] = c;
    str2[len+1] = '\0';*/
    //printf("%d %d\n",str2,label);
    struct Node *current = *head_ref;
    while(current!=NULL){
      if(current->label==label){
        printf("Found\n");
        return current->address;
      }
      current = current->next;
    }
    return -1;
}

void insert(struct Node** head_ref,int address,int label){
     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
     struct Node *last = *head_ref;
     temp->label = label;
     temp->address = address;
     temp->next = NULL;
     if(*head_ref==NULL){
        *head_ref = temp;
        printf("%d %d\n",(*head_ref)->label,(*head_ref)->address);
        return ;
     }
     while(last->next!=NULL){
      last = last->next;
     }
     last->next = temp;
     //printf("%d %d\n",temp->label,temp->address);
     /*struct Node * current = *head_ref;
     while(current!=NULL){
      printf("%d %d\n",current->label,current->address);
      current = current->next;
    }*/
     return ;
}

int yywrap(){
    return 1;
}


int main(){
    yyin = fopen("target_file.xsm","r");
    fptr = fopen("target_file_1.xsm","w");
    yylex();
    fclose(fptr);
    var = 2;
    yyin = fopen("target_file_1.xsm","r");
    fptr = fopen("target_file_2.xsm","w");
    yylex();
    return 1;
}
