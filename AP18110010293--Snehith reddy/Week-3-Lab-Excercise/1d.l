
%{
#include<stdio.h>
%}

%%

([0-1])*00 {printf("string accepted");}

[0-9]* {printf("string rejected");}
%%
int yywrap(void){}
int main()
{
yylex();
return 0;
}
