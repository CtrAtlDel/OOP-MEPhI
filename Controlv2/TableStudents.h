#ifndef CONTROLV2_TABLESTUDENTS_H
#define CONTROLV2_TABLESTUDENTS_H

#include <vector>
#include <set>
#include "Student.h"
#include "Junior.h"
#include "Senior.h"

namespace Console {
    class TableStudents {
    public:
        std::vector<Student *> table;
        char category;
    public:
        explicit TableStudents(char category);

        //------------------Getters-------------------//
        [[nodiscard]]
        unsigned long long getSize() const { return table.size(); }; //получить количество студентов в группе

        [[nodiscard]]
        int getIndex(const std::string &surname,
                                   const std::string &initials) const; //получить номер студента в таблице по имени и фамиилии
        //---------------------------------------------//

        //------------------Setters--------------------//
        TableStudents &setUIR(const std::string &surname, const std::string &initials, const std::string &newUIR);

        TableStudents &setNewSumOfRating(const std::string &surname, const std::string &initials, int newSum);

        TableStudents &setRating(double rating, int index);

        TableStudents &setRating(const std::string &surname, const std::string &initials, double rating);

        TableStudents &setNewStudent(const std::string &surname, const std::string &initials);
        //---------------------------------------------//

        //---------------------Search------------------//
    private:
        Student *search(const std::string &surname, const std::string &initials) const;
        //---------------------------------------------//

        //---------------------Print------------------//
    public:
        std::ostream& getInfo(std::ostream& s, const std::string &surname, const std::string &initials) const;

        std::ostream& getInfo(std::ostream& s, int index) const;
        //----------------------------------------------//
    public:
        ~TableStudents() {
            for (auto &i: table) {
                delete i;
            }
        };
    };

}


#endif //CONTROLV2_TABLESTUDENTS_H
