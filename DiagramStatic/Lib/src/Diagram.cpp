#include "Diagram.h"
#include <iostream>

namespace Lab3 {

    [[maybe_unused]] Diagram::Diagram(char ch) {
        if (!Diagram::ifSig(ch)) {
            throw std::invalid_argument("Bad char its not (0,1 or X)");
        }
        list[0].status = ch;
        list[0].time = Diagram::MAX_TIME;
        this->sum_time = Diagram::MAX_TIME;
        this->sum_size = 1;
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
        this->sum_size = 1; // текущий размер массива
        this->sum_time = 0;
        this->list[0].status = tmp;
        this->list[0].time = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (this->sum_time >= Diagram::MAX_TIME || this->sum_size >= Diagram::MAX_SIZE) {
                throw std::invalid_argument("Bad size or bad time");
            }
            if (tmp == str[i]) {
                this->list[sum_size - 1].time += 1;
                this->sum_time += 1;
            } else {
                tmp = str[i];
                this->sum_size += 1;
                this->list[sum_size - 1].status = tmp;
                this->list[sum_size - 1].time += 1;
                this->sum_time += 1;
            }
        }
    }

    //checking parametrs
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

    std::ostream &Diagram::printDiagram(std::ostream &s) const {
        if (this->sum_size == 0) {
            s << "Diagram is empty";
        } else {
            s << "Status: ";
            for (int i = 0; i < this->sum_size; ++i) {
                if (this->list[i].time != 0) {
                    s << this->list[i].status << ' ';
                }
            }
            s << std::endl;
            s << "Time:   ";
            for (int i = 0; i < this->sum_size; ++i) {
                if (this->list[i].time != 0) {
                    s << this->list[i].time << ' ';
                }
            }
        }
        s << std::endl << std::endl;
        return s;
    }

    [[maybe_unused]] Diagram &Diagram::concatinate(const Diagram &dtmp) {
        if (dtmp.sum_size + this->sum_size > Diagram::MAX_SIZE) {
            throw std::invalid_argument("Buffer size overflow");
        }
        if (dtmp.sum_time + this->sum_time > Diagram::MAX_TIME) {
            throw std::invalid_argument("Diagram time overflow");
        }
        if (this->sum_size == 0) {
            throw std::invalid_argument("Diagram is empty");
        }
        if (dtmp.sum_size == 0) {
            throw std::invalid_argument("Concat diagram is empty");
        }
        if (this->list[this->sum_size - 1].status == dtmp.list[0].status) { //конец и начало у диаграм совпадают
            int time = this->list[dtmp.sum_size - 1].time;
            for (int i = 0; i < Diagram::MAX_SIZE && i < dtmp.sum_size; ++i) {
                this->list[this->sum_size + i - 1].status = dtmp.list[i].status;
                this->list[this->sum_size + i - 1].time += dtmp.list[i].time;
            }
            this->sum_size += dtmp.sum_size - 1;
            this->sum_time += dtmp.sum_time;
            this->list[this->sum_size - 1].time = time;
        } else {
            for (int i = 0; i < Diagram::MAX_SIZE && i < dtmp.sum_size; ++i) {
                this->list[this->sum_size + i].status = dtmp.list[i].status;
                this->list[this->sum_size + i].time = dtmp.list[i].time;
            }
            this->sum_size += dtmp.sum_size;
            this->sum_time += dtmp.sum_time;
        }


        return *this;
    }

    [[maybe_unused]] Diagram &Diagram::shiftRight(int time) {
        if (time < 0) { throw std::invalid_argument("Time < 0"); }
        if (this->sum_time + time > Diagram::MAX_TIME) { throw std::invalid_argument("Diagram time overflow"); }
        if (this->sum_size == 0) { return *this; }
        this->list[0].time += time;
        this->sum_time += time;
        return *this;
    }

    [[maybe_unused]] Diagram &Diagram::shiftLeft(int time) {
        if (time < 0) { throw std::invalid_argument("Time < 0"); }
        if (this->sum_time - time < 0) { throw std::invalid_argument("Diagram time < 0"); }
        if (time == 0) { return *this; }
        if (this->sum_size == 0) { return *this; }
        int end_index = 0;
        int size = this->sum_size;
        for (int i = 0; i < size; ++i) {
            if (this->list[i].time <= time) {
                this->list[i].status = 'X';
                time -= this->list[i].time;
                this->list[i].time = 0;
                this->sum_size--;
                end_index = i;
            } else {
                this->list[i].time -= time;
                end_index = i;
                break;
            }
        }
        int tmp_index = end_index;
        if (this->list[tmp_index].time == 0) {
            for (int i = 0; i < this->sum_size; ++i) {
                this->list[i].status = this->list[i + tmp_index + 1].status;
                this->list[i].time = this->list[i + tmp_index + 1].time;
            }
        } else {//if this->list[tmp_index].time > 0
            for (int i = 0; i < this->sum_size; ++i) { //- (tmp_index + 1)
                this->list[i].status = this->list[i + tmp_index].status;
                this->list[i].time = this->list[i + tmp_index].time;
            }
        }
        return *this;
    }

    [[maybe_unused]] Diagram &Diagram::multiplyCopy(int n) {
        if (n <= 0) { throw std::invalid_argument("Bad input n <= 0"); }
        if (this->sum_size == 0) { return *this; }
        if (this->sum_time * n > Diagram::MAX_TIME) { throw std::invalid_argument("Diagram time overflow"); }
        if (this->sum_size == 1) {
            this->list[0].time *= n;
            this->sum_time = this->list[0].time;
            return *this;
        }
        if (this->list[0].status == this->list[this->sum_size - 1].status) {
            if (this->sum_size * n - (n - 1) > Diagram::MAX_SIZE) {
                throw std::invalid_argument("Buffer size overflow");
            }
            int tmp_time = this->list[this->sum_size - 1].time;
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < this->sum_size; ++j) {
                    this->list[j + i * this->sum_size - i].status = this->list[j].status;
                    this->list[j + i * this->sum_size - i].time += this->list[j].time;
                }
                this->list[this->sum_size - 1 + i * this->sum_size - i].time = tmp_time;
            }
            this->sum_size = this->sum_size * n - (n - 1);
            this->sum_time = this->sum_time * n;
        } else {
            if (this->sum_size * n > Diagram::MAX_SIZE) { throw std::invalid_argument("Buffer size overflow"); }
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < this->sum_size; ++j) {
                    this->list[j + i * this->sum_size].status = this->list[j].status;
                    this->list[j + i * this->sum_size].time += this->list[j].time;
                }
            }
            this->sum_size = this->sum_size * n;
            this->sum_time *= n;
        }
        return *this;
    }

    Diagram &Diagram::insert(Diagram &dtmp, int time) {
        if (time < 0) { throw std::invalid_argument("Time < 0"); }
        if (dtmp.sum_size == 0) { throw std::invalid_argument("Diagram is empty"); }
        if (dtmp.sum_time + this->sum_time > Diagram::MAX_TIME) {
            throw std::invalid_argument("Diagram time overflow");
        }
        if (dtmp.sum_size + this->sum_size > Diagram::MAX_SIZE) {
            throw std::invalid_argument("Bad time for input, part of diagram can be lost");
        }
        if (time > sum_time) {
            throw std::invalid_argument("Use concatenation");
        }
        int tmp_time = time;
        int save_index = 0;//индекс начиная с которого будем вставлять диаграмму
        for (int i = 0; i < this->sum_size; ++i) {
            if (tmp_time > this->list[i].time) {
                tmp_time -= this->list[i].time;
            } else {
                save_index = i;
                break;
            }
        }
        if (save_index + 1 + dtmp.sum_size > Diagram::MAX_SIZE) {
            throw std::invalid_argument("Bad time for input, part of diagram can be lost");
        }
        this->sum_time -= this->list[save_index].time; //потому что удаляем элемент
        for (int i = dtmp.sum_size; i > 0; --i) {
            this->list[this->sum_size - 1 + i].status = this->list[this->sum_size - 1 + i -
                                                                   (dtmp.sum_size - 1)].status;
            this->list[this->sum_size - 1 + i].time = this->list[this->sum_size - 1 + i - (dtmp.sum_size - 1)].time;
        }
        int j = 0;
        for (int i = save_index; i < save_index + dtmp.sum_size; ++i) {
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
        this->sum_size = tmp_size;
        this->sum_time += dtmp.sum_time;

        i = 0;
        int save = -1;
        while (this->list[i].time != 0 && i < Diagram::MAX_SIZE) {
            if (this->list[i].status == this->list[i + 1].status) {
                save = i;
                break;
            }
            ++i;
        }
        if (save != -1) {
            for (int j = save; j < this->sum_size; ++j) {
                if (j == save) {
                    this->list[j].time += this->list[j + 1].time;
                } else {
                    this->list[j].status = this->list[j + 1].status;
                    this->list[j].time = this->list[j + 1].time;
                }
            }
            this->sum_size--;
        }

        i = 0;
        save = -1;
        while (this->list[i].time != 0 && i < Diagram::MAX_SIZE) {
            if (this->list[i].status == this->list[i + 1].status) {
                save = i;
                break;
            }
            ++i;
        }
        if (save != -1) {
            for (int j = save; j < this->sum_size; ++j) {
                if (j == save) {
                    this->list[j].time += this->list[j + 1].time;
                } else {
                    this->list[j].status = this->list[j + 1].status;
                    this->list[j].time = this->list[j + 1].time;
                }
            }
            this->sum_size--;
        }
        return *this;
    }

    [[maybe_unused]] std::istream &Diagram::initDiagram(std::istream &s) {
        std::string str;
        s >> str;
        init(str);
        return s;
    }

    void Diagram::init(std::string &str) {
        if (str.length() == 0) {
            throw std::invalid_argument("Empty string");
        }
        for (int i = 0; i < str.length(); ++i) {
            if (!Diagram::ifSig(str[i])) {
                throw std::invalid_argument("Bad char its not (0,1 or X)");
            }
        }//clear
        for (int i = 0; i < Diagram::MAX_SIZE; ++i) {
            this->list[i].time = 0;
            this->list[i].status = sig_X;
        }
        this->sum_size = 0;
        this->sum_time = 0;
        char tmp = str[0];
        int time = 0;
        int j = 0;
        for (int i = 0; i < str.length();) {
            while (str[i] == tmp && i < str.length() && i < Diagram::MAX_SIZE) {
                ++time;
                ++i;
            }
            this->list[j].status = tmp;
            this->list[j].time = time;
            ++j;
            this->sum_size++;
            this->sum_time += time;
            tmp = str[i];
            time = 0;
        }
    }


    Diagram &Diagram::operator++() { //pref
        for (int i = 0; i < this->sum_size; ++i) {
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
        Diagram d(*this);
        for (int i = 0; i < this->sum_size; ++i) {
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
        if (tmp.size() == 0) {
            s << "Diagram is empty";
        } else {
            s << "Status: ";
            for (int i = 0; i < tmp.size(); ++i) {
                if (tmp.list[i].time != 0) {
                    s << tmp.list[i].status << ' ';
                }
            }
            s << std::endl;
            s << "Time:   ";
            for (int i = 0; i < tmp.size(); ++i) {
                if (tmp.list[i].time != 0) {
                    s << tmp.list[i].time << ' ';
                }
            }
        }
        return s;
    }

    std::istream &operator>>(std::istream &s, Diagram &dtmp) {
        std::string str;
        s >> str;
        if (str.length() == 0) {
            throw std::invalid_argument("Empty string");
        }
        for (int i = 0; i < str.length(); ++i) {
            if (!Diagram::ifSig(str[i])) {
                throw std::invalid_argument("Bad char its not (0,1 or X)");
            }
        }//clear
        for (int i = 0; i < Diagram::MAXSIZE(); ++i) {
            dtmp.list[i].time = 0;
            dtmp.list[i].status = sig_X;
        }
        dtmp.sum_size = 0;
        dtmp.sum_time = 0;
        char tmp = str[0];
        int time = 0;
        int j = 0;
        for (int i = 0; i < str.length();) {
            while (str[i] == tmp && i < str.length() && i < Diagram::MAX_SIZE) {
                ++time;
                ++i;
            }
            dtmp.list[j].status = tmp;
            dtmp.list[j].time = time;
            ++j;
            dtmp.sum_size++;
            dtmp.sum_time += time;
            tmp = str[i];
            time = 0;
        }
        return s;
    }

    char Diagram::operator[](const int index) const {
        if (index < 0 || index > this->sum_time) {
            throw std::invalid_argument(" Index out of range");
        }
        return this->list[index].status;
    }

    Diagram &Diagram::operator+=(const Diagram &dtmp) {
        if (dtmp.sum_size + this->sum_size > Diagram::MAX_SIZE) {
            throw std::invalid_argument("Diagram buffer oversize");
        }
        if (this->sum_size == 0) {
            throw std::invalid_argument("Diagram is empty");
        }
        if (dtmp.sum_size == 0) {
            throw std::invalid_argument("Concat diagram is empty");
        }
        if (this->list[this->sum_size - 1].status == dtmp.list[0].status) { //конец и начало у диаграм совпадают
            int time = this->list[dtmp.sum_size - 1].time;
            for (int i = 0; i < Diagram::MAX_SIZE && i < dtmp.sum_size; ++i) {
                this->list[this->sum_size + i - 1].status = dtmp.list[i].status;
                this->list[this->sum_size + i - 1].time += dtmp.list[i].time;
            }

            this->sum_size += dtmp.sum_size - 1;
            this->sum_time += dtmp.sum_time;
            this->list[this->sum_size - 1].time = time;
        } else {
            for (int i = 0; i < Diagram::MAX_SIZE && i < dtmp.sum_size; ++i) {
                this->list[this->sum_size + i].status = dtmp.list[i].status;
                this->list[this->sum_size + i].time = dtmp.list[i].time;
            }
            this->sum_size += dtmp.sum_size;
            this->sum_time += dtmp.sum_time;
        }
        return *this;
    }

    std::string Diagram::getStr() const {
        if (this->sum_size == 0) {
            throw std::invalid_argument("Empty string");
        }
        std::string str;
        char ar[this->sum_size];
        for (int i = 0; i < this->sum_size; ++i) {
            ar[i] = this->list[i].status;
        }
        str = std::string(ar, sizeof(ar));
        return str;
    }

    int Diagram::operator()(int index) const {
        if (index < 0 || index > this->sum_time) {
            throw std::invalid_argument(" Index out of range");
        }
        return list[index].time;
    }

    char &Diagram::operator[](int index) {
        if (index < 0 || index > this->sum_time) {
            throw std::invalid_argument(" Index out of range");
        }
        return this->list[index].status;
    }

    Diagram Diagram::operator+(const Diagram &tmp) {
        if (this->sum_size + tmp.sum_size > Diagram::MAX_SIZE) {
            throw std::invalid_argument("Bad size");
        }
        Diagram new_d;
        for (int i = 0; i < this->sum_size; ++i) {
            new_d.list[i].status = this->list[i].status;
            new_d.list[i].time = this->list[i].time;
        }
        new_d.sum_size = this->sum_size;
        new_d.sum_time = this->sum_time;
        new_d = new_d.concatinate(tmp);
        return new_d;
    }
}