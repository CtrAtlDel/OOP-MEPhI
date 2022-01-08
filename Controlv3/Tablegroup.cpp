#include "Tablegroup.h"
#include "Junior.h"
#include <iostream>

Console::TableGroup::TableGroup(char category, int indexGroup, int maxRatings) : course(1) {
    if (category != Jun && category != Sen)
        throw std::invalid_argument("Not state category");
    this->indexGroup = indexGroup;
    this->category = category;
    this->maxRatings = maxRatings;
    this->course = 1; // todo first course
    this->table = new TableStudent(category, maxRatings);
}

double Console::TableGroup::getMedian() {
    if (this->table->getSize() == 0)
        throw std::invalid_argument("Empty table(no student)");
    double median = 0;
    for (int i = 0; i < this->table->getSize(); ++i) {
        median += this->table->getMedian(i);
    }
    median = (double) median / this->table->getSize();
    return median;
}

//todo 215A
std::ostream &Console::TableGroup::printTable(std::ostream &s) const {
    if (this->table->getSize() == 0) {
        s << "Empty group";
    } else {
        for (int i = 0; i < this->table->getSize(); ++i) {
            this->table->getStudent(s, i);
        }
    }
    return s;
}

std::ostream &
Console::TableGroup::printStudent(std::ostream &s, const std::string &surname, const std::string &initials) {
    int indexStudent = this->table->indexOfStudent(surname, initials);
    this->table->getStudent(s, indexStudent);
    return s;
}

Console::Student *Console::TableGroup::search(const std::string &surname, const std::string &initials) {
    for (int i = 0; i < this->table->getSize(); ++i) {
        if (this->table->table[i] != nullptr) {
            if (this->table->table[i]->getSurname() == surname && this->table->table[i]->getInitials() == initials) {
                return this->table->table[i];
            }
        }
    }
    return nullptr;
}

Console::TableGroup::TableGroup() {
    this->category = Jun;
    this->course = 1;
    this->maxRatings = 10; //todo 10 max rating
    this->indexGroup = 0;
    this->table = new TableStudent(Jun, maxRatings);

}

Console::TableGroup &Console::TableGroup::newStudent(std::string &surname, std::string &initials) {
    Student *st = nullptr;
    Junior *jun = new Junior(surname, initials);
    st = jun;
    this->table->setNewStudent(st);
    return *this;
}

Console::TableGroup &Console::TableGroup::lvlUp() {
    return *this;
}

Console::TableGroup &Console::TableGroup::lvlUpStudent(const std::string &surname, const std::string &initials) {
    return *this;
}

bool Console::TableGroup::inGroup(const std::string &surname, const std::string &initials) {
    Student *st = nullptr;
    if (search(surname, initials)) {
        return true;
    }
    return false;
}

std::ostream &Console::TableGroup::printAll(std::ostream &s) const {
    for (int i = 0; i < table->getSize(); ++i) {

    }
    return s;
}

std::ostream &Console::TableGroup::printStudent(std::ostream &s, const std::string &surname) {
//    int indexStudent = this->table->indexOfStudent(surname, initials);
//    this->table->getStudent(s, indexStudent);
    return s;
}

Console::Student *Console::TableGroup::search(const std::string &surname) {
    Student* st = nullptr;
    return st;
}

Console::TableGroup &Console::TableGroup::newStudent(Console::Student *st) {
    this->table->setNewStudent(st);
    return *this;
}

Console::TableGroup &
Console::TableGroup::setRating(const std::string &surname, const std::string &initials, double mark) {
    int indexStudent = table->indexOfStudent(surname, initials);
    table->setRating(indexStudent, mark);
    return *this;
}

Console::TableGroup &
Console::TableGroup::setRating(const std::string &surname, const std::string &initials, double mark,
                               int indexOfRating) {
    int indexStudent = table->indexOfStudent(surname,initials);
    table->setRating(indexStudent, mark, indexOfRating);
    return *this;
}

Console::TableGroup &
Console::TableGroup::setUIR(const std::string &surname, const std::string &initials, const std::string &theme) {
    int indexStudent = table->indexOfStudent(surname, initials);
    this->table->setUIR(indexStudent, theme);
    return *this;
}

Console::TableGroup &
Console::TableGroup::setPlace(const std::string &surname, const std::string &initials, const std::string &place) {
    int indexStudent = table->indexOfStudent(surname, initials);
    this->table->setPlace(indexStudent,place);
    return *this;
}

Console::TableGroup &
Console::TableGroup::setNumberTeacher(const std::string &surname, const std::string &initials, double number) {
    int indexStudent = table->indexOfStudent(surname, initials);
    this->table->setNumberTeacher(indexStudent, number);
    return *this;
}

Console::TableGroup &Console::TableGroup::setRating(Student* st, double mark) {
    if (st == nullptr)
        throw std::invalid_argument("Student == nullptr");
    table->setMark(st, mark);
    return *this;
}

Console::TableGroup &Console::TableGroup::setRating(Console::Student *st, double mark, int index) {
    if (st == nullptr)
        throw std::invalid_argument("Student == nullptr");
    table->setMark(st, mark, index);
    return *this;
}
