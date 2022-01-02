//
// Created by ctratldelete on 29.11.2021.
//

#ifndef CONTROLV2_SENIOR_H
#define CONTROLV2_SENIOR_H

#include "Junior.h"

namespace Console {
    class Senior : public Junior {
        std::string themeUIR; //тема УИР
        std::string placeUIR; //место выполнения УИР
        double numberTeacher; // оценка Научрука
    public:
        explicit Senior();

        explicit Senior(const std::string &surname, const std::string &initials) : Junior(surname,
                                                                                          initials) { this->numberTeacher = 0; }

        explicit Senior(const std::string &surname, const std::string &initials, const int sum) : Junior(surname,
                                                                                                         initials,
                                                                                                         sum),
                                                                                                  themeUIR(""),
                                                                                                  placeUIR(""),
                                                                                                  numberTeacher(
                                                                                                          0) { this->category = Sen; }

        explicit Senior(const std::string &surname, const std::string &initials, std::string &themeUIR,
                        std::string &placeUIR,
                        double numberTeacher);

        //------------------Getters-------------------//
        std::string getThemeUIR() const; //получить тему УИР

        std::string getPlaceUIR() const; //получить место выполнения УИР

        double getNumber() const;

        //------------------Setters-------------------//
        Student &setThemeUIR(std::string theme);

        Student &setPlaceUIR(std::string place);

        Student &setNumber(double count);
        //---------------------------------------------//
    };
}

#endif //CONTROLV2_SENIOR_H
