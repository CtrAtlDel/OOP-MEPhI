//
// Created by Ivan on 05.10.2021.
//
#include <iostream>

namespace Lab2 {
    template<class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }
}