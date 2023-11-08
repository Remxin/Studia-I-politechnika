
#include <printf.h>

void zamien(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 2, y = 5;
    zamien(&x, &y);

    printf("Zamieniono x na %d oraz y na %d", x, y);
    return 0;
}
