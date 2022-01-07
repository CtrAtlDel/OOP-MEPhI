#include "Application.h"
#include <iostream>
#include "getSome.h"

Console::Application::Application() {

}

std::istream& Console::Application::newStudent(std::istream&) {
    std::cout << "Create new Student " << std::endl;
    std::cout << "Input surname: -> " << std::endl;
    std::string surname;
    std::string initials;
    getNum(surname);
    std::cout << "Input initials: -> " << std::endl;
    getNum(initials);
    addStudentInGroup(surname, initials);
    // todo trim surname intiials
}

void Console::Application::addStudentInGroup(std::string &surname, std::string &initials) {
    //если  есть свободное место в группах
    for (int i = 0; i < this->allgroup.size(); ++i) {
        if (allgroup[i].getCategory() == Jun && allgroup[i].getCourse() == 1) {
            if (!allgroup[i].isFull()) {
                allgroup[i].newStudent(surname, initials);
            }
        }
    }
    //если все группы переполнены или вообще нет групп
    TableGroup newGroup(Jun, createIndex(), 30);
    newGroup.newStudent(surname,initials); //todo сделать 30 константой
    allgroup.push_back(newGroup);
}

void Console::Application::newGroup(char category, int maxSize, int indexGroup) {

}

int Console::Application::createIndex() {
    return allgroup.size() + 1;
}

void Console::Application::getMediana() {
    std::cout << "Input index of group: -> " << std::endl;
    int index;
    getNum(index);
    TableGroup* group = findGroup(index);
    if (group == nullptr){
        std::cout << "No group whith this index" << std::endl;
    }else{
        double mediana = group->getMediana();
        std::cout << "This is median " << mediana << std::endl;
    }
}

Console::TableGroup *Console::Application::findGroup(int index) {
    for (int i = 0; i < this->allgroup.size(); ++i) {
        if (i == index){
            return &allgroup[i];
        }
    }
    return nullptr;
}


