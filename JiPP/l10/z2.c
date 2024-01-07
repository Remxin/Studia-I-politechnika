

#include <malloc.h>
#include <stdio.h>

typedef struct MY_VECTOR {
    int dim;
    char str[64];
    double *buff;
} VECT;

double inner_product(VECT x, VECT y, int length) {
    double result = 0;
//    printf("%lf", x.buff[1]);
    for (int i = 0; i < length; i++) {
        printf("x%d: %lf\ty%d: %lf\n", i, x.buff[i],i, y.buff[i]);
        result += x.buff[i] * y.buff[i];
    }
    return result;
}

int main() {
    int n = 2;
    int dim;
    VECT *tab = (VECT *)malloc(sizeof(VECT) *n);
    printf("Podaj rozmiar wektorow: ");
    scanf("%d", &dim);

    for (int i = 0; i < n; i++) {
        tab[i].buff = (double *)malloc(sizeof(double) * dim);
        tab[i].dim = dim;
        printf("podaj nazwe wektora %d: ", i+1);
        scanf("%s", tab[i].str);
        for (int j = 0; j < dim; j++) {
            if (i == 0) {
//
                tab[i].buff[j] = 1./(j+1);
            } else {
                tab[i].buff[j] = (double) j+1;
            }
        }
    }

    double iloczyn = inner_product(tab[0], tab[1], dim);
    printf("iloczyn: %lf", iloczyn);

    for (int i = 0; i < n; i++) {
        free(tab[i].buff);
    }

    free(tab);


    return 0;

}