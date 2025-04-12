//
// Created by kusia on 11.04.2025.
//
#include "../Matrix.h"
#include <catch2/catch_test_macros.hpp>
int matrix1[] = {
        1, 2,
        3, 4
};
int dimension1 = 2;
int matrix2[] = {
        5, 6,
        7, 8
};
int dimension2 =2;
int matrix3[] = {
        -1, 0,
        0, -1
};
int dimension3 = 2;

Matrix Matrix1(matrix1,dimension1);
Matrix Matrix2(matrix2,dimension2);
Matrix Matrix3(matrix3,dimension3);
TEST_CASE("Matrix init","[Initialization]"){


}
int main(){
    Matrix1.printMatrix();
    Matrix2.printMatrix();
    Matrix3.printMatrix();
}

