#include<stdio.h>
int main(){
    int A[10]={1,2,2,3,3,4},n=6,i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            if(A[i]==A[j])
            {
                for(k=j;k<n-1;k++) A[k]=A[k+1];
                n--; j--;
            }
    }
    for(i=0;i<n;i++) 
    {
        printf("%d ",A[i]);
    }
}
