#ifndef CONTROL_CONSOLEAPLICATION_H
#define CONTROL_CONSOLEAPLICATION_H

#include "TableGroup.h"

namespace App {
    class ConsoleAplication {
    private:
        std::vector<TableGroup> finalTable; //вектор
    public:
        ConsoleAplication() {}

        void setStudent(char type, int sum, std::string &surname, std::string &initial,
                        int indexG); //поступление студента в университета

        void lvlUp(std::string surname, std::string initials); //перевод на следующий курс студента

        void lvlUp(int indexG); //перевод на следующий курс группу

        double getMediana(int indexG); //индекс группы для среднего балла

        void wheelStudent();

        int getSize() { return finalTable.size(); }

        ~ConsoleAplication() {}
    private:
        bool ifIndex(int index);
    };
}

#endif //CONTROL_CONSOLEAPLICATION_H
