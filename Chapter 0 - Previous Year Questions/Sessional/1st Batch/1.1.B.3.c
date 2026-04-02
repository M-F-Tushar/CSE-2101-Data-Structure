/*
  Write a program to translate merge sort into a subprogram 
  MERGESORT(A, N) for a N-elements array A. (60)  
*/
#include<stdio.h>

void Merge(int A[], int first, int mid, int last)
{
    int T[100];
    int i = first, j = mid + 1, k = first;

    while(i <= mid && j <= last)
    {
        if(A[i] < A[j])
        {
            T[k++] = A[i++];
        }
        else
        {
            T[k++] = A[j++];
        }
    }

    while(i <= mid)
    {
        T[k++] = A[i++];
    }

    while(j <= last)
    {
        T[k++] = A[j++];
    }

    for(int i = first; i <= last; i++)
    {
        A[i] = T[i];
    }

}

void Mergesort(int A[], int first, int last)
{
    if(first >= last)
    {
        return;
    }

    int mid = (first + last) / 2;

    Mergesort(A, first, mid);
    Mergesort(A, mid + 1, last);
    Merge(A, first, mid, last);

}


int main()
{
    int A[] = {18, 26, 32, 6, 43, 15, 9, 1};
    int N = 8;

    printf("Before: ");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }

    Mergesort(A, 0, N - 1);

    printf("\nAfter: ");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;

}
