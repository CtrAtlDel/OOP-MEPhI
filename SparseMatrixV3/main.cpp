#include <iostream>
#include "matr.h"


int main() {
    SparseMatrix::Matrix *matrix = SparseMatrix::input();
    SparseMatrix::print(matrix);
    SparseMatrix::Matrix *newMatrix = SparseMatrix::algoMatrix(matrix);
    SparseMatrix::print(newMatrix);
    SparseMatrix::deleteMatrix(matrix); /// old matrix
    SparseMatrix::deleteMatrix(newMatrix);/// new matrix
    return 0;
}
