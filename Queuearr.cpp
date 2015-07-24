#include<iostream>
#define MaxSize 5
using namespace std;
class Queue
{
	int queue[MaxSize];
	int front, rear;
	public:
		Queue()
		{
			front=-1;
			rear=-1;
		}
		void Enqueue(int);
		int Dequeue();
		void Print();

};
void Queue::Enqueue(int x)
{
	if(rear==MaxSize-1)
	{	
		cout<<"\n Queue is full : Overflow.";
		return;
	}	
	else
	{
		if(front==-1)
			front=0;
		queue[++rear]=x;
	}
}
int Queue::Dequeue()
{
	int val;
	if(front==-1)
	{
		cout<<"\n Queue is Empty : Underflow.";
		return 0;
	}
	else
	{
		if(front>rear)
		{
			front=rear=-1;
			cout<<"\n Queue is Empty : Underflow.";
			return 0;
		}
		else
		{
			val=queue[front];
			front++;
			return val;
		}
	}
}
void Queue::Print()
{
	cout<<"\n Queue : ";
	for(int i=front; i<=rear; i++)
		cout<<"\t\a"<<queue[i];
}
int main()
{
	Queue Q1;
	while(1)
	{
		cout<<"\n=================================================";
		cout<<"\n   Basic Queue Operations implemented on array : ";
		cout<<"\n=================================================";
		cout<<"\n 1. Enqueue an element into the Queue.";
		cout<<"\n 2. Dequeue an element from the Queue.";
		cout<<"\n 3. Print the elements of the Queue.";
		cout<<"\n 4. Exit. ";
		cout<<"\n\t Enter your choice : ";
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1 :
				cout<<"\n Enter the element to be Enqueued : ";
				int val;
				cin>>val;
				Q1.Enqueue(val);
				break;
				
			case 2:
				cout<<"\n Element Dequeued from the Queue : "<< Q1.Dequeue();
				break;
				
			case 3:
				Q1.Print();
				break;
			
			case 4:
				cout<<"\n Thanks for using it.!!";
				exit(0);
				
			default:
				cout<<"\n Invaild option.. Try again..";
				
			}		
	}
	
}
