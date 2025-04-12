#include "Engine.h"
//#include "Circle.h"
#include "Matrix.h"
int main(int argc, char *argv[])
{
    const char *title = "bruh";
    //Engine *engine = new Engine(title,200,200,400,400);
    int matrix1[] = {
            1, 2,
            3, 4
    };
    int dimension1 = 2;
    Matrix Matrix1(matrix1,dimension1);
    Matrix1.printMatrix();
    Matrix* Matrix2 = Matrix1.matrixCofactor(0,0);
    Matrix1.printMatrix();
    Matrix2->printMatrix();
    delete Matrix2;
    return 0;
}