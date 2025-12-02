#include<stdio.h>

int main()
{
    int A[5]={1,2,3,4,5},*p;

    for(p=A;p<A+5;p++) 
    {
        printf("%d ",*p);
    }
}
