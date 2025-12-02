#include<stdio.h>
int main(){
    int A[5]={1,2,3,4,5},i,sum=0;
    for(i=0;i<5;i++) 
    {
        sum+=A[i];
    }
    printf("%d %.2f",sum,sum/5.0);
}
