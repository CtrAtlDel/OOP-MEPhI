#include <iostream>
#include "TableGroup.h"


Console::TableGroup::TableGroup(char category, int index, int maxsize) {
    this->category = category;
    this->numberGroup = index;
    this->maxRiders = 0;
    tableGroup = new TableStudents(category);
}

std::ostream &Console::TableGroup::printTable(std::ostream &s) {
    for (int i = 0; i < this->tableGroup->table.size(); ++i) {
        this->tableGroup->getInfo(s, i);
    }
    return s;
}

std::ostream &
Console::TableGroup::printStudent(std::ostream &s, const std::string &surname, const std::string &initials) const {
    this->tableGroup->getInfo(s, surname, initials);
    return s;
}

std::istream &Console::TableGroup::inputStudent(std::istream &s) { //?????????????????????????????????????
    std::string str;
    s >> str;
    return s;
}

Console::TableGroup &
Console::TableGroup::setUIR(const std::string &surname, const std::string &initials, const std::string &newUIR) {
    this->tableGroup->setUIR(surname, initials, newUIR);
    return *this;
}

Console::TableGroup &
Console::TableGroup::setNewSumOfRating(const std::string &surname, const std::string &initials, int newSum) {
    this->tableGroup->setNewSumOfRating(surname, initials, newSum);
    return *this;
}

Console::TableGroup &Console::TableGroup::setRating(double rating, int index) {
    this->tableGroup->setRating(rating, index);
    return *this;
}

Console::TableGroup &
Console::TableGroup::setRating(const std::string &surname, const std::string &initials, double rating) {
    this->tableGroup->setRating(surname, initials, rating);
    return *this;
}

Console::TableGroup &Console::TableGroup::setNewStudent(const std::string &surname, const std::string &initials) {
    this->tableGroup->setNewStudent(surname, initials);
    return *this;
}

double Console::TableGroup::getMediana() { // ср балл по группе
    double mediana = 0;
    for (int i = 0; i < tableGroup->table.size(); ++i) {
        std::vector tmp = tableGroup->table[i]->getRating();
    }
    return mediana;
}
