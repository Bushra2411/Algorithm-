#include<iostream>
#include<math.h>
using namespace std;
int BSR(int a[],int s,int key,int b,int e)
{
    int m;
    if(b>e){
        return -1;
    }
    else{
        m=(b+e)/2;
        if(a[m]==key)
            return m+1;

        else if(key>a[m])
            BSR(a,s,key,m+1,e);

        else
            BSR(a,s,key,b,m-1);

    }
}

int main()
{
   int a[] = {10,5,9,7,4};
    int s = sizeof(a) / sizeof(a[0]);

    int key = 4;
    int pos = BSR(a, s, key, 0, s-1);
    if(pos == -1)
        printf("Key not Found!\n");
    else
        printf("Key %d found at Position: %d\n", key, pos);
}
