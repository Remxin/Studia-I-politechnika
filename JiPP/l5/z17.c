#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

void addString(char *text, char *text2, int n) { // -1 if not found
    char d;
    int i = 0;
    while ((d = text[i]) != '\0') {
        i++;
    }

    int j = 0;
    while ((d = text2[j]) != '\0') {
        if (j >= n) {
            text[i] = d;
            i++;
        }
        j++;

    }
    text[i] = '\0';
}

int main() {
    char text[MAX_LINE] = "Ala ma kota";
    char *text2 = " Ola ma psa";
    int n = 4;

    addString(text, text2, n);

    printf("nowy string to %s", text);
    return 0;
}