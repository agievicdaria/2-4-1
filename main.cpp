#include <iostream>
#include "vector.h"
using namespace std;

int main() {
    Vector v1(3);
    Vector v2(3);
    cout << "Enter elements for vector v1: ";
    cin >> v1;
    cout << "Enter elements for vector v2: ";
    cin >> v2;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    
    Vector v3 = v1 + v2;
    cout << "v3 = " << v3 << endl;

    if (v1 == v2) {
        cout << "v1 and v2 are equal." << endl;
    } else {
        cout << "v1 and v2 are not equal." << endl;
    }
    
    cout << "Norm of v1: " << v1.norm() << endl;
    
    cout << "v1 elements: ";
    for (int i = 0; i < v1.getSize(); ++i) {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "Size of Vector without #pragma pack(1): " << sizeof(Vector) << endl;

    #pragma pack(1)
    cout << "Size of Vector with #pragma pack(1): " << sizeof(Vector) << endl;
    #pragma pack()
    
    return 0;
}
