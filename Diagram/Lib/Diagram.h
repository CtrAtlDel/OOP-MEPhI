//
// Created by Ivan on 12.10.2021.
//

#ifndef LAB3_DIAGRAM_H
#define LAB3_DIAGRAM_H

#include <iostream>


namespace Lab3 {
    enum status {
        sig_0 = '0',
        sig_1 = '1',
        sig_X = 'X',
    };

    class Diagram {
    public:
        struct Item {
            char status;
            int time;

            Item() : status('X'), time(0) {}

//            Item(char s, int t) : status(s), time(t) {}
        };

    private:
        static const int MAX_SIZE = 20;
        static const int MAX_TIME = 100;
        int sum_time;
        int sum_size;
        Item list[MAX_SIZE];

        // суммарная длительность программы
        [[nodiscard]] static bool ifSig(char sig);

    public:
        //constructors
        Diagram() : sum_time(0), sum_size(0) {}//1)
        explicit Diagram(char ch);  //2)
        explicit Diagram(std::string &str); //3

        //getters
        [[nodiscard]] int time() const { return this->sum_time; }

        [[maybe_unused]] [[nodiscard]] int size() const { return this->sum_size; }

        [[nodiscard]] static int MAXSIZE() {return Diagram::MAX_SIZE;}
        [[nodiscard]] static int MAXTIME() {return Diagram::MAX_TIME;}

        [[maybe_unused]] [[nodiscard]] char getStatus(int time) const;

        //concatination
        Diagram &concatinate(Diagram &dtmp);

        [[maybe_unused]] Diagram &multiplyCopy(int n);

        //shift
        [[maybe_unused]] Diagram &shiftRight(int time);

        [[maybe_unused]] Diagram &shiftLeft(int time);

        //print
        std::ostream &printDiagram(std::ostream &s) const;

        //input
        void initDiagram(std::istream &s);

        //insert
        Diagram &insert(Diagram &dtmp, int time);

    private:
        void init(std::string& str);
    };
}

#endif //LAB3_DIAGRAM_H
