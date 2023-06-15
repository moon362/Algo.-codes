#include<bits/stdc++.h>
using namespace std;
int L[1000];
int R[1000];
void display(int a[],int p,int r)
{
    for(int i=p; i<=r; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void Merge(int a[],int p,int q, int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    for(i=0; i<n1; i++)
    {
        L[i]=a[p+i];
    }
    for(i=0; i<n2; i++)
    {
        R[i]=a[q+i+1];
    }
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    i=j=0;
    for(k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
    }
    cout<<"##After merging## ";
    display(a,p,r);
}
void mergesort(int a[],int p,int r)
{
    if(p<r)
    {

        cout<<"\nBefore dividing: ";
        display(a,p,r);
        int q=(p+r)/2;
        cout<<"After dividing: ";
        display(a,p,q);
        cout<<"After dividing: ";
        display(a,q+1,r);
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        Merge(a,p,q,r);
    }
}
int main()
{
    int n=7;
    int a[]= {10,-7,12,3,16,1,2};
    cout<<"Given array: ";
    display(a,0,n-1);
    mergesort(a,0,n-1);
    cout<<"Sorted array: ";
    display(a,0,n-1);
}
