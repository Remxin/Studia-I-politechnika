//==============================PLIK_1===================================
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#define LL 20
FILE *fw, *fd;
void argumenty(int, char **);
extern void error(int, char *);
extern double **DajMac_1(int n, int m);
extern double **DajMac_2(int n, int m);

extern void ZwrocMac_1(double **ma, int n, int m);
extern void ZwrocMac_2(double **ma, int n, int m);

extern void CzytMac(FILE *fd, double **ma, int n, int m);
extern void PiszMac(FILE *fw, double **ma, int n, int m);
extern void DodMac(double **ma1, double **ma2, double **ma3, int n, int m);
extern void Mac_x_Wekt(double **ma, double *we, double *wy, int n, int m);
extern void Mac_x_Mac(double **x, double **y, double **z, int n, int m, int p);


int main(int argc, char *argv[]) {
    double **a, **b, **c, *x, *y, r;
    int i, j, k, n, m;
    argumenty(argc, argv);
    if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
    if (!(fw = fopen(argv[2], "w"))) error(2, "wyniki");
    fscanf(fd, "%d %d", &n, &m);

    x = (double *)malloc(sizeof(double) * (unsigned)n);
    y = (double *)malloc(sizeof(double) * (unsigned)n);

    a = DajMac_1(n, m);
    b = DajMac_2(n, m);
    c = DajMac_1(n, m);

    CzytMac(fd, a, n, m);

    for (i = 0; i < m; i++)
        fscanf(fd, "%lf", &x[i]);

    CzytMac(fd, b, n, m);

    DodMac(a, b, c, n, m);

    Mac_x_Wekt(a, x, y, n, m);

    PiszMac(fw, c, n, m);

    for (i = 0; i < n; i++)
    {
        fprintf(fw, "%lf ", y[i]);
        if (!((i + 1) % 5)) fprintf(fw, "\n");
    }

    Mac_x_Mac(a,b,c,n,m,n);

    ZwrocMac_1(a, n, m);
    ZwrocMac_2(b, n, m);
    ZwrocMac_1(c, n, m);
    return 0;
}

void argumenty(int argc, char *argv[])
{
    int len;
    char *usage;
    if (argc != 3)
    {
        len = strlen(argv[0]) + 19;
        if (!(usage = (char*)malloc((unsigned)len * sizeof(char))))
            error(3, "tablica usage");
        strcpy(usage, argv[0]);
        strcat(usage, " file_in file_out");
        error(4, usage);
    }
}