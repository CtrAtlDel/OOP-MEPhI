//
// Created by Ivan on 02.10.2021.
//

#include "Lem.h"

namespace Lab2 {
    Lemn::Lemn(double c) {
        if (c <= 0) { throw std::invalid_argument("Invalid c"); }
        else { this->c = c; }
    }

    double Lemn::getRo(double phi) const {
        double coss;
        double psi = phi;
        if (cos(psi) < 0) { coss = -cos(psi); }
        else { coss = cos(psi); }
        return sqrt(2 * this->c * this->c * coss);
    }

    double Lemn::getRcurByphi(double phi) const {
        if (phi > 2 * M_PI || phi < 0) { throw std::invalid_argument("Invalid phi (0, 2PI)"); }
        double psi = phi / 2;
        double ro = getRo(psi);
        return 2 * (this->c * this->c) / (3 * ro);
    }

    Lemn &Lemn::setC(double c) {
        if (c < 0) { throw std::invalid_argument(" c <= 0 "); }
        this->c = c;
        return *this;
    }

    double Lemn::getRcurByro(double ro) const {
        if (ro <= 0) { throw std::invalid_argument("Invalid rad(<=0)"); }
        return 2 * (this->c * this->c) / (3 * ro);
    }

    double Lemn::squareSec(double phi) const {
        double psi = phi;
        if (psi > 2 * M_PI || psi < 0) { throw std::invalid_argument("Invalid phi (0, 2PI)"); }
        double s = (this->c * this->c) / 2 * sin(psi);
        if (s <= 0) { s = -s; }
        return s;
    }

    const char *Lemn::print() const {
        if (this->c != 0) {
            const char *s1 = "(x^2 + y^2)^2 = 2 * ^2 * (x^2 - y^2) \n";
            int l = strlen(s1) + 1;
            size_t size = 20;
            char num[size];
            sprintf(num, "%2f", this->c);
            l += 2 * strlen(num);
            char *s = new char[l];
            sprintf(s, "(x^2 + y^2)^2 = 2 * %.2f^2 * (x^2 - y^2) \n", this->c);
            return s;
        } else {
            return "x = 0 y = 0 \n";
        }
    }
}







