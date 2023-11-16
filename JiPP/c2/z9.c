// W4.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <math.h>
#include <process.h>


static void my_exit();
static void my_return();
int main(int argc, char* argv[])
{
    double a = 0.0, b = 0.0, c = 0.0;
    int ret = -1;
//input data
    printf("Program obliczenia pierwiastkow rownania kwadratowego\n");
    printf("-------------------- a*x^2+b*x+c = 0 ------------------------------\n\n");
    printf("Podaj a,b,c\n");
    ret = scanf("%le%le%le", &a, &b, &c);
    if(ret != 3)
    {
        printf("Blad przy wczytaniu\n");
        printf("Wczytane: a = %e b = %e c = %e\n", a, b, c);
        //To jest blad oprogramowania
        my_exit();
    }
//Sprawdzenie a
    if(a == 0.0) //To nie jest dobry kod: a jest typu double!!!
    {
        //a == 0
        printf("To nie jest rownanie kwadratowe: a = 0.\n");
        //To jest blad uzytkownika przy wprowadzeniu danych
        my_exit();
    }
//Obliczenie D
    double D = -1.0; //to jest inicjalizacje zmiennej
    D = b*b-4.0*a*c;
    if(D < 0.0)
    {
        //brak pierwiastkow rzeczywistych
        printf("Brak pierwiastkow rzeczywistych: D = %lf < 0.\n", D);
        double r1 = -b / (2*a), r2 = -b / (2*a);
        double u1 = sqrt(fabs(pow(b/(a*2), 2) - c/a));
        double u2 = -sqrt(fabs(pow(b/(a*2), 2) - c/a));

        printf("Pierwiastki urojone: 1) %lf %+lfi, 2) %lf %+lfi\n", r1, u1, r2, u2);


        my_return(); //To nie jest blad
    }
//Obliczenie pierwiastkow
    double p1, p2, x1, x2;
    p1 = -b/(2.0*a);
    p2 = sqrt(D)/(2.0*a);
    x1 = p1+p2;
    x2 = p1-p2;
    printf("Rownanie kwadratowe: %lf *X*X + %lf *X + %lf = 0\n\n", a, b, c);
    printf("Pierwiastki: x1 = %e x2 = %e\n", x1, x2);
    printf("---------------------------------------------------------");
    my_return();
    return 0;
}
void my_exit()
/*==============================================================================
Przymusowe zakonczenie wykonania
Zawiesza monitor dok№d nie bкdzie wprowadzony ^Z
exit(1)
===============================================================================*/
{
    int ch;
    printf("Zakoncz - ctrl+Z Enter\n");
    while((ch = getchar()) != EOF)
        ;
    exit(1);
}

void my_return()
/*==============================================================================
Normalne zakonczenie
Zawiesza monitor dok№d nie bкdzie wprowadzony ^Z
exit(0)
===============================================================================*/
{
    int ch;
    printf("Zakoncz - ctrl+Z Enter\n");
    while((ch = getchar()) != EOF)
        ;
    exit(0);
}