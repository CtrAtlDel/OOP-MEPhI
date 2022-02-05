#include "Senior.h"

Console::Senior::Senior() {
    this->numberTeacher = 0;
    this->themeUIR = "-";
    this->placeUIR = "-";
    this->setCategories(Sen);
}

Console::Senior::Senior(const std::string &surname, const std::string &initials, std::string &themeUIR,
                        std::string &placeUIR, double numberTeacher) {
    this->surname = surname;
    this->initial = initials;
    this->themeUIR = themeUIR;
    this->placeUIR = placeUIR;
    this->numberTeacher = numberTeacher;
}

std::string Console::Senior::getThemeUIR() const {
    return this->themeUIR;
}

std::string Console::Senior::getPlaceUIR() const {
    return this->placeUIR;
}

double Console::Senior::getNumber() const {
    return this->numberTeacher;
}

Console::Student &Console::Senior::setThemeUIR(std::string theme) {
    this->themeUIR = theme;
    return *this;
}

Console::Student &Console::Senior::setPlaceUIR(std::string place) {
    this->placeUIR = place;
    return *this;
}

Console::Student &Console::Senior::setNumber(double count) {
    this->numberTeacher = count;
    return *this;
}
