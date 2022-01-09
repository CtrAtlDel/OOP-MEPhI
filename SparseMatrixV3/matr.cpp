#include "matr.h"

namespace SparseMatrix {

    Matrix *input() {
        Matrix *matrix;
        int m, n;
        char quit;
        do {
            std::cout << "Input size of matrix m and n: ";
            m = getInt();
            n = getInt();
        } while ((m < 1) || (n < 1));
        matrix = new Matrix;
        matrix->n = n;
        matrix->m = m;
        matrix->begin = nullptr;
        int x, y, a;
        std::cout << "Input elements:" << std::endl;
        std::cout << "Like in physical system(x,y) " << std::endl;
        do {
            std::cout << "Enter the first index: -> ";
            x = getInt();
            if (x < 1 || x > m) {
                std::cout << "ERROR bad input, index must be >= 1 and <= m" << std::endl;
                continue;
            }
            std::cout << "Enter the second index: -> ";
            y = getInt();
            if (y < 1 || y > n) {
                std::cout << "ERROR bad input, index must be >= 1 and <= n" << std::endl;
                continue;
            }
            std::cout << "Input value of the element: -> ";
            a = getInt();
            if (a == 0) {
                std::cout << "In your matrix only 0" << std::endl;
                continue;
            }
            matrix = addElement(matrix, x, y, a);
            std::cout << "If you want to quit, type letter q: -> ";
            std::cin >> quit;
        } while (quit != 'q');
        return matrix;
    }

    Matrix *addElement(Matrix *matrix, int x, int y, int data) {
        if (!matrix->begin) { /// Если матрица пустая
            matrix->begin = createColumn(x, y, data);
            return matrix;
        }
        Column *list = matrix->begin;
        while (list && list->next) {
            if (list->y > y) { /// Нужно вставить в начало списка
                Column *head = list;
                list = createColumn(x, y, data);
                list->next = head;
                matrix->begin = list;
                return matrix;
            }
            if (list->y < y && list->next->y > y) { /// Нужно вставить элемент между колком и следующим за ним
                Column *next = list->next;
                list->next = createColumn(x, y, data);
                list->next->next = next;
                return matrix;
            }
            if (list->y == y) { /// Нужная строка уже есть
                list->lines = addInLine(list->lines, x, data);
                return matrix;
            }
            list = list->next;
        }
        if (list) {
            if (list->y == y) {
                list->lines = addInLine(list->lines, x, data);
                return matrix;
            }
            if (list->y > y) {
                Column *next = list;
                list = createColumn(x, y, data);
                list->next = next;
                matrix->begin = list;
                return matrix;
            }
            list->next = createColumn(x, y, data);
        }
        return matrix;
    }

    void print(Matrix *matrix) {
        if (matrix && matrix->begin) {
            std::cout << "Matrix:" << std::endl;
            Column *list = matrix->begin;
            for (int i = 1; i <= matrix->n; ++i) {
                if (list && list->y == i) {
                    Line *row = list->lines;
                    for (int j = 1; j <= matrix->m; ++j) {
                        if (row && row->x == j) {
                            std::cout << row->data << " ";
                            row = row->next;
                        } else{
//                            std::cout << "0 ";
                        }
                    }
//                    std::cout << std::endl;
                    list = list->next;
                } else {
//                    for (int j = 1; j <= matrix->m; ++j) {
//                        std::cout << "0 ";
//                    }
//                    std::cout << std::endl;
                }
            }
        } else {
            std::cout << std::endl;
            std::cout << "There are no non-zero values in the matrix!" << std::endl;
        }
    }

    Line *addInLine(Line *line, int x, int data) {
        Line *head = line;
        while (line && line->next) {
            if (line->x > x) { //need to add at start of line
                Line *next = line;
                line = createLine(x, data);
                line->next = next;
                return line;
            }
            if (line->x < x && line->next->x > x) {
                Line *next = line->next;
                line->next = createLine(x, data);
                line->next->next = next;
                return head;
            }
            if (line->x == x) {
                line->data = data;
                return head;
            }
            line = line->next;
        }
        if (line) { //end of line
            if (line->x == x) {
                line->data = data;
                return head;
            }
            if (line->x > x) { //add previous
                Line *next = line;
                line = createLine(x, data);
                line->next = next;
                return line;
            }
            line->next = createLine(x, data);
        }
        return head;
    }

    Column *createColumn(int x, int y, int data) {
        Column *collumn;
        collumn = new Column;
        collumn->y = y;
        collumn->lines = createLine(x, data);
        collumn->next = nullptr;
        return collumn;
    }

    Line *createLine(int x, int a) {
        Line *line;
        line = new Line;
        line->x = x;
        line->data = a;
        line->next = nullptr;
        return line;
    }

    void deleteMatrix(Matrix *m) {
        if (m) {
            if (m->begin) {
                Column *list = m->begin;
                while (list) {
                    Line *line = list->lines;
                    while (line) {
                        Line *ptr = line->next;
                        delete line;
                        line = ptr;
                    }
                    Column *tmp = list->next;
                    delete list;
                    list = tmp;
                }
            }
        }
        delete m;
    }



    int getInt() {
        int a;
        std::cin >> a;
        if (!std::cin.good())
            throw std::invalid_argument("it is not a integer");
        return a;
    }

    Matrix *algoMatrix(Matrix *matrix) {
        Matrix *newMatrix = new Matrix;
        newMatrix->n = matrix->n;
        newMatrix->m = matrix->m;
        newMatrix->begin = nullptr;
        Column *ptrCollum = matrix->begin;
        while (ptrCollum != nullptr) {
            if (findLine(ptrCollum) != nullptr) {
                copyLine(newMatrix, ptrCollum);
            }
            ptrCollum = ptrCollum->next;
        }
        return newMatrix;
    }

    int copyLine(Matrix *newMatrix, Column *column) {
        Column *ptrCol = column;
        int y = column->y;
        Line *ptrLine = column->lines;
        while (ptrLine) {
            addElement(newMatrix, ptrLine->x, y, ptrLine->data);
            ptrLine = ptrLine->next;
        }
        return 1;
    }

    Column *findLine(Column *column) {
        Column *ptr = column;
        Line *ptrLine = ptr->lines;
        Line *begin = ptr->lines;
        int sum = sumLine(ptr->lines);
        Line *end = endItem(begin, sum);
        int roBegin = 0; /// расстояние от начального номера
        int roEnd = 0; /// расстояние от конечного номера
        int counter = sum;
        Line *tmp = nullptr;
        if (sum == 1)
            return nullptr;
        while (ptrLine != nullptr) {
            tmp = endItem(begin, counter); /// элемент с конца
            roBegin = ptrLine->x - begin->x; /// расстояние от начала
            roEnd = end->x - tmp->x; /// расстояние от конца
            if (ptrLine->x == tmp->x) {
                return column;
            }
            if (ptrLine->x > tmp->x)
                return column;
            if (ptrLine->data == tmp->data && roBegin == roEnd) {
                ptrLine = ptrLine->next;
                continue;
            } else {
                return nullptr;
            }
        }
    }

    Line *endItem(Line *begin, int count) { //возвращает конечный элемент
        Line *ptr = begin;
        int sum = 0;
        while (ptr != nullptr) {
            ++sum;
            if (sum == count)
                return ptr;
            ptr = ptr->next;
        }
        return nullptr;
    }

    int sumLine(Line *line) {
        Line *ptrLine = line;
        int count = 0;
        while (ptrLine != nullptr) {
            count++;
            ptrLine = ptrLine->next;
        }
        return count;
    }
}