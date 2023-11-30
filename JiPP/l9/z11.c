#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTUDENT 10
#define MAXLINE 256
FILE *fd;

typedef struct student {
    char* imie;
    char* nazwisko;
    int rok;
    char* adres;
    double stypendium;
} STUDENT;

int main() {
    return 0;
}

void wezStudentow(STUDENT *studenci[]) {
    if (!(fd = fopen("dane.txt", "r"))) exit(-1);
    char bufor[MAXLINE];
    int i = 0;
    while (i < MAXSTUDENT && (fgets(bufor, MAXLINE, fd)) != (char*)NULL) {
        int len = (unsigned) strlen(bufor);
        bufor[len - 1] = '\n';
        studenci[i]->nazwisko = (char *)malloc(len);
        strcpy(studenci[i]->nazwisko, bufor);
        i++;
    }
}
