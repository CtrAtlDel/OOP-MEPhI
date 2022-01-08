/**
 * \file
 * \brief Заголовочный файл с описанием абстарктоного класса студента,
 * обладающего всеми виртуальными методами класса Младшекурсник
 *
 * Файл содержит полностью абстрактный класс Студент, от которого
 * отнаследован класс Младшекурсник
 *
 */

#ifndef CONTROLV3_STUDENT_H
#define CONTROLV3_STUDENT_H

#include <string>
#include <vector>
#include "vector.h"


namespace Console {
    /**
     * \brief родительский класс
     * \author Ivan Kvasov
     * \version 1.0
     * \date декабрь 2021
     *
     * Родительский абстрактный класс, выполняющий функцию интерфейса и
     * имеющий виртуальные методы класса младшекурсник
     */

    enum Category {
        Jun = 'J', ///< индикатор класса младшекурсник
        Sen = 'S', ///< индикатор класса старшекурсник
        No = '-' ///< индикатор отсутствия принадлежности к какому либо классу
    };

    class Student {
    public:
        //------------------Getters-------------------//
        /**
         * Получить фамилию студента
         * \param не имеет параметров
         * \return строку с фамилией
         * \throw
         */
        virtual std::string getSurname() const = 0;

        /**
         * Получить иницалы стужента
         * \param не имеет параметров
         * \return строку с инициалами
         * \throw
         */
        virtual std::string getInitials() const = 0;

        /**
         * Получить тип студента
         * \param не имеет параметров
         * \return категорию студента
         * \throw
         */
        virtual char getCategory() const = 0;

        /**
         * Получить список оценок стужента
         * \param не имеет параметров
         * \return массив оценок
         * \throw
         */
        virtual templates::vector<double> getRating() const = 0;

        /**
         * Получить количество оценок студента
         * \param не имеет параметров
         * \return максимальное количество оценок
         * \throw
         */
        virtual int getSumOfRating() const = 0;

        //---------------------------------------------//

        //------------------Setters--------------------//
        /**
         * Сохранить фамилию студента
         * \param surname фамилия студента
         * \return ссылку на измененный объект класса
         * \throw
         */
        virtual Student &setSurname(const std::string &surname) = 0;

        /**
         * Сохранить инициалы стужента
         * \param initials инициалы студента
         * \return ссылку на измененный объект класса
         * \throw
         */
        virtual Student &setInitials(const std::string &initials) = 0;

        /**
         * Сохранить оценку студента по номеру студента
         * \param rating оценка
         * \param index  номер оценки
         * \return ссылку на измененный объект класса
         * \throw
         */
        virtual Student &setRating(double rating, int index) = 0;

        /**
         * Сохранить оценку студента(добавить в конец)
         * \param rating оценка
         * \return ссылку на измененный объект класса
         * \throw
         */
        virtual Student &setRating(double rating) = 0;

        /**
         * Сохранить категорию студента
         * \param type тип студента
         * \return ссылку на измененный объект класса
         * \throw
         */
        virtual Student &setCategories(char type) = 0;

        /**
         * Сохранить текущее количество оценок
         * \param ratting максимальное количество оценок
         * \return ссылку на измененный объект класса
         * \throw
         */
        virtual Student &setSumOfRating(int ratting) = 0;

        //---------------------------------------------//
        /**
         * Очищает буфер оценок
         * @return
         */
        virtual Student& deleteRating() = 0;

        virtual Student& setMaxMark(int maxMark) = 0;

        virtual ~Student() = default;
    };

}


#endif //CONTROLV3_STUDENT_H
