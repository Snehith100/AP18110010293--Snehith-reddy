/* LEX analyser 
• A minimum of 10 keywords of your choice
• Identifiers with the regular expression : letter(letter | digit)*
• Signed as well as unsigned integers
• Signed as well as unsigned Floats in fractional as well as exponential notation.
• Relational operators: <, >, <=, >=, ==, !=
• Assignment Operator:=
• Ignores everything between comments: single line as well as multiline comments as in C
• Storing identifiers in symbol table
• Using files for input and output.
*/
%{
#undef yywrap
#define yywrap() 1
#include<stdio.h>
 
%}

DIGIT [0-9]
LETTER [A-Za-z]
TYPE int|struct|typedef|float|void|for|do|while|if|else|return|void|printf|scanf|main|include|stdio
PARAN "{"|"}"|"("|")"
RELOP "+"|"-"|"*"|"%"|"&"|"/"|"<"|">"
EXPR ","|";"|"\""|"."
%option yylineno
%option noyywrap

%%
{TYPE} {fprintf(yyout, " Keyword : %s\n", yytext);}
{RELOP} {fprintf(yyout, " Relational Operator : %s\n" , yytext);}
{PARAN} {fprintf(yyout, "Paranthesis : %s\n", yytext);}
{EXPR} {fprintf(yyout, " Supporters : %s\n", yytext);}
[0-9]+|[a-zA-Z][a-zA-Z0-9_]* {fprintf(yyout, "Identifier : %s\n" ,yytext);}
%%
void main(int argc, char **argv)
{
extern FILE *yyin, *yyout; 
  
    yyin = fopen("1.txt", "r"); 
  
    yyout = fopen("Output.txt", "w"); 
    
  yylex();
  printf("Successs! ! !\n");
}

