#include <stdio.h>
#include <malloc.h>

FILE *fin = NULL;
FILE *fout = NULL;

int main() {
    if (!(fout = fopen("binary.txt", "wb"))) return -1;
    int binaryTab[6] = { 1, 2, 3, 4, 5, 6};

    size_t elements_written = fwrite(binaryTab, sizeof(int), sizeof(binaryTab) / sizeof(int), fout);

    if (elements_written != sizeof(binaryTab) / sizeof(int)) {
        perror("Błąd podczas zapisywania do pliku");
        fclose(fout);
        return 1;
    }
    for (int i = 0; i < 6; i++) {
        binaryTab[i] = 0;
    }
    if (!(fin = fopen("binary.txt", "rb"))) return -1;

    fseek(fin, 0, SEEK_END);
    long file_size = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    int *array_to_read = malloc(file_size);
    size_t elements_read = fread(array_to_read, sizeof(int), file_size / sizeof(int), fin);

    if (elements_read != file_size / sizeof(int)) {
        perror("Błąd podczas odczytywania z pliku");
        fclose(fin);
        free(array_to_read);
        return 1;
    }

    for (size_t i = 0; i < 6; i++) {
        printf("%d\n", array_to_read[i]);
    }

    return 0;
}