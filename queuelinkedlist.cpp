#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
class Queue
{
	Node *front, *rear;
	public:
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		void Enqueue(int);
		int Dequeue();
		void Print();
};
void Queue::Enqueue(int x)
{
	Node *tmp, *q;
	tmp = new Node;
	tmp->data=x;
	tmp->next=NULL;
	if(front==NULL && rear==NULL)
		front=rear=tmp;
	else
	{
		q=front;
		while(q->next!=NULL)
			q=q->next;
		q->next=tmp;
		rear=tmp;
	}	
}
int Queue::Dequeue()
{
	int val;
	Node *tmp;
	if(front==NULL)
	{
		cout<<"\n Queue is Empty : Underflow.";
		return 0;
	}
	else
	{
		tmp=front;
		val=tmp->data;
		front=front->next;
		delete tmp;
		return val;
	}
}
void Queue::Print()
{
	Node *q;
	cout<<"\n Queue : ";
	for(q=front;q!=rear;q=q->next)
		cout<<"\t"<<q->data;
	cout<<"\t"<<q->data;
}
int main()
{
	Queue Q;
	while(1)
	{
		cout<<"\n=======================================================";
		cout<<"\n		Queue implemented on Linked List				";
		cout<<"\n=======================================================";
		cout<<"\n 1. Enqueue an element.";
		cout<<"\n 2. Dequeue an element.";
		cout<<"\n 3. Print the Queue.";
		cout<<"\n 4. Exit.";
		cout<<"\n \tEnter your choice : ";
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\n Enter the data to be enqueued : ";
				int val1;
				cin>>val1;
				Q.Enqueue(val1);
				break;
				
			case 2:
				cout<<"\n Data dequeued from the Queue : "<<Q.Dequeue();
				break;
				
			case 3:
				Q.Print();
				break;
				
			case 4:
				cout<<"\n Thanks for using.";
				exit(0);
				
			default:
				cout<<"\n Invalid Option : Try again ";
		}
	}
	return 0;
}
