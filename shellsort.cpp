#include <iostream>
using namespace std;

//Shell sort function
void shell_sort (int ar[], int size)
{
  int j;
  //Narrow the array by 2 everytime
  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; ++i)
    {
      int temp = ar[i];
      for (j = i; j >= gap && temp < ar[j - gap]; j -= gap)
      {
        ar[j] = ar[j - gap];
      }
      ar[j] = temp;
    } 
  }
}
//Print values
void print_ar (int ar[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    cout << ar[i] << " ";
  }
  cout << endl;
} 
//Driver Functions
int main ()
{
  int *ar;
  cout<<"/*******Shell Sort Algorithm Implementation************/";
  cout<<"\n Enter number of elements:";
  int n;
  cin>>n; 
  ar=new int[n];
  // Enter the elements in the array 
  for(int i=0;i<n;i++)
  {
	cout<<"\n Enter the data at A["<<i<<"] : ";
	cin>>ar[i];
  }  
  
  cout << "Intial Array : ";
  print_ar (ar, n);
  shell_sort (ar, n);
 
  cout << "Sorted Array : ";
  print_ar (ar, n);
 
  return 0;
}
