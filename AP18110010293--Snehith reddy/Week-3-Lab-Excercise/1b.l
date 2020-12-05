/*lex program to count the number of vowels and consanants*/
%{
int i=0;
int j=0;
%}

/*Rules Section*/
%% 
([a,e,i,o,u,A,E,I,O,U])  {i=i+1;}
([a-zA-Z])  {j=j+1;}
"\n" {printf("Vowels : %d ",i);  printf("Consonants : %d ",j);}
%%


int yywrap(void){}

int main()
{
  //function will starts the analysis
  yylex();
  
  return 0;
}


