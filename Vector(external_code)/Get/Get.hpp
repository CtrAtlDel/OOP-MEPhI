//
// Created by ivan on 16.10.2021.
//

#ifndef LABA_3B_GET_HPP
#define LABA_3B_GET_HPP

#include <limits>


template<typename T>
void getNum(T &a) {
    while (!(std::cin >> a)) {
        if (std::cin.eof()) {
            throw std::runtime_error("EOF");
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You are wrong; repeat please!" << std::endl;
    }
}
#endif //LABA_3B_GET_HPP
