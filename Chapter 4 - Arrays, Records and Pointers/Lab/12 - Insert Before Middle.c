#include<stdio.h>
int main(){
    int A[10]={1,2,3,4,5},n=5,i,x,pos;

    scanf("%d",&x);

    pos=n/2-1;

    for(i=n-1;i>=pos;i--) 
    {
        A[i+1]=A[i];
    }

    A[pos]=x; n++;

    for(i=0;i<n;i++) 
    {
        printf("%d ",A[i]);
    }
}
