//
// Created by ivan on 16.10.2021.
//

#ifndef LABA_3B_VEC_HPP
#define LABA_3B_VEC_HPP

#include "iostream"

namespace vec {
    class double_vector {
    private:
        int n = 0; // количетсво элементов
        double *vector = nullptr;
    public:

        double_vector() = default;

        double_vector(double);

        double_vector(int, const double *);

        ~double_vector() { delete[] vector; };

        double_vector(const double_vector &); // копирующий конструктор

        double_vector(double_vector &&); // перемещающий конструктор

        int get_n() const {
            return n;
        }

        double *get_mas() const{
            return vector;
        }

        std::ostream &output(std::ostream &) const; // <<, >>

        void add(double x);

        void new_from_terminal(std::ostream &);

        double maximum() const;

        double_vector operator+(const double_vector &v1) const;

        double_vector operator-(const double_vector &v1) const;

        double_vector operator*(const double_vector &v1) const;

        double_vector &operator=(const double_vector &v1); //копирующий

        double_vector &operator=(double_vector &&v1); // перемещающий

        friend std::ostream &operator<<(std::ostream &, const double_vector &v2);

        friend std::istream &operator>>(std::istream &, double_vector &v1);

        //преобразование в bool, bool x = vec;
        bool operator()() const;
    };
}
#endif //LABA_3B_VEC_HPP
