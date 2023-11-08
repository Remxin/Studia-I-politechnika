#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define INPUT_SIZE 30
#pragma warning (disable: 4996)

FILE *fp;


double calcExactVal(double x) {
    return pow(1.0 + x, -3. / 2.);
}

double calcApproximateVal(double x, int i, double sum, int *prevT, int *prevB, double *prevEq) {
    if (i == 0) {
        sum = 1.;
        return sum;
    }

    // multiply prev top and bottom vals
    *prevEq *= ((double) *prevT / (double) *prevB) * x;


    // increment prev values
    *prevT += 2;
    *prevB += 2;

    if (i % 2 == 0) { // even (+)
        sum += *prevEq;
    } else { // odd (-)
        sum -= *prevEq;
    }
    return sum;

}

void endWithErr(char where[], char error[]) {
    printf("\nBlad %s!: \n%s\n\n_____ ZAKONCZENIE PROGRAMU _____\n\n", where, error);
    exit(-1);
}

char* checkD(double *md, double *Md) {
    if (*md <= -1) return "Dolna granica powinna być większa od -1";
    if (*Md >= 1) return "Gorna granica powinna byc mniejsza nic 1";
    if (*md >= *Md) return "Dolna granica powinna byc mniejsza od gornej";
    return "";
}

double input(char text[]) {
    char *ptr;
    double ret;
    char str[INPUT_SIZE]; // max input size

    printf(text);

    fgets(str, INPUT_SIZE, stdin);
    ret = strtod(str, &ptr);

    if (ret >= LONG_MAX || ret <= LONG_MIN) { // min and max long len(+-9223372036854775808)
        endWithErr("przy dlugosci liczby", "* przyblizenie liczby nie miesci sie w zakresie");
    } else if (ret) { // the char is long
        return ret;
    }
    // char is not long
    endWithErr("przy pobieraniu liczby zmiennoprzecinkowej", "podana wartosc nie jest zmiennoprzecinkowa");
    return 1.;

}

void writeToFile(double x, double exact, double approx, int i, char text[]) {
    fprintf(fp, "%lf\t\t%lf\t\t%lf\t\t%d\t\t%s\n", x, exact, approx, i, text);
}

void szereg(double md, int i, double d, double skok, int maxIter, double *x, double *exact, double *sum, int *j, char *text[]) {
    *x = md + i * skok;
    *exact = calcExactVal(*x);
    int iter = 0;

    double diff; // pozniej: dokladna wartosc - przyblizona

    // okreslanie dokladnej wartosci
    *sum = 0;
    int prevT = 3; // previous top value
    int prevB = 2; // previous bottom value

    double prevEq = 1; // previous multiply value
    int ok = 0;
    do {
        *sum = calcApproximateVal(*x, iter, *sum, &prevT, &prevB, &prevEq);
        diff = fabs(prevEq);

        if (diff <= d) {
            *j = iter;
            *text = "osiagnieto wymagana dokladnosc";
            ok = 1;
            break;
        }

        iter++;
    } while (iter < maxIter);
    if (!ok)  {
        *j = iter;
        *text = "nie osiagnieto (limit iteracji przekroczony)";
    }
}


int main() {
    // otwieranie pliku
    fp = fopen("wyniki.txt", "w");
    if (fp == NULL) endWithErr("w opercji na pliku", "nie udalo sie otworzyc pliku");

    // pobieranie dziedziny
    double md = input("Podaj dolny zakres dziedziny (min -1): ");
    double Md = input("Podaj gorny zakres dziedziny  (max 1): ");

    // sprawdzenie poprawnosci z dziedzina
    char *dAlright = checkD(&md, &Md);
    if (strcmp(dAlright, "") != 0) endWithErr("w dziedzinie", dAlright);

    // pobierania probkowania
    int maxIter = (int) input("Podaj max wartosc iteracji dla pojedynczego argumentu (min 1): ");
    if (maxIter < 1) endWithErr("w maksymalnej ilosci iteracji", "Max wartosc inkrementacji nie moze byc mniejsza od 1");
    int parts = (int) input("Podaj na ile czesci ma byc podzielony zakres: ");
    if (parts < 1) endWithErr("w podziale zakresu", "Nie mozna podzielic przedzialu na te ilosc!");
    double skok = (Md - md) / parts;

    // pobieranie delty (wymaganej dokladnosci)
    double d = input("Podaj wymagana dokladnosc (delta): ");

    if (d <= 0) endWithErr("w dokladnosci", "dokladnosc musi byc dodatnia");



    // obliczanie sumy i wypisywanie jej do pliku
    double x, exact, sum;
    int j;
    char *text;
    for (int i = 0; i <= parts; i++) {
        szereg(md, i, d, skok, maxIter, &x, &exact, &sum, &j, &text);
        writeToFile(x, exact, sum, j, text);
    }

    fclose(fp);
    return 0;
}
