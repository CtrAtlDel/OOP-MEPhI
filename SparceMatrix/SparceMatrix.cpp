
#include "SparceMatrix.h"
#include "iostream"

namespace SparceMatrix {

    Matrix *createMatrix() {
        Matrix *matrix = new Matrix;
        matrix->begin = nullptr;
        return matrix;
    }

    Coll *createColl(int &x, int &y, int &data) {
        Coll *collum = nullptr;
        collum = new Coll;
        collum->i = x;
        collum->nextDown = nullptr;
        collum->nextRight = nullptr;
        Line *line = createLine(x, data);
        collum->nextRight = line;
        return collum;
    }

    Line *createLine(int &x, int &data) {
        Line *line = new Line;
        line->next = nullptr;
        line->j = x;
        line->data = data;
        return line;
    }

    Line *newLine(Line *line, int &j, int &data) {
        Line *ptr = line;
        while (ptr != nullptr && ptr->next != nullptr) {
            if (ptr->j > j) {
                Line *newItem = ptr;
                ptr = createLine(j, data);
                ptr->next = newItem;
                return line;
            }
            if (ptr->j < j && ptr->next->j > j) {
                Line *newLine = ptr->next;
                ptr->next = createLine(j, data);
                return line;
            }
            if (ptr->j == j) {
                ptr->data = data;
                return line;
            }
        }
        /// check end
        if (ptr != nullptr) {
            if (ptr->j == j) {
                ptr->data = data;
                return line;
            }
            if (ptr->j > j) {
                Line *newLine = ptr;
                ptr = createLine(j, data);
                return line;
            }
            ptr->next = createLine(j, data);
        }
        return line;
    }

    Matrix *insert(Matrix *matrix, int &i, int &j, int &data) {
        if (matrix->begin == nullptr) {
            matrix->begin = createColl(i, j, data);
            return matrix;
        }
        Coll *ptr = nullptr;
        ptr = matrix->begin;
        while (ptr != nullptr && ptr->nextDown != nullptr) { /// nextDown? ofcourse
            if (ptr->i > i) { /// вставить перед элементом
                Coll *newColl = ptr;
                ptr = createColl(i, j, data);
                ptr->nextDown = newColl;
                matrix->begin = ptr;
                return matrix;
            }
            if (ptr->i < i && ptr->nextDown->i > i) {  /// вставить после элемента
                Coll *tmp = ptr->nextDown;
                ptr->nextDown = createColl(i, j, data);
                ptr->nextDown->nextDown = tmp;
                return matrix;
            }
            if (ptr->i == i) { /// вставить в существующую линию
                Line *tmpLine = ptr->nextRight;
                ptr->nextRight = newLine(tmpLine, j, data);
                return matrix;
            }
            ptr = ptr->nextDown;
        }
        if (ptr != nullptr) {
            if (ptr->i == i) {
                Line *tmpLine = ptr->nextRight;
                ptr->nextRight = newLine(tmpLine, j, data);
                return matrix;
            }
            if (ptr->i > i) {
                Coll *newColl = ptr;
                ptr = createColl(i, j, data);
                ptr->nextDown = newColl;
                matrix->begin = ptr;
                return matrix;
            }
            ptr->nextDown = createColl(i, j, data);
        }
        return matrix;
    }

    void Menu() {
        int n;
        int m;
        char exit;
        do {
            std::cout << "Please, enter size of matrix (m x n): --> ";
            n = getInt();
            m = getInt();
        } while ((m < 1) || (n < 1));
        Matrix *matrix = createMatrix();
        matrix->n = n;
        matrix->m = m;
        int i, j, data;
        do {
            std::cout << "Enter the first index: --> ";
            i = getInt();
            if (i < 1 || i > m) {
                std::cout << "Index must be >= 1 and <= m" << std::endl;
                continue;
            }
            std::cout << "Enter the second index: --> ";
            j = getInt();
            if (j < 1 || j > n) {
                std::cout << "Index must be >= 1 and <= n" << std::endl;
                continue;
            }
            std::cout << "Enter value of the element: --> ";
            data = getInt();
            if (data == 0) {
                std::cout << "Zeroes are already in the matrix!" << std::endl;
                continue;
            }
            matrix = insert(matrix, i, j, data);
            std::cout << "If you want to quit, type 'q': --> ";
            std::cin >> exit;
        } while (exit != 'q');
        printMatrix(matrix);
    }

    void printMatrix(Matrix *matrix) {
        if (matrix != nullptr && matrix->begin != nullptr) {
            std::cout << "Martix:" << std::endl;
            Coll *ptr = matrix->begin;
            for (int i = 1; i <= matrix->n; ++i) {
                if (ptr != nullptr && ptr->i == i) {
                    Line *ptrLine = ptr->nextRight;
                    for (int j = 1; j <= matrix->m; ++j) {
                        if (ptrLine != nullptr && ptrLine->j == j) {
                            std::cout << ptrLine->data << " ";
                            ptrLine = ptrLine->next;
                        } else {
                            std::cout << "0 ";
                        }
                    }
                    std::cout << std::endl;
                    ptr = ptr->nextDown;//ptrLine = ptrLine->next;//todo fix this
                } else {
                    for (int j = 1; j <= matrix->m; ++j) {
                        std::cout << "0 ";
                    }
                    std::cout << std::endl;
                }
            }
        } else { std::cout << "All elements in matrix zero" << std::endl; };
    };

    int getInt() {
        int a;
        std::cin >> a;
        if (!std::cin.good())
            throw std::invalid_argument("Enter integer numbers only!");
        return a;
    }
}
