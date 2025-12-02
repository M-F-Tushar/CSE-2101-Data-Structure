#include<stdio.h>

int main()
{
    int A[5]={1,2,3,4,5},x,i;
    
    scanf("%d",&x);

    for(i=0;i<5;i++) 
    {
        if(A[i]>x) break;
        printf("%d",i==5?-1:i);
    }
    
}
