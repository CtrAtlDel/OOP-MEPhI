#ifndef CONTROLV3_APPLICATION_H
#define CONTROLV3_APPLICATION_H

//todo написать результирующий класс
//todo сделать ввод студента на первый курс
//todo сделать vector как шаблон +
//todo сделать переход на следующий курс(добавить в новую таблицу)
//todo сделать гугл тесты +
//todo

#include "Tablegroup.h"
#include "vector.h"

namespace Console {
    class Application {
        private:
        templates::vector<TableGroup> allgroup;
//        std::vector<TableGroup> allgroup;
    public:
        Application();
        ~Application() = default;
    public:
        void newGroup(char category, int maxSize, int indexGroup);
        //todo обрабатывать здесь сначала считывание, затем передачу как парметр
        //todo набора аргументов

        void newStudent();

        void lvlup();

        void printTable();

        void printStudent();

        void getMediana();

    private:

    };
}

#endif //CONTROLV3_APPLICATION_H
