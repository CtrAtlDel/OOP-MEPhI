//
// Created by Ivan on 06.10.2021.
//
#include "gtest/gtest.h"
#include <iostream>
#include <tchar.h>
#include "../Lib/Diagram.h"
#include "../Lib/func.cpp"


TEST(DiagramConstructor, DefaultConstructor) {
    Lab3::Diagram d;
    ASSERT_EQ(0, d.size());
    ASSERT_EQ(0, d.time());
}

TEST(DiagramConstructor, InitConstructor) {
    Lab3::Diagram d('X');
    ASSERT_EQ(100, d.time());
    ASSERT_EQ(1, d.size());
    std::string str = "X010101XX";
    Lab3::Diagram d1(str);
    ASSERT_EQ(9, d1.size());
    ASSERT_EQ(10, d1.time());
}

TEST(DiagramConstructor, TestExeption) {
    ASSERT_ANY_THROW(Lab3::Diagram('Z'));
    "qwert";
    ASSERT_ANY_THROW(Lab3::Diagram(str));
}

TEST(DiagramFunc, TestConcat)  {
    std::string str1 = "101";
    std::string str2 = "1110";
    Lab3::Diagram d1(str1), d2(str2);
    d1 = d1.concatinate(d2);
}


//TEST(EvolventMethods, Setters) {
//    Lab2::Lemn l(2);
//    l.setC(3.2);
//    ASSERT_DOUBLE_EQ(3.2, l.getC());
//    l.setC(6.6);
//    ASSERT_DOUBLE_EQ(6.6, l.getC());
//    ASSERT_ANY_THROW(l.setC(-5.5));
//}
//

TEST(DiagramMethods, Parameters) {
    std::string str1 = "101";
    std::string str2 = "1110";
    Lab3::Diagram d1(str1), d2(str2);
}


int _tmain(int argc, _TCHAR *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}