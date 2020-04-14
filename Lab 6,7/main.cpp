//
// Created by Timur Oshnokov on 2019-05-06.
//

#include <iostream>
#include "matrix.h"

using namespace std;

template<class T>

void swap(T *a, T *b) {
    T t = *a;
    *a = *b;
    *b = t;
}

int main() {

    int a = 10;
    int b = 20;

    swap(&a, &b);

    cout << a << "," << b << endl;

    matrix<int, 3, 3> m;

    try {

        cout << m.address(2, 2) << endl;
        cout << m.address(1, 1) << endl;
        cout << m.address(0, 0) << endl;
        m.address(0, 0) = 1;
        cout << m.address(0, 0) << endl;
        cout << m.address(3, 3) << endl;
    }
    catch (matrix_element_doesnt_exist *e) {
        cout << e->what() << endl;
    }


    return 0;
}