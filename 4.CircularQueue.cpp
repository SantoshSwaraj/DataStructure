#include<iostream>
#define MaxSize 3
using namespace std;
class CQueue
{
	int cqueue[MaxSize];
	int front, rear;
	public:
		CQueue()
		{
			front=rear=-1;
		}
		void cqueue_insert(int);
		int cqueue_delete();
		void cqueue_print();
};
void CQueue::cqueue_insert(int x)
{
	if(front==(rear+1)%MaxSize)
	{
		cout<<"\n Circular Queue is Full : Overflow.";
		return;
	}
	else
	{
		if(front=-1)
			front=0;
		rear=(rear+1)%MaxSize;
		cqueue[rear]=x;
	}
}
int CQueue::cqueue_delete()
{
	int val;
	if(front==-1)
	{
		cout<<"\n Circular Queue is Empty : Underflow.";
		return 0;
	}
	else
	{
		val=cqueue[front];
		if(front==rear)
			front=rear=-1;
		else
		{
			front=(front+1)%MaxSize;
			return val;
		}
	}
}
void CQueue::cqueue_print()
{
	cout<<"\n Circular Queue : ";
	if(front<rear)
	{
		for(int i=front; i<=rear; i++)
			cout<<"\t\a"<<cqueue[i];
	}
	else	
	{
		for(int i=front; i<MaxSize; i++)
			cout<<"\t\a"<<cqueue[i];
		for(int j=rear; j<front; j++)
			cout<<"\t\a"<<cqueue[j];
	}
}
int main()
{
	CQueue Q1;
	while(1)
	{
		cout<<"\n==========================================================";
		cout<<"\n   Basic Circular Queue Operations implemented on array : ";
		cout<<"\n==========================================================";
		cout<<"\n 1. Enqueue an element into the Circular Queue.";
		cout<<"\n 2. Dequeue an element from the Circular Queue.";
		cout<<"\n 3. Print the elements of the Circular Queue.";
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
				Q1.cqueue_insert(val);
				break;
				
			case 2:
				cout<<"\n Element Dequeued from the Queue : "<< Q1.cqueue_delete();
				break;
				
			case 3:
				Q1.cqueue_print();
				break;
			
			case 4:
				cout<<"\n Thanks for using it.!!";
				exit(0);
				
			default:
				cout<<"\n Invaild option.. Try again..";
		}
	}
}

