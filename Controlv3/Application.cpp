#include "Application.h"
#include <iostream>
#include "getSome.h"
#include "MyRealization.h"

Console::Application::Application() {

}

std::istream &Console::Application::newStudent(std::istream &s) {
    std::cout << "Create new Student " << std::endl;
    std::cout << "Input surname: -> " << std::endl;
    std::string surname;
    std::string initials;
    getNum(surname);
    MyFun::MyRealization::trim(surname);
    std::cout << "Input initials: -> " << std::endl;
    getNum(initials);
    MyFun::MyRealization::trim(initials);
    addStudentInGroup(surname, initials);
    return s;
}

void Console::Application::addStudentInGroup(std::string &surname, std::string &initials) {
    //если  есть свободное место в группах
    for (int i = 0; i < this->allGroup.size(); ++i) {
        if (allGroup[i].getCategory() == Jun && allGroup[i].getCourse() == 1) {
            if (!allGroup[i].isFull()) {
                allGroup[i].newStudent(surname, initials);
            }
        }
    }
    //если все группы переполнены или вообще нет групп
    TableGroup newGroup(Jun, createIndex(), 30);//todo сделать 30 константой
    this->allGroup.push_back(newGroup.newStudent(surname, initials));
}

void Console::Application::newGroup(char category, int maxSize, int indexGroup) {

}

int Console::Application::createIndex() {
    return allGroup.size() + 1;
}

void Console::Application::getMedian() {
    std::cout << "Input index of group: -> " << std::endl;
    int index;
    getNum(index);
    TableGroup *group = findGroup(index);
    if (group == nullptr) {
        std::cout << "No group whith this index" << std::endl;
    } else {
        double median = group->getMedian();
        std::cout << "This is median " << median << std::endl;
    }
}

Console::TableGroup *Console::Application::findGroup(int index) {
    for (int i = 0; i < this->allGroup.size(); ++i) {
        if (i == index) {
            return &allGroup[i];
        }
    }
    return nullptr;
}

std::istream &Console::Application::lvlUp(std::istream &s) {
    std::cout << "Input index of group: -> " << std::endl;
    int indexGroup;
    getNum(indexGroup);
    for (int i = 0; i < allGroup.size(); ++i) {
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
    for (auto &i: allGroup) {
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

/**
 * печать студента по фамилии
 */
void Console::Application::printStudentSurname() {
    std::cout << "Input surname: -> " << std::endl;
    std::string surname;
    getNum(surname);
    MyFun::MyRealization::trim(surname);
}

/**
 * Индекс студента, которого нужно напечаать
 * @param index
 */
void Console::Application::printTable(const int index) {
    if (index < 0 || index > allGroup.size())
        throw std::invalid_argument("Index out of range");
    for (int i = 0; i < allGroup.size(); ++i) {
        if (index == i) {
            //todo печатать
        }
    }
}

std::ostream &Console::Application::printAllTable(std::ostream &s) const {

    return s;
}

void Console::Application::printStudent(const std::string &surname) {

}

void Console::Application::lvlUp() {
    std::cout << "Input index of group: -> " << std::endl;
    int index;
    getNum(index);
    this->lvlUp(index);
}
Console::Application &Console::Application::lvlUp(const int index) {
    if (index < 0 || index> allGroup.size())
        throw std::invalid_argument("Index of range");
    if (allGroup[index].getCourse() == 4){
        allGroup.erase(index);
        return *this;
    }else{
        allGroup[index].lvlUp(); //todo 4 курс
    };
    return *this;
}

