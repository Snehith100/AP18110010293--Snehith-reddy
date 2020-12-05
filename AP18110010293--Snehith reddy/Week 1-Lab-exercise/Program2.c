#include<stdio.h>
void main()
{
  int state=0,i=0;
  char curr,input[20];
  printf("Enter str:\n");
  scanf("%s",input);
  while((curr=input[i++])!='\0')
  {
    switch(state)
    {
      case 0:
      if(curr=='a')
      state=1;
      else if(curr=='b')
      state=3;
      else
      {
      printf('Invalid\n');
      exit(0);
      }
      break;
      case 1:
      if(curr=='a')
      state=2;
      else if(curr=='b')
      state=3;
      else
      {
       printf("Invalid\n");
       exit(0);
      }
      break;
      case 2:
      if(curr=='a')
      state=2;
      else if(curr=='b')
      state=3;
      else
      {
      printf("Invalid\n");
      exit(0);
      }
      break;
      case 3:
      if(curr=='a')
      state=1;
      else if(curr=='b')
      state=4;
      else
      {
      printf("Invalid\n");
      exit(0);
      }
      break;
      case 4:
      if(curr=='a')
      state=1;
      else if(curr=='b')
      state=4;
      else
      {
      printf("Invalid\n");
      exit(0);
      }
      break;
    }
  }
  if(state==2||state==4)
  {
   printf("\nString accepted\n");
  }
  else
  {
   printf("\nString not accepted\n");
  }
}
