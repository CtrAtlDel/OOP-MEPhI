#include "Tablegroup.h"
#include <iostream>

Console::TableGroup::TableGroup(char category, int indexGroup, int maxRatings) : course(1) {
    if (category != Jun && category != Sen)
        throw std::invalid_argument("Not state category");
    this->indexGroup = indexGroup;
    this->category = category;
    this->maxRatings = maxRatings;
    this->table = new TableStudent(category, maxRatings);
}

double Console::TableGroup::getMediana() {
    if (this->table->getSize() == 0)
        throw std::invalid_argument("Empty table(no student)");
    double mediana = 0;
    for (int i = 0; i < this->table->getSize(); ++i) {
        mediana += this->table->getMedian(i);
    }
    mediana /= this->table->getSize();
    return mediana;
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
//    Student* st = search(surname, initials);
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
//
//Console::TableGroup &Console::TableGroup::lvlup() {
//
//    return *this;
//}
