  
Implementation of Language recognizer for set of all strings ending with two symbols of same type.

#include <stdio.h>
void main(){
 int state=0,i=0;
 char current,input[20];
 printf("Enter input string \t :");
 scanf("%s",input);
 while((current=input[i++])!='\0'){
 switch(state)
 {
 case 0: if(current=='a')
 state=1;
 else if(current=='b')
 state=3;
 else
 {
 printf("Invalid token");
 exit(0);
 }
 break;
 case 1: if(current=='a')
 state=2;
 else if(current=='b')
 state=3;
 else
 {
 printf("Invalid token");
 exit(0);
 }
 break;
 case 2: if(current=='a')
 state=2;
 else if(current=='b')
 state=3;
 else
 {
 printf("Invalid token");
 exit(0);
 }
 break;
 case 3: if(current=='a')
 state=1;
 else if(current=='b')
 state=4;
 else
 {
 printf("Invalid token");
 exit(0);
 }
 break;
 case 4: if(current=='a')
 state=1;
 else if(current=='b')
 state=4;
 else
 {
 printf("Invalid token");
 exit(0);
 }
 break;
 }
 }
 if(state==2)
 printf("\n\nString accepted\n\n");
 else if(state==4)
 printf("\n\nString accepted\n\n");
 else
 printf("\n\nString not accepted\n\n");
}