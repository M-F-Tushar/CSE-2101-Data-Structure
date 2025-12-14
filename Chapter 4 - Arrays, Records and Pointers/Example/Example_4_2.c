/*
Example 4.2

Show common array declarations in other languages and the equivalent in C.
Provide a simple C program demonstrating static array declarations and access.
*/

#include <stdio.h>

int main() 
{
    int numbers[5] = {1, 2, 3, 4, 5};
    char name[6] = "Alice";

    printf("Integers: ");
    for (int i = 0; i < 5; ++i) 
        printf("%d ", numbers[i]);
    printf("\nName: %s\n", name);

    return 0;
}

