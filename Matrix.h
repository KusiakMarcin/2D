//
// Created by marcin on 06.04.25.
//

#ifndef SDL2TEST_MATRIX_H
#define SDL2TEST_MATRIX_H
#include <vector>





class Matrix {

private:
    int **matrix;
    int dimension;
public:
    Matrix(int * matrix[], int dimension);
    int computeDet();

};


#endif //SDL2TEST_MATRIX_H
