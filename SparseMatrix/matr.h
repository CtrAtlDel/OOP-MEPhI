#ifndef ADENIUM_ADENIUM_H
#define ADENIUM_ADENIUM_H

#include <iostream>

using std::exception;

namespace SparseMatrix {
    struct Line {
        int x;
        int data;
        Line *next;
    };

    struct Column {
        int y;
        Line *lines;
        Column *next;
    };

    struct Matrix {
        int n; //quantity of lines
        int m; //quantity of columns
        Column *begin;
    };

    Matrix *input();

    void print(Matrix *matrix);

    Matrix *addElement(Matrix *matrix, int x, int y, int data);

    Line *addInLine(Line *line, int x, int data);

    Column *createColumn(int, int, int);

    Line *createLine(int, int);

    void deleteMatrix(Matrix *);

    int getInt();

    Matrix *algoMatrix(Matrix *matrix);

    Column *findLine(Column *column) ;

    int copyLine(Matrix* newMatrix, Column* column);

    int sumLine(Line* line);

    Line* endItem(Line* begin, int count);
}

#endif //ADENIUM_ADENIUM_H