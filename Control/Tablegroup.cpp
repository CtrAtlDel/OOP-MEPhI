#include "Tablegroup.h"
#include "Junior.h"
#include "Application.h"
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

std::ostream &Console::TableGroup::printTable(std::ostream &s) const {
    if (this->table->getSize() == 0) {
        s << "Empty group";
    } else {
        s << "Index group: " << this->getIndexGroup() << std::endl;
        s << "Coutse: " << this->getCourse() <<std::endl;
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
    this->maxRatings = Console::course_1; //todo 10 max rating
    this->indexGroup = 0;
    this->table = new TableStudent(Jun, maxRatings);

}

Console::TableGroup &Console::TableGroup::newStudent(const std::string &surname, const std::string &initials, int maxMark) {
    Student *st = nullptr;
    auto *jun = new Junior(surname, initials, maxMark);
    st = jun;
    this->table->setNewStudent(st);
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

Console::Student *Console::TableGroup::search(const std::string &surname) {
    Student *st = nullptr;
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
    int indexStudent = table->indexOfStudent(surname, initials);
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
    this->table->setPlace(indexStudent, place);
    return *this;
}

Console::TableGroup &
Console::TableGroup::setNumberTeacher(const std::string &surname, const std::string &initials, double number) {
    int indexStudent = table->indexOfStudent(surname, initials);
    this->table->setNumberTeacher(indexStudent, number);
    return *this;
}

Console::TableGroup &Console::TableGroup::setRating(Student *st, double mark) {
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

Console::TableGroup &Console::TableGroup::setUIR(Console::Student *student, const std::string &theme) {
    if (student == nullptr)
        throw std::invalid_argument("Student == nullptr");
    return *this;
}

Console::TableGroup &Console::TableGroup::lvlUp(int sizeOfRating) {
    if (course == 4)
        throw std::invalid_argument("Delete this in Application");
    if (this->course == 2) {
        //увеличиваем курс на единицу и пересобираем студентов
        ++course; // 3
        this->category = Sen;
        this->table->lvlUpJS(sizeOfRating);
        return *this;
    }
    this->maxRatings = sizeOfRating;
    table->lvlUp(sizeOfRating);
    ++course;
    return *this;
}

Console::Student *Console::TableGroup::getStudent(int indexOfStudent) {
    Student* st = nullptr;
    for (int i = 0; i < table->getSize(); ++i) {
        if (indexOfStudent == i){
            st = table->table[i];
            return st;
        }
    }
    return nullptr;
}


