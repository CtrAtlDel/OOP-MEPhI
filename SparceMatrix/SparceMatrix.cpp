
#include "SparceMatrix.h"

namespace SparceMatrix {
    Matrix *createMatrix() {
        Matrix *matrix = new Matrix;
        matrix->begin = nullptr;
        return matrix;
    }

    Coll *createColl(int &i, int &data) {
        Coll *collum = nullptr;
        collum = new Coll;
        collum->i = i;
        collum->nextDown = nullptr;
        collum->nextRight = nullptr;
        Line *line = new Line;
        collum->nextRight = line;
        line->data = data;
        line->next = nullptr;
        return collum;
    }

    Line *createLine(int &j, int & data) {
        Line *line = new Line;
        line->next = nullptr;
        line->j = j;
        line->data = data;
        return line;
    }

    Line* newLine(Line* line, int& j, int& data){
        Line* ptr = line;
        while(ptr!=nullptr && ptr->next != nullptr){
            if (ptr->j > j){
                Line* newItem = ptr;
                ptr = createLine(j, data);
                ptr->next = newItem;
                return line;
            }
            if (ptr->j < j && ptr->next->j > j){
                Line* newLine = ptr->next;
                ptr->next = createLine(j, data);
                return line;
            }
            if (ptr->j == j){
                ptr->data = data;
                return line;
            }
        }
        return line;
    }

    Matrix *insert(Matrix *matrix, int &i, int &j, int &data) {
        if (matrix->begin == nullptr) {
            matrix->begin = createColl(i, data);
            return matrix;
        }
        Coll *ptr = nullptr;
        ptr = matrix->begin;
        while (ptr != nullptr && ptr->nextDown) { /// nextDown? ofcourse
            if (ptr->i > i) { /// вставить перед элементом
                Coll *newColl = ptr;
                ptr = createColl(i, data);
                ptr->nextDown = newColl;
                matrix->begin = ptr;
                return matrix;
            }
            if (ptr->i < i && ptr->nextDown->i > i) {  /// вставить после элемента
                Coll *tmp = ptr->nextDown;
                ptr->nextDown = createColl(i, data);
                ptr->nextDown->nextDown = tmp;
                return matrix;
            }
            if (ptr->i == i) { /// вставить в существующую линию
                Line* tmpLine = ptr->nextRight;
                ptr->nextRight = newLine(tmpLine, j, data);
                return matrix;
            }
            ptr = ptr->nextDown;
        }
        return matrix;
    }
}
