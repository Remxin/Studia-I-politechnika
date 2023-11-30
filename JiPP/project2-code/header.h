// header.h
#ifndef HEADER_H
#define HEADER_H

int **SlowaILitery(int *text, int *rows, int *cols);
char *InputText(char *text);
void printNewTextTab(int rows, int cols, int **textTab, int choice);
void error(int nr, char *str);
void InitPlik();
void clearInputBuffer();
void ZamknijPlik();
void Pisz(char c);
void Piszstr(char *str);
int *encodeText(char *text);



#endif
