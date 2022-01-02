#ifndef CONTROL_TABLEGROUP_H
#define CONTROL_TABLEGROUP_H

#include "TableStudents.h"

namespace App {

    class TableGroup {
    private:
        TableStudents tableGroup;
        int maxRiders; // колиество максимальных дисциплин
        int index; // индекс группы (525)
        char category; //jun or Senior
    public:

        TableGroup(): maxRiders(0), index(0), category(No){}

        explicit TableGroup(char category, int index, int maxRiders); //создание таблицы без студентов

        [[nodiscard]] int getIndex() const { return index; } //получить индекс группы

        [[nodiscard]] int getMaxRiders() const { return maxRiders; } //получить максимальное количество оценок

        [[nodiscard]] char getType() const { return category; } //получить категорию студентов

        void setRating(const std::string &surname, const std::string &initials, double rating, int index);

        void setRating(const std::string &surname, const std::string &initials, double rating);

        void setStudent(std::string &surname, std::string &initials, int sum, char type,
                                  int indexG); //записать нового студента

        friend std::ostream &printTable(std::ostream &s); //напечатать таблицу
    };


}

#endif //CONTROL_TABLEGROUP_H
