#include<stdio.h>
int main()
{
    int A[10]={1,2,2,3,2},n=5,i,j;

    int x; scanf("%d",&x);

    for(i=0;i<n;i++)
    {
        if(A[i]==x)
        {
            for(j=i;j<n-1;j++) A[j]=A[j+1];
            n--; i--;
        }
    }
    for(i=0;i<n;i++) 
    {
        printf("%d ",A[i]);
    }
}
