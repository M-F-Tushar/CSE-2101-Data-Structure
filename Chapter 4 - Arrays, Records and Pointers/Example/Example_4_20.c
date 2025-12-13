/*
Example 4.20

Demonstrate variable-length records using PTR and NUMB arrays with sibling listing example.
*/

#include <stdio.h>

int main(void) {
    const char *SIBS[] = {"Ann","Ben","Cara","Dan","Eve","Finn","Gail"};
    int PTR[] = {0, 2, 5}; /* 3 families */
    int NUMB[] = {2, 3, 2};

    int family = 2; /* print second family */
    int start = PTR[family-1];
    int count = NUMB[family-1];

    printf("Family %d siblings: ", family);
    for (int i = 0; i < count; ++i) printf("%s ", SIBS[start + i]);
    printf("\n");
    return 0;
}
