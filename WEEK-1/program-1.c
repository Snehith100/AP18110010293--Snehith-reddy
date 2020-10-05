#include<stdio.h>
void main(){
	int state=0,i=0;
	char current,input[20];
	printf("Enter a string \t : ");
	scanf("%s",input);
	while((current=input[i++])!='\0'){
		switch(state)
		{
			case 0: if(current=='0')
						state=1;
					else if(current=='1')
						state=3;
					else
					{
						printf("Invalid token");
						exit(0);
					}
					break;
			case 1: if(current=='0')
						state=0;
					else if(current=='1')
						state=2;
					else
					{
						printf("Invalid token");
						exit(0);
					}
					break;
			case 2: if(current=='0')
						state=3;
					else if(current=='1')
						state=1;
					else
					{
						printf("Invalid token");
						exit(0);
					}
					break;
			case 3: if(current=='0')
						state=2;
					else if(current=='1')
						state=0;
					else
					{
						printf("Invalid token");
						exit(0);
					}
					break;
		}
	}
	if(state==0)
		printf("\n\nString accepted\n\n");
	else
		printf("\n\nString not accepted\n\n");
}
