#ifndef CONTROL_JUNIOR_H
#define CONTROL_JUNIOR_H

#include <string>
#include <vector>

namespace App {
    enum Category {
        Jun = 'J', //младшекурсник
        Sen = 'S', //старшекурсник
        No = '-' //без статуса
    };

    class Junior {
    protected:
        std::string surname; //фамилия
        std::string initial; //инициалы
        int sumOfRating; //количество оценок студента
//        double *rating; //массив оценок студента // vector
        std::vector<double> rating;
        char category; //тип студента
    public:
        explicit Junior() : sumOfRating(0), category(Jun) {}

        explicit Junior(const std::string &surname, const std::string &initial);

        explicit Junior(const std::string &surname, const std::string &initial, int sum);

        //getters
        char getCategory() const { return category; } //получить категорию

        double *getRating(); //получить список оченок

        std::string getSurname() { return surname; } //получить фамилию

        std::string getInitials() { return initial; } //получить инициалы

        //setters
        Junior &setRating(double rating, int index); //добавить оценку

        Junior &setRating(double rating);

        ~Junior() {  }

    public:
        void setSurname(std::string surname) { this->surname = surname; }; //внести фамилию

        void setInitals(std::string initials) { this->initial = initials; }; //внести инициалы

        void setCategories(char type) { this->category = type; }; //установить категорию

        void setSumOfRating(int ratting) { this->sumOfRating = ratting; }; //установить оценку

    };

}


#endif //CONTROL_JUNIOR_H
