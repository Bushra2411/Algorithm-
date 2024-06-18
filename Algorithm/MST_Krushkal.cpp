#include<bits/stdc++.h>
using namespace std;

const int s=100;
int parents[s];
struct node
{
    int u,v,w;
    node(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
    bool operator <(const node &p) const
    {
        return w<p.w;
    }
};

vector<node>edges;
void make_set(int numNodes)
{
    for(int i=1;i<=numNodes;i++)
    {
        parents[i]=i;
    }
}
int findd(int r)
{
    if(parents[r]==r)
    {
        return r;
    }
    else
    {
        return parents[r]=findd(parents[r]);
    }
}

void krushkal(int numNodes)
{
    sort(edges.begin(),edges.end());
    int sum=0,numEdges=0,selectedEdges=0;
    for(int i=0;i<edges.size();i++)
    {
        int u=findd(edges[i].u);
        int v=findd(edges[i].v);
        if(u!=v)
        {
            cout<<"selected edge"<<selectedEdges+1<<":";
            cout<<edges[i].u<<" "<<edges[i].v<<"\n";
            selectedEdges++;
            parents[u]=v;
            sum+=edges[i].w;
            numEdges+=1;
            if(numEdges==numNodes-1)
            {
                break;
            }
        }
    }
    cout<<"\nthe weight of the mst is: "<<sum<<"\n";
}

int main()
{
    int numNodes,numEdges,a,b,w;
    cout<<"enter number of nodes and edges:";
    cin>>numNodes>>numEdges;
    make_set(numNodes);
    cout<<"\nenter edges and weights:\n";
    for(int i=1;i<=numEdges;i++)
    {
        cout<<"edges "<<i<<":";
        cin>>a>>b>>w;
        edges.push_back(node(a,b,w));
    }
    krushkal(numNodes);
    return 0;
}
