//#include <stdlib.h>
//#include <stdio.h>
//
//#define MAX_STRLEN 255
//extern void error(int nr, char* str);
//
//FILE* fd = NULL;
//
//char* InputText(char* text) {
//    char* buffer;
//    size_t bufsize = MAX_STRLEN;
//
//
//    buffer = (char*)malloc(bufsize * sizeof(char));
//    //if (buffer == NULL) error(3, "blad w przypisywaniu pamieci dla tekstu");
//
//    printf("%s", text);
//    fgets(buffer, MAX_STRLEN, stdin);
//
//    return buffer;
//}
//
//void InitPlik() {
//    //if (!(fd = fopen("wyniki.txt", "w"))) error(2, "blad w otwarciu pliku");
//    if (!(fd = fopen("wyniki.txt", "w"))) return;
//    //    fprintf(fd, "żźąę");
//    char polish_chars[] = "ąćęłńóśźż";
//
//    // Display each Polish character with hexadecimal values
//    for (int i = 0; i < sizeof(polish_chars) - 1; ++i) {
//        printf("%c (%02X)\n", polish_chars[i], polish_chars[i] & 0xFF);
//    }
//}
//
//void ZamknijPlik() {
//    fclose(fd);
//    fd = NULL;
//}
//
//void Pisz(char c) {
//    fprintf(fd, "%c", c);
//}