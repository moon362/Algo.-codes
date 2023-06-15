#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x="ABCBDAB";
    string a=x;
    string y="BDCABA";
    int m=x.size();
    int n=y.size();
    int c[m+1][n+1];
    int b[m+1][n+1];
    int i,j;
    for(i=0; i<=m; i++)
    {

        c[i][0]=0;
    }
    for(j=0; j<=n; j++)
    {
        c[0][j]=0;
    }
    for(i=1; i<=m; i++)
    {

        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }
            else
            {
                if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]='v';
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]='h';
                }
            }

        }
    }

    cout<<"Total matching character: "<<c[m][n]<<endl;
    i=m,j=n;
    while(1)
    {
        if(i==0||j==0)
        {
            break;
        }
        else
        {
            if(b[i][j]=='d')
            {
                cout<<"i: "<<i<<" j: "<<j<<"-->>";
                i--,j--;
                cout<<a[i]<<"\n";

            }
            else if(b[i][j]=='v')
            {
                i--;
            }
            else
                j--;
        }

    }
}
