#include <stdio.h>
#include <stdlib.h>
#include "string_modif.h"

void print_game(char ** grille)
{
    int i = 0;

    while (grille[i] != NULL) {

        int j = 0;

        while (grille[i][j+1] != '\0') {
            printf("%c | ", grille[i][j]);
            j++;
        }
        printf("%c\n", grille[i][j]);
        
        i++;
    }
}

char ** grille_creation() {
    char ** grille = malloc(4 * sizeof(*grille));
    for (int x = 0; x < 3; x++) {
        grille[x] = str_cpy("...");
    }
    grille[3] = NULL;
  
    return grille;
}