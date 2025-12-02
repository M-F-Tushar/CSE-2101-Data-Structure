#include<stdio.h>
int main(){
    int A[10]={1,3,5,7,9},n=5,i,x;

    scanf("%d",&x);
    
    for(i=n-1;i>=0 && A[i]>x;i--) 
    {
        A[i+1]=A[i];
    }

    A[i+1]=x; n++;

    for(i=0;i<n;i++) 
    {
        printf("%d ",A[i]);
    }
}
