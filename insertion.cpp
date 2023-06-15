#include<bits/stdc++.h>
using namespace std;
int l=0;
void print(int a[],int n)
{
     for(int i=0;i<n;i++)cout<<a[i]<<" ";
     cout<<endl;
}

void InsertionSort(int a[],int n)
{
    int i,j;
    for(j=1;j<n;j++)
    {
          int key=a[j];
          i=j-1;
          while(i>=0&&a[i]>key)
          {
              a[i+1]=a[i];
              i--;
          }
          a[i+1]=key;
          l++;
          cout<<"For iteration "<<l<<" and key "<<key<<": ";
          print(a,n);
    }

}
int main()
{
    int a[] = {5, 1, 3, 4, 6, 2};
    cout<<"given array: ";
    print(a,6);
 InsertionSort(a, 6 );
 cout<<" Output: ";
 print(a,6);

}
