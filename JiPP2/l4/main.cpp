#include <iostream>

using namespace std;

class Vector {
private:
    double x;
    double y;
public:
    explicit Vector(double x);
    operator double() const;
    Vector(double x, double y);
    void display();
    double getX();
    double getY();
    Vector operator+ (Vector& vect) {
        Vector newVector(vect.getX() + this->x, vect.getY() + this->getY());
        return newVector;
    }
    friend Vector operator*(double a, Vector v1);
};

int main() {
    Vector v1 = Vector(4.5, 5.5);
    Vector v2 = Vector(5.5, 6.2);
    auto v3 = v1+v2;
    Vector v4 = (Vector)1.5;
    double a = (double)v4;
    v3 = 2.0 * v3;
    return 0;
}

Vector::Vector(double x) {
    this->x = x;
    this->y = x;
}
Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}

void Vector::display() {
    cout << "x: " << this->x << " y: " << this->y << endl;
}





double Vector::getX() {
    return this->x;
}

double Vector::getY() {
    return this->y;
}

Vector operator*(double a, Vector v1) {
    Vector newV(a*v1.getX(), a*v1.getY());
    return newV;
}

Vector::operator double() const {
    return x + y;
}
