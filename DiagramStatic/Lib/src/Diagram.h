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
        };

        // суммарная длительность программы


    private:
        static const int MAX_SIZE = 20;
        static const int MAX_TIME = INT_MAX;
        int sum_time;
        int sum_size;
        Item list[MAX_SIZE];
        [[nodiscard]] static bool ifSig(char sig);

    public:
        //constructors
        Diagram() : sum_size(0), sum_time(0) {} //1) //пустой конструктор для инициализации экземпляров и массивов экземпляров класса по умолчанию;

        explicit Diagram(char ch);  //2) //создание экземпляров класса с инициализацией временной диаграммы постоянным уровнем сигнала (уровень 0, 1 или Х на максимальную длительность)

        explicit Diagram(const std::string &str); //3 //создание экземпляров класса с инициализацией временной диаграммы сигналом, представленным строкой ASCII-символов;

        //getters
        [[nodiscard]] int time() const { return this->sum_time; }

        [[nodiscard]] int size() const { return this->sum_size; }

        [[nodiscard]] static int MAXSIZE() { return Diagram::MAX_SIZE; }

        [[nodiscard]] static int MAXTIME() { return Diagram::MAX_TIME; }

        [[nodiscard]] int getTimeByIndex(int index) const {
            if (index < 0 || index > this->sum_size - 1) {
                throw std::invalid_argument("Index out of range");
            }
            return this->list[index].time;
        }

        [[nodiscard]] char getStatusByIndex(int index) const {
            if (index < 0 || index > this->sum_size - 1) {
                throw std::invalid_argument("Index out of range");
            }
            return this->list[index].status;
        }

        [[nodiscard]] std::string getStr() const;

        //setters
        [[nodiscard]] Diagram &setTime(int index, int time) {
            if (index < 0 || index > this->sum_size - 1) {
                throw std::invalid_argument("Index out of range");
            }
            if (time < 0 || Diagram::sum_size + time < time) {
                throw std::invalid_argument("Bad time");
            }
            this->list[index].time = time;
            return *this;
        }

        [[nodiscard]] Diagram &setStatus(int index, char status) {
            if (index < 0 || index > this->sum_size - 1) {
                throw std::invalid_argument("Index out of range");
            }
            if (Diagram::ifSig(status) == 0) {
                throw std::invalid_argument("Bad char its not (0,1 or X)");
            }
            this->list[index].status = status;
            return *this;
        }

        //concatinate
        Diagram &concatinate(const Diagram &dtmp); // объединение временной диаграммы с другой временной диаграммой;

        Diagram &multiplyCopy(int n); //копирование временной диаграммы определённое число раз;

        //shift
        [[maybe_unused]] Diagram &shiftRight(int time); //сдвиг временной диаграммы на определенное время вправо

        [[maybe_unused]] Diagram &shiftLeft(int time);  //сдвиг временной диаграммы на определенное время влево.

        //insert
        Diagram &insert(Diagram &dtmp, int time); //замена временной диаграммы в определённый момент времени (тип int) другой временной диаграммой;

        //print
        std::ostream &printDiagram(std::ostream &s) const; //ввод экземпляров класса из входного потока и вывод в выходной поток;

        //input
        std::istream &initDiagram(std::istream &s); //ввод экземпляров класса из входного потока и вывод в выходной поток;

    public: //overrides
        const Diagram operator++(int notused);

        Diagram &operator++();

        int operator()(int index) const;

        Diagram operator+(const Diagram &tmp);

        Diagram &operator+=(const Diagram &dtmp);

        char operator[](int index) const;

        char &operator[](int index);

        friend std::ostream &operator<<(std::ostream &s, const Diagram &tmp);

        friend std::istream &operator>>(std::istream &s, Diagram &tmp);
    private:
        void init(std::string &str);

    };

}
#endif //LAB3_DIAGRAM_H
