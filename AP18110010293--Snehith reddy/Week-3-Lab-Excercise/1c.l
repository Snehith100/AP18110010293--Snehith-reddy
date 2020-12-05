%{ #include<studio.h>
int lc=0,ch=0;
%}

%%
\n {lc++;}
.ch++;

%%
int yywrap(void){}
int main()
{

 yylex();
  
 printf("\nNo of lines: %d",lc);
 printf("\nNo of characters: %d",ch);
 return 0;
}
