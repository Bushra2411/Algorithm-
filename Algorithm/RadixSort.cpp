#include<iostream>
using namespace std;
int getMax(int a[],int n)
{
    int Max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>Max){
            Max=a[i];
        }
    }
    return Max;
}
void CountSort(int a[],int n,int pos)
{
    int i;
    int output[n];
    int Count[10]={0};
    for(i=0;i<n;i++){
        Count[(a[i]/pos)%10]++;
    }
    for(i=1;i<10;i++){
        Count[i]=Count[i]+Count[i-1];
    }
    for(i=n-1;i>=0;i--){
        output[Count[(a[i]/pos)%10]-1]=a[i];
        Count[(a[i]/pos)%10]--;
    }
    for(i=0;i<n;i++)
        a[i]=output[i];
}

void Radixsort(int a[],int n)
{
    int h=getMax(a,n);
    for(int pos=1;h/pos>0;pos*=10){
        CountSort(a,n,pos);
    }
}

int main()
{
    int a[]={121,432,564,23,1,788};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"before radix:"<<"\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    Radixsort(a,n);
    cout<<"\n"<<"after redix sort: "<<"\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
