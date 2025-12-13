/*
Example 4.15

Demonstrate pointer-array style grouping: print group L using GROUP array indices.
GROUP contains start indices of groups in NAMES.
*/

#include <stdio.h>

int main(void) {
    const char *NAMES[] = {"Ann","Ben","Cara","Dan","Eve","Finn","Gail"};
    int GROUP[] = {0, 3, 5, 7}; /* 3 groups: [0..2], [3..4], [5..6] */
    int L = 2; /* print 2nd group (index 1-based) */

    int g = L - 1; /* zero-based group index */
    int start = GROUP[g];
    int end = GROUP[g+1];

    printf("Group %d: ", L);
    for (int i = start; i < end; ++i) printf("%s ", NAMES[i]);
    printf("\n");
    return 0;
}
