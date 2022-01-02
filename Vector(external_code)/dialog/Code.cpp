#include <valarray>
#include <cmath>
#include "Code.h"
#include "../Get/Get.hpp"

namespace Program {
    void Start() {
        try {
            Hi();
            vec::double_vector v1, v2;
            int a = 1;
            std::cout << "Input 1 vectors (firstly input size): " << std::endl;
            std::cin >> v1;
            std::cout << "Input 2 vectors (firstly input size): " << std::endl;
            std::cin >> v2;
            std::cout << "Your vecttors" << std::endl;
            std::cout << v1;
            std::cout << v2;
            while (a) {
                Menu();
                int ch = -1;
                std::cout << "Input ch:" << std::endl;
                do {
                    getNum(ch);
                    if (ch < 0 || ch > 8) { std::cout << "Bad input. Try else: " << std::endl; }
                } while (ch < 0 || ch > 8);
                if (ch == 1) { std::cout << "Dot : " << v1 * v2 << std::endl; }
                if (ch == 2) { std::cout << "Max v1: " << v1.maximum() << " Max v2: " << v2.maximum() << std::endl; }
                if (ch == 3) { std::cout << "Angel : " << angel(v1, v2) << std::endl; }
                if (ch == 4) { std::cout << "Sum of vectors : " << v1 + v2; }
                if (ch == 5) { std::cout << "Length v1 : " << v1.get_n() << " Length v2: " << v2.get_n() << std::endl; }
                if (ch == 6) { std::cout << "Difference : " << v1 - v2 << std::endl; }
                if (ch == 7) { std::cout << "Norm v1 : " << norm(v1) << " Norm v2 : " << norm(v2) << std::endl; }
                if (ch == 8) { std::cout << "Skalar: " << skalar(v1, v2) << std::endl; }
                if (ch == 0) { break; }
            }
        }
        catch (std::exception &ex) {
            std::cout << ex.what() << std::endl;
        }
    }

    void Hi() {
        std::cout << "Hello student ! Now, I help you to paste your exam. " << std::endl;
    };

    double angel(vec::double_vector vector1, vec::double_vector vector2) {
        if (vector1.get_n() != vector2.get_n()) {
            throw std::invalid_argument("V1 size != V2 size");
        }
        double normv1 = norm(vector1);
        double normv2 = norm(vector2);
        vec::double_vector v3 = vector1 * vector2;
        double *arv3 = v3.get_mas();
        double sum = 0;
        for (int i = 0; i < vector1.get_n(); ++i) {
            sum += arv3[i];
        }
        return acos(sum / (normv1 * normv2));
    }

    double norm(vec::double_vector vector) {
        double *array = vector.get_mas();
        double result = 0.0;
        double sum = 0.0;
        if (vector.get_n() != 0) {
            for (int i = 0; i < vector.get_n(); ++i) {
                sum += array[i] * array[i];
            };
            return sqrt(sum);
        } else {
            return 0.0;
        }
    }

    double skalar(vec::double_vector vector1, vec::double_vector vector2){
            if (vector1.get_n() != vector2.get_n()) {
                throw std::invalid_argument("V1 size != V2 size");
            }
            double normv1 = norm(vector1);
            double normv2 = norm(vector2);
            vec::double_vector v3 = vector1 * vector2;
            double *arv3 = v3.get_mas();
            double sum = 0;
            for (int i = 0; i < vector1.get_n(); ++i) {
                sum += arv3[i];
            }
            return sum;
    }
    void Menu() {
        std::cout << "1. Dot product of vectors" << std::endl;
        std::cout << "2. Max elements of vectors" << std::endl;
        std::cout << "3. Angle between vectors" << std::endl; //угол между векторами
        std::cout << "4. Sum of vectors" << std::endl;
        std::cout << "5. Length of 2 vectors" << std::endl;
        std::cout << "6. Difference of vectors" << std::endl;
        std::cout << "7. Norms of vectors" << std::endl;
        std::cout << "8. Skalar of 2 vectors" << std::endl;
        std::cout << "If you wanna to exit, press 0" << std::endl;
    }

}