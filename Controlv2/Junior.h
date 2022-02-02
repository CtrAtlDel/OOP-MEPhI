#ifndef CONTROLV2_JUNIOR_H
#define CONTROLV2_JUNIOR_H


#include <vector>
#include <iostream>
#include "Student.h"

namespace Console {
    class Junior : public Student {
    protected:
        std::string surname; //фамилия
        std::string initial; //инициалы
        int sumOfRating; //количество оценок студента
        std::vector<double> rating;
        char category; //тип студента
    public:
        explicit Junior() : sumOfRating(0), category(Jun) {}

        explicit Junior(const std::string &surname, const std::string &initial);

        explicit Junior(const std::string &surname, const std::string &initial, int sum);

    public:
        //----------------Getters----------------//
        std::string getSurname() const override { return surname; } //получить фамилию

        std::string getInitials() const override { return initial; } //получить инициалы

        int getSumOfRating() const override { return sumOfRating; } //получить количество оценок студента

        char getCategory() const override { return category; }

        std::vector<double> getRating() const override { return rating; } //получить список оченок

        //------------------Setters-------------------//
        Student &setSurname(std::string &surname) override; //внести фамилию

        Student &setInitials(std::string &initials) override; //внести инициалы

        Student &setRating(double rating, int index) override;

        Student &setRating(double rating) override;

        Student &setCategories(char type) override;

        Student &setSumOfRating(int ratting) override;

        ~Junior() override {
            std::cout<<"Destructor Junior" <<std::endl;
        };

        //---------------------------------------------//
        //---------------------------------------------//
    };

}
#endif //CONTROLV2_JUNIOR_H

