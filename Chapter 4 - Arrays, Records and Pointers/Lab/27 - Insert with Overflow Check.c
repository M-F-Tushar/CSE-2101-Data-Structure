#include<stdio.h>
int main(){
    int A[5]={1,2,3,4},n=4,x;
    scanf("%d",&x);
    if(n==5) printf("Full");
    else{ A[n++]=x; for(int i=0;i<n;i++) printf("%d ",A[i]); }
}
