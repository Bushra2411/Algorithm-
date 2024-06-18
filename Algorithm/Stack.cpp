
#include<iostream>
#include<stack>
using namespace std;
stack <int>s;

int main()
{
    int n,x;
    cin>>n;

    cout<<"inputs: ";
    for(int i=0;i<n;i++){
        cin>>x;
        s.push(x);
    }
    cout<<"output: ";
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
