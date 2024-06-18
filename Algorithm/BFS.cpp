#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int>adjacent[100];
int visited[150],par[150];
void undirected(int node,int edge)
{
    int u,v;
    for(int i=0;i<edge;i++){
        cout<<"Construct Edge "<<i+1<<"->";
        cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    cout<<"\nPrinting Adjacency lists for each nodes: \n";
    for(int i=1;i<=node;i++){
        cout<<"the adjacency list for nodes "<< i <<"->";
        for(int j=0;j<adjacent[i].size();j++){
            cout<<adjacent[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void initialization()
{
    for(int i=0;i<105;i++)
    {
        visited[i]=0;
        par[i]=0;
    }
}
void printing_path(int source,int destination)
{
    if(source==destination)
    {
        cout<<" "<<source;
    }
    else if(par[destination]==0)
    {
        cout<<"No path here...";
    }
    else
    {
        printing_path(source,par[destination]);
        cout<<" "<<destination;
    }
}



void BFS(int start)
{
    initialization();
    queue<int>Q;

    Q.push(start);
    visited[start]=1;

    int u,v;

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        cout << "\nThe visited Nodes are: ";
        cout<< u <<" ";
        for(int i=0;i<adjacent[u].size();i++)
        {
            v=adjacent[u][i];
            if(visited[v]==0){
                Q.push(v);
                visited[v]=1;
                par[v]=u;
            }
        }
    }
}

int main()
{
    int node,edge;
    cout<<"enter number of nodes: ";
    cin>>node;
    cout<<"enter number of edges: ";
    cin>>edge;
    cout<<"\nCreate your graph: \n";
    undirected(node,edge);

    cout<<"\nenter a starting node to run bfs: ";
    int start;
    cin>>start;
    cout<<"\n\nrunning bsf...\n\n";
    BFS(start);


    int destination;
    cout<<"\n\nenter your destination node to see the path: ";
    cin>>destination;
    printing_path(start,destination);
    cout<<"\n\nstop bfs...\n\n";
    return 0;
}

