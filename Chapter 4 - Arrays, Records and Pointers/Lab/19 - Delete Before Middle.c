#include<stdio.h>
int main()
{
    int A[10]={1,2,3,4,5},n=5,i,pos=n/2-1;

    for(i=pos;i<n-1;i++) 
    {
        A[i]=A[i+1];


    n--;

    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
