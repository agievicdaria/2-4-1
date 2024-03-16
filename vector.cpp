#include "vector.h"
#include <sstream>
using namespace std;

Vector::Vector() {
    elements = nullptr;
    size = 0;
}

Vector::Vector(int n) {
    size = n;
    elements = new int[size];
}

Vector::Vector(const Vector& other) {
    size = other.size;
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

Vector::~Vector() {
    delete[] elements;
}

double Vector::norm() const {
    double sumOfSquares = 0.0;
    for (int i = 0; i < size; ++i) {
        sumOfSquares += elements[i] * elements[i];
    }
    return sqrt(sumOfSquares);
}

istream& operator>>(istream& in, Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        in >> vec.elements[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Vector& vec) {
    out << "(";
    for (int i = 0; i < vec.size; ++i) {
        out << vec.elements[i];
        if (i < vec.size - 1) {
            out << ", ";
        }
    }
    out << ")";
    return out;
}

Vector Vector::operator+(const Vector& other) const {
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

bool Vector::operator==(const Vector& other) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] != other.elements[i]) {
            return false;
        }
    }
    return true;
}

int& Vector::operator[](int index) {
    return elements[index];
}

string Vector::toString() const {
    stringstream sout;
    sout << "(";
    for (int i = 0; i < size; ++i) {
        sout << elements[i];
        if (i < size - 1) {
            sout << ", ";
        }
    }
    sout << ")";
    return sout.str();
}