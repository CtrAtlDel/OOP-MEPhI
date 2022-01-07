#ifndef CONTROLV3_APPLICATION_H
#define CONTROLV3_APPLICATION_H

//todo написать результирующий класс
//todo сделать ввод студента на первый курс
//todo сделать переход на следующий курс(добавить в новую таблицу)
//todo Добавить трим

#include "Tablegroup.h"
#include "vector.h"

namespace Console {
    class Application {
        private:
        templates::vector<TableGroup> allgroup;
    public:
        Application();
        ~Application() = default;
    public:
        void newGroup(char category, int maxSize, int indexGroup);
        //todo обрабатывать здесь сначала считывание, затем передачу как парметр
        //todo набора аргументов

        std::istream& newStudent(std::istream&);

        void addStudentInGroup(std::string& surname, std::string& initials);

        int createIndex();

        void lvlup();

        void printTable();

        std::ostream& printStudent(std::ostream& s, int index, int indexGroup);

        void getMediana();

        TableGroup* findGroup(int index);

    };
}

#endif //CONTROLV3_APPLICATION_H
