#include "Application.h"
#include <iostream>
#include "getSome.h"
#include "MyRealization.h"


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

void Console::Application::addStudentInGroup(const std::string &surname, const std::string &initials) {
    //если  есть свободное место в группах
    for (int i = 0; i < this->allGroup.size(); ++i) {
        if (allGroup[i].getCategory() == Jun && allGroup[i].getCourse() == 1) {
            if (!allGroup[i].isFull()) {
                allGroup[i].newStudent(surname, initials, defaultMarkFirst);
                return;
            }
        }
    }
    //если все группы переполнены или вообще нет групп
    TableGroup newGroup(Jun, createIndex(), defaultMarkFirst);//todo сделать 30 константой
    this->allGroup.push_back(newGroup.newStudent(surname, initials, defaultMarkFirst));
}

void Console::Application::newGroup(char category, int maxSize, int indexGroup) {

}

int Console::Application::createIndex() {
    return allGroup.size() + 1;
}

void Console::Application::getMedian() {
    std::cout << "Input index of group: -> " << std::endl;
    int indexGroup;
    getNum(indexGroup);
    int index = indexByIndexGroup(indexGroup);
    TableGroup *group = findGroup(index);
    if (group == nullptr) {
        std::cout << "No group with this index..." << std::endl;
    } else {
        double median = group->getMedian();
        std::cout << "This is median: -> " << median << std::endl;
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
    for (auto &&i: allGroup) {
        i.printTable(s);
    }
    return s;
}

void Console::Application::printStudent(const std::string &surname) {

}

void Console::Application::lvlUp() {
    std::cout << "Input index of group: -> " << std::endl;
    int index;
    getNum(index);
    if (!checkIndex(index)) {
        std::cout << "I didnt find index with this index..." << std::endl;
        return;
    }
    std::cout << "New size of mark: " << std::endl;
    int maxMark;
    getNum(maxMark);
    this->lvlUp(index, maxMark);
}

Console::Application &Console::Application::lvlUp(const int indexGroup, int maxMark) {
    int index = indexByIndexGroup(indexGroup);
    if (allGroup[index].getCourse() == 4) { //todo 4 курс
        allGroup.erase(index);
        return *this;
    }

    allGroup[index].lvlUp(maxMark);
    return *this;
}

void Console::Application::inputThemeUIR() {
    std::string theme, surname, initials;
    std::cout << "Input surname: -> " << std::endl;
    getNum(surname);
    MyFun::MyRealization::trim(surname);

    std::cout << "Input initials: -> " << std::endl;
    getNum(initials);
    MyFun::MyRealization::trim(initials);

    std::cout << "Input theme UIR: -> " << std::endl;
    getNum(theme);
    MyFun::MyRealization::trim(theme);

    this->setUIR(surname, initials, theme);
}

Console::Application &
Console::Application::setUIR(const std::string &surname, const std::string &initials, const std::string &theme) {
    for (auto &it: allGroup) {
        if (it.getCategory() == Sen)
            if (it.inGroup(surname, initials)) {
                it.setUIR(surname, initials, theme);
                return *this;
            }
        return *this;
    }
    return *this;
}

Console::Application &
Console::Application::setPlace(const std::string &surname, const std::string &initials, const std::string &place) {
    for (auto &it: allGroup) {
        if (it.getCategory() == Sen)
            if (it.inGroup(surname, initials)) {
                it.setPlace(surname, initials, place);
                return *this;
            }
        return *this;
    }
    return *this;
}

Console::Application &
Console::Application::setNumberTeacher(const std::string &surname, const std::string &initials, double number) {
    for (auto &it: allGroup) {
        if (it.getCategory() == Sen)
            if (it.inGroup(surname, initials)) {
                it.setNumberTeacher(surname, initials, number);
                return *this;
            }
        return *this;
    }
    return *this;
}

void Console::Application::inputPlaceUIR() {
    std::string place, surname, initials;
    std::cout << "Input surname: -> " << std::endl;
    getNum(surname);
    MyFun::MyRealization::trim(surname);

    std::cout << "Input initials: -> " << std::endl;
    getNum(initials);
    MyFun::MyRealization::trim(initials);

    std::cout << "Input place UIR: -> " << std::endl;
    getNum(place);
    MyFun::MyRealization::trim(place);
    this->setPlace(surname, initials, place);
}

void Console::Application::inputNumberTeacher() {
    std::string surname, initials;
    double numberTeacher;
    std::cout << "Input surname: -> " << std::endl;
    getNum(surname);
    MyFun::MyRealization::trim(surname);

    std::cout << "Input initials: -> " << std::endl;
    getNum(initials);
    MyFun::MyRealization::trim(initials);

    std::cout << "Input numberTeacher UIR: -> " << std::endl;
    getNum(numberTeacher);
    this->setNumberTeacher(surname, initials, numberTeacher);
}

int Console::Application::getSizeOfGroup(int index) {
    if (index < 0 || index > allGroup.size())
        throw std::invalid_argument("Bad index >> this->sizeOfGroup");
    return allGroup[index].getSize();
}

void Console::Application::addStudent() {
    std::string surname, initials;
    double numberTeacher;
    std::cout << "Input surname: -> " << std::endl;
    getNum(surname);
    MyFun::MyRealization::trim(surname);

    std::cout << "Input initials: -> " << std::endl;
    getNum(initials);
    MyFun::MyRealization::trim(initials);

    addStudentInGroup(surname, initials);
}

void Console::Application::sizeOfGroup() {
    std::cout << "There is " << allGroup.size() << " in course" << std::endl;
}

bool Console::Application::checkIndex(int index) const {
    for (auto &&i: allGroup) {
        if (i.getIndexGroup() == index) {
            return true;
        }
    }
    return false;
}

int Console::Application::indexByIndexGroup(int indexGroup) const {
    for (int i = 0; i < allGroup.size(); ++i) {
        if (allGroup[i].getIndexGroup() == indexGroup)
            return i;
    }
    return -1;
}

void Console::Application::addMarkForStudent() {
    std::string surname, initials;
    double mark;
    std::cout << "Input surname: -> " << std::endl;
    getNum(surname);
    MyFun::MyRealization::trim(surname);

    std::cout << "Input initials: -> " << std::endl;
    getNum(initials);
    MyFun::MyRealization::trim(initials);
    std::cout << "Input mark: -> " << std::endl;
    getNum(mark);
    if (!addMarkForStudent(surname, initials, mark))
        std::cout << "I didnt find this student" << std::endl;
}


bool
Console::Application::addMarkForStudent(const std::string &surname, const std::string &initials, double mark) {
    for (auto &i: allGroup) {
        if (i.inGroup(surname, initials)) {
            i.setRating(surname, initials, mark);
            return true;
        }
    }
    return false;
}

void Console::Application::addMarkForGroup() {
    int indexGroup;
    std::cout << "Input index of group: " << std::endl;
    getNum(indexGroup);
    if (!checkIndex(indexGroup)) {
        std::cout << "I didnt find index with this index..." << std::endl;
        return;
    }
    addMarkForGroup(indexGroup);
}

bool Console::Application::addMarkForGroup(int indexGroup) {
    int index = indexByIndexGroup(indexGroup);
    double mark = 0;
    Student *st = nullptr;
    for (int i = 0; i < allGroup[index].getSize(); ++i) {
        st = allGroup[index].getStudent(i);
        std::cout << "Course: " << allGroup[index].getCourse() << std::endl;
        std::cout << "Surname: " << st->getSurname() << std::endl;
        std::cout << "Initials: " << st->getInitials() << std::endl;
        std::cout << "Input mark: " << std::endl;
        getNum(mark);
        st->setRating(mark);
    }
    return true;
}

void Console::Application::addMarkForAllGroup() {
    std::cout << "Input mark for all students in all group" << std::endl;
    for (int i = 0; i < allGroup.size(); ++i) {
        addMarkForAllGroup(i);
    }
}

void Console::Application::changeMarkDef() {
    int markDef;
    std::cout << "Now default mark is " << defaultMarkFirst << std::endl;
    std::cout << "Input new default mark: " << std::endl;
    getNum(markDef);
    if (markDef <= 0) {
        std::cout << "Bad input..." << std::endl;
        return;
    }
    this->defaultMarkFirst = markDef;
}

bool Console::Application::addMarkForAllGroup(int index) {
    double mark = 0;
    Student *st = nullptr;
    for (int i = 0; i < allGroup[index].getSize(); ++i) {
        st = allGroup[index].getStudent(i);
        std::cout << "Course: " << allGroup[index].getCourse() << std::endl;
        std::cout << "Surname: " << st->getSurname() << std::endl;
        std::cout << "Initials: " << st->getInitials() << std::endl;
        std::cout << "Input mark: " << std::endl;
        getNum(mark);
        st->setRating(mark);
    }
    return true;
}

Console::Application::Application() = default;

