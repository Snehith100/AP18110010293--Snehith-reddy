
%{
#include<stdio.h>
%}

%%
[aeiouAEIOU] {printf("Vowel\n");}
[A-Za-z] {printf("Consonants \n");}
%%
int yywrap(void){}
int main()
{
printf("Enter a string::");
yylex();
}

