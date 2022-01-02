#include "vec.hpp"
#include "../Get/Get.hpp"
#include <iostream>


namespace vec {

    //std::move(), std::copy(), std::fill()

    double_vector::double_vector(double x) {
        double *mas;
        mas = new double[1];
        mas[0] = x;
        n = 1;
        vector = mas;
    }

    double_vector::double_vector(int k, const double *mas) {
        if (k < 0) {
            throw std::runtime_error("Размерность вектора не может быть отрицательной");
        } else {
            double *m;
            m = new double[k];
            n = k;
            for (int i = 0; i < n; i++) {
                m[i] = mas[i];
            }
            vector = m;
        }
    }

    double_vector::double_vector(const double_vector &v1) {
        double *mas = new double[v1.n];
        for (int i = 0; i < v1.n; i++) {
            mas[i] = v1.vector[i];
        }
        vector = mas;
        n = v1.n;
    }

    double_vector::double_vector(double_vector &&v1) {
        n = v1.n;
        vector = v1.vector;
        v1.vector = nullptr;
    }

    std::ostream &double_vector::output(std::ostream &s) const {
        int i;
        for (i = 0; i < n; i++) {
            s << vector[i] << ' ';
        }
        s << std::endl;
        return s;
    }


    double double_vector::maximum() const {
        double ans = 0;
        for (int i = 0; i < n; i++) {
            if (std::abs(ans) < std::abs(vector[i])) {
                ans = vector[i];
            }
        }
        return ans;
    }

    void double_vector::add(double x) {
        double *mas = new double[n+1];
        for (int i = 0; i < n; i++) {
            mas[i] = vector[i];
        }
        mas[n] = x;
        n++;
        delete[] vector;
        vector = mas;
    }

    void double_vector::new_from_terminal(std::ostream &out) {
        bool vvod = true;
        double x;
        n = 0;
        std::string answer;
        while (vvod) {
            out << "Enter element" << std::endl;
            getNum(x);
            this->add(x);
            n++;
            out << "One more element? (y/n)" << std::endl;
            std::cin >> answer;
            std::cout << std::endl;
            if (answer != "y") {
                vvod = false;
            }
        }
    }

// перегрузка операторов

    double_vector double_vector::operator+(double_vector const &v1) const {
        double_vector v3;
        int k;
        if (n <= v1.n) {
            v3.n = v1.n;
            k = n;
            v3.vector = new double[v3.n];
            for (int i = k; i < v3.n; i++)
                v3.vector[i] = v1.vector[i];
        } else {
            v3.n = n;
            k = v1.n;
            v3.vector = new double[v3.n];
            for (int i = k; i < v3.n; i++)
                v3.vector[i] = vector[i];
        }
        for (int i = 0; i < k; i++) {
            v3.vector[i] = vector[i] + v1.vector[i];
        }
        return v3;
    }

    double_vector double_vector::operator-(double_vector const &v1) const {
        double_vector v3;
        int k;
        if (n <= v1.n) {
            v3.n = v1.n;
            k = n;
            v3.vector = new double[v3.n];
            for (int i = k; i < v3.n; i++)
                v3.vector[i] = -v1.vector[i];
        } else {
            v3.n = n;
            k = v1.n;
            v3.vector = new double[v3.n];
            for (int i = k; i < v3.n; i++)
                v3.vector[i] = vector[i];
        }
        for (int i = 0; i < k; i++) {
            v3.vector[i] = vector[i] - v1.vector[i];
        }
        return v3;
    }

    double_vector double_vector::operator*(double_vector const &v1) const {
        double_vector v3;
        int k;
        if (n <= v1.n) {
            v3.n = v1.n;
            k = n;
            v3.vector = new double[v3.n];
            for (int i = k; i < v3.n; i++)
                v3.vector[i] = 0;
        } else {
            v3.n = n;
            k = v1.n;
            v3.vector = new double[v3.n];
            for (int i = k; i < v3.n; i++)
                v3.vector[i] = 0;
        }
        for (int i = 0; i < k; i++) {
            v3.vector[i] = vector[i] * v1.vector[i];
        }
        return v3;
    }

    std::ostream &operator<<(std::ostream &s, const double_vector &v1) {
        {
            for (int i = 0; i < v1.n; i++) {
                s << v1.vector[i] << ' ';
            }
            s << std::endl;
            return s;
        }
    }

    std::istream &operator>>(std::istream &s, double_vector &v1) {
        double x;
        int size;
        s >> size;
        if (size < 0) {
            throw std::runtime_error("Размерность вектора не может быть отрицательной");
        } else {
            v1.n = size;
            delete[] v1.vector;
            v1.vector = new double[v1.n];
            for (int i = 0; i < size; i++) {
                s >> x;
                v1.vector[i] = x;
            }
        }
        return s;
    }

    bool double_vector::operator()() const {
        for (int i = 0; i < n; i++) {
            if (vector[i] != 0)
                return false;
        }
        return true;
    }

    double_vector &double_vector::operator=(const double_vector &v1) {
        if (this != &v1) {
            double *mas ;
                mas = new double[v1.n];
            for (int i = 0; i < v1.n; i++) {
                mas[i] = v1.vector[i];
            }
            n = v1.n;
            delete[]  vector;
            vector=mas;
        }
        return *this;
    }

    double_vector &double_vector::operator=(double_vector &&v1) {
        int x;
        double *mas;
        x = n;
        n = v1.n;
        v1.n = x;
        mas = vector;
        vector = v1.vector;
        v1.vector = mas;
        return *this;
    }

}


