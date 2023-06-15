#include<bits/stdc++.h>
using namespace std;
int l=0;
void print(int a[],int p,int r)
{
    for(int i=p; i<=r; i++)cout<<a[i]<<" ";
    cout<<endl;
}
void compare(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int Partition(int arr[],int p,int r)
{
    int x=arr[r];
    int i=p-1;
    for(int j=p; j<r; j++)
    {
        if(arr[j]<=x)
        {
            i=i+1;
          compare(&arr[i],&arr[j]);
        }
    }
 compare(&arr[i+1],&arr[r]);
    return i+1;
}
void Quicksort(int a[],int p,int r)
{
    if(p<r)
    {

        int q=Partition(a,p,r);
        l++;
        cout<<"Array before partition: ";
        print(a,p,r);
        cout<<endl;
        cout<<"Iteration: "<<l<<" with pivot "<<a[q]<<":\n" ;
        cout<<"left array: ";
        print(a,p,q-1);
        cout<<"Right array: ";
        print(a,q+1,r);
        cout<<endl;
        Quicksort(a,p,q-1);
        Quicksort(a,q+1,r);

    }
}
int main()
{
    int a[] = {12,0,22,1,-4,44};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"given array: ";
    print(a,0,n-1);
    Quicksort(a,0,n-1);
cout<<"Output: ";
    print(a,0,n-1);
}
