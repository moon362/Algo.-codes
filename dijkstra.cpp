#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >graph[10];
int dis[10],vis[10];
priority_queue<pair<int,int> >pq;

void dijkstra(int source)
{
    for(int i=0;i<10;i++)
    {
        dis[i]=10000;
    }
    dis[source]=0;
    pq.push(make_pair(0,source));
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        int u=p.second;
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].first;
            if(dis[v]>dis[u]+graph[u][i].second)
            {
                dis[v]=dis[u]+graph[u][i].second;
                pq.push(make_pair(-dis[v],v));
            }
        }
    }

}
int main()
{
    int node,edge,a,b,c;
    cin>>node>>edge;
    for(int i=1;i<=edge;i++)
    {
        cin>>a>>b>>c;
        pair<int,int> p=make_pair(b,c);
        graph[a].push_back(p);
    }

    for(int i=1;i<=node;i++)
    {
        int m=graph[i].size();
        cout<<"Adjacent list of node "<<i<<": ";
        for(int j=0;j<m;j++)
        {
            cout<<"("<<graph[i][j].first<<","<<graph[i][j].second<<")";
        }
        cout<<endl;
    }
    dijkstra(5);

    for(int i=1;i<=node;i++)
    {
        cout<<"Distance from 5 "<<" to "<<i<<" "<<dis[i]<<endl;
    }
}

/*
5 9
1 2 3
2 1 2
1 3 8
1 4 5
2 3 1
3 4 4
4 3 5
5 1 2
5 2 7
*/
