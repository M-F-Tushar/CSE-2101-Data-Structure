/*
Example 4.6

Show insertion and deletion in the middle of an array using shifting; use names
so output is clear.
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char names[6][20] = {"Ana", "Bob", "Carl", "Dana", "Eli"};
    int n = 5;

    printf("Original list:\n");
    for (int i = 0; i < n; ++i) printf("%d: %s\n", i, names[i]);

    /* Insert "Zoe" at position 2 */
    int pos = 2;
    if (n < 6) {
        for (int j = n; j > pos; --j) strcpy(names[j], names[j-1]);
        strcpy(names[pos], "Zoe");
        n++;
        printf("\nAfter insertion at %d:\n", pos);
        for (int i = 0; i < n; ++i) printf("%d: %s\n", i, names[i]);
    }

    /* Delete element at position 3 */
    int del = 3;
    for (int j = del; j < n-1; ++j) strcpy(names[j], names[j+1]);
    n--;
    printf("\nAfter deletion at %d:\n", del);
    for (int i = 0; i < n; ++i) printf("%d: %s\n", i, names[i]);

    return 0;
}
