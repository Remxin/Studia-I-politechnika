#include <iostream>

using namespace std;

class Stack {
private:
    int len;
    int tab[1000];

public:
    Stack() {
        this->len = 0;
    }
    ~Stack() {
        cout << "Koniec pracy z objektem" << endl;
    }

    bool isEmpty() {
        if (this->len == 0) return true;
        return false;
    }
    bool isFull() {
        if (this->len >= 1000) return true;
        return false;
    }

    void push(const int e) {
        this->tab[this->len] = e;
        this->len++;
    }

    int pop() {
        if (this->len == 0) {
            cout << "Brak elementów na stosie!" << endl;
            return 0;
        }
        this->len--;
        return this->tab[this->len];
    }

};

enum ACTIONS {
    PUSH,
    POP,
    END
};

int main() {
    Stack s = Stack();

    bool running = true;
    ACTIONS action;
    int newNum;

    while (running) {
        cout << "Podaj numer akcji, jaka chcesz wykonac:\n0) PUSH\n1) POP\n2) END" << endl;
        scanf("%d", &action);
        switch (action) {
            case PUSH:
                cout << "Podaj numer do dodania: ";
                cin >> newNum;
                s.push(newNum);
                break;
            case POP:
                cout << "Element ze stacku: " << s.pop() << endl;
                break;
            case END:
                running = false;
        }
    }

    return 0;
}
