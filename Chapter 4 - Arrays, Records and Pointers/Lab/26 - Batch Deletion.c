#include<stdio.h>
int main()
{
    int A[20]={1,2,3,4,5,6,7},n=7,i,pos,k;

    for(k=0;k<3;k++)
    {
        scanf("%d",&pos);

        for(i=pos;i<n-1;i++) 
        {
            A[i]=A[i+1];
        }
        n--;
    }

    for(i=0;i<n;i++) 
    {
        printf("%d ",A[i]);
    }
}
