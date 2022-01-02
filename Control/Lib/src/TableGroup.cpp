//
// Created by Ivan on 16.11.2021.
//
#include <stdexcept>
#include "TableGroup.h"

App::TableGroup::TableGroup(char category, int index, int maxRiders) {
    this->category = category;
    this->index = index;
    this->maxRiders = maxRiders;
}

void App::TableGroup::setStudent(std::string &surname, std::string &initials, int sum, char type, int indexG) {
    if (type != Jun && type != Sen)
        throw std::invalid_argument("Not state category");
    this->index = indexG;
    if (type == Jun) {
        auto *jun = new Junior();
        jun->setCategories(type);
        jun->setSumOfRating(sum);
        jun->setSurname(surname);
        jun->setInitals(initials);
        this->tableGroup.setStudent(*jun);
    } else {
        Junior *sen = new Senior();
        sen->setInitals(initials);
        sen->setSurname(surname);
        sen->setCategories(type);
        sen->setSumOfRating(sum);
        this->tableGroup.setStudent(*sen);
    }
}

std::ostream &App::printTable(std::ostream &s) {
    //
}

void App::TableGroup::setRating(const std::string &surname, const std::string &initials, double rating, int index) {
    this->tableGroup.setRating(surname,initials, rating, index);
}

void App::TableGroup::setRating(const std::string &surname, const std::string &initials, double rating) {
    this->tableGroup.setRating(surname, initials, rating);
}
