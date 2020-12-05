#include<stdio.h>
#include<ctype.h>
#include<string.h>
char
keyword[24][30]={"int","while","break","for","do","if","float","char","switch","double","sho
rt","long","unsigned","sizeof",
"else","register","extern","static","auto","case","break","volatile","enum","typedef"};
int check_keyword(char s[]) {
for(int i=0;i<24;++i)
if(strcmp(s,keyword[i])==0)
return 1;
return 0;
}
void store_symb_tab(char id[], char symb_tab[][30]) {
int i;
for(i=0; strcmp(symb_tab[i],"")&&i<20;++i)
if(!strcmp(symb_tab[i],id))
return;
if(i==20)
{
 printf("Overflow!");
 return;
}
strcpy(symb_tab[i],id);
}
int main()
{
FILE *fp1,*fp2;
char c,id[30], num[10];
int state=0,i=0,j=0;
fp1=fopen("in.txt","r");
fp2=fopen("out.txt","w");
char symb_tab[20][30];
for(int i=0;i<20;++i) {
strcpy(symb_tab[i],"");
}
while((c=fgetc(fp1))!=EOF) {
switch(state) {
case 0:
if(isalpha(c)||c=='_') {
 state=1;
 id[i++]=c;
}
else if(isdigit(c))
{
 state=3;
 num[j++]=c;
}
else if(c=='<' || c=='>') {
state=5;
}
else if(c=='=' || c=='!') {
state=8;
}
else if(c=='/') {
state=10;
}
else if(c==' ' || c=='\t' || c=='\n' || c=='\r') {
state=0;
}
else {
fprintf(fp2,"\n%c",c);
}
break;
case 1:
if(isalnum(c)||c=='_') {
 state=1;
 id[i++]=c;
}
else {
id[i]='\0';
if(check_keyword(id)) {
fprintf(fp2," \n%s : keyword ",id);
}
else {
fprintf(fp2,"\n%s : identifier",id);
store_symb_tab(id,symb_tab);
}
state=0;
i=0;
ungetc(c,fp1);
}
break;
case 3:
if(isdigit(c)) {
 num[j++]=c;
 state=3;
}
else {
num[j]='\0';
fprintf(fp2," \n%s: number",num);
state=0;
j=0;
ungetc(c,fp1);
}
break;
case 5:
if(c=='=') {
fseek(fp1,-2,SEEK_CUR);
c=fgetc(fp1);
if(c=='<') {
fprintf(fp2,"\n<=: relational operator Less Than
or Equal To");
}
else {
fprintf(fp2,"\n<=: relational operator Greater
Than or Equal To");
}
c=fgetc(fp1);
state=0;
}
else {
fseek(fp1,-2,SEEK_CUR);
c=fgetc(fp1);
if(c=='<') {
fprintf(fp2,"\n<: relational operator Less Than");
}
else {
fprintf(fp2,"\n>: relational operator Greater
Than");
}
state=0;
}
break;
case 8:
if(c=='=') {
fseek(fp1,-2,SEEK_CUR);
c=fgetc(fp1);
if(c=='=') {
fprintf(fp2,"\n==: relational operator Equal
To");
}
else {
fprintf(fp2,"\n!=: relational operator Not Equal
To");
}
c=fgetc(fp1);
state=0;
}
else {
fprintf(fp2,"\n!");
ungetc(c,fp1);
state=0;
}
break;
case 10:
if(c=='*') {
state=11;
}
else {
fprintf(fp2,"\n/%c: invalid lexeme",c);
state=0;
}
break;
case 11:
if(c=='*') {
state=12;
}
break;
case 12:
if(c=='*') {
state=12;
}
else if(c=='/') {
state=0;
}
else {
state=11;
}
break;
}
}
if(state==11) {
fprintf(fp2,"\nComment Not Closed");
}
fclose(fp1);
fclose(fp2);
return 0;
}