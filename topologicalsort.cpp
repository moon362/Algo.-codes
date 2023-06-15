#include<bits/stdc++.h>
using namespace std;
#define Mx 50

vector<int>graph[Mx];
queue<int>q;
int dis[Mx];
int start[Mx];
int finish[Mx];
int T=0;

void dfs(int u)
{
    ++T;
    start[u]=T;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v=graph[u][i];
        if(start[v]==0)
        {
            dfs(v);
        }

    }

    ++T;
    finish[u]=T;

}

string nodeName[]={"","undershots","shocks","pants","shoes","watch","shirt","belt","tie","jacket"};
map<string,int>M;
int main()
{
freopen("topoinput.txt","r",stdin);
    for(int i=1;i<=9;i++)
    {
        M[nodeName[i]]=i;
    }
    int node=9,edge=9,a,b;

    for(int i=1; i<=edge; i++)
    {
        string x,y;

        cin>>x>>y;
        a=M[x];
        b=M[y];
        graph[a].push_back(b );
        //graph[v].push_back(u);
    }
    for(int i=1; i<=node; i++)
    {
        cout<<"Adjacent list of node "<<i<<"=";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<=node;i++)
    {
        if(!start[i])
        {
            dfs(i);

        }

    }
    vector<pair<int,int> >topo;

    for(int k=1; k<=node; k++)
    {
         topo.push_back(make_pair(finish[k],k));
        cout<<"For "<<nodeName[k]<<" -> start time="<<start[k]<<" , finish time="<<finish[k]<<endl;
    }

    sort(topo.begin(),topo.end());

    for(int i=node-1;i>=0;i--)
    {
        cout<<topo[i].second<<" "<<nodeName[topo[i].second]<<endl;
    }






}

/*
undershots pants
pants belt
belt jacket
shirt belt
shirt tie
tie jacket
shocks shoes
undershots shoes
pants shoes
*/
