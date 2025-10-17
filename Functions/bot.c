#include <stdlib.h>
#include <time.h>

void request_to_bot(int player, int coordone[], char ** grille) {
    srand(time(NULL));

    int i;
    int j;

    do {
        i = rand() % 3;
        j = rand() % 3;
    } while (grille[i][j] != '.');

    coordone[0] = i;
    coordone[1] = j;
}