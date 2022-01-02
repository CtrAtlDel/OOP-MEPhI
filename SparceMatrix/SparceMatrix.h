
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

    struct Collum {
        int i;
        Line* nextRight;
        Collum* nextDown;
    };

    struct Matrix{
        int n;
        int m;
        Collum* begin;
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


}


