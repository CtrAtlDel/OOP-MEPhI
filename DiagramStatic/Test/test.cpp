//
// Created by Ivan on 06.10.2021.
//
#include "gtest/gtest.h"
#include <iostream>
#include <tchar.h>
#include "../Lib/src/Diagram.h"
#include "../Lib/src/func.cpp"


TEST(DiagramConstructor, DefaultConstructor) {
    Lab3::Diagram d("X010101X");
    ASSERT_EQ(8, d.size());
    ASSERT_EQ(8, d.time());
}

TEST(FiagramOperators, Operationsum) {
    Lab3::Diagram d("1");
    Lab3::Diagram d1("101010");
    Lab3::Diagram dr;
    dr = d + d1;
    ASSERT_EQ("101010", dr.getStr());
}

TEST(DiagramConstructor, InitConstructor) {
    Lab3::Diagram d('X');
    ASSERT_EQ(INT_MAX, d.time());
    ASSERT_EQ(1, d.size());
    ASSERT_EQ('X', d.getStatusByIndex(0));
    std::string str = "X010XX101XX";
    std::string str2 = "X010X101X";

    Lab3::Diagram d1(str);
    std::string str3 = d1.getStr();
    ASSERT_EQ(str2, d1.getStr());
    ASSERT_EQ(11, d1.time());
}

TEST(DiagramConstructor, TestExeption) {
    ASSERT_ANY_THROW(Lab3::Diagram('Z'));
    ASSERT_ANY_THROW(Lab3::Diagram("10101010101010101010101"));
}

TEST(DiagramFunc, TestMethods) {
    std::string str1 = "1010X";
    std::string str2 = "11101";
    std::string str3 = "111XX01";
    Lab3::Diagram d1(str1), d2(str2);
    Lab3::Diagram d3 = d1.concatinate(d2);          //concatinate
    ASSERT_EQ("1010X101", d3.getStr());
    Lab3::Diagram d4(str1), d5(str2);
    d4 = d4.insert(d5, 3);                  //insert
    ASSERT_EQ("10101", d4.getStr());
    d4 = d4.multiplyCopy(3);                      //multyplycopy
    ASSERT_EQ("1010101010101", d4.getStr());
    Lab3::Diagram dd(str3);
    dd = dd.shiftLeft(5);                       //shift left
    ASSERT_EQ("01", dd.getStr());
    ASSERT_EQ(7, dd.time());
    dd = dd.shiftRight(5);                       //shift left
    ASSERT_EQ("01", dd.getStr());
    ASSERT_EQ(12, dd.time());

}

TEST(DiagramFunc, TestOperators) {
    std::string str1 = "101";
    std::string str2 = "1110";
    std::string str3 = "1010";
    Lab3::Diagram d1(str1), d2(str2);
    d1 = d1.concatinate(d2);
    std::string str = d1.getStr();
    ASSERT_EQ(str3, str);
    Lab3::Diagram d3(str1), d4(str2);
    d3 += d4;                           //operator +=
    ASSERT_EQ(str3, str);
    Lab3::Diagram d5(str1), d6(str2);
    Lab3::Diagram d7("1");
    d7 = d5 + d6;                       //operator +
    str3 = "1010";
    ASSERT_EQ(str3, d7.getStr());
    Lab3::Diagram d8("1010101");
    d8++;                               //operator ++
    ASSERT_EQ("0101010", d8.getStr());
    ++d8;                               //operator ++
    ASSERT_EQ("1010101", d8.getStr());
    str = "1010101010";
    Lab3::Diagram d9("1010101010");
    for (int i = 0; i < d9.size(); ++i) {
        ASSERT_EQ(str[i], d9.getStatusByIndex(i));
    }

    for (int i = 0; i < d9.size(); ++i) {
        ASSERT_EQ(str[i], d9[i]);               //operator []
    }

    for (int i = 0; i < d9.size(); ++i) {
        ASSERT_EQ(d9.getTimeByIndex(i), d9(i));
    }
}

TEST(DiagramFunc, TestConstant) {
    Lab3::Diagram d("1010101"), d1("0001X");
    std::string str = "0001X";
    const int tmp = 0;
    ASSERT_EQ('1', d[tmp]);
    ASSERT_EQ(1, d(tmp)); // time
    ASSERT_EQ("01X", d1.getStr());
    ASSERT_EQ(5, d1.time());
    ASSERT_EQ(3, d1.size());
    ASSERT_EQ(3, d1(0));
    ASSERT_EQ('1', d1[1]);

    for (int i = 1; i < d1.size(); ++i) {
        d1[i] = 'X';
    }
    ASSERT_EQ("0XX", d1.getStr());
}

int _tmain(int argc, _TCHAR *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}