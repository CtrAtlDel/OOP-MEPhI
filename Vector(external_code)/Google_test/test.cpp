#include <iostream>
#include "../library/vec.hpp"
#include "gtest/gtest.h"

using namespace vec;

bool same(const double_vector &v1, const double_vector &v2) { // проверка одинаковые ли вектора

    bool ans = true;
    double *m1 = v1.get_mas();
    double *m2 = v2.get_mas();
    if (v1.get_n() != v2.get_n()) {
        ans = false;
    } else {
        for (int i = 0; i < v1.get_n(); i++) {
            if (m1[i] != m2[i]) {
                ans = false;
                break;
            }
        }
    }
    return ans;
}

bool same_mas(const double_vector &v1, const double *v2) { // проверка одинаковые ли векторы
    bool ans = true;
    double *m1 = v1.get_mas();
    int p;
    if (v1.get_n() == 0) {
        p = v1.get_n();
    } else {
        p = v1.get_n();
    }
    for (int i = 0; i < p; i++) {
        if (m1[i] != v2[i]) {
            ans = false;
            break;
        }
    }
    return ans;
}

TEST(vec, constructor1) { //обычный конструктор

    double_vector v1;
    EXPECT_TRUE((v1.get_mas() == nullptr));
    EXPECT_TRUE((v1.get_n() == 0));
}

TEST(vec, constructor2) { //конструктор одним элементом

    double_vector v1(2.1);
    double v2[1] = {2.1};
    EXPECT_TRUE(same_mas(v1, v2));
    EXPECT_TRUE((v1.get_n() == 1));
}


TEST(vec, constructor3) { // конструктор масивом
    double mas[3] = {2.1, 2, 4.5};
    double_vector v1(3, mas);
    double v2[3];
    v2[0] = 2.1;
    v2[1] = 2;
    v2[2] = 4.5;
    EXPECT_TRUE(same_mas(v1, v2));
    EXPECT_TRUE((v1.get_n() == 3));
}
TEST(vec, constructor3exception) { // конструктор масивом
    double mas[3] = {2.1, 2, 4.5};
    EXPECT_ANY_THROW(double_vector v1(-2, mas));
}

TEST(vec, constructor4) { //копирующий конструктор
    double mas[3] = {2.1, 2, 4.5};
    double_vector v1(3, mas);
    double_vector v3(v1);
    EXPECT_TRUE(same_mas(v3, mas));
    EXPECT_TRUE((v3.get_n() == 3));
}

TEST(vec, add) {
    double mas[3] = {2.1, 2, 4.5};
    double_vector v1(3, mas);
    double v2[4];
    v1.add(2.6);
    v2[0] = 2.1;
    v2[1] = 2;
    v2[2] = 4.5;
    v2[3] = 2.6;
    EXPECT_TRUE(same_mas(v1, v2));
}


TEST(vec, max) {
    double mas[3] = {2.1, 2, 4.5};
    double_vector v1(3, mas);
    EXPECT_NEAR(v1.maximum(), 4.5, 0.0000001);
}

TEST(vec, plus) {
    double mas[3] = {2.1, 2, 4.5};
    double_vector v1(3, mas);
    double mas1[5] = {2.1, 2, 4.5, 2, 5.6};
    double_vector v2(5, mas1);
    double_vector v3;
    v3 = v1 + v2;
    double mas2[5] = {2.1 + 2.1, 2 + 2, 4.5 + 4.5, 2, 5.6};
    EXPECT_TRUE(same_mas(v3, mas2));
}


TEST(vec, minus) {
    double mas[3] = {2.1, 2, 4.5};
    double_vector v1(3, mas);
    double mas1[5] = {1, 3.5, 4.5, 2, 5.6};
    double_vector v2(5, mas1);
    double_vector v3;
    v3 = v1 - v2;
    double mas2[5] = {2.1 - 1, 2 - 3.5, 4.5 - 4.5, -2, -5.6};
    EXPECT_TRUE(same_mas(v3, mas2));
}



TEST(vec, multi) {
    double mas[3] = {2.1, 2, 4.5};
    double_vector v1(3, mas);
    double mas1[5] = {1, 3.5, 4.5, 2, 5.6};
    double_vector v2(5, mas1);
    double_vector v3;
    v3 = v1 * v2;
    double mas2[5] = {2.1 * 1, 2 * 3.5, 4.5 * 4.5, 0, 0};
    EXPECT_TRUE(same_mas(v3, mas2));
}


TEST(vec, equte) { //копирующий равно
    double mas[3] = {2.1, 2, 4.5};
    double_vector v1(3, mas);
    double_vector v3;
    v3=v1;
    EXPECT_TRUE(same_mas(v3, mas));
    EXPECT_TRUE((v3.get_n() == 3));
}

TEST(vec,  boolean) { //
    double_vector v1;
    EXPECT_TRUE(v1());
    v1.add(0);
    EXPECT_TRUE(v1());;
    v1.add(2.6);
    EXPECT_FALSE(v1());
}

