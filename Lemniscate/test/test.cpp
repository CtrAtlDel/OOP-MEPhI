//
// Created by Ivan on 06.10.2021.
//
#include "gtest/gtest.h"
#include <iostream>
#include <tchar.h>
#include "../lib/Lem.h"
//#include "../lib/func.cpp"


TEST(LemnConstructor, DefaultConstructor) {
    Lab2::Lemn l;
    ASSERT_DOUBLE_EQ(1, l.getC());
}

TEST(LemnConstructor, InitConstructor) {
    Lab2::Lemn l(2.3);
    ASSERT_DOUBLE_EQ(2.3, l.getC());
}

TEST(EvolventConstructor, TestExeption) {
    ASSERT_ANY_THROW(Lab2::Lemn(-1));
    ASSERT_ANY_THROW(Lab2::Lemn(0));
    ASSERT_ANY_THROW(Lab2::Lemn(-2));
}

TEST(EvolventMethods, Setters) {
    Lab2::Lemn l(2);
    l.setC(3.2);
    ASSERT_DOUBLE_EQ(3.2, l.getC());
    l.setC(6.6);
    ASSERT_DOUBLE_EQ(6.6, l.getC());
    ASSERT_ANY_THROW(l.setC(-5.5));
}

TEST(EvolventMethods, Parameters) {
    Lab2::Lemn l; //c == 1
    const double err = 0.00010, sqrt = 1.41421;
    const double PI = 3.14159;
    ASSERT_NEAR(1.41421, l.getRo(PI), err);
    ASSERT_NEAR(0.56059, l.getRcurByphi(PI / 2), err);
    ASSERT_ANY_THROW(l.getRcurByro(0));
    ASSERT_ANY_THROW(l.squareSec(-PI));
    ASSERT_NEAR(0.66666, l.getRcurByro(1), err);
    ASSERT_NEAR(0, l.squareSec(PI), err);
    ASSERT_NEAR(0.50000, l.square(), err);
    Lab2::Lemn lemn(3);
    ASSERT_STREQ("(x^2 + y^2)^2 = 2 * 3.00^2 * (x^2 - y^2) \n", lemn.print());
}


int _tmain(int argc, _TCHAR *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}