
#include <stdlib.h>
#include <stdio.h>

extern void error(int nr, char *str);

double **DajMac_1(int n, int m) {
    double **tab;
    tab = (double **)malloc(sizeof(double *) * n);
    if (!tab) error(3, "blad przy alokowaniu pamieci dla tablicy dwuwymiarowej");

    for (int i = 0; i < n; i++)
    {
        tab[i] = (double *)malloc(sizeof(double) * m);
        if (!tab[i]) error(3, "blad przy alokowaniu pamieci dla tablicy");
    }
    return tab;
}

double **DajMac_2(int n, int m) {
    double **tab_a, *tab_b;
    tab_b = (double *)malloc(sizeof(double) * n * m );
    if (!tab_b) error(3, "blad przy alokowaniu pamieci dla tablicy");
    tab_a = (double **)malloc(sizeof(double *) * n);
    if (!tab_a) error(3, "blad przy alokowaniu pamieci dla tablicy dwuwymiarowej");
    for (int i = 0; i < n; i++)
    {
        tab_a[i] = &tab_b[ m * i ];
    }

    return tab_a;
}

void ZwrocMac_1(double **ma, int n, int m) {
    if (ma){
        for (int i = 0; i < n; i++)
        {
            if (ma[i])
            {
                free(ma[i]);
            }
        }
        free(ma);
        ma = NULL;
    }
}

void ZwrocMac_2(double **ma, int n, int m) {
    if (ma){
        if (ma[0]) {
            free(ma[0]);
            ma[0] = NULL;
        }
        free(ma);
        ma = NULL;
    }
}

void CzytMac(FILE *fd, double **ma, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if (fscanf(fd, "%lf", &ma[i][j]) != 1)
            {
                error(1, "plik zawiera zle dane");
            }
        }
}