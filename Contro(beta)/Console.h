#ifndef CONTROLV2_CONSOLE_H
#define CONTROLV2_CONSOLE_H

#include <vector>
#include "TableGroup.h"

namespace Console {
    class Console {
    private:
        std::vector<TableGroup *> listOfGroup;
    public:
        Console();

        Console &lvlUp(const std::string &surname, const std::string &initials);

        Console &lvlUp(int indexGroup);

        Console &newStudent(const std::string &surname, const std::string &initials);

        Console &Student(const std::string &surname, const std::string &initials);

        int Median(int indexGroup);

        Console &setRating(const std::string &surname, const std::string &initials, double rating);

        Console &semControl(int indexGroup);

        Console &getInfoStudent(const std::string &surname, const std::string &initials);

        ~Console() {
            for (auto &i: listOfGroup)
                delete i;
        };
    };
}


#endif //CONTROLV2_CONSOLE_H
