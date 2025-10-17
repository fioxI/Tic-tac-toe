int verif_win_col(char ** grille) {
    int win = 0;

    for (int i = 0; i < 3; i++) {
        if (grille[0][i] != '.') {
            if ((grille[0][i] == grille[1][i]) && (grille[0][i] == grille[2][i])) {
                if (grille[0][i] == '0') {
                    win = 1;
                } else {
                    win = 2;
                }
                
            }
        }
    }

    return win;
}

int verif_win_line(char ** grille) {
    int win = 0;

    for (int j = 0; j < 3; j++) {
        if (grille[j][0] != '.') {
            if ((grille[j][0] == grille[j][1]) && (grille[j][0] == grille[j][2])) {
                if (grille[j][0] == '0') {
                    win = 1;
                } else {
                    win = 2;
                }
                
            }
        }
    }

    return win;
}

int verif_win_diag(char ** grille) {
    int win = 0;

    if (grille[0][0] != '.') {
        if ((grille[0][0] == grille[1][1]) && (grille[0][0] == grille[2][2])) {
            if (grille[0][0] == '0') {
                win = 1;
            } else {
                win = 2;
            }
        }
    }
    if (grille[0][2] != '.') {
        if ((grille[0][2] == grille[1][1]) && (grille[0][2] == grille[2][0])) {
            if (grille[0][2] == '0') {
                win = 1;
            } else {
                win = 2;
            }
        }
    } 

    return win;
}

int verif_win(char ** grille) {
    int win = verif_win_col(grille);

    if (win == 0) {

        win = verif_win_line(grille);

        if (win == 0) {

            win = verif_win_diag(grille);
        }
    }

    return win;
}

int grille_full(char ** grille) {
    int full = 1;
    int i = 0;
    int j;

    while ((i < 3) && (full == 1)) {

        j = 0;

        while ((j < 3) && full == 1) {
            if (grille[i][j] == '.') {
                full = 0;
            }
            j++;
        }
        i++;
    }

    return full;
}