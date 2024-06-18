#include<iostream>
#include<queue>
using namespace std;
queue <int>q;

int main()
{
    int n,x;
    cin>>n;

    cout<<"inputs: ";
    for(int i=0;i<n;i++){
        cin>>x;
        q.push(x);
    }
    cout<<"output: ";
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}
