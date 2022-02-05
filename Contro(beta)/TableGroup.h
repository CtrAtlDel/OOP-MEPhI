#ifndef CONTROLV2_TABLEGROUP_H
#define CONTROLV2_TABLEGROUP_H

#include "TableStudents.h"

namespace Console {
    class TableGroup {
    private:
        TableStudents *tableGroup;
        int maxRiders; // колиество оценок
        int numberGroup; // индекс группы (525)
        char category; //jun or Sen
    public:
        explicit TableGroup(char category, int index, int maxsize);

        //------------------Getters-------------------//
        [[nodiscard]]
        int getIndex() const { return this->numberGroup; }

        [[nodiscard]]
        char getcategory() const { return this->category; }

        [[nodiscard]]
        int getMaxRiders() const { return this->maxRiders; } //вернуть количество оценок

        //---------------------------------------------//

        //------------------Setters--------------------//
        TableGroup &setUIR(const std::string &surname, const std::string &initials, const std::string &newUIR);

        TableGroup &setNewSumOfRating(const std::string &surname, const std::string &initials, int newSum);

        TableGroup &setRating(double rating, int index);

        TableGroup &setRating(const std::string &surname, const std::string &initials, double rating);

        TableGroup &setNewStudent(const std::string &surname, const std::string &initials);
        //---------------------------------------------//

        //------------------Functions------------------//
        std::istream &inputStudent(std::istream &s); //поступление студента в институт

        TableGroup &lvlUp(); //перевод на следующий курс

        TableGroup& controlTable(); // ведомость семетрового контроля

        double getMediana() ; // ср бал группы

        TableGroup& getFFF(); // получить коичество двоишников
        //---------------------------------------------//

        //--------------------Input--------------------//

        //---------------------------------------------//

        //---------------------Print-------------------//
        std::ostream &printTable(std::ostream &s);

        std::ostream &printStudent(std::ostream &s, const std::string &surname, const std::string &initials) const;
        //--------------------------------------------//
    public:
        ~TableGroup() {
            delete tableGroup;
        }
    };
}

#endif //CONTROLV2_TABLEGROUP_H
