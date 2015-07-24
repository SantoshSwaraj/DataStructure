#include<iostream>
using namespace std;
# define MaxSize 6
void InsertionSort(int A[], int n)
{
	for(int i=1; i<n; i++)
	{
		int value = A[i];
		int hole = i;
		while(hole>0 && A[hole-1]>value)
		{
			A[hole]=A[hole-1];
			hole--;
		}
		A[hole]=value;
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
	InsertionSort(A,MaxSize);
	cout<<"\n Array after sorting : \n";
	for(int i=0;i<MaxSize;i++)
	{
		cout<<"\t"<<A[i];
	}
	return 0;
}
