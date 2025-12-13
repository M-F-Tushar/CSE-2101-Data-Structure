/*
Example 4.22

Newborn file stored as parallel arrays and demonstrate accessing father age and mother name.
*/

#include <stdio.h>

int main(void) {
    const char *Name[] = {"Sam","Lia","Omar"};
    const char *Mother[] = {"Anna","Bella","Carla"};
    const char *Father[] = {"John","Karl","Moe"};
    int MotherAge[] = {28, 32, 26};
    int FatherAge[] = {30, 35, 29};

    int k = 1;
    printf("Record %d -> Mother: %s, Father age: %d\n", k, Mother[k], FatherAge[k]);
    return 0;
}
