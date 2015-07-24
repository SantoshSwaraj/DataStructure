#include<iostream>
using namespace std;
#define MaxSize 10
void SelectionSort(int A[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int iMin = i;
		for(int j=i+1; j<n; j++)
		{
			if(A[j]<A[iMin])
				iMin = j;
		}
		int temp = A[i];
		A[i]= A[iMin];
		A[iMin]=temp;
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
	SelectionSort(A,MaxSize);
	cout<<"\n Array after sorting : \n";
	for(int i=0;i<MaxSize;i++)
	{
		cout<<"\t"<<A[i];
	}
	
}
