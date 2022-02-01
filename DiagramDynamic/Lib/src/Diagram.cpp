//
// Created by Ivan on 12.10.2021.
//

#include "Diagram.h"
#include <iostream>
#include <climits>

namespace Lab3 {

    bool Diagram::ifSig(char sig) {
        if (sig == sig_X) {
            return true;
        }
        if (sig == sig_0) {
            return true;
        }
        if (sig == sig_1) {
            return true;
        }
        return false;
    }

    Diagram::Diagram(char ch) {
        if (!Diagram::ifSig(ch)) {
            throw std::invalid_argument("Bad char");
        }
        size = 1;
        this->size = 1;
        list = new Item[1];
        list[0].time = Diagram::MAX_TIME;
        this->sum_time = Diagram::MAX_TIME;
        list[0].status = ch;
    }

    Diagram::Diagram(const std::string &str) {
        //exceptions
        if (str.length() == 0) {
            throw std::invalid_argument("Empty string");
        }
        for (int i = 0; i < str.length(); ++i) {
            if (!Diagram::ifSig(str[i])) {
                throw std::invalid_argument("Bad char its not (0,1 or X)");
            }
        }
        char tmp = str[0]; //текущий элемент
        int count = 1;
        for (int i = 0; i < str.length(); ++i) {
            if (tmp == str[i]) {
            } else {
                tmp = str[i];
                count++;
            }
        }
        this->list = new Item[count];
        tmp = str[0]; //текущий элемент
        this->size = 1; // текущий размер массива
        this->sum_time = 0;
        this->list[0].status = tmp;
        this->list[0].time = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (tmp == str[i]) {
                this->list[size - 1].time += 1;
                this->sum_time += 1;
            } else {
                tmp = str[i];
                this->size += 1;
                this->list[size - 1].status = tmp;
                this->list[size - 1].time += 1;
                this->sum_time += 1;
            }
        }
        this->size = count;
    }

    Diagram::Diagram(int size) {
        if (size < 0) {
            throw std::invalid_argument("Time < 0");
        }
        if (size == 0) {
            this->size = 0;
            list = new Item[1];
            this->sum_time = 0;
        } else {
            this->size = size;
            list = new Item[size];
            this->size = 0;
        }
    }

    Diagram::Diagram(const Diagram &dtmp) noexcept: list(nullptr), size(dtmp.size),
                                                    sum_time(dtmp.sum_time) { //конструктор копирования
//        std::cout << "Copy Constructor" << std::endl; //for test uncomment
        Item *tmp = this->list;
        Item *new_list = new Item[dtmp.size];
        delete[] tmp;
        for (int i = 0; i < dtmp.size; ++i) {
            new_list[i].status = dtmp.list[i].status;
            new_list[i].time = dtmp.list[i].time;
        }
        this->list = new_list;
    }

    Diagram &Diagram::operator=(const Diagram &tmp) {
//        std::cout << "Copy operator" << std::endl;
        if (this != &tmp) {
            delete[] this->list;
            this->list = nullptr;
            this->size = tmp.size;
            this->sum_time = tmp.sum_time;
            if (this->size != 0) {
                this->list = new Item[this->size];
                //copy elements
                for (int i = 0; i < this->size; ++i) {
                    this->list[i].time = tmp.list[i].time;
                    this->list[i].status = tmp.list[i].status;
                }
            }
        }
        return *this;
    }

    Diagram::Diagram(Diagram &&dtmp) noexcept: list(dtmp.list), size(dtmp.size),
                                               sum_time(dtmp.sum_time) {  //конструктор
//        std::cout << "Move Constructor" << std::endl; //for test uncomment
        dtmp.list = nullptr;
    }

    Diagram &Diagram::operator=(Diagram &&tmp) {
//        std::cout << "Move operator" << std::endl;
        int num = this->size;
        this->size = tmp.size;
        tmp.size = num;
        int times = this->sum_time;
        this->sum_time = tmp.sum_time;
        tmp.sum_time = times;
        Item *new_list = this->list;
        this->list = tmp.list;
        tmp.list = new_list;
        return *this;
    }

    std::ostream &Diagram::printDiagram(std::ostream &s) const {
        if (this->size == 0) {
            s << "Diagram is empty";
        } else {
            s << "Status: ";
            for (int i = 0; i < this->size; ++i) {
                if (this->list[i].time != 0) {
                    s << this->list[i].status << ' ';
                }
            }
            s << std::endl;
            s << "Time:   ";
            for (int i = 0; i < this->size; ++i) {
                if (this->list[i].time != 0) {
                    s << this->list[i].time << ' ';
                }
            }
        }
        s << std::endl << std::endl;
        return s;
    }

    std::istream &Diagram::initDiagram(std::istream &s) {
        std::string str;
        s >> str;
        init(str);
        return s;
    }

    void Diagram::init(std::string &str) {
        if (str.length() == 0) {
            throw std::invalid_argument("Empty string");
        }
        for (char i : str) {
            if (!Diagram::ifSig(i)) {
                throw std::invalid_argument("Bad char its not (0,1 or X)");
            }
        }//clear
        char tmp = str[0]; //текущий элемент
        int count = 1;//нужный размер
        for (int i = 0; i < str.length(); ++i) {
            if (tmp == str[i]) {
            } else {
                tmp = str[i];
                count++;
            }
        }
        Item *temp = this->list;
        delete[] temp;
        this->list = new Item[count];
        for (int i = 0; i < count; ++i) {
            this->list[i].time = 0;
            this->list[i].status = sig_X;
        }
        this->sum_time = 0;
        tmp = str[0];
        this->size = 1; // текущий размер массива
        this->sum_time = 0;
        this->list[0].status = tmp;
        this->list[0].time = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (tmp == str[i]) {
                this->list[size - 1].time += 1;
                this->sum_time += 1;
            } else {
                tmp = str[i];
                this->size += 1;
                this->list[size - 1].status = tmp;
                this->list[size - 1].time += 1;
                this->sum_time += 1;
            }
        }
        this->size = count;
    }

    Diagram &Diagram::shiftRight(int time) {
        if (this->size == 0) { throw std::invalid_argument("Empty diagram"); }
        if (time < 0) { throw std::invalid_argument("Time < 0"); }
        if (this->sum_time + time > Diagram::MAX_TIME) { throw std::invalid_argument("Diagram time overflow"); }
        if (this->size == 0) { return *this; }
        this->list[0].time += time;
        this->sum_time += time;
        return *this;
    }

    Diagram &Diagram::shiftLeft(int time) {
        if (this->size == 0) { throw std::invalid_argument("Empty diagram"); }
        if (time < 0) { throw std::invalid_argument("Time < 0"); }
        if (this->sum_time - time < 0) { throw std::invalid_argument("Diagram time < 0"); }
        if (time == 0) { return *this; }
        if (this->size == 0) { return *this; }
        int end_index = 0;
        int sizes = this->size;
        int tmp_size = 0;
        int tmp_time = time;
        for (int i = 0; i < this->size; ++i) {
            if (this->list[i].time <= tmp_time) {
                this->list[i].status = 'X';
                tmp_time -= this->list[i].time;
                this->list[i].time = 0;
                sizes--;
                tmp_size++;
            } else {
                this->list[i].time -= tmp_time;
                end_index = i;
                break;
            }
        }
        int tmp_index = end_index;
        Item *tmp = this->list;
        Item *l = new Item[sizes];
        if (this->list[tmp_index].time == 0) {
            for (int i = 0; i < sizes; ++i) {
                l[i].status = this->list[i + tmp_index].status;
                l[i].time = this->list[i + tmp_index].time;
            }
        } else {        //if this->list[tmp_index].time > 0
            for (int i = 0; i < sizes; ++i) { //- (tmp_index + 1)
                l[i].status = this->list[i + tmp_index].status;
                l[i].time = this->list[i + tmp_index].time;
            }
        }
        this->list = l;
        this->size = sizes;
        this->sum_time -= time;
        delete[] tmp;

    }

    Diagram &Diagram::concatinate(const Diagram &dtmp) {
        if (dtmp.sum_time + this->sum_time > Diagram::MAX_TIME) {
            throw std::invalid_argument("Diagram time overflow");
        }
        if (this->size == 0) {
            throw std::invalid_argument("Diagram is empty");
        }
        if (dtmp.size == 0) {
            throw std::invalid_argument("Concat diagram is empty");
        }
        if (this->list[this->size - 1].status == dtmp.list[0].status) {//конец и начало у диаграм совпадают
            Item *tmp = this->list;
            Item *new_list = new Item[this->size + dtmp.size - 1];
            for (int i = 0; i <
                            this->size; ++i) { //копируем старый массив в новый  и работаем как со старым массивом увличенного размера
                new_list[i].status = tmp[i].status;
                new_list[i].time = tmp[i].time;
            }
            this->list = new_list;
            delete[] tmp;
            int time = this->list[dtmp.size - 1].time;
            for (int i = 0; i < dtmp.size; ++i) {
                this->list[this->size + i - 1].status = dtmp.list[i].status;
                this->list[this->size + i - 1].time += dtmp.list[i].time;
            }
            this->size += dtmp.size - 1;
            this->sum_time += dtmp.sum_time;
            this->list[this->size - 1].time = time;

        } else {
            Item *tmp = this->list;
            Item *new_list = new Item[this->size + dtmp.size];
            for (int i = 0; i < this->size; ++i) { //копируем элементы в другой массив
                new_list[i].status = tmp[i].status;
                new_list[i].time = tmp[i].time;
            }
            delete[] tmp;
            this->list = new_list;
            for (int i = 0; i < dtmp.size; ++i) {
                this->list[this->size + i].status = dtmp.list[i].status;
                this->list[this->size + i].time = dtmp.list[i].time;
            }
            this->size += dtmp.size;
            this->sum_time += dtmp.sum_time;
        }
        return *this;
    }

    Diagram &Diagram::multiplyCopy(int n) {
        if (this->size == 0) { throw std::invalid_argument("Empty diagram"); }
        if (n <= 0) { throw std::invalid_argument("Bad input n <= 0"); }
        if (this->size == 0) { return *this; }
        if (this->sum_time * n > Diagram::MAX_TIME) { throw std::invalid_argument("Diagram time overflow"); }
        if (this->size == 1) {
            this->list[0].time *= n;
            this->sum_time = this->list[0].time;
            return *this;
        }
		// если несколько элементов
        if (this->list[0].status == this->list[this->size - 1].status) { // если совпадают концы
            int new_size = this->size * n - n + 1;

            Item *new_list = new Item[new_size];
			for (size_t i = 0; i < new_size; i++)
			{
				new_list[i].status = sig_X;
				new_list[i].time = 0;
			}
            for (int i = 0; i < this->size; ++i) {
                new_list[i].status = list[i].status;
                new_list[i].time = list[i].time;
            }
			Item* tmp = list;
            list = new_list;
            delete[] tmp;
            int tmp_time = this->list[this->size - 1].time;
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < this->size; ++j) {
                    this->list[j + i * this->size - i].status = this->list[j].status;
                    this->list[j + i * this->size - i].time += this->list[j].time;
                }
                this->list[this->size - 1 + i * this->size - i].time = tmp_time;
            }
            this->size = this->size * n - (n - 1);
            this->sum_time = this->sum_time * n;
        } else { // если нге совпадают концы
            Item* new_list = new Item[size * n];
            for (int i = 0; i < size ; ++i) {
                new_list[i].status = list[i].status;
                new_list[i].time = list[i].time;
            }
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < this->size; ++j) {
                    new_list[j + i * this->size].status = new_list[j].status;
                    new_list[j + i * this->size].time += new_list[j].time;
                }
            }
            this->size = this->size * n;
            this->sum_time *= n;
            Item* tmp = list;
            list = new_list;
            delete[] tmp;
        }
        return *this;
    }

    Diagram &Diagram::insert(Diagram &dtmp, int time) {
        if (time < 0) { throw std::invalid_argument("Time < 0"); }
        if (dtmp.size == 0) { throw std::invalid_argument("Diagram is empty"); }
        if (dtmp.sum_time + this->sum_time > Diagram::MAX_TIME) {
            throw std::invalid_argument("Diagram time overflow");
        }
        if (time > sum_time) {
            throw std::invalid_argument("Use concatenation");
        }
        Item *tmp = this->list;
        Item *new_list = new Item[this->size + dtmp.size];
        for (int i = 0; i < this->size; ++i) {
            new_list[i].status = tmp[i].status;
            new_list[i].time = tmp[i].time;
        }
        this->list = new_list;
        delete[] tmp;
        int tmp_time = time;
        int save_index = 0;//индекс начиная с которого будем вставлять диаграмму
        for (int i = 0; i < this->size; ++i) {
            if (tmp_time > this->list[i].time) {
                tmp_time -= this->list[i].time;
            } else {
                save_index = i;
                break;
            }
        }
        this->sum_time -= this->list[save_index].time; //потому что удаляем элемент
        for (int i = dtmp.size; i > 0; --i) {
            this->list[this->size - 1 + i].status = this->list[this->size - 1 + i -
                                                               (dtmp.size - 1)].status;
            this->list[this->size - 1 + i].time = this->list[this->size - 1 + i - (dtmp.size - 1)].time;
        }
        int j = 0;
        for (int i = save_index; i < save_index + dtmp.size; ++i) {
            this->list[i].status = dtmp.list[j].status;
            this->list[i].time = dtmp.list[j].time;
            j++;
        }
        int i = 0;
        int tmp_size = 0;
        while (this->list[i].time != 0) {
            ++tmp_size;
            ++i;
        }
        this->size = tmp_size;
        this->sum_time += dtmp.sum_time;

        i = 0;
        int save = -1;
        while (this->list[i].time != 0) {
            if (this->list[i].status == this->list[i + 1].status) {
                save = i;
                break;
            }
            ++i;
        }
        if (save != -1) {
            for (int j = save; j < this->size; ++j) {
                if (j == save) {
                    this->list[j].time += this->list[j + 1].time;
                } else {
                    this->list[j].status = this->list[j + 1].status;
                    this->list[j].time = this->list[j + 1].time;
                }
            }
            this->size--;
        }

        i = 0;
        save = -1;
        while (this->list[i].time != 0) {
            if (this->list[i].status == this->list[i + 1].status) {
                save = i;
                break;
            }
            ++i;
        }
        if (save != -1) {
            for (int j = save; j < this->size; ++j) {
                if (j == save) {
                    this->list[j].time += this->list[j + 1].time;
                } else {
                    this->list[j].status = this->list[j + 1].status;
                    this->list[j].time = this->list[j + 1].time;
                }
            }
            this->size--;
        }
        return *this;
    }
	/*
    std::string Diagram::getStr() const {
        if (this->size == 0) {
            throw std::invalid_argument("Empty string");
        }
        std::string str;
        char ar[this->size];
        for (int i = 0; i < this->size; ++i) {
            ar[i] = this->list[i].status;
        }
        str = std::string(ar, sizeof(ar));
        return str;
    }
	*/
    //operators realization

    int Diagram::operator()(int index) const { //rvalue
        if (index < 0 || index > this->size) {
            throw std::invalid_argument(" Index out of range");
        }
        return list[index].time;
    }

    char Diagram::operator[](const int index) const { //lvalue
        if (index < 0 || index >= this->size) {
            throw std::invalid_argument(" Index out of range");
        }
        return this->list[index].status;
    }

    Diagram &Diagram::operator++() { //pref
        if (this->size == 0) { throw std::invalid_argument("Empty diagram"); }
        for (int i = 0; i < this->size; ++i) {
            if (this->list[i].time != 0) {
                if (this->list[i].status == sig_1) {
                    this->list[i].status = sig_0;
                } else {
                    if (this->list[i].status == sig_0) {
                        this->list[i].status = sig_1;
                    }
                }
            }
        }
        return *this;
    }

    const Diagram Diagram::operator++(int notused) { //postfix
        if (this->size == 0) { throw std::invalid_argument("Empty diagram"); }
        Diagram d(*this);
        for (int i = 0; i < this->size; ++i) {
            if (this->list[i].time != 0) {
                if (this->list[i].status == sig_1) {
                    this->list[i].status = sig_0;
                } else {
                    if (this->list[i].status == sig_0) {
                        this->list[i].status = sig_1;
                    }
                }
            }
        }
        return d;
    }

    std::ostream &operator<<(std::ostream &s, const Diagram &tmp) {
        if (tmp.length() == 0) {
            s << "Diagram is empty" << std::endl;
        } else {
            s << "Status: ";
            for (int i = 0; i < tmp.length(); ++i) {
                if (tmp.list[i].time != 0) {
                    s << tmp.list[i].status << ' ';
                }
            }
            s << std::endl;
            s << "Time:   ";
            for (int i = 0; i < tmp.length(); ++i) {
                if (tmp.list[i].time != 0) {
                    s << tmp.list[i].time << ' ';
                }
            }
            s << std::endl;
        }
        return s;
    }



    std::istream &operator>>(std::istream &s, Diagram &dtmp) {
        std::string str;
        s >> str;
        if (s.good()) {
            for (int i = 0; i < str.length(); ++i) {
                if (!Diagram::ifSig(str[i])) {
                    s.setstate(std::ios::failbit);
                    return s;
                }
            }
            dtmp.setStr(str);
        } else {
            s.setstate(std::ios::failbit);
        }
        return s;
    }

    Diagram Diagram::operator+(const Diagram &tmp) {
        Diagram new_d(this->size);
        for (int i = 0; i < this->size; ++i) {
            new_d.list[i].status = this->list[i].status;
            new_d.list[i].time = this->list[i].time;
        }
        new_d.size = this->size;
        new_d.sum_time = this->sum_time;
        new_d = new_d.concatinate(tmp);
        return new_d;
    }

    void Diagram::setStr(std::string str) {
        int count = 1; // количество элементов в строке
        delete[] list;
        char tmp = str[0]; // первый элемент строки
        for (char i : str) {
            if (tmp != i){
                count++;
                tmp = i;
            }
        }
        delete[] list;
        list = new Item[count];
        tmp = str[0];
        this->size = 1;
        this->sum_time = 0;
        list[0].status = tmp;
        for (char i : str) {
            if (tmp == i){
                list[size -1].time += 1;
                sum_time +=1;
            }else{
                tmp = i;
                size += 1;
                list[size - 1].status = tmp;
                list[size - 1].time += 1;
                sum_time +=1;
            }
        }
        this->size = count;
    }

}