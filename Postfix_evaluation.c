#include <stdio.h>
#include <ctype.h>
#define size 50
int top=-1;
int s[size];
void push(int elem)
{
s[++top]=elem;
}
int pop()
{
return (s[top--]);
}
int main()
{
char pofx[50],ch;
int i=0,op1,op2;
printf("\n\nRead the postfix expression:\n");
scanf("%s",pofx);
while((ch=pofx[i++])!='\0')
{
if(isdigit(ch))
push(ch-'0');
else
{
op2=pop();
op1=pop();
switch(ch)
{
case '+':
push(op1+op2);
break;
case '-':
push(op1-op2);
break;
case '*':
push(op1*op2);
break;
case '/':
push(op1/op2);
break;
case '^':
push(op1^op2);
break;
}
}
}
printf("\n Result\n:%d\n",s[top]);

return 0;
}
