#include <_mingw.h>
#include <malloc.h>
#include <stdio.h>

typedef struct eint {
    __int8 f1;
    __int8 f2;
} EINT;

typedef struct un {
    EINT f1;
    __int16 f2;
} UNII;

int main() {
    UNII *u1 = (UNII *)malloc(sizeof(UNII));
    u1->f1.f1 = 155;
    u1->f1.f2 = 17;

    printf("f1 8: %i, %x\nf2 8: %i, %x\nf1 16: %i, %x\n", u1->f1.f1,u1->f1.f1, u1->f1.f2,u1->f1.f2, u1->f2,u1->f2);
    return 0;
}