/*
Example 4.19

Show qualified field access and parallel arrays usage demonstration.
*/

#include <stdio.h>

int main(void) {
    const char *Name[] = {"Ann","Ben","Cara"};
    int Age[] = {21, 19, 22};
    const char *City[] = {"Dhaka","Chittagong","Khulna"};

    int k = 1; /* record index */
    printf("Record %d -> Name: %s, Age: %d, City: %s\n", k, Name[k], Age[k], City[k]);
    return 0;
}
