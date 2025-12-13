/*
Example 4.11

Show 2D array (matrix) declaration and access (student scores example).
*/

#include <stdio.h>

int main(void) {
    int scores[3][4] = {
        {85, 90, 78, 92},
        {88, 76, 95, 89},
        {91, 82, 87, 90}
    };

    printf("Scores matrix (3 students x 4 tests):\n");
    for (int i = 0; i < 3; ++i) {
        printf("Student %d: ", i);
        for (int j = 0; j < 4; ++j) printf("%d ", scores[i][j]);
        printf("\n");
    }

    printf("\nAccess scores[1][2] = %d\n", scores[1][2]);
    return 0;
}
