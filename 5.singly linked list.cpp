#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
Node *head = NULL;
void Create()
{
	Node *temp, *q;
	char ans = 'Y';
	while(ans=='Y'||ans=='y')
	{
		temp = new Node;
		cout<<"\n Enter the data in the Node : ";
		cin>>temp->data;
		temp->next=NULL;
		if(head==NULL)
			head=temp;
		else
		{
			q=head;
			while(q->next!=NULL)
				q=q->next;
			q->next=temp;
		}
		cout<<"\n Do u want to create another Node ? (Y/N) : ";
		cin>>ans;
	}
}
void print()
{
	Node *q;
	cout<<"\n List : ";
	for(q=head; q!=NULL; q=q->next)
		cout<<"\t"<<q->data;
}
void insertbeg()
{
	Node *temp;
	temp = new Node;
	cout<<"\n Enter data in the Node : ";
	cin>>temp->data;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		temp->next=head;
		head=temp;
	}
}

void insertend()
{
	Node *temp, *q;
	temp  = new Node;
	cout<<"\n Enter data in the Node : ";
	cin>>temp->data;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
	}
}
void insertatpos(int val, int pos)
{
	Node *temp, *q;
	temp= new Node;
	temp->data=val;
	temp->next=NULL;
	if(pos==1)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		q=head;
		for(int i=1; i<pos-1 && q!=NULL; i++)
			q=q->next;
		if(q==NULL)
			cout<<"\n Invalid Position:";
		else
		{
			temp->next=q->next;
			q->next=temp;
		}
	}
}
void deletebeg()
{
	Node *temp;
	if(head==NULL)
		cout<<"\n List is Empty : Invalid operation..";
	else if(head->next==NULL)
	{
		temp=head;
		delete temp;
		head=NULL;
	}
	else
	{
		temp=head;
		head=head->next;
		delete temp;
	}
}
void deleteend()
{
	Node *q, *p;
	if(head==NULL)
		cout<<"\n List is Empty :  Invalid Opertion : ";
	else if(head->next==NULL)
	{
		q=head;
		delete q;
		head=NULL;
	}
	else
	{
		q=head;
		while(q->next->next!=NULL)
			q=q->next;
		q->next=p;
		delete p;
		q->next=NULL;
	}	
}
void deleteatpos(int pos)
{
	Node *tmp, *q, *p;
	if(pos==1)
	{
		if(head==NULL)
			cout<<"\n List is Empty : Invaild Operation.";
		else if(head->next==NULL)
		{
			tmp=head;
			delete tmp;
			head=NULL;
		}
		else
		{
			tmp=head;
			head=head->next;
			delete tmp;
		}
	}
	else
	{
		q=head;
		p=q->next;
		for(int i=1;i<pos-1 && p!=NULL; i++)
		{
			q=q->next;
			p=p->next;	
		}
	}
	if(p==NULL)
		cout<<"\n Invalid Position.: Can't Not Delete Node.";
	else
	{
		q->next=p->next;
		delete p;
	}
}
int main()
{
	while(1)
	{
		cout<<"\n=========================================================================";
		cout<<"\n			Basic Operation on Singly Linked List				   		  ";
		cout<<"\n=========================================================================";
		cout<<"\n 1. Create Node. ";
		cout<<"\n 2. Display Nodes.";
		cout<<"\n 3. Insert Node at Begaining of the List . ";
		cout<<"\n 4. Insert Node at End of the List.";
		cout<<"\n 5. Insert at a Particular Position in the List.";
		cout<<"\n 6. Delete at the Begainning of List.";
		cout<<"\n 7. Delete at the End of the List.";
		cout<<"\n 8. Delete at a Particular Position in the List.";
		cout<<"\n 9. Exit.";
		cout<<"\n\t Enter your choice : ";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
				Create();
				break;
			
			case 2:
				print();
				break;
			
			case 3:
				insertbeg();
				break;
				
			case 4:
				insertend();
				break;
				
			case 5:
				cout<<"\n Enter the data to be inserted : ";
				int val;
				cin>>val;
				cout<<"\n At position : ";
				int pos;
				cin>>pos;
				insertatpos(val,pos);
				break;

			case 6:
				deletebeg();
				break;
				
			case 7:
				deleteend();
				break;
				
			case 8:
				cout<<"\n Enter the position to be deleted : ";
				int pos1;
				cin>>pos1;
				deleteatpos(pos1);
				break;
							
			case 9:
				cout<<"\n Thanks for using..";
				exit(0);
				
			default:
				cout<<"\n Invalid Option.. Try again..";
		}
	}
	return 0;
}
	
