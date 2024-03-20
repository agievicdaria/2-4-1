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
    Vector(const Vector& secondVector);
    ~Vector();

    int getSize() const {return size;}
    int getElement(int index) const {return elements[index];}
    void setElement(int index, int value) {  elements[index] = value; }
    void setSize(int newSize) { size = newSize; }

    friend Vector operator+(const Vector& firstVector, const Vector& secondVector);
    friend bool operator==(const Vector& firstVector, const Vector& secondVector);
    double norm() const;
    int& operator[](int index);
    operator string() const;
    Vector& operator= (const Vector&);

    friend istream& operator>>(istream& in, Vector& vec);
    friend ostream& operator<<(ostream& out, const Vector& vec);
};
