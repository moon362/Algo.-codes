#include<bits/stdc++.h>
using namespace std;
queue<int>Q;
 vector<int>v[10];
int dis[10];
void BFS(int s)
{
    Q.push(s);
    for(int i=0;i<10;i++)
    {
        dis[i]=100;
    }
    dis[s]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<v[u].size();i++)
        {
           int w=v[u][i];
           if(dis[w]>dis[u]+1)
           {
               dis[w]=dis[u]+1;
               Q.push(w);
           }
        }
    }
}
int main()
{

    int n,e;
    int a,b;
    cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }
    for(int i=1;i<=n;i++)
    {
        cout<<"for node "<<i<<"= ";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    BFS(2);
      for(int i=1;i<=n;i++)
      {
           cout<<"distance from 2 to node "<<i<<"= "<<dis[i]<<endl;
      }
}
/* 4 4
1 2
1 3
1 4
2 2
*/
