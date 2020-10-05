/*Recognizing a string with three consecutive 0's*/

%{
#include<stdio.h>
%}

%%
[0-1]*000[0-1]* {printf("String Accepted");}
[0-9]* {printf("String Rejected");}

%%

int yywrap(void){}
int main()
{
yylex();
  return 0;
}