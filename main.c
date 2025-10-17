#include <stdlib.h>
#include <stdio.h>
#include "Functions/tic-tac-toe.h"
#include "Functions/string_modif.h"
#include "Functions/user_modif.h"
#include "Functions/verification.h"
#include "Functions/bot.h"

int main()
{
    int player = 0;
    int bot = 0;
    int win;
    int coordone[2];
    char play;
    char ** grille;

    do {
        win = 0;

        system("clear");
        printf("Bienvenue sur mon tic tac toe !\n\n");
        selection_player(&player, &bot);
        printf("Pour jouer vous allez devoir entre le numero de la case choisie.\n\n1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n\n");

        printf("win : %d | player : %d | bot : %d\n", win, player, bot);
        grille = grille_creation();

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

        win_message(win, player, bot);

        grille_cleaning(grille);

        int i = 0;
        while (grille[i] != NULL) {
            free(grille[i]);
            i++;
        }
        free(grille);

        while (getchar() != '\n') {}

        printf("Si vous voulez rejouer entre 'y' sinon tout autre chose.\n");
        scanf("%c", &play);

    } while (play == 'y');
	exit(0);
}