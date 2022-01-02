
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

    Line *createLine(int &j, int &data) {
        Line *line = nullptr;
        line = new Line;
        line->next = nullptr;
        line->j = j;
        line->data;
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
            if (ptr->i < i) { /// вставить перед элементом
                Coll *newColl = createColl(i, data);
                Coll *tmp = ptr;
                ptr->nextDown = newColl;
                matrix->begin = ptr;
                return matrix;
            }
            if (ptr->i > i && ptr->nextDown->i < i) {  /// вставить после элемента
                Coll *newColl = ptr->nextDown;
                newColl = createColl(i, data);


                return matrix;
            }
            if (ptr->i == i) { /// вставить в существующую линию

                break;
            }

            ptr = ptr->nextDown;
        }
        return matrix;
    }
}
