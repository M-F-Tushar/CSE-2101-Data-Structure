/*
Example 4.18

Student record example with arrays representing file of records and accessing Test[6,2].
*/

#include <stdio.h>

int main(void) {
    int Test[7][3] = {
        {70, 72, 74},
        {75, 77, 79},
        {80, 82, 84},
        {85, 87, 89},
        {90, 92, 94},
        {95, 97, 99},
        {88, 86, 84}
    };

    printf("Test[6][2] = %d\n", Test[6][2]);
    return 0;
}
