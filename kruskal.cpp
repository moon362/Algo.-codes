#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>graph[100];
vector<pair<int,int>>fgraph[100];
int node,edge;
int vis[10];
int dis[10];
int par[10];
priority_queue<pair<int,pair<int,int>>>PQ;
int findpar(int u)
{

    if(par[u]==u)
        return u;
   return  par[u]=findpar(par[u]);
}
void kruskal()
{
    for(int i=1; i<=node; i++)par[i]=i;
    int edge_num=0;
    while(edge_num<node-1)
    {
        pair<int,pair<int,int>>u=PQ.top();
        PQ.pop();
        int x,y,a,b;
        x=u.second.first;
        y=u.second.second;
        if(findpar(x)!=findpar(y))
        {
            par[y]=x;
            edge_num++;
            cout<<char(x+'a'-1)<<" "<<char(y+'a'-1)<<" : "<<-u.first<<endl;

        }
    }

}
int main()
{
    //freopen("input.txt","r",stdin);
    int a,b,c;
    cin>>node>>edge;
    for(int i=1; i<=edge; i++)
    {
        cin>>a>>b>>c;
        pair<int,int> p=make_pair(b,c);
        graph[a].push_back(p);
        p=make_pair(a,c);
        graph[b].push_back(p);
        p=make_pair(a,b);
        PQ.push(make_pair(-c,p));
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
    kruskal();

    /* for(int i=1; i<=node; i++)
     {
         for(int j=0;j<fgraph[i].size();j++)
         {
           // cout<<char('a'+i-1)<<" "<<char('a'+fgraph[i][j].first-1)<<" "<<fgraph[i][j].second<< "\n";
             cout<<i<<" "<<fgraph[i][j].first<<" "<<fgraph[i][j].second<< "\n";

         }
         //cout<<char('a'+i-1)<<" "<<char('a'+par[i]-1)<<" "<<dis[i]<<endl;
     }*/
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

