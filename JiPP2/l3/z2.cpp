#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;
        float height;
        string gender;

    public:
        Person(string name, int age, float height, string gender) {
            this->name = name;
            this->age = age;
            this->height = height;
            this->gender = gender;
        };
        int getAge() {
            return this->age;
        }
};



int main() {
    Person tab[5] = {
            Person("Jan", 20, 185, "male"),
            Person("Ola", 20, 170, "female"),
            Person("Jakub", 20, 178, "male"),
            Person("Jan", 19, 180, "male"),
            Person("Włodzimierz", 21, 170, "male")
    };

    int i = 0;
    for (; i < 5; i++) {
        cout << tab[i].getAge() << endl;
    }
    i = 0;

    Person *p;
    p = tab;

    for (; i < 5; i++) {
        cout << p->getAge() << endl;
        *p++;
    }




    return 0;
}