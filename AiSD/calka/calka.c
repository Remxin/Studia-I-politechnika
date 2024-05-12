
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

extern void initRandom();
extern double f3(double x);
extern double f4(double x);
extern double prostokaty(double( *f)(double));
extern double trapezy(double (*f)(double));
extern double mc(double(*f)(double));


double c_od, c_do;



double f1(double x)
{
    return -3.13*x*x*x*x+14.5*x*x-3;
}
double f2(double x)
{
    double y;
    y=cos(2*x*x)*2*sin(8*x)-cos(5*x)+1;
    return y;
}

int main(int argc, char *argv[])
{
    printf("od=");
    scanf("%lf",&c_od);
    printf("do=");
    scanf("%lf",&c_do);
    printf ("\n\nFunkcja 1 \n");
    printf( "wynik prostokaty - %lf\n" ,prostokaty(f1));
    printf( "wynik trapezy    - %lf\n" ,trapezy(f1));
     printf( "wynik MC   - %lf\n", mc(f1));
    printf("\n\nFunkcja 2 \n");
    printf( "wynik prostokaty - %lf\n" ,prostokaty(f2));
    printf( "wynik trapezy    - %lf\n" ,trapezy(f2));
     printf("wynik MC   - %lf\n", mc(f2));
    printf ("\n\nFunkcja 3 \n");
    printf( "wynik prostokaty - %lf\n" ,prostokaty(f3));
    printf( "wynik trapezy    - %lf\n" ,trapezy(f3));
     printf( "wynik MC   - %lf\n", mc(f3));
    printf("\n\nFunkcja 4 \n");
    printf( "wynik prostokaty - %lf\n" ,prostokaty(f4));
    printf( "wynik trapezy    - %lf\n" ,trapezy(f4));
     printf( "wynik MC   - %lf\n", mc(f4));

    return 0;
}
