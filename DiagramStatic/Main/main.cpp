#include <iostream>
#include "../Lib/src/Diagram.h"
#include "../Lib/src/func.cpp"
using namespace Lab3;

int main() {
    int a = 1;
    try {
        while (a) {
            //test empty constructor
            Diagram d0;
            std::cout << "Max diagram size: " << Diagram::MAXSIZE() << std::endl;
            std::cout << "Max time: " << Diagram::MAXTIME() << std::endl;

            char ch;
            std::cout << "1.Input init char: " << std::endl;
            getNum(ch);
            Diagram d1(ch);
            std::cout << "Sum time: " << d1.time() << std::endl;
            d1.printDiagram(std::cout);

            //test init constructor
            std::cout << "2.Test init constructor, input str: " << std::endl;
            std::string str;
            getNum(str);
            Diagram d2(str);
            std::cout << "Sum time: " << d2.time() << std::endl;
            d2.printDiagram(std::cout);

            //test input
            Diagram d3;
            std::cout << "3.Test input, input str: " << std::endl;
            d3.initDiagram(std::cin);
            std::cout << "Sum time: " << d3.time() << std::endl;
            d3.printDiagram(std::cout);
            //test lshifr
            int n;
            std::cout << "4.Test Lshift: " << std::endl;
            std::cout << "Init diagram: " << std::endl;
            d3.initDiagram(std::cin);
            d3.printDiagram(std::cout);
            std::cout << "Input time: " << std::endl;
            getNum(n);
            d3.shiftLeft(n);
            d3.printDiagram(std::cout);
            std::cout << "5.Test Rshift: " << std::endl;
            std::cout << "Input time: " << std::endl;
            getNum(n);
            d3.shiftRight(n);
            d3.printDiagram(std::cout);

            //test concat
            std::cout << "6.Test concat 2->1: " << std::endl;
            std::cout << "Init diagram 1:" << std::endl;
            d3.initDiagram(std::cin);
            d3.printDiagram(std::cout);
            std::cout << "Init diagram 2: " << std::endl;
            d2.initDiagram(std::cin);
            d2.printDiagram(std::cout);
            d3 = d3.concatinate(d2);
            d3.printDiagram(std::cout);

            //test copy
            std::cout << "6.Test multyply copy: " << std::endl;
            std::cout << "Init diagram: " << std::endl;
            d3.initDiagram(std::cin);
            d3.printDiagram(std::cout);
            std::cout << "Input n for copy: " << std::endl;
            getNum(n);
            d3 = d3.multiplyCopy(n);
            std::cout << "Sum time: " << d3.time() << std::endl;
            d3.printDiagram(std::cout);

            std::cout << "7.Test insert: " << std::endl;
            std::cout << "Init diagram:" << std::endl;
            d2.initDiagram(std::cin);
            d2.printDiagram(std::cout);
            std::cout << "Init diagram: " << std::endl;
            d3.initDiagram(std::cin);
            d3.printDiagram(std::cout);
            std::cout << "Input time n: " << std::endl;
            getNum(n);
            d2.insert(d3, n);
            d2.printDiagram(std::cout);
            std::cout << "If you wanna exit, input 0: " << std::endl;
            getNum(a);
            if (a == 0) { break; }
        }
    } catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}