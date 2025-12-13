/*
Example 4.21

Parallel arrays membership list example and print record K.
*/

#include <stdio.h>

int main(void) {
    const char *MemberName[] = {"Ali","Bora","Cem","Derya"};
    int MemberId[] = {101, 102, 103, 104};
    int K = 3;
    printf("Record %d -> Id: %d, Name: %s\n", K, MemberId[K], MemberName[K]);
    return 0;
}
