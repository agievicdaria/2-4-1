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

Vector::Vector(const Vector& secondVector) {
    size = secondVector.size;
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = secondVector.elements[i];
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
    out << string(vec);
    return out;
}

Vector operator+(const Vector& firstVector, const Vector& secondVector) {
    Vector result(firstVector.size);
    for (int i = 0; i < firstVector.size; ++i) {
        result.elements[i] = firstVector.elements[i] + secondVector.elements[i];
    }
    return result;
}

bool operator==(const Vector& firstVector, const Vector& secondVector) {
    for (int i = 0; i < firstVector.size; ++i) {
        if (firstVector.elements[i] != secondVector.elements[i]) {
            return false;
        }
    }
    return true;
}

int& Vector::operator[](int index) {
    return elements[index];
}

Vector::operator string () const {
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

Vector& Vector::operator= (const Vector& r) {
    elements = r.elements;
    size = r.size;
    return *this;
}