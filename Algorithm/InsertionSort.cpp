#include<iostream>
#include<conio.h>
using namespace std;
void isort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++){
            int key=a[i];
             j=i-1;
        while (j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
         a[j+1] = key;
        }
         for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
    }

}

int main()
{
    int a[]={9,4,6,3,1};
    int n=sizeof (a)/ sizeof (a[0]);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    isort(a,n);



}
