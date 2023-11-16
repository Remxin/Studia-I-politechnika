#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

void replaceChar(char *text, char from, char to) { // -1 if not found
    char d;
    int i = 0;
    char newStr[MAX_LINE];
    while ((d = text[i]) != '\0') {
        if (d == from) {
            newStr[i] = to;
        } else {
            newStr[i] = d;
        }
        i++;
    }
    newStr[i] = '\0';
    strcpy(text, newStr);


}

int main() {
    char text[MAX_LINE] = "Ala ma kota";
    char from = 'a';
    char to = 'b';
    replaceChar(text, from ,to);

    printf("nowy string to %s", text);
    return 0;
}