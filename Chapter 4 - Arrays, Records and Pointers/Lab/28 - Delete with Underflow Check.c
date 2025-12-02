#include<stdio.h>
int main(){
    int A[5]={1},n=1;
    if(n==0) printf("Empty");
    else n--;
    for(int i=0;i<n;i++) printf("%d ",A[i]);
}
