#ifndef __TIC_TAC_TOE_H__
#define __TIC_TAC_TOE_H__

void print_game(char ** grille);
char ** grille_creation();
void grille_cleaning(char ** grille);
void win_message(int win, int player, int bot);

#endif