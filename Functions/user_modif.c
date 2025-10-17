#include <stdio.h>

void request_to_player(int player, int coordone[], char ** grille) {
    int numero;
    int verif;

    do {
        printf("Joueur %d : ", player);
        verif = scanf("%d", &numero);

        while (verif == 0) {
            if ((numero < 1) || (numero > 9)){
                printf("Case invalide (entre 1 et 9) !\n");
                verif = scanf("%d", &numero);
            } else {
                verif = 1;
            }

            while (getchar() != '\n') {};
        }

        if (numero < 4) {
            coordone[0] = 0;
            coordone[1] = numero - 1;
        } else if (numero < 7) {
            coordone[0] = 1;
            coordone[1] = numero - 4;
        } else {
            coordone[0] = 2;
            coordone[1] = numero - 7;
        }

        if (grille[coordone[0]][coordone[1]] != '.') {
            printf("\nCase deja prise choisissez une autre case : ");
        }
    } while (grille[coordone[0]][coordone[1]] != '.');
}

void add_symbole(char ** grille, int i, int j, int joueur) {
    char symbole;

    if (joueur == 1) {
        symbole = '0';
    } else {
        symbole = 'X';
    }

    grille[i][j] = symbole;
}

void selection_player(int * player, int * bot) {
    int verif;
    int selection;

    printf("Choisissez votre symbole.\nLe joueur 1 (0) ou le joueur 2 (X) (entre 1 ou 2)\n");
    verif = scanf("%d", &selection);
    while (verif == 0) {
        printf("Entre invalide.\n");
        verif = scanf("%d", &selection);

        while (getchar() != '\n') {};
    }

    *player = selection;

    if (*player == 1) {
        *bot = 2;
    } else {
        *bot = 1;
    }
}