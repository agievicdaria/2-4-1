#pragma once

#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    int* elements;
    int size;

public:
    Vector();
    Vector(int n);
    Vector(const Vector& other);
    ~Vector();

    int getSize() const {return size;}
    int getElement(int index) const {return elements[index];}
    void setElement(int index, int value) {  elements[index] = value; }
    void setSize(int newSize) { size = newSize; }

    Vector operator+(const Vector& other) const;
    bool operator==(const Vector& other) const;
    double norm() const;
    int& operator[](int index);
    string toString() const;

    friend istream& operator>>(istream& in, Vector& vec);
    friend ostream& operator<<(ostream& out, const Vector& vec);
};
