#include <iostream>
#include "TableStudent.h"
#include "Senior.h"

Console::TableStudent::TableStudent(char category, int maxSize) {
    this->category = category;
    this->sizeRatings = maxSize;
}

int
Console::TableStudent::indexOfStudent(const std::string &surname, const std::string &initials) const { //номер студента
    for (int i = 0; i < table.size(); ++i) {
        if (table[i] != nullptr) {
            if (table[i]->getSurname() == surname && table[i]->getInitials() == initials) {
                return i;
            }
        }
    }
    return -1;
}

Console::Student *Console::TableStudent::search(const std::string &surname, const std::string &initials) const {
    for (auto &i: table) {
        if (i != nullptr) {
            if (i->getSurname() == surname && i->getInitials() == initials)
                return i;
        }
    }
    return nullptr;
}

Console::TableStudent &Console::TableStudent::setUIR(int indexStudent, const std::string &newUIR) {
    if (indexStudent < 0 || (indexStudent > this->table.size() - 1))
        throw std::invalid_argument("Index out of range");
    if (this->category == Jun)
        throw std::invalid_argument("Junior has'nt a UIR");
    Student *st = this->table[indexStudent];
    if (this->category == Sen) {
        auto *tmp = dynamic_cast<Senior *>(st);
        if (tmp == nullptr){
            throw std::invalid_argument("Bad dynamic_cast");
        }
        tmp->setThemeUIR(newUIR);
    }
    return *this;
}

Console::TableStudent &Console::TableStudent::setPlace(int indexStudent, const std::string &place) {
    if (indexStudent < 0 || (indexStudent > this->table.size() - 1))
        throw std::invalid_argument("Index out of range");
    if (this->category == Jun)
        throw std::invalid_argument("Junior has'nt a UIR");
    Student *student = this->table[indexStudent];
    auto *sen = dynamic_cast<Senior *>(student);
    if (sen == nullptr)
        throw std::invalid_argument("Dynamic_cast error");
    sen->setPlaceUIR(place);
    return *this;
}

Console::TableStudent &Console::TableStudent::setNumberTeacher(int indexStudent, double number) {
    if (indexStudent < 0 || (indexStudent > this->table.size() - 1))
        throw std::invalid_argument("Index out of range");
    if (this->category == Jun)
        throw std::invalid_argument("Junior has'nt a UIR");
    Student *student = this->table[indexStudent];
    Senior *sen = dynamic_cast<Senior *>(student);
    if (sen == nullptr)
        throw std::invalid_argument("Dynamic_cast error");
    sen->setNumber(number);
    return *this;
}

Console::TableStudent &Console::TableStudent::setNewStudent(Console::Student *student) { // todo sort this
    if (student == nullptr)
        throw std::invalid_argument("Empty student");
    if (student->getCategory() != this->category)
        throw std::invalid_argument("No equal category");
    this->table.push_back(student); //todo отсортировать
//    std::sort(table.begin(), table.end(), compareFun);
    return *this;
}

Console::TableStudent &Console::TableStudent::setRating(int indexStudent, double rating) {
    if (indexStudent < 0 || (indexStudent > this->table.size() - 1))
        throw std::invalid_argument("Index out of range");
    if (this->table[indexStudent]->getSumOfRating() >= this->sizeRatings)
        throw std::invalid_argument("Max size of rating");
    this->table[indexStudent]->setRating(rating);
    return *this;
}

std::ostream &Console::TableStudent::getStudent(std::ostream &s, int indexStudent) const {
    if (this->table.empty()) {
        s << "Table is empty";
        return s;
    } else {
        Student *st = this->table[indexStudent];
        if (st == nullptr) {
            s << "Student is absence " << std::endl;
            return s;
        }
        if (this->category == Jun) {
            s << "Surname: " << st->getSurname() << std::endl;
            s << "Initials: " << st->getInitials() << std::endl;
            s << "Number of student grades: " << st->getSumOfRating() << std::endl;
            s << "Rating: " << std::endl;
            templates::vector<double> tmp = st->getRating();
            for (double i: tmp) {
                s << i << " ";
            }
            s << std::endl;
            return s;

        } else {
            if (this->category == Sen) {
                s << "Surname: " << st->getSurname() << std::endl;
                s << "Initials: " << st->getInitials() << std::endl;
                s << "Number of student grades: " << st->getSumOfRating() << std::endl;
                s << "Rating: ";
                templates::vector<double> tmp = st->getRating();
                for (double i: tmp) {
                    s << i << " ";
                }
                Senior *sen_cast = nullptr;
                sen_cast = dynamic_cast<Senior *>(st);
                if (sen_cast == nullptr)
                    throw std::invalid_argument("Dynamic_cast error");
                s << std::endl;
                s << "Theme UIR: " << sen_cast->getThemeUIR() << std::endl;
                s << "Place UIR: " << sen_cast->getPlaceUIR() << std::endl;
                s << "Number of " << sen_cast->getNumber() << std::endl;
                s << std::endl;
                return s;
            }
        }
    }
    s << "I dont know" << std::endl;
    return s;
}

Console::TableStudent &Console::TableStudent::setRating(int indexStudent, double rating, int indexOfRating) {
    if (indexStudent < 0 || (indexStudent > this->table.size() - 1))
        throw std::invalid_argument("Index out of range");
    this->table[indexStudent]->setRating(rating, indexOfRating);
    return *this;
}

double Console::TableStudent::getMedian(int indexStudent) { //средний балл студента
    if (indexStudent < 0 || (indexStudent > this->table.size() - 1))
        throw std::invalid_argument("Index out of range");
    Student *student = this->table[indexStudent];
    double median = 0;
    templates::vector<double> tmp = student->getRating();
    for (int i = 0; i < tmp.size(); ++i) {
        median += tmp[i];
    }
    median = (double) median / tmp.size();
    return median;
}

Console::TableStudent &Console::TableStudent::deleteStudent(int indexStudent) {
    if (indexStudent < 0 || (indexStudent > this->table.size() - 1))
        throw std::invalid_argument("Index out of range");
    this->table.erase(indexStudent);
    return *this;
}

Console::TableStudent &Console::TableStudent::lvlup(int indexStudent) {

    return *this;
}

Console::TableStudent &Console::TableStudent::addStudent(Console::Student *st) {
    this->table.push_back(st);
    return *this;
}

void Console::TableStudent::setMark(Console::Student *pStudent, double d) {
    Student* st = pStudent;
    if (st == nullptr)
        throw std::invalid_argument("Student is nullptr");
    st->setRating(d);
}

void Console::TableStudent::setMark(Console::Student *pStudent, double d, int indexRating) {
    Student* st = pStudent;
    if (st == nullptr)
        throw std::invalid_argument("Student is nullptr");
    st->setRating(d, indexRating);
}
//Change max rating and clear rating vector
Console::TableStudent &Console::TableStudent::lvlUp() {
    if(this->table.empty())
        throw std::invalid_argument("Size == 0");



    return *this;
}
/*
 * Change Junior->Senior
 */
Console::TableStudent &Console::TableStudent::lvlUpJS() {
    return *this;
}

