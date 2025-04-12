
#ifndef SDL2TEST_MATRIX_H
#define SDL2TEST_MATRIX_H
#include <iostream>
enum errorType {DATA_DIMENSION_MISMATCH};


class MatrixException : std::exception{
private:


    errorType type;
public:
    char * what();
    MatrixException(errorType type);

};


class Matrix {

private:
    int **matrix;
    int dimension;
public:

    /**
     * Constructor Template for inicialization of square
     * Matrix object of N dimension
     *
     *
     * */
    template<size_t N>
    Matrix(const int (&matrix)[N],int dimension){
        try {
            int argumentSize = (sizeof matrix)/sizeof (int);
            if (argumentSize!= dimension * dimension) throw MatrixException(DATA_DIMENSION_MISMATCH);
            this->dimension = dimension;
            this->matrix = new int*[dimension];
            for(int i=0;i<dimension;i++){
                this->matrix[i]= new int[dimension];
                for(int j=0; j<dimension;j++) {
                    *(this->matrix[i] +j) = matrix[i*dimension+j];
                }
            }
        } catch (MatrixException e) {
            std::cerr<<e.what()<<std::endl;


        }

    };
    Matrix(int * matrix[], int dimension);
    /**
     * Creates cofactor relative to given columns and verse
     *
     *@param column
     * @param verse
     *
     * @return pointer to the two dimensional array
     * which represents matrix of the cofactor
     * */
    Matrix * matrixCofactor(int column, int verse);

    void printMatrix();
    int computeDet(int *matrix[] =NULL,int dim =0);

};



#endif //SDL2TEST_MATRIX_H
