

#include <math.h>
#include <printf.h>

int main() {
    int rozm = 4;
    int mac[4][4] = {
            {2, 0, 0,3},
            {0, 1, 5, 0},
            {0 ,2, 3, 4},
            {1, 2, 3, 4}
    };
    int i, j, sum = 0;

    for (i = 0; i < rozm; i++) {
        for (j = 0; j < rozm; j++) {
            if (i == j) {
                if (sin(mac[i][j] >= 0)) sum += mac[i][j];
            } else if (i == rozm - j) {
                if (sin(mac[i][j] >= 0.5)) sum += mac[i][rozm-j];
            }
        }
    }

    printf("suma przekatnych + warunek: %d", sum);

    return 0;
}