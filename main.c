#include <stdlib.h>
#include <stdio.h>
#include "Functions/grille_modif.h"
#include "Functions/string_modif.h"
#include "Functions/user_modif.h"
#include "Functions/verification.h"
#include "Functions/bot.h"

int main()
{
    int player = 0;
    int bot = 0;
    int win = 0;
    int x;
    int coordone[2];
    char ** grille = grille_creation();

    system("clear");
    printf("Bienvenue sur mon tic tac toe !\n\n");
    selection_player(&player, &bot);
    printf("Pour jouer vous allez devoir entre le numero de la case choisie.\n\n1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n\n");

    while (win == 0) {

        // Player part
        print_game(grille);

        request_to_player(player, coordone, grille);

        add_symbole(grille, coordone[0], coordone[1], player);

        win = verif_win(grille);

        if (win == 0) {
            if (grille_full(grille) == 1) {
                win = 3;
            }
        }
        
        system("clear");

        // Bot part
        if (win == 0) {
            print_game(grille);

            request_to_bot(player, coordone, grille);

            add_symbole(grille, coordone[0], coordone[1], bot);

            win = verif_win(grille);

            if (win == 0) {
                if (grille_full(grille) == 1) {
                    win = 3;
                }
            }
            
            system("clear");
        }
    }

    print_game(grille);

    if (win == 1) {
        printf("Bravo joueur !\n");
    } else if (win == 2) {
        printf("Bravo bot !\n");
    } else if (win == 3) {
        printf("Egalite !\n");
    } else {
        printf("Petit probleme technique !\n");
    }

    int i = 0;
    while (grille[i] != NULL) {
        free(grille[i]);
        i++;
    }
    free(grille);

	exit(0);
}