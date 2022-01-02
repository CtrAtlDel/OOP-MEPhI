#ifndef CONTROL_SENIOR_H
#define CONTROL_SENIOR_H

#include <utility>
#include "Junior.h"

namespace App {
    class Senior : public Junior {
    private:
        std::string themeUIR; //тема УИР
        std::string placeUIR; //место выполнения УИР
        double numberTeacher; // оценка Научрука
    public:
        Senior() : numberTeacher(0) { this->category = Sen; }

        Senior(const std::string &surname, const std::string &initials, const int sum) : Junior(surname, initials,
                                                                                                sum) { this->category = Sen; }

        Senior(const std::string &surname, const std::string &initioals, std::string &themeUIR, std::string &placeUIR,
               double numberTeacher);


        //getters
        [[nodiscard]] std::string getThemeUIR() const { return themeUIR; } //получить тему УИР

        [[nodiscard]] std::string getPlaceUIR() const { return placeUIR; } //получить место выполнения УИР

        [[nodiscard]] double getNumber() const { return numberTeacher; } //

        //setters
        Senior &setThemeUIR(std::string theme);

        Senior &setPlaceUIR(std::string place);

        Senior &setNumber(double count);

    };
}

#endif //CONTROL_SENIOR_H
