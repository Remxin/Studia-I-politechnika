#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

int moje_strcmp(char *text, char *text2) { // 1 jesli zle, 0 jesli dobre
    int i = 0;
    if (strlen(text) != strlen(text2)) return 1;


    while (text[i] != '\0') {
       if (text[i] != text2[i]) return 1;
       i++;
    }

    return 0;
}

char *moje_strcat(char *text, char *add) {
    int i = (int) strlen(text);
    int j = 0;
    char d;
    while ((d = add[j]) != '\0') {
        text[i] = d;
        j++;
        i++;
    }
    text[i] = '\0';

    return text;
}

char *moje_strcpy(char *src, char *dest) {
    int i = 0;
    char d;
    while ((d = src[i]) != '\0') {
        dest[i] = d;
        i++;
    }
    return dest;
}



int main() {
    char text[MAX_LINE] = "Ala ma kota";
    char text2[MAX_LINE] = "Ala ma kota";
    char text3[MAX_LINE];

    int good_strcmp = moje_strcmp(text, text2); // dziala


    printf("wynik strcmp: %d\n", good_strcmp);
    printf("wynik strcat po dodaniu ' i psa': %s\n", moje_strcat(text, " i psa"));
    printf("wynik strcpy: %p\n", moje_strcpy(text, text3));
    return 0;
}