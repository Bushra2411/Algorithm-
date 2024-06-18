#include<iostream>
#include<vector>
using namespace std;
vector<int>adjacent[100];
void directed_graph(int node,int edge)
{
    int u,v;
    for(int i=0;i<edge;i++)
    {
        cout<<"Construct Edge "<<i+1<<":";
        cin>>u>>v;
        adjacent[u].push_back(v);
    }
    cout<<"\nPrinting Adjacency List for each Node:\n";
    for(int i=1;i<=node;i++)
    {
        cout<<"The Adjacency list for each node"<<i<<"->";
        for(int j=0;j<adjacent[i].size();j++)
        {
            cout<<adjacent[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void undirected_graph(int node,int edge)
{
    int u,v;
    for(int i=0;i<edge;i++)
    {
        cout<<"Construct edge"<<i+1<<":";
        cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    cout<<"\nThe printing adjacency list for each node:\n";
    for(int i=1;i<=node;i++)
    {
        cout<<"the adjacency list for nodes"<<i<<"->";
        for(int j=0;j<adjacent[i].size();j++)
        {

            cout<<adjacent[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int node,edge;
    cout<<"enter number of nodes: ";
    cin>>node;
    cout<<"enter number of edges: ";
    cin>>edge;
    cout << "\nCreate your graph:\n";
    directed_graph(node, edge);
    return 0;
}
