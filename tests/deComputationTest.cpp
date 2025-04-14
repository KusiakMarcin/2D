//
// Created by kusia on 11.04.2025.
//
#include "../Matrix.h"
#include <catch2/catch_test_macros.hpp>

int matrix1[] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
};
int matrix2[] = {
        2, 3, 1,
        0, 4, 5,
        0, 0, 6
};
int matrix3[] = {
        6, 1, 1,
        4, -2, 5,
        2, 8, 7
};
int matrix4[] = {
        1, 2, 3,
        0, 0, 0,
        7, 8, 9
};
int expectedDet4 = 0;

int expectedDet3 = -306;

int expectedDet2 = 2 * 4 * 6;  // = 48

int expectedDet1 = 1;
int matrix5[] = {
        2, 5, 3,
        1, -2, -1,
        1, 3, 4
};
int expectedDet5 = -20;


Matrix Matrix1(matrix1,3);
Matrix Matrix2(matrix2,3);
Matrix Matrix3(matrix3,3);
Matrix Matrix4(matrix4,3);
Matrix Matrix5(matrix5,3);

TEST_CASE("det Computation","[Determinant]"){
    Matrix1.computeDet();
    Matrix2.computeDet();
    Matrix3.computeDet();
    Matrix5.computeDet();
    CHECK(Matrix1.computeDet()==1);
    CHECK(Matrix2.computeDet()==48);
    CHECK(Matrix3.computeDet()==-306);
    CHECK(Matrix4.computeDet()==0);
    CHECK(Matrix5.computeDet()==-20);


}
