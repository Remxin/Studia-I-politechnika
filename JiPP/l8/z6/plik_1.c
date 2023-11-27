#include <stdio.h>

FILE *fw, *fd;
extern void error(int, char*),PiszWekt(FILE *, double *, int),
        CzytWekt(FILE *, double *, int),CzytMac(FILE *, double **, int, int),
        PiszMac(FILE *, double **, int, int);
extern double *DajWekt(int), **DajMac_1(int, int);
extern void DodMac(double **, double **, double **, int, int),
        Mac_x_Wekt(double **, double *, double *, int, int);
void argumenty(int argc, char *argv[]);
int main(int argc, char *argv[])
{
    double *x, *y;
    double **a, **b, **c;
    int n, m;
    argumenty(argc, argv);
    if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
    if (!(fw = fopen(argv[2], "w"))) error(2, "wyniki");
    fscanf(fd, "%d %d", &n, &m);
    x = DajWekt(m);

    y = DajWekt(m);
    a = DajMac_1(n, m);
    b = DajMac_1(n, m);
    c = DajMac_1(n, m);
    CzytMac(fd, a, n, m);
    CzytMac(fd, b, n, m);
    CzytWekt(fd, x, m);
    DodMac(a, b, c, n, m);
    Mac_x_Wekt(a, x, y, n, m);
    printf("Macierz\n");
    PiszMac(stdout, c, n, m);
    fprintf(fw, "Macierz\n");
    PiszMac(fw, c, n, m);
    printf("Wektor\n");
    PiszWekt(stdout, y, n);
    fprintf(fw, "Wektor\n");
    PiszWekt(fw, y, n);
}