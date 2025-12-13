/*
Example 4.16

Variant with NUMB and GROUP arrays: GROUP holds concatenated items, NUMB holds
start offsets per group. Print Lth group using NUMB offsets.
*/

#include <stdio.h>

int main(void) {
    const char *GROUP[] = {"Ann","Ben","Cara","Dan","Eve","Finn","Gail"};
    int NUMB[] = {0, 3, 5, 7};
    int L = 3; /* print 3rd group */

    int g = L - 1;
    int start = NUMB[g];
    int end = NUMB[g+1];

    printf("Group %d: ", L);
    for (int i = start; i < end; ++i) printf("%s ", GROUP[i]);
    printf("\n");
    return 0;
}
