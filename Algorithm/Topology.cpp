#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int w=0,g=1,b=-1;
vector<int>adjacencyList[100];
vector<int>topo_order;
void DFS(int color[],int u)
{
    color[u]=g;
    for(int i=0;i<adjacencyList[u].size();i++)
    {
        int v=adjacencyList[u][i];
        if(color[v]==w)
        {
            DFS(color,v);
        }
    }
    color[u]=b;
    topo_order.push_back(u);
}

void TopologicalSort(int numTasks)
{
    int color[numTasks+1];
    for(int i=1;i<=numTasks;i++)
    {
        color[i]=w;
    }
    for(int i=1;i<numTasks;i++)
    {
        if(color[i]==w)
        {
            DFS(color,i);
        }
    }
    reverse(topo_order.begin(),topo_order.end());
    cout<<"\nThe order of task is:\n";
    cout<<topo_order[0];
    for(int i=1;i<topo_order.size();i++)
    {
        cout<<"->"<<topo_order[i];
    }
}

int main()
{
    int numTasks,relations;
    cout<<"enter numbers of tasks and number of their relation:";
    cin>>numTasks>>relations;
    for(int i=0;i<relations;i++)
    {
        cout<<"\nenter relation "<<i+1<<" ";
        int u,v;
        cin>>u>>v;
        adjacencyList[u].push_back(v);
    }
    TopologicalSort(numTasks);
    return 0;
}
