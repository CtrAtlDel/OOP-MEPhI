#include <iostream>
#include "dialog.hpp"
#include "../library/vec.hpp"
#include "../Get/Get.hpp"

namespace dialog {
    void menu(const vec::double_vector &v1, const vec::double_vector &v2) {
        std::cout << std::endl;
        std::cout << "V1:" << std::endl;
        std::cout << v1;
        std::cout << "V2:" << std::endl;
        std::cout << v2;
        std::cout << "Menu:" << std::endl;
        std::cout << "0.Exit" << std::endl << "1.New" << std::endl << "2. Add elem" << std::endl
                  << "3.V1+V2 " << std::endl << "4. V1-V2" << std::endl
                  << "5. V1*V2" << std::endl << "6.MAX" << std::endl << "7. Bool" << std::endl;
        std::cout << "Choose:" << std::endl;
    }

    void Dialog() {
        const char *pr, *prt;
        bool vvod = true;
        int ans, ans1;
        double x;
        bool answer;
        vec::double_vector v1, v2, v3;
        while (vvod) {
            menu(v1, v2);
            pr = "";
            prt = "";
            do {
                std::cout << pr << std::endl;
                pr = "You are wrong; repeat please!";
                getNum(ans);
            } while (ans > 7 || ans < 0);

            if (ans == 0) {
                vvod = false;

            } else if (ans == 1) {
                std::cout << "1 or 2?" << std::endl;
                do {
                    std::cout << prt << std::endl;
                    prt = "You are wrong; repeat please!";
                    getNum(ans1);
                } while (ans1 > 2 || ans1 < 0);
                if (ans1 == 1) {
                    std::cin >> v1;
                } else {
                    v2.new_from_terminal(std::cout);
                }

            } else if (ans == 2) {
                std::cout << "1 or 2?" << std::endl;
                do {
                    std::cout << prt << std::endl;
                    prt = "You are wrong; repeat please!";
                    getNum(ans1);
                } while (ans1 > 2 || ans1 < 0);
                std::cout << "Write elem" << std::endl;
                getNum(x);
                if (ans1 == 1) {
                    v1.add(x);
                } else {
                    v2.add(x);
                }
            } else if (ans == 3) {
                v3 = v1 + v2;
                v3.output(std::cout);

            } else if (ans == 4) {
                v3 = v1 - v2;
                v3.output(std::cout);
            } else if (ans == 5) {
                v3 = v1 * v2;
                v3.output(std::cout);
            } else if (ans == 6) {
                std::cout << "1 or 2?" << std::endl;
                do {
                    std::cout << prt << std::endl;
                    prt = "You are wrong; repeat please!";
                    getNum(ans1);
                } while (ans1 > 2 || ans1 < 0);
                if (ans1 == 1) {
                    x = v1.maximum();
                } else {
                    x = v2.maximum();
                }
                std::cout << " MAX:" << x << std::endl;
            } else if (ans == 7) {
                std::cout << "1 or 2?" << std::endl;
                do {
                    std::cout << prt << std::endl;
                    prt = "You are wrong; repeat please!";
                    getNum(ans1);
                } while (ans1 > 2 || ans1 < 0);
                if (ans1 == 1) {
                    answer = v1();
                    std::cout << answer;
                } else {
                    answer = v2();
                    std::cout << answer;
                }
            }
        }
    }
}