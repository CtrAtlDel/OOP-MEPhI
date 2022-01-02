//
// Created by Ivan on 05.10.2021.
//

#include <iostream>
#include "lib/Lem.h"
#include "lib/func.cpp"
#include "cmath"

using namespace Lab2;

int main(int argc, char *argv[]) {
    Lemn lemn(3);
    const char *s = nullptr;
    int fl1 = 1;
    double c;
    double phi;
    double ro;
    while (fl1) {
        std::cout << "Your Lemniscate: " << std::endl;
        s = lemn.print();
        std::cout << s << std::endl;
        delete[] s;
        std::cout << "Const parametr c : " << lemn.getC() << std::endl;
        const char *er = "";

        std::cout << "Enter phi (radians) of rotation or some letter to exit: ";
        do {
            std::cout << er << std::endl;
            if (!getNum(phi)) {
                return 0;
            }
            er = "Error: enter value of phi in interval (0; 2PI)";
        } while (phi < 0 || phi > 2 * M_PI);
        er = "";
        std::cout << "Enter ro of rotation or some letter to exit: ";
        do {
            std::cout << er << std::endl;
            if (!getNum(ro)) {
                return 0;
            }
            er = "Error: enter value of phi in interval (0; + inf)";
        } while (ro <= 0);

        er = "";
        try {
            std::cout << "Distance to center in polar coordinate system: -> " << lemn.getRo(phi) << std::endl; //3
            std::cout << "Radius of curvature depending on the angle of the polar radius: -> " << lemn.getRcurByphi(phi)
                      << std::endl;//4
            std::cout << "Radius of curvature versus the length of the polar radius: -> "
                      << lemn.getRcurByro(ro)
                      << std::endl; //5
            std::cout << "Area of the polar sector of the lemniscate depending on the angle of the polar radius: -> "
                      << lemn.squareSec(phi) << std::endl; //6
            std::cout << "Lemniscate square: -> " << lemn.square() << std::endl; //7

        }
        catch (std::exception &ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "Enter new c - parametr or some letter to exit: ";
        std::cin >> c;
        if (std::cin.good()) {
            try {
                lemn = lemn.setC(c);
            } catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        } else {
            fl1 = 0;
        }
    }

    return 0;
}