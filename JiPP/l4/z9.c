//
// Created by Dawid N on 26/11/2023.
//


#include <stdio.h>

int main() {
    char chr;
    int a = 0, b = 0, c = 0, znaki = 0;
    while (1) {
        chr = (char) getchar();
        if (chr == 'e') break;
        else if (chr == 'a') {
            a++;
            continue;
        }
        else if (chr == 'b') {
            b++;
            continue;
        }
        else if (chr == 'c') {
            c++;
            goto L;
        }

        L:
            znaki ++;

    };

    printf("Wystapienia:\na: %d\nb: %d\nc: %d\npozostale: %d", a, b, c, znaki);
    return 0;
}
