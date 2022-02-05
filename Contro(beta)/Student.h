//
// Created by ctratldelete on 29.11.2021.
//

#ifndef CONTROLV2_STUDENT_H
#define CONTROLV2_STUDENT_H

#include <string>
#include <vector>

namespace Console {

    enum Category {
        Jun = 'J', //младшекурсник
        Sen = 'S', //старшекурсник
        No = '-' //без статуса
    };

    class Student {
    public:
        //------------------Getters-------------------//
        virtual std::string getSurname() const = 0;

        virtual std::string getInitials() const = 0;

        virtual char getCategory() const = 0;

        virtual std::vector<double> getRating() const = 0;

        virtual int getSumOfRating() const = 0;

        //---------------------------------------------//

        //------------------Setters--------------------//
        virtual Student &setSurname(std::string &surname) = 0;

        virtual Student &setInitials(std::string &initials) = 0;

        virtual Student &setRating(double rating, int index) = 0;

        virtual Student &setRating(double rating) = 0;

        virtual Student &setCategories(char type) = 0;

        virtual Student &setSumOfRating(int ratting) = 0;

        //---------------------------------------------//
        virtual ~Student() = default;
    };

}
#endif //CONTROLV2_STUDENT_H