
#include<iostream>

namespace SparceMatrix {

    struct Data {
        int i;
        int j;
        int data;
    };

    struct Line{
        int j;
        int data;
        Line* next;
    };

    struct Coll {
        int i;
        Line* nextRight;
        Coll* nextDown;
    };

    struct Matrix{
        int n;
        int m;
        Coll* begin;
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

    Matrix* createMatrix();

    Matrix* insert(Matrix* matrix, int i, int j, int data);
}


