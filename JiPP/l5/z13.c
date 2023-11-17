#include <stdio.h>

int getCharPos(char *text, char c) { // -1 if not found
    char d;
    int i = 0;
    while ((d = *text) != '\0') {
        if (d == c) {
            return i;
        }
        i++;
        text++;
    }
    return -1;
}

int main() {
    char *text = "Ala ma kota";
    char a = ' ';
    int n = getCharPos(text, a);

    printf("znaleziono znak: %c, na pozycji: %d ", a, n);
    return 0;
}