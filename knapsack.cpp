#include<bits/stdc++.h>
using namespace std;
int main()
{

    int weights[]={2,3,4,5};
    int values[]={3,4,5,6};
    int n=4, capacity=5;
    int totalbenefit;
    int v[n+1][capacity+1];
    int i,w;
    for(i=0;i<=capacity;i++)
    {
        v[0][i]=0;
    }
    for(i=1;i<=n;i++)
    {
        v[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(w=0;w<=capacity;w++)
        {
          if(weights[i-1]<=w)
          {
              if((values[i-1]+v[i-1][w-weights[i-1]])>v[i-1][w])
              {
                  v[i][w]=values[i-1]+v[i-1][w-weights[i-1]];
              }
              else
              {
                  v[i][w]=v[i-1][w];
              }
          }
          else
          {
              v[i][w]=v[i-1][w];
          }
        }
    }
    cout<<"Maximum weight: "<<v[n][capacity]<<endl;
   i=n;
   int k=capacity;
   while(i>0&&k>0)
   {

            if(v[i][k]!=v[i-1][k])
            {

                cout<<i<<"th item selected\n";
                 i--;
                k=k-weights[i];

            }
            else
                i--;
        }
}

