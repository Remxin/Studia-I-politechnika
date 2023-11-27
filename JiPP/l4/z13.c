#include <_stdio.h>
#include <stdio.h>

int main() {
    FILE *fd;
    if (!(fd = fopen("dane.txt", "r"))) return -1;
    char c;
    while ((c = (char)fgetc(fd)) != EOF)
    {
        printf("%c", c);
    }

    return 0;
}