#include<stdio.h>
int main(){
    int A[5]={3,9,1,8,2},i,min=A[0],max=A[0];
    for(i=1;i<5;i++)
    { 
        if(A[i]<min)
        {
            min=A[i];
        }
        if(A[i]>max)
        {
            max=A[i];
        }
    }
    printf("%d %d",min,max);
}
