#ifndef LAB3_DIAGRAM_H
#define LAB3_DIAGRAM_H

#include <climits>
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
        };

        static bool ifSig(char sig);

    private:
        static const int MAX_TIME = INT_MAX;
        int sum_time; // суммарная длительность программы
        int size; //размер массива
        Item *list;

    public:
        //constructors
         Diagram() : list(nullptr), size(0), sum_time(0) {}
         Diagram(char ch);  //2)
         Diagram(const std::string &str);

    public:
        Diagram(const Diagram &) noexcept;

        Diagram(Diagram &&dtmp) noexcept;

        //getters
        int time() const { return this->sum_time; }

        int length() const { return this->size; }

        static int MAXTIME() { return Diagram::MAX_TIME; }

        int getTimeByIndex(int index) const {
            if (index < 0 || index > this->size - 1) {
                throw std::invalid_argument("Index out of range");
            }
            return this->list[index].time;
        }

        char getStatusByIndex(int index) const {
            if (index < 0 || index > this->size - 1) {
                throw std::invalid_argument("Index out of range");
            }
            return this->list[index].status;
        }

        std::string getStr() const;

        //setters
        Diagram &setTime(int index, int time) {
            if (index < 0 || index > this->size - 1) {
                throw std::invalid_argument("Index out of range");
            }
            if (time < 0 || Diagram::size + time < time) {
                throw std::invalid_argument("Bad time");
            }
            this->list[index].time = time;
            return *this;
        }

        Diagram &setStatus(int index, char status) {
            if (index < 0 || index > this->size - 1) {
                throw std::invalid_argument("Index out of range");
            }
            if (Diagram::ifSig(status) == 0) {
                throw std::invalid_argument("Bad char its not (0,1 or X)");
            }
            this->list[index].status = status;
            return *this;
        }

        //concatinate
        Diagram &concatinate(const Diagram &dtmp);

        Diagram &multiplyCopy(int n);

        //shift
        Diagram &shiftRight(int time);

        Diagram &shiftLeft(int time);

        //insert
        Diagram &insert(Diagram &dtmp, int time);


    public: //overrides
        const Diagram operator++(int notused); //invers status 1-0; 0-1; X-X

        Diagram &operator++();

        int operator()(int index) const;

        Diagram &operator=(const Diagram &tmp);

        Diagram &operator=(Diagram &&tmp);

        char operator[](int index) const;

        Diagram operator+(const Diagram &tmp);

        friend std::ostream &operator<<(std::ostream &s, const Diagram &tmp);

        friend std::istream &operator>>(std::istream &s, Diagram &tmp);

        ~Diagram() { delete[] list; }

    private:
        explicit Diagram(int size);
        void init(std::string &str);
        std::istream &initDiagram(std::istream &s); // replaced by the operator >>
        std::ostream &printDiagram(std::ostream &s) const; //replaced by the operator <<
        void setStr(std::string dtmp);
    };
}
#endif //LAB3_DIAGRAM_H