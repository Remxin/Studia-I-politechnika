#include <stdio.h>

#define MAX_LINE 256

void deleteChar(char *text, char c) { // -1 if not found
    char d;
    int i = 0;
    char newStr[MAX_LINE];
    int done = 0;
    while ((d = text[i]) != '\0') {
        if (d == c && !done) {
            newStr[i] = ' ';
            done = 1;
        } else {
            newStr[i] = d;
        }
        i++;
    }
    newStr[i] = '\0';

    printf("nowy string to %s", newStr);
    *text = *newStr;
}

int main() {
    char *text = "Ala ma kota";
    char a = 'a';
    deleteChar(text, a);

    return 0;
}