
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

    Line* addInLine(Line* l, int x, int a) {
        Line* head = l;
        while (l && l->next) {
            if (l->j > x) { //need to add at start of line
                Line* next = l;
                l = createLine(x, a);
                l->next = next;
                return l;
            }
            if (l->j < x && l->next->j > x) {
                Line* next = l->next;
                l->next = createLine(x, a);
                l->next->next = next;
                return head;
            }
            if (l->j == x) {
                l->data = a;
                return head;
            }
            l = l->next;
        }
        if (l) { //end of line
            if (l->j == x) {
                l->data = a;
                return head;
            }
            if (l->j > x) { //add previous
                Line* next = l;
                l = createLine(x, a);
                l->next = next;
                return l;
            }
            l->next = createLine(x, a);
        }
        return head;
    }

//    Line *newLine(Line *line, int &j, int &data) {
//        Line *ptr = line;
//        while (ptr != nullptr && ptr->next != nullptr) {
//            if (ptr->j > j) {
//                Line *newItem = ptr;
//                ptr = createLine(j, data);
//                ptr->next = newItem;
//                return line;
//            }
//            if (ptr->j < j && ptr->next->j > j) {
//                Line *newLine = ptr->next;
//                ptr->next = createLine(j, data);
//                return line;
//            }
//            if (ptr->j == j) {
//                ptr->data = data;
//                return line;
//            }
//        }
//        /// check end
//        if (ptr != nullptr) {
//            if (ptr->j == j) {
//                ptr->data = data;
//                return line;
//            }
//            if (ptr->j > j) {
//                Line *newLine = ptr;
//                ptr = createLine(j, data);
//                return line;
//            }
//            ptr->next = createLine(j, data);
//        }
//        return line;
//    }

//    Matrix *insert(Matrix *matrix, int &i, int &j, int &data) {
//        if (matrix->begin == nullptr) {
//            matrix->begin = createColl(i, j, data);
//            return matrix;
//        }
//        Coll *ptr = nullptr;
//        ptr = matrix->begin;
//        while (ptr != nullptr && ptr->nextDown != nullptr) { /// nextDown? ofcourse
//            if (ptr->i > i) { /// вставить перед элементом
//                Coll *newColl = ptr;
//                ptr = createColl(i, j, data);
//                ptr->nextDown = newColl;
//                matrix->begin = ptr;
//                return matrix;
//            }
//            if (ptr->i < i && ptr->nextDown->i > i) {  /// вставить после элемента
//                Coll *tmp = ptr->nextDown;
//                ptr->nextDown = createColl(i, j, data);
//                ptr->nextDown->nextDown = tmp;
//                return matrix;
//            }
//            if (ptr->i == i) { /// вставить в существующую линию
//                Line *tmpLine = ptr->nextRight;
//                ptr->nextRight = newLine(tmpLine, j, data);
//                return matrix;
//            }
//            ptr = ptr->nextDown;
//        }
//        if (ptr != nullptr) {
//            if (ptr->i == i) {
//                Line *tmpLine = ptr->nextRight;
//                ptr->nextRight = newLine(tmpLine, j, data);
//                return matrix;
//            }
//            if (ptr->i > i) {
//                Coll *newColl = ptr;
//                ptr = createColl(i, j, data);
//                ptr->nextDown = newColl;
//                matrix->begin = ptr;
//                return matrix;
//            }
//            ptr->nextDown = createColl(i, j, data);
//        }
//        return matrix;
//    }

    Matrix* addElement(Matrix* m, int x, int y, int a) {
        if (!m->begin) { //if matrix is empty
            m->begin = createColl(x, y, a);
            return m;
        }
        Coll* list = m->begin;
        while (list && list->nextDown) {
            if (list->i > y) { //need to add element in start of list
                Coll* head = list;
                list = createColl(x, y, a);
                list->nextDown = head;
                m->begin = list;
                return m;
            }
            if (list->i < y && list->nextDown->i > y) { // need to add element between list and next
                Coll* next = list->nextDown;
                list->nextDown = createColl(x, y, a);
                list->nextDown->nextDown = next;
                return m;
            }
            if (list->i == y) { //needed line already exists
                list->nextRight = addInLine(list->nextRight, x, a);
                return m;
            }
            list = list->nextDown;
        }
        if (list) {
            if (list->i == y) {
                list->nextRight = addInLine(list->nextRight, x, a);
                return m;
            }
            if (list->i > y) {
                Coll * next = list;
                list = createColl(x, y, a);
                list->nextDown = next;
                m->begin = list;
                return m;
            }
            list->nextDown = createColl(x, y, a);
        }
        return m;
    }

    void input() {
        Matrix* matrix;
        int m, n;
        char quit;
        do {
            std::cout << "Please, enter size of matrix (m x n): --> ";
            m = getInt();
            n = getInt();
        } while ((m < 1) || (n < 1));
        matrix = new Matrix;
        matrix->n = n;
        matrix->m = m;
        matrix->begin = nullptr;
        int x, y, a;
        std::cout << "Now enter elements:" << std::endl;
        do {
            std::cout << "Enter the first index: --> ";
            x = getInt();
            if (x < 1 || x > m) {
                std::cout << "Index must be >= 1 and <= m" << std::endl;
                continue;
            }
            std::cout << "Enter the second index: --> ";
            y = getInt();
            if (y < 1 || y > n) {
                std::cout << "Index must be >= 1 and <= n" << std::endl;
                continue;
            }
            std::cout << "Enter value of the element: --> ";
            a = getInt();
            if (a == 0) {
                std::cout << "Zeroes are already in the matrix!" <<  std::endl;
                continue;
            }
            matrix = addElement(matrix, x, y, a);
            std::cout << "If you want to quit, type 'q': --> ";
            std::cin >> quit;
        } while (quit != 'q');
        print(matrix);
    }

    void print (Matrix* m) {
        if (m && m->begin) {
            std::cout << "Your matrix:" << std::endl;
            Coll* list = m->begin;
            for (int i = 1; i <= m->n; ++i) {
                if (list && list->i == i) {
                    Line *row = list->nextRight;
                    for (int j = 1; j <= m->m; ++j) {
                        if (row && row->j == j) {
                            std::cout << row->data << " ";
                            row = row->next;
                        } else
                            std::cout << "0 ";
                    }
                    std::cout << std::endl;
                    list = list->nextDown;
                } else {
                    for (int j = 1; j <= m->m; ++j)
                        std::cout << "0 ";
                    std::cout << std::endl;
                }
            }
        }
        else {
            std::cout << "There are no non-zero values in the matrix!" << std::endl;
        }
    }

//    void Menu() {
//        int n;
//        int m;
//        char exit;
//        do {
//            std::cout << "Please, enter size of matrix (n x m): --> ";
//            getNum(n);
//            getNum(m);
//        } while ((m < 1) || (n < 1));
//        Matrix *matrix = createMatrix();
//        matrix->n = n;
//        matrix->m = m;
//        int i, j, data;
//        do {
//            std::cout << "Enter the first index -> ";
//            getNum(i);
//            if (i < 1 || i > n) {//i>n
//                std::cout << "Index must be >= 1 and <= m" << std::endl;
//                continue;
//            }
//            std::cout << "Enter the second index -> ";
//            getNum(j);
//            if (j < 1 || j > m) { //j>n
//                std::cout << "Index must be >= 1 and <= n" << std::endl;
//                continue;
//            }
//            std::cout << "Input data -> ";
//            getNum(data);
//            if (data == 0) {
//                std::cout << "Zeroes are already in the matrix!" << std::endl;
//                continue;
//            }
//            matrix = addElement(matrix, i, j, data);
//            std::cout << "If you want to quit, type 'q' -> ";
//            getNum(exit);
//        } while (exit != 'q');
//        printMatrix(matrix);
//    }

//    void printMatrix(Matrix *matrix) {
//        if (matrix != nullptr && matrix->begin != nullptr) {
//            std::cout << "Martix:" << std::endl;
//            Coll *ptr = matrix->begin;
//            for (int i = 1; i <= matrix->n; ++i) {
//                if (ptr != nullptr && ptr->i == i) {
//                    Line *ptrLine = ptr->nextRight;
//                    for (int j = 1; j <= matrix->m; ++j) {
//                        if (ptrLine != nullptr && ptrLine->j == j) {
//                            std::cout << ptrLine->data << " ";
//                            ptrLine = ptrLine->next;
//                        } else {
//                            std::cout << "0 ";
//                        }
//                    }
//                    std::cout << std::endl;
//                    ptr = ptr->nextDown;
//                } else {
//                    for (int j = 1; j <= matrix->m; ++j) {
//                        std::cout << "0 ";
//                    }
//                    std::cout << std::endl;
//                }
//            }
//        } else { std::cout << "All elements in matrix zero" << std::endl; };
//    };

    int getInt() {
        int a;
        std::cin >> a;
        if (!std::cin.good())
            throw std::invalid_argument("Enter integer numbers only!");
        return a;
    }
}
