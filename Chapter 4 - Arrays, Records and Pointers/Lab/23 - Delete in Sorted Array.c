#include<stdio.h>
int main()
{
    int A[10]={1,3,5,7,9},n=5,i,x;

    scanf("%d",&x);

    for(i=0;i<n;i++) 
    {
        if(A[i]==x) break;
    }
    for(;i<n-1;i++) 
    {
        A[i]=A[i+1];
    }
    n--;

    for(i=0;i<n;i++) 
    {
        printf("%d ",A[i]);
    }
}
