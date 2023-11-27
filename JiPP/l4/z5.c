#include <stdio.h>

int main() {
    int n;
    printf("Podaj n: ");
    if (scanf("%d", &n) != 1) return -1;
    int silnia = 1;

    for (int i = 1; i <= n; i++) {
        silnia *= i;
    }

    printf("silnia wynosi: %d", silnia);

    return 0;
}