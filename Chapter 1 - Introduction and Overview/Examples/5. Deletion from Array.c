#include <stdio.h>

int main() {
    int a[4]={10,20,30,40}, n=4;
    for (int i=1;i<n-1;i++) 
    {
        a[i]=a[i+1];
    }
    
    n--;

    for (int i=0;i<n;i++) 
    {
        printf("%d ",a[i]);
    }
    return 0;
}
