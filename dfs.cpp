#include<bits/stdc++.h>
using namespace std;
vector<int>v[10];
int start[10];
int finish[10];
int T=0;
void DFS(int s)
{
 ++T;
 start[s]=T;
    for(int i=0; i<v[s].size(); i++)
    {
        int u=v[s][i];
        if(start[u]==0)
        {
            DFS(u);
        }
    }
    ++T;
    finish[s]=T;
}
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    int n,e;
    int a,b;
    cin>>n>>e;

    for(int i=1; i<=e; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=1; i<=n; i++)
    {
        cout<<"for node "<<i<<"= ";
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
 DFS(1);
 for(int i=1;i<=n;i++)
 {
     cout<<"For edge "<<i<<" Starting point: "<<start[i]<<" Finishing point: "<<finish[i]<<"\n";
 }
}



