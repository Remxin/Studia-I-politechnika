/*
 Podanie liczby np. n = 20
 wczytanie n (20) elementow z pliku
 format pliku z danymi (oddzielone spacjami):
 1 2 3 4 5

 dynamiczne alokowanie pamięci
 Wyświetlenie menu
 1- insert
 2-6 - metody sortowania
 7 - exit

 wypisanie wyników
 plik z danymi nazywa się "dane" (nie "dane.txt")


narysować dane
 ^ czas [s]
 |
 |
 |       /---
 |   /---
 |  /
 --------------> rozmiar problem [n]

 mierzenie czasu
 1) gettimeofday
 2) algorytm
 3) jeszcze raz gettimeofday
 4) obliczenie różnicy

 */

#include <iostream>
#include "algorytmy.hpp"

using namespace std;

typedef void (*FunctionPtr2)(int*, int);
typedef void (*FunctionPtr3)(int*, int, int);

void calcTime(FunctionPtr2 f, int *t, int n) {

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    // Call the function passed as a parameter
    f(t, n);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;
}

void calcTime(FunctionPtr3 f, int *t, int startVal, int endVal) {

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    // Call the function passed as a parameter
    f(t, startVal, endVal);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;
}


class Menu {
private:
    int choice;
    
public:
    Menu() {
        this->choice = -1;
    }
    void startMenu() {
        cout << "____ Welcome to sorting program ____" << endl;
    }

    void chooseMenu() {
        cout << "Choose your action: \n0) Show elements\n1) Insert element\n2) Insertion sort\n3) Selection sort\n4) Bubble sort\n5) Quicksort\n6) Shell sort\n7) Heap sort\n8) End\n";
        cout << "Your choice: ";
        cin >> choice; 
    }

    int getChoice() {
        return this->choice;
    }

    void endMenu() {
        cout << "____ Goodbye! ____" << endl;
    }
};

class Data {
private:
    int *tab;
    int n;
    FILE *f;

public:
    Data() { // wczytanie elementow
        this->f = fopen("numbers_asc.txt", "r");
        cout << "Podaj ilosc elementow do wczytania: ";
        cin >> this->n;
        tab = new int[this->n];

        for(int i=0;i<this->n;i++)
            fscanf(f,"%d",&tab[i]);

    }

    int getLen() {
        return this->n;
    }

    void insertElement() {
        int e;
        cout << "Podaj nowy element: ";
        cin >> e;
        int *newTab = new int[this->n + 1];
        int i = 0;
        for (; i < this->n; i++) {
            newTab[i] = this->tab[i];
        }
        newTab[i] = e;
        delete [] this->tab;
        this->tab = newTab;
        this->n += 1;
    }

    void showData() {
        for (int i = 0; i < this->n; i++) {
            cout << this->tab[i] << "\t";
        }
        cout << "\n";
    }
    void showData(int *t) {
        for (int i = 0; i < this->n; i++) {
            cout << t[i] << "\t";
        }
        cout << "\n";
    }

    int *assignTabCopy() {
        int *t2 = new int[this->n];
        for (int i = 0; i < this->n; i++) {
            t2[i] = this->tab[i];
        }
        return t2;
    }

    ~Data() {
        fclose(this->f);
        this->f = nullptr;

        delete [] this->tab;
    }
};

int main() {
    Menu m = Menu();
    Data data = Data();
    m.startMenu();

    while (m.getChoice() != 8) {
        int *t2;
        switch (m.getChoice()) {
            case 0:
                data.showData();
                break;
            case 1:
                data.insertElement();
                break;
            case 2:
                t2 = data.assignTabCopy();
                calcTime(  insertionSort,t2, data.getLen());
                break;
            case 3:
                t2 = data.assignTabCopy();
                calcTime(selectionSort,t2, data.getLen());
                break;
            case 4:
                t2 = data.assignTabCopy();
                calcTime(bubbleSort, t2, data.getLen());

                break;
            case 5:
                t2 = data.assignTabCopy();
                calcTime(quickSort,t2, 0, data.getLen() - 1);
                break;
            case 6:
                t2 = data.assignTabCopy();
                calcTime( shellSort, t2, data.getLen());
                break;
            case 7:
                t2 = data.assignTabCopy();
                calcTime(   heapSort,t2, data.getLen());
                break;
        }

        m.chooseMenu();
    }

    m.endMenu();
    return 0;
}