#include <stdio.h>
#include <string.h>
#define size 10
int top = -1;
char stack[size];
int main()
{
	char exp[20];
	printf("Enter the expression: \n");
	scanf("%s", exp);
	int i;

	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			push(exp[i]);
		else if(exp[i]==')')
		{
			if(stack[top]=='(')
				pop();
			else
				printf("Invalid\n");
		}

		else if(exp[i]=='}')
		{
			if(stack[top]=='{')
				pop();
			else
				printf("Invalid\n");
		}

		else if(exp[i]==']')
		{
			if(stack[top]=='[')
				pop();
			else
				printf("Invalid\n");
		}

		else
			continue;
	}

	if(top==-1)
		printf("Expression is Valid\n");
	else
		printf("Expression is Invalid\n");
	return 0;
}

void push(char ch)
{
	if(top==size-1)
		printf("Overflow\n");
	else
		stack[++top] = ch;
}

void pop()
{
	if(top==-1)
		printf("Underflow\n");
	else
		top--;
}
