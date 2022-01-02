//
// Created by Ivan on 17.11.2021.
//

#include <stdexcept>
#include "ConsoleAplication.h"

void App::ConsoleAplication::setStudent(char type, int sum, std::string &surname, std::string &initial, int indexG) {
    if (!ifIndex(indexG))
        throw std::invalid_argument("Bad index of group");
    for (int i = 0; i <this->finalTable.size() ; ++i) {
        if (this->finalTable[i].getIndex() == indexG){
            this->finalTable[i].setStudent(surname, initial, sum, type, indexG);
        }
    }
}

bool App::ConsoleAplication::ifIndex(int index) {
    for (int i = 0; i < this->finalTable.size(); ++i) {
        if (this->finalTable[i].getIndex() == index) {
            return true;
        }
    }
    return false;
}

void App::ConsoleAplication::lvlUp(std::string surname, std::string initials) {
    
}
