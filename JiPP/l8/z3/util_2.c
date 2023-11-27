#include <stdio.h>
#include <stdlib.h>

double *DajWekt(int n) {
    return (double *)malloc(sizeof(double)*n);
}

void CzytajWekt(FILE *fd, double *we, int n) {
    int k;
    for (k = 0; k < n; k++)
        fscanf(fd, "%lf", &we[k]);

}

void PiszWekt(FILE *fw, double *we, int n) {
    int k;
    for (k = 0; k < n; k++)
    {
        fprintf(fw, "%lf ", we[k]);
        if (!((k + 1) % 5)) fprintf(fw, "\n");
    }
}