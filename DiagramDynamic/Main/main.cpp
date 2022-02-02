#include <iostream>
#include <map>
#include "../Lib/src/Diagram.h"
#include "../Lib/src/func.cpp"
using namespace Lab3;

Diagram createDiagram(const std::string& str){ //for demonstrating move constructor
    Diagram d(str);
    return d;
}

Diagram f(Diagram d){
    d++;
    return d;
}

int main() {
    int a = 1;
//    try {
//        while (a) {
//            Diagram d0;
//            std::cout << "Max time: " << Diagram::MAXTIME() << std::endl;
//
//            char ch;
//            std::cout << "1.Input init char: " << std::endl;
//            getNum(ch);
//            Diagram d1(ch);
//            std::cout << "Sum time: " << d1.time() << std::endl;
//            std::cout << d1;
//
//            //test init constructor
//            std::cout << "2.Test init constructor, input str: " << std::endl;
//            std::string str;
//            getNum(str);
//            Diagram d2(str);
//            std::cout << "Sum time: " << d2.time() << std::endl;
//            std::cout << d2; //d2.printDiagram(std::cout);
//
//            //test input
//            Diagram d3;
//            std::cout << "3.Test input, input str: " << std::endl;
//            std::cin >> d3;
//            std::cout << "Sum time: " << d3.time() << std::endl;
//            std::cout << d3;
//            //test lshift
//
//            int n;
//            std::cout << "4.Test Lshift: " << std::endl;
//            std::cout << "Init diagram: " << std::endl;
//            Diagram d5;
//            std::cin >> d5;
//            std::cout << d5;
//            std::cout << "Input time: " << std::endl;
//            getNum(n);
//            d5.shiftLeft(n);
//            std::cout << d5;
//            std::cout << "5.Test Rshift: " << std::endl;
//            std::cout << "Input time: " << std::endl;
//            getNum(n);
//            d5.shiftRight(n);
//            std::cout << d5;
//            //test concat
//            std::cout << "6.Test concat 2->1: " << std::endl;
//            std::cout << "Init diagram 1:" << std::endl;
//            Diagram d6;
//            std::cin >> d6;
//            std::cout << d6;
//            std::cout << "Init diagram 2: " << std::endl;
//            Diagram d62;
//            std::cin >> d62;
//            std::cout << d62;
//            d6.concatinate(d62);
//            std::cout << d6;
//            //test copy
//            std::cout << "7.Test multyply copy: " << std::endl;
//            std::cout << "Init diagram: " << std::endl;
//            Diagram d4;
//            std::cin >> d4;
//            std::cout << d4;
////            d4.printDiagram(std::cout);
//            std::cout << "Input n for copy: " << std::endl;
//            getNum(n);
//            d4.multiplyCopy(n);
//            std::cout << "Sum time: " << d4.time() << std::endl;
//            std::cout << d4;
//
//            std::cout << "8.Test insert: " << std::endl;
//            std::cout << "Init diagram:" << std::endl;
//            Diagram d8;
//            std::cin >> d8;
//            std::cout << d8;
//            std::cout << "Init diagram: " << std::endl;
//            Diagram d9;
//            std::cin >> d9;
//            std::cout << d9;
//            std::cout << "Input time n: " << std::endl;
//            getNum(n);
//            d8.insert(d9, n);
//            std::cout << d8;
//
//            std::cout << "If you wanna exit, input 0: " << std::endl;
//            getNum(a);
//            if (a == 0) { break; }
//        }
//    } catch (std::exception &ex) {
//        std::cout << ex.what() << std::endl;
//    }
    Diagram d0 = 1;

    return 0;
}
