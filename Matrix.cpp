#include "Matrix.h"
#include "iostream"
const char* errmsg[] = {
        "Data size didn't match dimension",
        "some other errmsg"
};
Matrix::Matrix(int *matrix[], int dimension) {

    this->matrix = matrix;
    this->dimension = dimension;

}

void Matrix::printMatrix() {
    char * tmp;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            std::cout<<*(this->matrix[i]+j)<<"|";
        }
        std::cout<<std::endl;
    }

}


//int Matrix::computeDet(int *matrix[],int dim){
//    int det;
//    if(dim>2){
//        for(int i=0 ;i<dim;i++){
//
//        }
//    }
//    return computeDet();
//}


Matrix * Matrix::matrixCofactor(int column, int verse){
    int ** tmp;
    int i=0;
    int jtmp =0;
    int itmp =0;
    int j=0;
    tmp = new int*[dimension-1];
    while(i<dimension){
        if(i!=verse){
            tmp[itmp] = new int [dimension-1];
            while(j<dimension){
                if(j!=column) {
                    *(tmp[itmp]+jtmp)=*(matrix[i]+j);
                    j++;
                    jtmp++;
                }else{
                    j++;
                }
            }

            i++;
            itmp++;
            j=0;
        }else{
            i++;
        }
    }
    Matrix *cofactor = new Matrix(tmp,dimension-1);
    return cofactor;
}

MatrixException::MatrixException(errorType type){
    this->type = type;
}
char * MatrixException::what(){
    switch (type) {
        case DATA_DIMENSION_MISMATCH:
            return "DATA_MISMATCH";

    }
}