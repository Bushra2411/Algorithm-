
#include<iostream>
#include<vector>
using namespace std;

const int w=0,g=1,b=-1,h=100;

vector<int>adjacent[100];
int color[h],time=0,starting_time[h],finishing_time[h];
void directed(int node,int edge)
{
    int u,v;
    for(int i=0;i<edge;i++)
    {
        cout<<"Construct Edge "<<i+1<<"->";
        cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    cout<<"\nPrinting adjacent list for each node: \n";
    for(int i=1;i<=node;i++)
    {
        cout<<"the adjacency list for node "<<i<<"->";
        for(int j=0;j<adjacent[i].size();j++)
        {
            cout<<adjacent[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void undirected(int node,int edge)
{
    int u,v;
    for(int i=0;i<edge;i++)
    {
        cout<<"construct Edge "<<i+1<<"->";
        cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    cout<<"\nprinting adjacent list for each node: \n";
    for(int i=0;i<=node;i++)
    {
        cout<<"the adjacency list for node: "<<i<<"->";
        for(int j=0;j<adjacent[i].size();j++)
        {
            cout<<adjacent[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void initialization()
{
    for(int i=0;i<101;i++)
    {
        color[i]=w;
    }
}
void DFS_visit(int u)
{
    int v;
    color[u]=g;
    time+=1;
    starting_time[u]=time;
    for(int i=0;i<adjacent[u].size();i++)
    {
        v=adjacent[u][i];
        if(color[v]==w)
        {
            DFS_visit(v);
        }
    }
    color[u]=b;
    time+=1;
    finishing_time[u]=time;
    cout<<u<<" ";
}

void DFS(int node)
{
    initialization();
    for(int i=0;i<node;i++)
    {
        if(color[i]==w)
        {
            DFS_visit(i);
        }
    }
    cout<<"\n\nstarting and finishing time of nodes:\n";
    for(int i=0;i<node;i++)
    {
        cout<<"node "<< i <<" "<<"starting_time:"<< starting_time[i ]<<" "<<"finishing_time"<< finishing_time[i] <<"\n";
    }
}

int main()
{
    int node,edge;
    cout<<"enter no of node: ";
    cin>>node;
    cout<<"enter no of edge: ";
    cin>>edge;
    cout<<"\nCreate your graph: \n";
    undirected(node,edge);
    cout<<"\nVisited nodes are: ";
    DFS(node);
    return 0;
}
