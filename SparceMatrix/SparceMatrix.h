
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

//    void Menu();
    void input();

    void print (Matrix* m) ;

    void printMatrix(Matrix* matrix);

    Matrix* createMatrix();

    Line *createLine(int &y, int &data);

    Matrix* addElement(Matrix* m, int x, int y, int a) ;

//    Line *newLine(Line *line, int &j, int &data) ;

    Matrix *insert(Matrix *matrix, int &i, int &j, int &data);

    int getInt();

}


