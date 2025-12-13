/*
Example 4.4

Traverse an array of year->value pairs, count how many years meet a condition,
and print the matching year/value pairs.
*/

#include <stdio.h>

int main(void) {
    int years[] = {2000, 2001, 2002, 2003, 2004};
    int values[] = {5, 12, 8, 15, 7};
    int n = sizeof(years) / sizeof(years[0]);
    int threshold = 10;

    printf("Years with value > %d:\n", threshold);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (values[i] > threshold) {
            printf("%d : %d\n", years[i], values[i]);
            count++;
        }
    }
    printf("Total matching years: %d\n", count);

    return 0;
}
