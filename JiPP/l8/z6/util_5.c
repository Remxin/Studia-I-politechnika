#include <stdio.h>

void PiszMac(FILE *fw, double **ma, int n, int m) {
    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            fprintf(fw, "%lf ", ma[i][j]);
        fprintf(fw, "\n");
    }
}

void DodMac(double **ma1, double **ma2, double **ma3, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            ma3[i][j] = ma1[i][j] + ma2[i][j];

}
void Mac_x_Wekt(double **ma, double *we, double *wy, int n, int m) {
    int i, k, r;
        for (i = 0; i < n; i++) {
        r = 0;
        for (k = 0; k < m; k++)
        r += ma[i][k] * we[k];
        wy[i] = r;
    }
}

void Mac_x_Mac(double **x, double **y, double **z, int n, int m, int p) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            z[i][j] = 0;
            for (k = 0; k < m; k++) {
                z[i][j] += x[i][k] * y[k][j];
            }
        }
    }

}
