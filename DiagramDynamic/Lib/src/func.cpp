//
// Created by Ivan on 05.10.2021.
//
#include <iostream>
#include <limits>
namespace Lab3 {
    template<class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            return -1;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        return 1;
    }
}