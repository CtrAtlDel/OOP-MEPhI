#include "Application.h"
#include <iostream>
#include "getSome.h"

Console::Application::Application() {

}

std::istream &Console::Application::newStudent(std::istream &s) {
    std::cout << "Create new Student " << std::endl;
    std::cout << "Input surname: -> " << std::endl;
    std::string surname;
    std::string initials;
    getNum(surname);
    std::cout << "Input initials: -> " << std::endl;
    getNum(initials);
    addStudentInGroup(surname, initials);
    // todo trim surname intiials
    return s;
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
    TableGroup newGroup(Jun, createIndex(), 30);//todo сделать 30 константой
    this->allgroup.push_back(newGroup.newStudent(surname, initials));
}

void Console::Application::newGroup(char category, int maxSize, int indexGroup) {

}

int Console::Application::createIndex() {
    return allgroup.size() + 1;
}

void Console::Application::getMedian() {
    std::cout << "Input index of group: -> " << std::endl;
    int index;
    getNum(index);
    TableGroup *group = findGroup(index);
    if (group == nullptr) {
        std::cout << "No group whith this index" << std::endl;
    } else {
        double mediana = group->getMedian();
        std::cout << "This is median " << mediana << std::endl;
    }
}

Console::TableGroup *Console::Application::findGroup(int index) {
    for (int i = 0; i < this->allgroup.size(); ++i) {
        if (i == index) {
            return &allgroup[i];
        }
    }
    return nullptr;
}

std::istream &Console::Application::lvlUp(std::istream &s) {
    std::cout << "Input index of group: -> " << std::endl;
    int indexGroup;
    getNum(indexGroup);
    for (int i = 0; i < allgroup.size(); ++i) {
        if (i == indexGroup) {

        }
    }
    return s;
}

std::ostream &
Console::Application::printStudent(std::ostream &s, const std::string &surname, const std::string &initials) {
    TableGroup *group = findStudent(surname, initials);
    group->printStudent(s, surname, initials);
    return s;
}

Console::TableGroup *Console::Application::findStudent(const std::string &surname, const std::string &initials) {
    TableGroup *group = nullptr;
    for (auto &i: allgroup) {
        if (i.inGroup(surname, initials)) {
            return &i;
        }
    }
    return nullptr;
}

void Console::Application::printStudent() {
    std::cout << "Input surname: -> " << std::endl;
    std::string surname;
    std::string initials;
    getNum(surname);
    std::cout << "Input initials" << std::endl;
    getNum(initials);
    this->printStudent(std::cout, surname, initials);
}

void Console::Application::printStudentSurname() {
    std::cout << "Input surname: -> " << std::endl;
    std::string surname;
    getNum(surname);

}

void Console::Application::printTable(const int index) {
    if(index <0 || index > allgroup.size())
        throw std::invalid_argument("Index out of range");
    for (int i = 0; i < allgroup.size(); ++i) {
        if (index == i){

        }
    }
}

