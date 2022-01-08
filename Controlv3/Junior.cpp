#include "Junior.h"
#include <stdexcept>

Console::Junior::Junior(const std::string &surname, const std::string &initial) {
    this->category = Jun;
    this->surname = surname;
    this->initial = initial;
    this->sizeOfRating = 0;
}

Console::Junior::Junior(const std::string &surname, const std::string &initial, int sum) {
    if (sum < 0)
        throw std::invalid_argument("Sum of rating < 0 ");
    this->category = Jun;
    this->surname = surname;
    this->initial = initial;
    this->sizeOfRating = sum;
}

Console::Student &Console::Junior::setSurname(const std::string &surname) {
    this->surname = surname;
    return *this;
}

Console::Student &Console::Junior::setInitials(const std::string &initials) {
    this->initial = initials;
    return *this;
}

Console::Student &Console::Junior::setRating(double rating, int index) {
    if (index < 0 || index > this->sizeOfRating)
        throw std::invalid_argument("Index out of range");
    this->sizeOfRating++;
    this->rating[index] = rating;
    return *this;
}

Console::Student &Console::Junior::setRating(double rating) {
    if (rating < 0)
        throw std::invalid_argument("Bad ratting");
    this->sizeOfRating++;
    this->rating.push_back(rating);
    return *this;
}

Console::Student &Console::Junior::setCategories(char type) {
    this->category = type;
    return *this;
}

Console::Student &Console::Junior::setSumOfRating(int ratting) {
    this->sizeOfRating = ratting;
    return *this;
}

Console::Student &Console::Junior::deleteRating() {
    if (!rating.empty())
        rating.clear();
    return *this;
}
