#ifndef CONTROL_TABLESTUDENTS_H
#define CONTROL_TABLESTUDENTS_H

#include <utility>
#include <vector>
#include "Junior.h"
#include "Senior.h"

namespace App {
    class TableStudents {
    private:
        std::vector<Junior *> table;
        char category;
        void sort(); //сортировка

    public:
        TableStudents() : category(No) {}

        explicit TableStudents(
                char category); //количество студентов (тип студента указывается с помощью конструктора)

        [[nodiscard]] Junior *getStudent(const int index) const { return table[index]; }; //получить по номеру в группе

        [[nodiscard]] Junior *getStudent(std::string &surname, std::string &initials) const {
            return table[getIndex(surname, initials)];
        }; //получить по фамилии и инициалам

        void setStudent(Junior &student); //записать нового студента в таблицу <- сслыка идет из TableGroup

        [[nodiscard]] unsigned long long
        getSize() const { return table.size(); }; //получить количество студентов в группе

        void setRating(const std::string &surname, const std::string &initials, double rating, int index);

        void setRating(const std::string &surname, const std::string &initials, double rating);

        double* getRating(const std::string &surname, const std::string &initials);

        void setNewSumOfRating(const std::string &surname, const std::string &initials, int newSum);

        void setUIR(const std::string &surname, const std::string &initials, const std::string& newUIR);

        ~TableStudents() = default;

    protected:
        [[nodiscard]] int getIndex(const std::string &surname,
                                   const std::string &initials) const; //получить номер студента в таблице по имени и фамиилии

        Junior &binSearch(int index) const; //бинарный поиск, который используется т.к. таблица упорядочена

    };

}

#endif //CONTROL_TABLESTUDENTS_H
