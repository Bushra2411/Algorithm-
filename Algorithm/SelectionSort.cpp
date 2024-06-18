#include<iostream>
#include<conio.h>
using namespace std;
void ssort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        int minValue=a[i];
        int minInd=0;
        for(j=i+1;j<n;j++){
            if(minValue>a[j]){
                minValue=a[j];
                minInd=j;
            }
        }
        int temp=a[minInd];
        a[minInd]=a[i];
        a[i]=temp;
    }
}

int main()
{
    int a[]={6,4,8,3,1};
    int n=sizeof(a)/sizeof (a[0]);
    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }
    cout<<"\n";
    ssort(a,n);
    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }
}
