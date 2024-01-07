

#include <stdlib.h>
#include <stdio.h>

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
<<<<<<< HEAD
    if (!(fd = fopen("wyniki.txt", "w"))) error(2, "blad w otwarciu pliku");
////    fprintf(fd, "żźąę");
    char polish_chars[] = "ą";
//
//
//    // Display each Polish character with hexadecimal values
    for (int i = 0; i < sizeof(polish_chars) - 1; ++i) {
//        printf("%d", polish_chars[i]);
        fprintf(fd, "%c", polish_chars[i]);
    }
=======
    if (!(fd = fopen("wyniki.txt", "w, css=UTF-8"))) error(2, "blad w otwarciu pliku");
>>>>>>> 049049d255b77a116506ba7e6eaba467df74c716
}

void ZamknijPlik() {
    fclose(fd);
    fd = NULL;
}

void Pisz(char c) {
    fprintf(fd, "%c", c);
}