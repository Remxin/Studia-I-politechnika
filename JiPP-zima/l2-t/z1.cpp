#include <iostream>
using namespace std;

void printTab(double **tab, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << tab[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void freeVect(double **v, int h) {
    for (int i = 0; i < h; i++) {
        delete v[i];
    }
    delete v;
}

double **getVector(int *w, int *h) {
    double **tab1;
    cout << "Podaj rozmiar wierszy macierzy: ";
    cin >> *h;
    cout << "Podaj rozmiar kolumn macierzy: ";
    cin >> *w;
    tab1 = new double *[*h];
    for (int i = 0; i < *h; i++) {
        tab1[i] = new double [*w];
        for (int j = 0; j < *w; j++) {
            cout << "Podaj wartosc dla rzedu: " << i << " i kolumnie: " << j << " : ";
            cin >> tab1[i][j];
        }
    }

    return tab1;
}

double **addVect(double **v1, int w1, int h1, double **v2, int w2, int h2, bool substr) {
    if (w1 != w2 || h1 != h2) {
        cerr << "Wektory nie sa jednakowego rozmiaru!!";
        exit(1);
    }
    double **result;
    result = new double *[w1];
    for (int i = 0; i < h1; i++) {
        result[i] = new double [h1];
        for (int j = 0; j < w1; j++) {
            if (substr) {
                result[i][j] = v1[i][j] - v2[i][j];
            } else {
                result[i][j] = v1[i][j] + v2[i][j];
            }
        }
    }

    return result;
}

double **multVector(double **v1, int w1, int h1, double **v2, int w2, int h2) {
    double **result;
    result = new double *[w1];
    for (int i = 0; i < w1; i++) {
        result[i] = new double [h2];
        for (int j = 0; j < h2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < w2; k++) {
                result[i][j] += v1[i][k] * v2[k][j];
            }

            printf("%lf\t", result[i][j]);
        }

        printf("\n");
    }
    return result;
}

double **skal_mult(double **v1, int w1, int h1, double skal) {
    double **result;
    result = new double *[w1];
    for(int i=0; i < h1; i++) {
        result[i] = new double[h1];
        for (int j = 0; j < w1; j++) {
            v1[i][j] *= skal;
        }
    }
    return v1;
}


enum ACTIONS {
        ADD,
        SUBST,
        MULT,
        SKAL
};

int main() {
    int w1, h1, w2, h2;
    cout << "____ KALKULATOR MACIERZY ____\n\n";
    double **tab1 = getVector(&w1, &h1);
    double **tab2 = getVector(&w2, &h2);

    printTab(tab1, w1, h1);
    cout << "Wybierz akcje:\n0) dodawanie\n1) odejmowanie\n2) mnozenie\n3) mnozenie przez skalar" << endl;
    ACTIONS a;
    scanf("%d", &a);

    double **result;
    double skal;
    switch (a) {
        case ADD:
            result = addVect(tab1, w1, h1, tab2, w2, h2, false);
            break;
        case SUBST:
            result = addVect(tab1, w1, h1, tab2, w2, h2, true);
            break;
        case MULT:
            result = multVector(tab1, w1, h1, tab2, w2, h2);
            break;
        case SKAL:
            cout << "Podaj skalar: ";
            cin >> skal;
            result = skal_mult(tab1, w1, h1, skal);
            break;
    }
    cout << "___ Wynik ___"<< endl;
    printTab(result, w1, h1);
    freeVect(tab1, h1);
    freeVect(tab2, h2);
    freeVect(result, h1);

    return 0;
}
