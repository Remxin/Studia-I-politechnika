

#include <printf.h>

void liczPod(int rozm, int ma[rozm][rozm]);

int main() {
    int mac[3][3] = {
            { 1, 0, 0},
            {2, 1, 1},
            { 1, 2, 1}
    };
    liczPod(3, mac);

    return 0;
}

void liczPod(int rozm, int ma[rozm][rozm] ) {
    int i, j, sum = 0;
    for (i = 0; i < rozm; i++) {
        for (j = 0; j < rozm; j++) {
            if (j < i) sum += ma[i][j];
        }
    }

    printf("suma: %d", sum);

}