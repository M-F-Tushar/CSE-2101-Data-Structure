#include <stdio.h>

void TOWER(int N, char BEG, char AUX, char END)
{
    if (N == 1)
    {
        printf("%c --> %c\n", BEG, END);
        return;
    }

    TOWER(N - 1, BEG, END, AUX);

    printf("%c --> %c\n", BEG, END);

    TOWER(N - 1, AUX, BEG, END);
}

int main()
{
    int N = 3;

    printf("Towers of Hanoi with %d disks:\n\n", N);
    TOWER(N, 'A', 'B', 'C');
    printf("\nTotal Moves: %d\n", (1 << N) - 1);

    return 0;
}
