//
// Created by Ivan on 02.10.2021.
//

#ifndef UNTITLED_LEM_H
#define UNTITLED_LEM_H

#include <stdexcept>
#include "cmath"
#include "cstring"
#include <cstdio>
#include <strstream>

namespace Lab2 {
    class Lemn {
    private:
        double c;
    public:
        Lemn(double c = 1);

        Lemn &setC(double c);

        inline double getC() const { return c; }

        double getRo(double phi) const; // радиус в полярной система координат кривой уравнении кривой

        double getRcurByphi(double phi) const; // радиус кривизны

        double getRcurByro(double ro) const;

        double squareSec(double phi) const; //6)

        inline double square() const { return (this->c) * (this->c) / 2; }; //7)

        const char *print() const;

    };
}

#endif //UNTITLED_LEM_H
