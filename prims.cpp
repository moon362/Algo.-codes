#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>graph[100];
int node,edge;
int vis[10];
int dis[10];
int par[10];
priority_queue<pair<int,int>>PQ;
void prims(int src)
{
   for(int i=0;i<=node;i++)dis[i]=1000;
   dis[src]=0;
   PQ.push(make_pair(0,src)); //cost,node
   while(!PQ.empty())
   {
       pair<int,int>p=PQ.top();
       PQ.pop();
       int u=p.second;
       vis[u]=1;
       for(int i=0;i<graph[u].size();i++)
       {
           int v=graph[u][i].first;
           int edge_cost=graph[u][i].second;
           if(dis[v]>edge_cost&&vis[v]==0)
           {
               dis[v]=edge_cost;
               par[v]=u;
               PQ.push(make_pair(-dis[v],v));
           }
       }
   }
}
int main()
{
int a,b,c;
cin>>node>>edge;
for(int i=1;i<=edge;i++)
{
    cin>>a>>b>>c;
    pair<int,int> p=make_pair(b,c);
    graph[a].push_back(p);
    p=make_pair(a,c);
    graph[b].push_back(p);

}
  for(int i=1; i<=node; i++)
    {
        cout<<"Adjacency of "<<char('a'+i-1)<<" : ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<"("<<char('a'+graph[i][j].first-1)<<" "<<graph[i][j].second<< "), ";
        }
        cout<<endl;
    }
    prims(1);
    for(int i=1;i<=node;i++)
    {
        cout<<char('a'+i-1)<<" "<<char('a'+par[i]-1)<<" "<<dis[i]<<endl;
    }
}
/*
9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7

*/
