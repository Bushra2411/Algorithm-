#include<iostream>
using namespace std;
int Partition(int arr[],int l,int h)
{
    int pivot=arr[h];
    int i=(l-1);
    for(int j=l;j<=h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}
void quicksort(int arr[],int l,int h)
{
    if(l<h){
        int pi=Partition(arr,l,h);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
}

int main()
{
    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    cout<<"sorted array\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
