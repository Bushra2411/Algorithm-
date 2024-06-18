#include<iostream>
#include<conio.h>
using namespace std;
void cumsum(int Count[],int n)
{
    int i=1;
    while(i<n){
        Count[i]+=Count[i-1];
        i++;
    }
}

int findMaxNum(int a[],int n)
{
    int Max=a[0];
    for(int i=1;i<n;i++){
        if(Max<a[i]){
            Max=a[i];
        }
    }
    return Max;
}

void countingSort(int a[],int n)
{
    int Max=findMaxNum(a,n);
    int Count [Max+1]={0},i=0;

    while(i<n){
        Count[a[i]]+=1;
        i++;
    }

    cumsum(Count,Max+1);

    int output[n];
    for(int i=0;i<n;i++){
        output[Count[a[i]]-=1]=a[i];
    }
    cout<<"after sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<output[i];
    }
}

int main()
{
    int a[]={5,9,1,3,10,55,7};
    int n=sizeof (a) / sizeof (a[0]);
    cout<<"initial array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }
    cout<<"\n";
    countingSort(a,n);

}
