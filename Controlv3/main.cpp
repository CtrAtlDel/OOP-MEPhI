#include <iostream>
#include "vector.h"

int main() {
    int size = 10;
    templates::vector<int> vector1;
    for (int i = 0; i < size; ++i) {
        vector1.push_back(i);
    }
    std::cout << "Size: " << vector1.size() << std::endl;
    for (int i = 0; i < vector1.size(); ++i) {
        std::cout << " " << vector1[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < vector1.size(); ++i) {
        std::cout << " " << vector1.get(i);
    }
    return 0;
}
