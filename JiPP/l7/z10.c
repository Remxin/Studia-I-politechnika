

#include <malloc/_malloc.h>
#include <stdlib.h>
#include <printf.h>
#include <string.h>

void myfunc(int *tab, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) tab[i] = rand() % 100;
}

int main() {
    int *t1, *t2, n = 200, min, max, l_min, l_max;
    t1 = t2 = NULL;

    t1 = (int *)malloc((unsigned)n * sizeof(int));
    t2 = (int *)malloc((unsigned)n * sizeof(int));

    if (!t1 || !t2) {
        printf("Blad alokacji pamieci");
        exit(1);
    }

    myfunc(t1, n);
    min = max = 0;
    l_min = l_max = 0;

    for (int i = 0; i < n; i++) {
        printf("%d ", t1[i]);
        if (t1[i] < min) {
            min = t1[i];
            l_min = i;
        }
        if (t1[i] > max) {
            max = t1[i];
            l_max = i;
        }
    }

    printf("min: %d, na pozycji: %d\n", min, l_min);
    printf("max: %d, na pozycji: %d\n", max, l_max);

    memcpy(t2, t1, n * sizeof(int));
    for (int i = 0; i < n; i++) printf("%d ", t2[i]);

    if (t1) {
        free(t1);
        t1 = NULL;
    }
    if (t2) {
        free(t2);
        t2 = NULL;
    }



    return 0;
}