#include <stdio.h>
#include <ctype.h>
#define size 50
char s[size];
int top=-1;
push(char elem)
{
s[++top]=elem;
}
char pop()
{
return (s[top--]);
}
int pr(char elem)
{
switch (elem)
{
case '#':
return 0;
break;
case '(':
return 1;
break;
case '+':
case '-':
return 2;
break;
case '*':
case '/':
return 3;
break;
}
}
main()
{
char infx[50],pofx[50],ch,elem;
int i=0,k=0;
printf("\n\n Read the infix expression\n");
scanf("%s",infx);
push('#');
while((ch=infx[i++])!='\0')
{
if(ch=='(')
push(ch);
else
if(isalnum(ch))
pofx[k++]=ch;
else
if(ch==')')
{
while (s[top]!='(')
pofx[k++]=pop();
elem=pop();
}
else
{
while(pr(s[top])>=pr(ch))
pofx[k++]=pop();
push(ch);
}
}
while(s[top]!='#')
pofx[k++]=pop();
pofx[k]='\0';
printf("\n\nGiven infix expression:\n %s \n Postfix Expression:\n %s\n",infx,pofx);
}
