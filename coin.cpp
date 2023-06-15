#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c[]= {1,10,25};
    int m=31;
    int d=3;
    int cost[m+3];
    int p[m+3];
    cost[0]=0;
    for(int i=1; i<=m; i++)
    {
        cost[i]=1000;
        for(int j=0; j<d; j++)
        {
            if(i>=c[j]&& cost[i-c[j]]+1<cost[i])
            {

                cost[i]=cost[i-c[j]]+1;
                p[i]=c[j];
            }
        }
    }
    cout<<cost[m]<<endl;
    int i=m;
    while(i>0)
    {
        cout<<p[i]<<" ";
        i-=p[i];

    }

}


