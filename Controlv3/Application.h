#ifndef CONTROLV3_APPLICATION_H
#define CONTROLV3_APPLICATION_H

//todo написать результирующий класс +-
//todo сделать ввод студента на первый курс +
//todo сделать переход на следующий курс(добавить в новую таблицу)
//todo Добавить трим +

//todo добавить добавление оценок в считывание

#include "Tablegroup.h"
#include "vector.h"

namespace Console {
    enum {
        course_1 = 5,
        course_2 = 10,
        course_3 = 15,
        course_4 = 15
    };

    class Application {
    private:
        templates::vector<TableGroup> allGroup;

    public:
        Application();

        ~Application() = default;

    public:
        void newGroup(char category, int maxSize, int indexGroup);

        //todo обрабатывать здесь сначала считывание, затем передачу как параметр
        //todo набора аргументов

        std::istream &newStudent(std::istream &s);

        void lvlUp();

        Application &lvlUp(int index, int maxMark);

        std::istream &lvlUp(std::istream &s); //todo добавить еще УИР для старшекурсников


        /**
         * Ввести тему УИР
         */
        void inputThemeUIR();

        /**
         * Ввести место УИР
         */
        void inputPlaceUIR();

        /**
         * Ввести номер УИР
         */
        void inputNumberTeacher();

        Application &setUIR(const std::string &surname, const std::string &initials, const std::string &theme);

        Application &setPlace(const std::string &surname, const std::string &initials, const std::string &place);

        Application &setNumberTeacher(const std::string &surname, const std::string &initials, double number);

        void addStudentInGroup(const std::string &surname, const std::string &initials);

        int createIndex();

        int getSizeOfGroup(int index);

        int getSizeOfGroupsWithStudent() { return this->allGroup.size(); };

        void printTable(int index);


        /**
         * Print all group
         * @return
         */
        std::ostream &printAllTable(std::ostream &) const;

        void printStudent();

        void printStudent(const std::string &surname);

        void printStudentSurname(); /// напечатать по фамилии

        std::ostream &printStudent(std::ostream &, const std::string &surname, const std::string &initials);

        void getMedian();

        TableGroup *findGroup(int index);

        TableGroup *findStudent(const std::string &surname, const std::string &initials);
    };
}

#endif //CONTROLV3_APPLICATION_H
