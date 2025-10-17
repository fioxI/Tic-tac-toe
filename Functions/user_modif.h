#ifndef __USER_MODIF_H__
#define __USER_MODIF_H__

void request_to_player(int player, int coordone[], char ** grille);
void add_symbole(char ** grille, int i, int j, int joueur);
void selection_player(int * player, int * bot);

#endif