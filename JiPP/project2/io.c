
#include <printf.h>
#include <stdlib.h>

#define MAX_STRLEN 50500
extern void error(int nr, char *str);

FILE *fd = NULL;

char *InputText(char *text) {
    char *buffer;
    size_t bufsize = MAX_STRLEN;


    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) error(3, "blad w przypisywaniu pamieci dla tekstu");

    printf("%s", text);
    fgets(buffer, MAX_STRLEN,stdin);

    return buffer;
}

void InitPlik() {
    if (!(fd = fopen("wyniki.txt", "w, css=UTF-8"))) error(2, "blad w otwarciu pliku");
}

void ZamknijPlik() {
    fclose(fd);
    fd = NULL;
}

void Pisz(char c) {
    fprintf(fd, "%c", c);
}