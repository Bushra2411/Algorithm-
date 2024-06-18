
#include<iostream>
using namespace std;
const int s=100;
int parents[s];
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

void unionn(int a,int b)
{
    int u=findd(a);
    int v=findd(b);
    if(u==v)
    {
        return;
    }
    else
    {
        parents[v]=u;
        parents[u]=v;
    }
}

int main()
{
    int numNodes,numRelation,a,b;
    cout<<"enter number of nodes and number of relations: ";
    cin>>numNodes>>numRelation;
    make_set(numNodes);
    int rel=0;
    cout<<"enter the node: \n";
    while(numRelation)
    {
        cout<<"Relation-"<<rel+1<<":";
        cin>>a>>b;
        unionn(a,b);
        rel++;
    }
    int componment=0;
    for(int i=1;i<=numNodes;i++)
    {
        cout<< i <<"\n";
        if(findd(i)==i)
        {
            componment++;
        }
    }
    cout<<"\nTotal subgraph= "<<componment<<"\n";
    return 0;
}
