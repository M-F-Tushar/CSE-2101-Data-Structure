#include<stdio.h>
int main()
{
    int A[5]={1,2,3,4,5},i;

    for(i=0;i<4;i++) 
    {
        A[i]=A[i+1];   // left shift
    }
    for(i=4;i>0;i--) 
    {
        A[i]=A[i-1];   // right shift
    }
    for(i=0;i<5;i++) 
    {
        printf("%d ",A[i]);
    }
}
