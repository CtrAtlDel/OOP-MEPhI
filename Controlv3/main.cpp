#include <iostream>
#include "Menu.h"

int main() {

//    Console::Menu();
    Console::Application app;
    int n;
    std::string initials, surname, themeUIR, placeUIR;
    double numberTeacher = 0;
    while (true) {
        std::cout << "0. Exit " << std::endl;
        std::cout << "1. Create new student " << std::endl;
        std::cout << "2. Input theme UIR " << std::endl;
        std::cout << "3. Input place UIR " << std::endl;
        std::cout << "4. Input number teacher " << std::endl;
        std::cout << "5. Print all students " << std::endl; //
        std::cout << "6. Print student " << std::endl;
        std::cout << "7. Get median from group " << std::endl;
        std::cout << "8. Go to another class (lvlIp) " << std::endl;
        std::cout << "9. How much group? " << std::endl;
        std::cout << "10. Add mark for Student" << std::endl;
        std::cout << "11. Add mark for all student in group" << std::endl;
        std::cout << "12. Add mark for all student in all group" << std::endl;
        std::cout << "13. Change mark for 1st course" << std::endl;

        //TODO добавить возможность добавлять оценки (протестировать это)
        //TODO добавить возможность внесения количества оценок при поступлении на первый курс

        if (!getNum(n)) {
            std::cout << "Bad input try again" << std::endl;
            continue;
        }
        if (n == 0) {
            std::cout << "Goodbye" << std::endl;
            break;
        }
        if (n == 1) {
            app.addStudent();
        }
        if (n == 2) {
            app.inputThemeUIR();
        }
        if (n == 3) {
            app.inputPlaceUIR();
        }
        if (n == 4) {
            app.inputNumberTeacher();
        }
        if (n == 5) { // print all student
            app.printAllTable(std::cout);
        }
        if (n == 6) {
            app.printStudent();
        }
        if (n == 7) {
            app.getMedian();
        }
        if (n == 8) {
            app.lvlUp();
        }
        if (n == 9){
            app.sizeOfGroup();
        }
        if (n == 10){
            app.addMarkForStudent();
        }
        if (n == 11){
            app.addMarkForGroup();
        }
        if (n == 12){
            app.addMarkForAllGroup();
        }
        if (n == 13){

        }

    }
    return 0;

}
