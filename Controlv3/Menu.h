#ifndef TEST_MENU_H
#define TEST_MENU_H
#include "Application.h"

#include "Menu.h"
#include "Application.h"

namespace Console {
    void Menu() {
        Application app;
        int n;
        std::string initials, surname, themeUIR, placeUIR;
        double numberTeacher = 0;
        while (true) {
            std::cout << "0. Exit " << std::endl;
            std::cout << "1. Create new student " << std::endl;
            std::cout << "2. Input theme UIR " << std::endl;
            std::cout << "3. Input place UIR " << std::endl;
            std::cout << "4. Input number teacher " << std::endl;
            std::cout << "5. Print all students " << std::endl;
            std::cout << "6. Print student " << std::endl;
            std::cout << "7. Get median from group " << std::endl;
            std::cout << "8. Go to another class " << std::endl;

            if (!getNum(n)) {
                std::cout << "Bad input try again" << std::endl;
                continue;
            }
            if (n == 0) {
                std::cout << "Good bye" << std::endl;
                break;
            }
            if (n == 1) {

            }
            if (n == 2){

            }
            if (n == 3){

            }
            if (n == 4){

            }
            if (n == 5){

            }
            if (n == 6){

            }
            if (n == 7){

            }
            if (n == 8){

            }
        }
    }
}
#endif //TEST_MENU_H
