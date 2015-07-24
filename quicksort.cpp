#include<iostream>
#include<stdlib.h>
using namespace std;
int Partition(int low,int high,int arr[]);
void Quick_sort(int low,int high,int arr[]);

int main()
{
int *a,n,low,high,i;
cout<<"/*******Quick Sort Algorithm Implementation************/";
cout<<"\n Enter number of elements:";
cin>>n;
a=new int[n];
// Enter the elements in the array 
for(i=0;i<n;i++)
{
	cout<<"\n Enter the data at A["<<i<<"] : ";
	cin>>a[i];
}
cout<<"\n Initial Order of elements";
for(i=0;i<n;i++)
{
	cout<<a[i]<<"	";
}

high=n-1;
low=0;
Quick_sort(low,high,a);
cout<<"\n";
cout<<"\n Final Array After Sorting: ";
  for(i=0;i<n;i++)
  	cout<<a[i]<<"	";
return 0;
}

/*Function for partitioning the array*/

int Partition(int low,int high,int arr[])
{
	 int i,high_vac,low_vac,pivot;
   	pivot=arr[low];
   	while(high>low)
	{ 
		high_vac=arr[high];
		while(pivot<high_vac)
  		{
    		if(high<=low) break;
    		high--;
    		high_vac=arr[high];
  		}
		arr[low]=high_vac;
  		low_vac=arr[low];
  		while(pivot>low_vac)
  		{
    		if(high<=low)
			 break;
    		low++;
    	low_vac=arr[low];
  		}
  	arr[high]=low_vac;
	}
arr[low]=pivot;
return low;
}

void Quick_sort(int low,int high,int arr[])
{
  int Piv_index,i;
  if(low<high)
  {
   Piv_index=Partition(low,high,arr);
   Quick_sort(low,Piv_index-1,arr);
   Quick_sort(Piv_index+1,high,arr);
  }
}


