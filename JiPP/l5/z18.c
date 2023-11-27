#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

void moveByOne(char *text) {
    int i = 0;
    char newStr[MAX_LINE];
    strcpy(newStr, text);
    int strl = (int) strlen(text);

    text[i++] = newStr[strl - 1];

    while (i < strl) {
        text[i] = newStr[i - 1];
        i++;
    }
    text[i] = '\0';
}

int main() {
    char text[MAX_LINE] = "Ala ma kota";
    moveByOne(text);

    printf("nowy string to %s", text);
    return 0;
}