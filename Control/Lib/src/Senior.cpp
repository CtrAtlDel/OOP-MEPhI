#include "Senior.h"
#include "Junior.h"


App::Senior &App::Senior::setThemeUIR(std::string theme) {
    this->themeUIR = theme;
    return *this;
}

App::Senior &App::Senior::setPlaceUIR(std::string place) {
    this->placeUIR = place;
    return *this;
}

App::Senior &App::Senior::setNumber(double count) {
    this->numberTeacher = count;
    return *this;
}

App::Senior::Senior(const std::string &surname, const std::string &initioals, std::string &themeUIR,
                    std::string &placeUIR, double numberTeacher) {
    this->surname = surname;
    this->initial = initioals;
    this->themeUIR = themeUIR;
    this->placeUIR = placeUIR;
    this->numberTeacher = numberTeacher;
}


