#include<stdio.h>
int main(){
    int A[10]={1,2,3,4,5},n=5,i,x; 

    scanf("%d",&x);

    for(i=n-1;i>=0;i--) 
    {
        A[i+1]=A[i];
    }
    
    A[0]=x; n++;

    for(i=0;i<n;i++) 
    {
        printf("%d ",A[i]);
    }
}
