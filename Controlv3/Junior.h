/**
 * \file
 * \brief Заголовочный файл c описанием класса Младшекурсник,
 * являющийся одной из разновидностью класса Студент
 *
 * Файл содержит класс Младшекурсник отнаследованный от
 * класса Студент
 *
 */

#ifndef CONTROLV3_JUNIOR_H
#define CONTROLV3_JUNIOR_H

#include <iostream>
#include "Student.h"
#include "vector.h"

namespace Console {
    /**
     * \brief дочерний класс
     * \author Ivan Kvasov
     * \version 1.0
     * \date декабрь 2021
     *
     * Дочерний класс, унаследованный от класса Student.
     * Переопределяющий все виртуальыне методы класса Student
     */

    class Junior : public Student {
    protected:
        std::string surname; ///< фамилия студента
        std::string initial; ///< инициалы студента
        int sizeOfRating; ///< количество оценок (фактическое) студента
        char category; ///< тип студента
        templates::vector<double> rating; ///< список оценок студента
    public:
        /**
         * Конструктор по умолчанию
         */
        explicit Junior() : sizeOfRating(0), category(Jun) {}

        /**
         * Инициализирующий конструктор
         * \param surname фамилия студента
         * \param initial инициалы студента
         */
        explicit Junior(const std::string &surname, const std::string &initial);

        /**
         * Инициализирующий конструктор
         * \param surname фамилия студента
         * \param initial инициалы студента
         * \param sum количество оценок студента
         * \throw exception sum of rating < 0
         */
        explicit Junior(const std::string &surname, const std::string &initial, int sum);

    public:
        //----------------Getters----------------//
        /**
         * Получить фамилию студента
         * \param нет параметров
         * \return фамилия студента
         */
        std::string getSurname() const override { return surname; } //получить фамилию

        /**
         * Получить иницалы стужента
         * \param не имеет параметров
         * \return строку с инициалами
         * \throw
         */
        std::string getInitials() const override { return initial; } //получить инициалы

        /**
         * Получить количество оценок студента
         * \param не имеет параметров
         * \return максимальное количество оценок
         * \throw
         */
        int getSumOfRating() const override { return sizeOfRating; } //получить количество оценок студента

        /**
         * Получить тип студента
         * \param не имеет параметров
         * \return категорию студента
         * \throw
         */
        char getCategory() const override { return category; }

        Student& deleteRating() override;

        /**
         * Получить список оценок стужента
         * \param не имеет параметров
         * \return массив оценок
         * \throw
         */
        templates::vector<double> getRating() const override { return rating; } //получить список оченок

        //------------------Setters-------------------//

        /**
         * Сохранить фамилию студента
         * \param surname фамилия студента
         * \return ссылку на измененный объект класса
         * \throw
         */
        Student &setSurname(const std::string &surname) override; //внести фамилию

        /**
         * Сохранить инициалы стужента
         * \param initials инициалы студента
         * \return ссылку на измененный объект класса
         * \throw
         */
        Student &setInitials(const std::string &initials) override; //внести инициалы

        /**
         * Сохранить оценку студента по номеру студента
         * \param rating оценка
         * \param index  номер оценки
         * \return ссылку на измененный объект класса
         * \throw exception Index out of range
         */
        Student &setRating(double rating, int index) override;

        /**
         * Сохранить оценку студента(добавить в конец)
         * \param rating оценка
         * \return ссылку на измененный объект класса
         * \throw exception Bad ratting ( <0 )
         */
        Student &setRating(double rating) override;

        /**
         * Сохранить категорию студента
         * \param type тип студента
         * \return ссылку на измененный объект класса
         * \throw
         */
        Student &setCategories(char type) override;

        /**
         * Сохранить текущее количество оценок
         * \param ratting максимальное количество оценок
         * \return ссылку на измененный объект класса
         * \throw
         */
        Student &setSumOfRating(int ratting) override;
        //---------------------------------------------//
    };

}
#endif //CONTROLV3_JUNIOR_H
