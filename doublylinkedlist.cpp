#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *prev, *next;
};
Node *head = NULL;
void create()
{
	Node *tmp, *q;
	char ans='Y';
	while(ans=='Y'||ans=='y')
	{
		tmp=new Node;
		cout<<"\n Enter data at the node : ";
		cin>>tmp->data;
		tmp->prev=NULL;
		tmp->next=NULL;
		if(head==NULL)
		{
			head=tmp;
			tmp->prev=head;
		}
		else
		{
			q=head;
			while(q->next!=NULL)
				q=q->next;
			q->next=tmp;
			tmp->prev=q;
		}
		cout<<"\n Do you want to create another node ? (Y/N) : ";
		cin>>ans;
	}
}
void print()
{
	Node *q;
	cout<<"\n List : ";
	for(q=head; q!=NULL; q=q->next)
		cout<<" "<<q->data;
}
void insertbeg()
{
	Node *tmp;
	tmp = new Node;
	cout<<"\n Enter the data at Node : ";
	cin>>tmp->data;
	tmp->prev=NULL;
	tmp->next=NULL;
	if(head==NULL)
		head=tmp;
	else
	{
		tmp->next=head;
		head->prev=tmp;
		head=tmp;
	}
}
void insertend()
{
	Node *tmp, *q;
	tmp = new Node;
	cout<<"\n Enter data to the node : ";
	cin>>tmp->data;
	tmp->prev=NULL;
	tmp->next=NULL;
	if(head==NULL)
		head=tmp;
	else
	{
		q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=tmp;
		tmp->prev=q;
	}
}
void insertatpos(int val, int pos)
{
	Node *tmp,*q,*p;
	tmp = new Node;
	tmp->data=val;
	tmp->prev=NULL;
	tmp->next=NULL;
	if(pos==1)
	{
		if(head==NULL)
			head=tmp;
		else
		{
			tmp->next=head;
			head->prev=tmp;
			head=tmp;	
		}	
	}
	else
	{
		q=head;
		for(int i=1; i<pos-1 && q!=NULL; i++)
			q=q->next;
		if(q==NULL)
			cout<<"\n Invalid Position..";
		else
		{
				p=q->next;
				tmp->next=q->next;
				p->prev=tmp;
				tmp->prev=q;
				q->next=tmp;
		}	
	}	
}
int main()
{
	while(1)
	{
		cout<<"\n=========================================================================";
		cout<<"\n		Basic Operation on Singly Linked List				   		      ";
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
				create();
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

			/*case 6:
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
				break;*/
							
			case 9:
				cout<<"\n Thanks for using..";
				exit(0);
				
			default:
				cout<<"\n Invalid Option.. Try again..";
		}
	}
	return 0;
}


