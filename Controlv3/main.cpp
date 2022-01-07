#include <iostream>
#include "vector.h"

int main() {
    int size = 10;
    templates::vector<int> vector1;
    templates::vector<int> vector2;
    for (int i = 0; i < size; ++i) {
        vector1.push_back(i);
    }
    vector2 = fun(10);
    for (int i = 0; i < vector2.size(); ++i) {
        std::cout << vector2[i];
    }
    return 0;
}
