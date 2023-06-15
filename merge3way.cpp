#include<bits/stdc++.h>
using namespace std;
int A[1000];
int B[1000];
int C[1000];
void getnumbers(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        a[i]=rand();
    }
}
void display(int a[],int p,int r)
{
    for(int i=p; i<=r; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void Merge(int a[],int p,int m1,int m2, int r)
{
    int i,k,j,x,y,z;
    x=y=z=1;
    for(i=p;i<=m1;i++)
    {
        A[x]=a[i];
        x++;
    }
    for(i=m1+1;i<=m2;i++)
    {
        B[y]=a[i];
        y++;
    }
    for(i=m2+1;i<=r;i++)
    {
        C[z]=a[i];
        z++;
    }
A[x]=INT_MAX;
B[y]=INT_MAX;
C[z]=INT_MAX;
    x=y=z=1;
    for(i=p;i<=r;i++)
    {
        if(A[x]<=B[y]&&A[x]<=C[z])
        {
            a[i]=A[x];
            x++;
        }
        else if(B[y]<=A[x]&&B[y]<=C[z])
        {
            a[i]=B[y];
            y++;
        }
        else
        {
            a[i]=C[z];
            z++;
        }

    }
}
void mergesort(int a[],int p,int r)
{
    if(p<r)
    {
        cout<<"\n before dividing: ";
        display(a,p,r);
        int m1 = p + ((r-p ) / 3);
        int m2 = p + 2 * ((r-p ) / 3) + 1;
         cout<<"After dividing: \n1st array: ";
        display(a,p,m1);
        cout<<"2nd array: ";
        display(a,m1+1,m2);
       cout<<"3rd array: ";
        display(a,m2+1,r);
        mergesort(a,p,m1);
        mergesort(a,m1+1,m2);
        mergesort(a,m2+1,r);
        Merge(a,p,m1,m2,r);
         cout<<"**After merging** ";
    display(a,p,r);
    }
}
int main()
{
    int n=9;
    int a[n];
    getnumbers(a,n);
    cout<<"Given array: ";
    display(a,0,n-1);
    mergesort(a,0,n-1);
     cout<<"Sorted array: ";
    display(a,0,n-1);

}


