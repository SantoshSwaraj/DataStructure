#include<iostream>
using namespace std;
void push(int x);
int pop();
void print();
struct StackNode
{
	int data;
	StackNode* link;
	
};
StackNode* top = NULL;
void push(int x)
{
	StackNode *temp;
	temp = new StackNode;
	temp->data = x;
	temp->link = NULL;
 	if(top==NULL)
		top=temp;
	else
	{
		temp->link=top;
		top=temp;
	}
}
int pop()
{
	if(top==NULL)
	{
		cout<<"\n Stack is Empty : ";
		return 0;
	}
	else
	{
		StackNode* temp1;
		temp1=top;
		top=top->link;
		int val=temp1->data;
		delete temp1;
		return(val);
	}
}
void print()
{
	StackNode *q;
	cout<<"\n Stack : \n";
	for(q=top; q!=NULL; q=q->link)
		cout<<"\n\t"<<q->data<<"\t";
}
int main()
{
	while(1)
	{
		cout<<"\n=======================================================";
		cout<<"\n   Basic Stack Operations implemented on Linked List : ";
		cout<<"\n=======================================================";
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
				push(val);
				break;
				
			case 2:
				cout<<"\n Element poped from the Stack : "<<pop();
				break;
				
			case 3:
				print();
				break;
			
			case 4:
				cout<<"\n Thanks for using it.!!";
				exit(0);
				
			default:
				cout<<"\n Invaild option.. Try again..";
				
			}		
	}
	
}
