#include <stdexcept>
#include "TableStudents.h"

App::TableStudents::TableStudents(char category) { //constructor
    if (category != Jun && category != Sen)
        throw std::invalid_argument("Not state category");
    this->category = category; //пушнуть джуна или сеньера
}

int App::TableStudents::getIndex(const std::string &surname,
                                 const std::string &initials) const {
    int search = -1;
    for (int i = 0; i < table.size(); ++i) {
        if (table[i]->getInitials() == surname && table[i]->getSurname() == surname) {
            return i;
        }
    }
    return -1;
}

void App::TableStudents::setStudent(App::Junior &student) {
    Junior *jun = &student;
    this->table.push_back(jun);
    //sort
}

void App::TableStudents::setRating(const std::string &surname, const std::string &initials, double rating, int index) {
    for (int i = 0; i <table.size(); ++i) {
        if (table[i]->getSurname() == surname && table[i]->getInitials() == initials){
            table[i]->setRating(rating, index);
            return;
        }
    }
}

void App::TableStudents::setRating(const std::string &surname, const std::string &initials, double rating) {
    for (int i = 0; i <table.size(); ++i) {
        if (table[i]->getSurname() == surname && table[i]->getInitials() == initials){
            table[i]->setRating(rating);
            return;
        }
    }
}

double* App::TableStudents::getRating(const std::string &surname, const std::string &initials) {
    int index = -1;
    for (int i = 0; i < this->getSize() ; ++i) {
        if (table[i]->getSurname() == surname && table[i]->getInitials() == initials){
            index = i;
        }
    }
    return table[index]->getRating();
}

void App::TableStudents::setNewSumOfRating(const std::string &surname, const std::string &initials, int newSum) {
    if (newSum <= 0)
        throw std::invalid_argument("Bad sum of rating");
    int index = -1;
    for (int i = 0; i < this->getSize() ; ++i) {
        if (table[i]->getSurname() == surname && table[i]->getInitials() == initials){
            index = i;
        }
    }
    this->table[index]->setSumOfRating(newSum);
}

void App::TableStudents::setUIR(const std::string &surname, const std::string &initials, const std::string &newUir) {
    int index = -1;
    for (int i = 0; i < this->table.size(); ++i) {
        if (table[i]->getSurname() == surname && table[i]->getInitials() == initials){
            index = i;
        }
    }
    this->table[index]->setThemeUIR(newUir);
}


