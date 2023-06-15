#include<bits/stdc++.h>
using namespace std;
int A[1000];
int B[1000];
int C[1000];
int D[1000];
void display(int a[],int p,int r)
{
 for(int i=p; i<=r; i++)
 cout<<a[i]<<" ";
 cout<<endl;
}
void Merge(int a[],int p,int m1,int m2,int m3, int r)
{
 int i,k,j,x,y,z,w;
 x=y=z=w=0;
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
 for(i=m2+1;i<=m3;i++)
 {
 C[z]=a[i];
 z++;
 }
 for(i=m3+1;i<=r;i++)
 {
 D[w]=a[i];
 w++;
 }
A[x]=INT_MAX;
B[y]=INT_MAX;
C[z]=INT_MAX;
D[w]=INT_MAX;
 w=x=y=z=0;
 for(i=p;i<=r;i++)
 {
 if(A[x]<=B[y]&&A[x]<=C[z]&&A[x]<=D[w])
 {
 a[i]=A[x];
 x++;
 }
 else if(B[y]<=A[x]&&B[y]<=C[z]&&B[y]<=D[w])
 {
 a[i]=B[y];
 y++;
 }
 else if(C[z]<=A[x]&&C[z]<=B[y]&&C[z]<=D[w])
 {
 a[i]=C[z];
 z++;
 }
 else
 {
 a[i]=D[w];
 w++;
 }
 }
}
void mergesort(int a[],int p,int r)
{
 if(p<r)
 {
     cout<<"\nBefore dividing: ";
        display(a,p,r);
 int m1=p+(r-p)/4;
 int m2=m1+(r-p)/4;
 int m3=m2+(r-p)/4;
 cout<<"\nAfter dividing:\n";
 cout<<"1st Array: "; display(a,p,m1);
 cout<<"2nd Array: "; display(a,m1+1,m2);
 cout<<"3rd Array: "; display(a,m2+1,m3);
 cout<<"4th Array: "; display(a,m3+1,r);
 cout<<endl;
 mergesort(a,p,m1);
 mergesort(a,m1+1,m2);
 mergesort(a,m2+1,m3);
 mergesort(a,m3+1,r);
 Merge(a,p,m1,m2,m3,r);
 cout<<"After merging: ";
 display(a,p,r);
 }
}
int main()
{
 int n=10;
 int a[]= {10,-7,12,33,6,1,2,7,24,66};
 cout<<"Given array: ";
 display(a,0,n-1);
 mergesort(a,0,n-1);
 cout<<"Sorted array: ";
 display(a,0,n-1);
}
