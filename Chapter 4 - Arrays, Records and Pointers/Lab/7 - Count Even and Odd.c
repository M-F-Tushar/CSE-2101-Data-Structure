#include<stdio.h>
int main(){
    int A[5]={1,2,3,4,5},i,even=0,odd=0;
    for(i=0;i<5;i++) 
    {
        if(A[i]%2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    printf("%d %d",even,odd);
}
