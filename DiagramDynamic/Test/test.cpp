#include "gtest/gtest.h"
#include <iostream>
#include <tchar.h>
#include "../Lib/src/Diagram.h"
#include "../Lib/src/func.cpp"


TEST(Diagram, DefaultConstructor) {
    Lab3::Diagram d;
    ASSERT_EQ(0, d.time());
    ASSERT_EQ(0, d.length());

    Lab3::Diagram d1('X');
    ASSERT_EQ(INT_MAX, d1.time());
    ASSERT_EQ(1, d1.length());

    Lab3::Diagram d2("X010101X");
    ASSERT_EQ(8, d2.length());
    ASSERT_EQ(8, d2.time());
}

TEST(Diagram, InitConstructor) {
    std::string str = "X010XX101XX";
    std::string str2 = "X010X101X";
    Lab3::Diagram d1(str);
    std::string str3 = d1.getStr();
    ASSERT_EQ(str2, d1.getStr());
    ASSERT_EQ(11, d1.time());
}

TEST(Diagram, CopyConstructor){
    Lab3::Diagram d1("10101XXX");
    Lab3::Diagram d2("1001");
    Lab3::Diagram d3(d1);
    d1 = d2;
    ASSERT_EQ("101", d1.getStr());
    ASSERT_EQ("101", d2.getStr());
}

TEST(Diagram, MoveConstructor){
    Lab3::Diagram d1("10101XXX");
    Lab3::Diagram d2("1001");
    d1 = d2;
    ASSERT_EQ("101", d1.getStr());
    ASSERT_EQ("101", d2.getStr());
}

TEST(Diagram, shiftRight){
    Lab3::Diagram d1("1011101XXX10");
    ASSERT_EQ("10101X10", d1.getStr());
    ASSERT_EQ(12, d1.time());
    ASSERT_EQ(8, d1.length());
    d1 = d1.shiftRight(3);
    ASSERT_EQ(15, d1.time());
    ASSERT_EQ(8, d1.length());
}

TEST(Diagram, shiftLeft){
    Lab3::Diagram d1("1101XXX10");
    ASSERT_EQ("101X10", d1.getStr());
    ASSERT_EQ(9, d1.time());
    ASSERT_EQ(6, d1.length());
    d1.shiftLeft(3);   // 1011101XXX10 -> 1101XXX10
    ASSERT_EQ("1X10", d1.getStr());
    ASSERT_EQ(6, d1.time());
    d1.shiftLeft(3);
    ASSERT_EQ("X10", d1.getStr());
    ASSERT_EQ(3, d1.length());
}

TEST(Diagram, OperatorEqual) {
    Lab3::Diagram d0;
    Lab3::Diagram d1("1011");
    d0 = d1;
    ASSERT_EQ("101", d0.getStr());
    d0.multiplyCopy(2);
    ASSERT_EQ("10101", d0.getStr());
    ASSERT_EQ("101", d1.getStr());
}

TEST(Diagram, OperatorSum){
    Lab3::Diagram d0("1"),dSum;
    Lab3::Diagram d1("1011");
    dSum = d0 + d1;
    ASSERT_EQ("101", dSum.getStr());
    ASSERT_EQ(5, dSum.time());
    ASSERT_EQ("101", d1.getStr());
    ASSERT_EQ(1, d0.time());
    ASSERT_EQ(4, d1.time());
}

TEST(Diagram, multyplyCopyFunction){
    Lab3::Diagram d1("1011");
    d1 = d1.multiplyCopy(2);
    ASSERT_EQ("10101", d1.getStr());
    d1 = d1.multiplyCopy(2);
    ASSERT_EQ("101010101", d1.getStr());
}

TEST(Diagram, concatFunction){
    Lab3::Diagram d1("1100XX10");
    Lab3::Diagram d2("1011");
    d1 = d1.concatinate(d2);
    ASSERT_EQ("10X10101", d1.getStr());
    ASSERT_EQ(8, d1.length());
    ASSERT_EQ(12, d1.time());
}

TEST(Diagram, InsertFunction) {
    Lab3::Diagram d, dcon("101");
    Lab3::Diagram dch('X');
    Lab3::Diagram dstr("1100XX10");
    ASSERT_EQ("10X10", dstr.getStr());
    Lab3::Diagram dtmp;
    dtmp = dstr.insert(dcon, 3);
    ASSERT_EQ("101010", dtmp.getStr());
}

TEST(DiagramConstructor, TestExeption) {
    Lab3::Diagram d1, d2;
    ASSERT_ANY_THROW(d1.concatinate(d2));
    ASSERT_ANY_THROW(d1.insert(d2,0));
    ASSERT_ANY_THROW(d1.multiplyCopy(222));
    ASSERT_ANY_THROW(Lab3::Diagram('Z'));
    ASSERT_ANY_THROW(Lab3::Diagram(""));
    ASSERT_ANY_THROW(Lab3::Diagram("Z"));
    ASSERT_ANY_THROW(Lab3::Diagram("1111000XXXZZZ1"));
}

TEST(Diagram, TestInput){
    Lab3::Diagram d("1010101");
    ASSERT_EQ("1010101", d.getStr());
}

TEST(DiagramFunc, TestConstant) {
    Lab3::Diagram d("1010101"), d1("0001X");
    const std::string str1 = "101010";
    Lab3::Diagram d3(str1);
    std::string str = "0001X";
    const int tmp = 0;
    ASSERT_EQ('1', d[tmp]);
    ASSERT_EQ(1, d(tmp)); // time
    ASSERT_EQ("01X", d1.getStr());
    ASSERT_EQ(5, d1.time());
    ASSERT_EQ(3, d1.length());
    ASSERT_EQ(3, d1(0));
    ASSERT_EQ('1', d1[1]);
}

TEST(DiagramFunc, TestOperators) {
    std::string str1 = "101";
    std::string str2 = "1110";
    std::string str3 = "1010";
    Lab3::Diagram d1(str1), d2(str2);
    d1 = d1.concatinate(d2);
    std::string str = d1.getStr();
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
    for (int i = 0; i < d9.length(); ++i) {
        ASSERT_EQ(str[i], d9.getStatusByIndex(i));
    }

    for (int i = 0; i < d9.length(); ++i) {
        ASSERT_EQ(str[i], d9[i]);               //operator []
    }

    for (int i = 0; i < d9.length(); ++i) {
        ASSERT_EQ(d9.getTimeByIndex(i), d9(i));
    }
}

int _tmain(int argc, _TCHAR *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}