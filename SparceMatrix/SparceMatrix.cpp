
#include "SparceMatrix.h"

using namespace SparceMatrix;

/// matrix size n * m
Matrix *createMatrix(int &n, int &m) {
    Matrix *matrix = new Matrix;
    matrix->begin = nullptr;
    matrix->n = n;
    matrix->m = m;
    return matrix;
}

/**
 *
 * @param matrix матрица
 * @param i индекс строки
 * @param j индекс столбца
 * @param data информация
 * @return
 */
int insert(Matrix *matrix, int &i, int &j, int &data) { /// считаем что данные корректны
    Line *item = new Line;
    Data *info = new Data;
    int success = 1;
    info->i = i;
    info->j = j;
    info->data = data;
    item->data = info;
    item->nextRight = nullptr;
    item->nextDown = nullptr;
    if (matrix->begin == nullptr) {
        matrix->begin = item;
        return 1;
    } else {
        Line *ptr = matrix->begin;
        while (ptr != nullptr) {
            if (ptr->data->i == i){
                Line* ptrLine = ptr;
                while(){

                }
            }
            ptr = ptr->nextDown;
        }
    }
}