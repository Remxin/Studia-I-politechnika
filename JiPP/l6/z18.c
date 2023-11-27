
#include <stdio.h>

#define MAX_LINE 256

int inputInt(char *text) {
    printf("%s", text);
    int num;
    if (!scanf("%d", &num)) {
        printf("Blad w pobieraniu wartosci");
    };
    return num;
}

void printslowo(int n, char *ciag) {
    char znak;
    int i = 0;
    int islowa = 0;
    int przeskok = 0;
    char slowo[MAX_LINE];
    while((znak = ciag[i]) != '\0') {
        if (znak == ':') {
            przeskok++;
            i++;
            continue;
        }
        if (n == przeskok) {
            slowo[islowa] = znak;
            islowa++;
        }
        i++;
    }

    printf("Szukane slowo: %s", slowo);
}

int main() {
    char *text = "rw:rwx:x:user:password:aaaaa:0000";
    int n = inputInt("Podaj numer slowa: ");

    printslowo(n, text);
    return 0;
}