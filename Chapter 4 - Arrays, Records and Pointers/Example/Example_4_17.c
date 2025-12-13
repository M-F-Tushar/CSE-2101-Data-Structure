/*
Example 4.17

Show record structure for Newborn as a C struct and example initialization/print.
*/

#include <stdio.h>

typedef struct {
    char name[20];
    char mother[20];
    char father[20];
    int mother_age;
    int father_age;
    int birth_weight;
} Newborn;

int main(void) {
    Newborn nb = {"Sam","Anna","John",28,30,3200};
    printf("Newborn %s: mother %s (%d), father %s (%d), weight %d g\n",
           nb.name, nb.mother, nb.mother_age, nb.father, nb.father_age, nb.birth_weight);
    return 0;
}
