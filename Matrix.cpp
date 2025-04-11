#include "Matrix.h"

Matrix::Matrix(int *matrix[], int dimension) {

    this->matrix = matrix;
    this->dimension = dimension;

}

int Matrix::computeDet(){
    int det;
    if(dimension==2){

        det += matrix[0][iterator]
                +matrix[1][(iterator+1)%dimension]
                +matrix[2][(iterator+2)%dimension];
        det-= matrix[0][dimension]
                +matrix[1][dimension-(iterator+1)%dimension]
                +matrix[2][dimension-(iterator+2)%dimension];

    }else{for(int iterator = 0; iterator<dimension;iterator++){
            det += matrix[0][iterator]
                   +matrix[1][(iterator+1)%dimension]
                   +matrix[2][(iterator+2)%dimension];
            det-= matrix[0][dimension]
                  +matrix[1][dimension-(iterator+1)%dimension]
                  +matrix[2][dimension-(iterator+2)%dimension];
        }}
    return det;
}