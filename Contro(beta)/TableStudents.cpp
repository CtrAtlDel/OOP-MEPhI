#include <stdexcept>
#include <iostream>

#include "TableStudents.h"


Console::TableStudents::TableStudents(char category) {
    if (category != Jun && category != Sen)
        throw std::invalid_argument("Not state category");
    this->category = category;
}

Console::TableStudents &
Console::TableStudents::setUIR(const std::string &surname, const std::string &initials, const std::string &newUIR) {
    Student *st = search(surname, initials);
    if (this->category == Sen) {
        Senior *tmp = dynamic_cast<Senior *>(st);
        tmp->setThemeUIR(newUIR);
    } else {
        if (this->category == Jun) { *this; }
    };
    return *this;
}

Console::TableStudents &
Console::TableStudents::setNewSumOfRating(const std::string &surname, const std::string &initials, int newSum) {
    Student *st = search(surname, initials);
    st->setSumOfRating(newSum);
    return *this;
}

Console::Student *Console::TableStudents::search(const std::string &surname, const std::string &initials) const {
    for (auto &i: table) {
        if (i != nullptr) {
            if (i->getSurname().compare(surname) && i->getInitials().compare(initials)) { return i; }
//            if (i->getSurname() == surname && i->getInitials() == initials) {
//                return i;
//            }
        }
    }
    return nullptr;
}

Console::TableStudents &
Console::TableStudents::setRating(double rating, int index) { //????????
    if (index < 0 || index > table.size())
        throw std::invalid_argument("Index our of a range ");
    table[index]->setSumOfRating(rating);
    return *this;
}

Console::TableStudents &
Console::TableStudents::setRating(const std::string &surname, const std::string &initials,
                                  double rating) { //????????????
    Student *st = search(surname, initials);
    return *this;
}

int Console::TableStudents::getIndex(const std::string &surname, const std::string &initials) const {
    //
    for (int i = 0; i < table.size(); ++i) {
        if (table[i] != nullptr) {
            if (table[i]->getSurname().compare(surname) && table[i]->getInitials().compare(initials)) {
                return i;
            }
        }
    }
}

Console::TableStudents &Console::TableStudents::setNewStudent(const std::string &surname, const std::string &initials) {
    if (this->category == Jun) {
        Student *st = new Junior(surname, initials);
        this->table.push_back(st);
    } else {
        Student *st = new Senior(surname, initials);
        this->table.push_back(st);
    }
    return *this;
}

std::ostream &
Console::TableStudents::getInfo(std::ostream &s, const std::string &surname, const std::string &initials) const {
    if (this->table.empty()) {
        s << "Table is empty";
    } else {
        Student *st = search(surname, initials);
        if (st == nullptr) {
            s << "Student is absence " << std::endl;
            return s;
        }
        if (this->category == Jun) {
            s << "Surname: " << st->getSurname() << std::endl;
            s << "Initials: " << st->getInitials() << std::endl;
            s << "Number of student grades: " << st->getSumOfRating() << std::endl;
            s << "Rating: ";
            std::vector tmp = st->getRating();
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
                std::vector tmp = st->getRating();
                for (double i: tmp) {
                    s << i << " ";
                }
                Senior *sen_cast = nullptr;
                sen_cast = dynamic_cast<Senior *>(st);
                s << std::endl;
                s << "Theme UIR: " << sen_cast->getThemeUIR() << std::endl;
                s << "Place UIR: " << sen_cast->getPlaceUIR() << std::endl;
                s << "Number of " << sen_cast->getNumber() << std::endl;
                return s;
            }
        }

    }
    s << "I dont know" << std::endl;
    return s;
}

std::ostream &Console::TableStudents::getInfo(std::ostream &s, int index) const {
    if (this->table.empty()) {
        s << "Table is empty";
    } else {
        Student *st = this->table[index];
        if (st == nullptr) {
            s << "Student is absence " << std::endl;
            return s;
        }
        if (this->category == Jun) {
            s << "Surname: " << st->getSurname() << std::endl;
            s << "Initials: " << st->getInitials() << std::endl;
            s << "Number of student grades: " << st->getSumOfRating() << std::endl;
            s << "Rating: ";
            std::vector tmp = st->getRating();
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
                std::vector tmp = st->getRating();
                for (double i: tmp) {
                    s << i << " ";
                }
                Senior *sen_cast = nullptr;
                sen_cast = dynamic_cast<Senior *>(st);
                s << std::endl;
                s << "Theme UIR: " << sen_cast->getThemeUIR() << std::endl;
                s << "Place UIR: " << sen_cast->getPlaceUIR() << std::endl;
                s << "Number of " << sen_cast->getNumber() << std::endl;
                return s;
            }
        }

    }
    s << "I dont know" << std::endl;
    return s;
}




