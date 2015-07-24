#include<iostream>
#include<stdio.h>
#include<ctype.h>
using namespace std;
#define Size 50
char s[Size];
int top = -1;
void push(char elem)
{
	s[++top] = elem;
}
char pop()
{
	return(s[top--]);
}
int pr(char elem)		//Function for precedence
{
	switch(elem)
	{
		case '#':
			return 0;
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		default :
			return 0;
	}
}
void pushit(int ele)
{
	s[++top] = ele;
}
int popit()
{
	return(s[top--]);
}
int main()
{
	char infix[Size], postfix[Size], ch, elem;
	int i=0, k=0, op1, op2, ele;
	cout<<"\n Enter the Infix expression : ";
	cin>>infix;
	
	push('#');
	while((ch=getchar())!='\0')
	{
		if(ch=='(')
			push(ch);
		else if(isdigit(ch))
			postfix[k++] = ch;
		else if(ch == ')')
		{
			while(s[top]!='(')
				postfix[k++]=pop();
			elem = pop();	// Removal of '(' from the stack
		}
		else	//operator
		{
			while(pr(s[top])>=pr(ch))
			{
				postfix[k++]=pop();
			}
			push(ch);
		}
	}
	while(s[top]!='#')
	{
		postfix[k++] = pop();
	}
	postfix[k] = '\0';
	cout<<"\n Given Infix Expression : "<< infix;
	cout<<"\n Converted Postfix Expression : " <<postfix;
	
	// Evaluation of Postfix Expression..
	while((ch=getchar())!='\0')
	{
		if(isdigit(ch)) // Push the operand
			pushit(ch-'0');
		else			// operator , pop two operand
		{
			op2 = popit();
			op1 = popit();
			
			switch(ch)
			{
				case '+': pushit(op1+op2); break;
				case '-': pushit(op1-op2); break;
				case '*': pushit(op1*op2); break;
				case '/': pushit(op1/op2); break;
			}
		}
	} 
	cout<<"\n Given Mathematical expression is : "<<infix;
	cout<<"\n Result after Evaluation  : "<<s[top];
	return 0;
}

