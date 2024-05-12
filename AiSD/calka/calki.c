#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>

#define lp 1000000

double c_od,c_do;



double getRandomNum(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void assingMinMaxForRange(double *min, double *max, double( *f)(double)) {
    double m = DBL_MAX;
    double M = -DBL_MAX;

    double krok=(c_do-c_od)/lp;
    double current;

    for (double x = c_od; x <= c_do; x += krok) {
        current = (*f)(x);
        if (current > M) M = current;
        if (current < m) m = current;
    }
    *min = m;
    *max = M;
}



double f3(double x)
{
    return atan(x) / pow(1 + x*x, 3./2);
}
double f4(double x) {

    return pow(x, 2)*sin(x);
}


double prostokaty(double( *f)(double))
{
    double krok, prev, current, suma=0;
    krok=(c_do-c_od)/lp;

    prev = fabs((*f)(c_od));
    for (double x = c_od; x <= c_do; x += krok) {
        current = (*f)(x);
        suma += (prev + current);
        prev = current;
    }
    return (suma)/2*krok;
}

double trapezy(double (*f)(double)) {
    double krok = (c_do-c_od)/lp;
    double calka = ((*f)(c_od)+(*f)(c_do))/2;
    for (double x = c_od + krok; x < c_do; x += krok) {
        calka += (*f)(x);
    }
    return calka * krok;
}



double mc(double(*f)(double))
{
    srand(time(NULL));
    double minV, maxV;
    double px, py, pxVal;
    int lpkt = 0;

    assingMinMaxForRange(&minV, &maxV, *f);

    for (int i = 0; i < lp; i++) {
         px = getRandomNum(c_od, c_do);
         py = getRandomNum(minV, maxV);
         pxVal = (*f)(px);

         if ((py >= 0 && py <= pxVal)) lpkt++;
         else if (py < 0 && py >= pxVal) lpkt--;
    }

    double rectF = (c_do - c_od) * (maxV - minV);

    return lpkt * rectF / lp;


}

