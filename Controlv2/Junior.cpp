//
// Created by ctratldelete on 29.11.2021.
//

#include <stdexcept>
#include "Junior.h"

Console::Junior::Junior(const std::string &surname, const std::string &initial) {
    this->category = Jun;
    this->surname = surname;
    this->initial = initial;
    this->sumOfRating = 0;
}

Console::Junior::Junior(const std::string &surname, const std::string &initial, int sum) {
    if (sum < 0)
        throw std::invalid_argument("Sum of rating < 0 ");
    this->category = Jun;
    this->surname = surname;
    this->initial = initial;
    this->sumOfRating = sum;
}

Console::Student &Console::Junior::setSurname(std::string &surname) {
    this->surname = surname;
    return *this;
}

Console::Student &Console::Junior::setInitials(std::string &initials) {
    this->initial = initials;
    return *this;
}

Console::Student &Console::Junior::setRating(double rating, int index) {
    if (index < 0 || index > this->sumOfRating)
        throw std::invalid_argument("Index out of range");
    this->rating[index] = rating;
    return *this;
}

Console::Student &Console::Junior::setRating(double rating) {
    if (rating < 0)
        throw std::invalid_argument("Bad ratting");
    this->rating.push_back(rating);
    return *this;
}

Console::Student &Console::Junior::setCategories(char type) {
    this->category = type;
    return *this;
}

Console::Student &Console::Junior::setSumOfRating(int ratting) {
    this->sumOfRating = ratting;
    return *this;
}

//Console::Student &Console::Junior::setThemeUIR(std::string theme) {
//    return *this;
//}
//
//Console::Student &Console::Junior::setPlaceUIR(std::string place) {
//    return *this;
//}
//
//Console::Student &Console::Junior::setNumber(double count) {
//    return *this;
//}
