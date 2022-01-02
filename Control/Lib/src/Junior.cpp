#include <stdexcept>
#include "Junior.h"

App::Junior::Junior(const std::string &surname, const std::string &initial) {
    this->category = Jun;
    this->surname = surname;
    this->initial = initial;
    this->sumOfRating = 0;
}

App::Junior::Junior(const std::string &surname, const std::string &initial, int summofrating) {
    if (summofrating < 0)
        throw std::invalid_argument("Sum of rating < 0 ");
    this->category = Jun;
    this->surname = surname;
    this->initial = initial;
    this->sumOfRating = summofrating;
}

App::Junior &App::Junior::setRating(double rating, int index) {
    if (index < 0 || index > this->sumOfRating)
        throw std::invalid_argument("Index out of range");
    this->rating[index] = rating;

    return *this;
}

double *App::Junior::getRating() {
    double* newRating = new double[this->rating.size()];
    for (int i = 0; i <this->rating.size() ; ++i) {
        newRating[i] = this->rating[i];
    }
    return newRating;
}

App::Junior &App::Junior::setRating(double rating) {
    this->rating.push_back(rating);
}
