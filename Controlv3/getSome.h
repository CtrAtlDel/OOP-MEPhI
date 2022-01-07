#ifndef TEST_GETSOME_H
#define TEST_GETSOME_H

#include <iostream>
#include <string>


template<class T>
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

#endif //TEST_GETSOME_H
