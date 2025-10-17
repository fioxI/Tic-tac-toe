#include <stdlib.h>

int str_len(char *str){
    int compteur = 0;
    char ch = str[compteur];

    while (ch != '\0') {
        compteur++;
        ch = str[compteur];
    }

    return compteur;
}

char * str_cpy(char * str)
{
    const int len_str = str_len(str);

    char * str2 = malloc( (len_str+1) * sizeof(char));

    for (int x = 0; x < len_str; x++) {
        str2[x] = str[x];
    }
    
    return str2;
}