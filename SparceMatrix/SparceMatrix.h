#ifndef SPARCEMATRIX_SPARCEMATRIX_H
#define SPARCEMATRIX_SPARCEMATRIX_H

#include<iostream>

/// struct of matrix

namespace SparceMatrix {
    struct Data {
        int i;
        int j;
        int data;
    };
    struct Line {
        Data *data;
        Line *nextRight;
        Line *nextDown;
    };
    struct Matrix {
        int n;
        int m;
        Line *begin;
    };

    template<typename T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    Matrix* createNewMatrix(int &n, int &m);

    int insert(Matrix* matrix, int& i, int& j, int& data);

    int printMatrix(Matrix* matrix);
}

#endif //SPARCEMATRIX_SPARCEMATRIX_H
