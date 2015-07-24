#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 10
class Stack
{
	int stk[MAXSIZE];
	int top;
	public:
		Stack()
		{
			top=-1;
		}
		void push(int);
		int pop();
		void print();
};
void Stack::push(int x)
{
	if(top==MAXSIZE-1)
	{
		cout<<"\n Error : Stack Overflow..";
		return;
	}
	else
	{
		top = top + 1;
		stk[top]=x;
	}
}
int Stack::pop()
{
	int val;
	if( top==-1 )
		{  
			cout<<"\n Error : Stack Underflow..";
			return 0;
		}
	else
	{
		val = stk[top];
		top--;
		return (val);
	}		
}
void Stack::print()
{
	cout<<"\n Stack : ";
	for(int i=top; i>=0; i--)
		cout<<"\n"<<stk[i];
}
int main()
{
	Stack S1;
	while(1)
	{
		cout<<"\n=================================================";
		cout<<"\n   Basic Stack Operations implemented on array : ";
		cout<<"\n=================================================";
		cout<<"\n 1. Push an element into the Stack.";
		cout<<"\n 2. Pop an element from the Stack.";
		cout<<"\n 3. Print the elements of the Stack.";
		cout<<"\n 4. Exit. ";
		cout<<"\n\t Enter your choice : ";
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1 :
				cout<<"\n Enter the element to be pushed : ";
				int val;
				cin>>val;
				S1.push(val);
				break;
				
			case 2:
				cout<<"\n Element poped from the Stack : "<< S1.pop();
				break;
				
			case 3:
				system("cls");
				S1.print();
				break;
			
			case 4:
				cout<<"\n Thanks for using it.!!";
				exit(0);
				
			default:
				cout<<"\n Invaild option.. Try again..";
				
			}		
	}
}
