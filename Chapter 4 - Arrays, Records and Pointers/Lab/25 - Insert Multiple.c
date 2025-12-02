#include<stdio.h>
int main()
{
    int A[20]={1,2,3,4,5},n=5,i,x,pos,k;

    for(k=0;k<3;k++)
    {
        scanf("%d %d",&x,&pos);

        for(i=n-1;i>=pos;i--) 
        {
            A[i+1]=A[i];
        }

        A[pos]=x; n++;
    }
    
    for(i=0;i<n;i++) 
    {
        printf("%d ",A[i]);
    }
}
