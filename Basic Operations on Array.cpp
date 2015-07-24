/*Basic opertions of One dimensional Array*/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
static int A[size];
void insert_element(int A[], int, int, int);
void delete_element(int A[], int, int);
void display(int A[], int n);
int main()
{
	while(1)
	{
		clrscr();
		cout<<"\n============================================================================= ";
		cout<<"\n Project(Prepared by : Santosh):: Basic operations on One dimensional array "  ;
		cout<<"\n=============================================================================" ;
		cout<<"\n 1. Insert an element to a particular position in the List. ";
		cout<<"\n 2. Delete an element from a particular position in the List .";
		cout<<"\n 3. Display the List.";
		cout<<"\n 4. Exit";
		cout<<"\n\t Enter your option : ";
		int opt;
		cin>>opt;

		switch(opt)
		{
			case 1:
				clrscr();
				cout<<"\n Enter the position : ";
				int pos;
				cin>>pos;
				cout<<"\n Enter the value : ";
				int val;
				cin>>val;
				insert_element(A,size,pos,val);
				getch();
				break;

			case 2:
				clrscr();
				cout<<"\n Enter the position : ";
				cin>>pos;
				delete_element(A,size,pos);
				getch();
				break;


			case 3:
				clrscr();
				cout<<"\n List :: ";
				display(A,size);
				getch();
				break;

			case 4:
				clrscr();
				cout<<"\n Thanks for using it..";
				getch();
				exit(0);

			default :
				clrscr();
				cout<<"\n Invaild option.. Try again!!";
				getch();
		}//end of switch

	}//end of while
	getch();
	return 0;
}//end of main

void insert_element(int A[], int n, int pos, int  val)
{
	for(int j=n-1; j>=pos-1; j--)
		A[j+1] = A[j];

	A[j+1]=val;
}
void delete_element(int A[], int n, int pos)
{
	for(int j=pos; j<n; j++)
		A[j-1]=A[j];
}

void display(int A[], int n)
{
	for(int i=0; i<n; i++)
		cout<<"\t\a"<<A[i];
}
