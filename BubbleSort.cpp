#include<iostream>
using namespace std;
#define MaxSize 6
//void swap(int, int);
void BubbleSort(int A[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int flag = 0;
		for(int j=0; j<n-1; j++)
		{
			if(A[j]>A[j+1])
			{
				int temp = A[j];
				A[j]=A[j+1];
				A[j+1] = temp;
				flag = 1;	
			}
			if(flag==0)
				break;
		}
	}
}

int main()
{
	int A[MaxSize];
	cout<<"\n Input Array : ";
	for(int i=0; i<MaxSize; i++)
	{
		cout<<"\n A["<<i<<"] : ";
		cin>>A[i];
	}
	cout<<"\n Array before sorting :\n ";
	for(int i=0;i<MaxSize;i++)
	{
		cout<<"\t"<<A[i];
	}
	BubbleSort(A,MaxSize);
	cout<<"\n Array after sorting : \n";
	for(int i=0;i<MaxSize;i++)
	{
		cout<<"\t"<<A[i];
	}
	return 0;
}
