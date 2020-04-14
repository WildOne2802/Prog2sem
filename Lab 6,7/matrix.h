//
// Created by Timur Oshnokov on 2019-05-06.
//

#ifndef PROGRAMMING_MATRIX_H
#define PROGRAMMING_MATRIX_H

#include <exception>

using namespace std;

class matrix_exception : public exception {
};

class matrix_element_doesnt_exist : matrix_exception {

public:
    virtual const char *what() const throw() {
        return "Such index doesn't exist";
    }
};

template<class T, int N, int M>
class matrix {

    T data[N][M];
    int sizeN = N;
    int sizeM = M;

public:

    T &address(int a, int b) {
        if (a >= N || a < 0 || b >= M || b < 0)
            throw new matrix_element_doesnt_exist();
        return data[a][b];
    }

};

#endif //PROGRAMMING_MATRIX_H
