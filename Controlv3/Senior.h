/**
 * \file
 * \brief Заголовочный файл c описанием класса Старшекурсник,
 * являющийся одной из разновидностью класса Студент
 *
 * Файл содержит класс Старшекурсник отнаследованный от
 * класса Младшекурсник.
 *
 */

#ifndef CONTROLV3_SENIOR_H
#define CONTROLV3_SENIOR_H

#include <string>
#include "Junior.h"

namespace Console {
    /**
     * \brief дочерний класс
     * \author Ivan Kvasov
     * \version 1.0
     * \date декабрь 2021
     *
     * Дочерний класс, унаследованный от класса Junior.
     * Переопределяющий все виртуальыне методы класса Student
     */

    class Senior : public Junior {
        std::string themeUIR; ///< тема УИР
        std::string placeUIR; ///< место выполнения УИР
        double numberTeacher; ///< оценка Научрука
    public:
        /**
         * Конструктор по умолчанию
         */
        Senior() : Junior(), themeUIR("-"), placeUIR("-"), numberTeacher(0) { category = Sen; };

        /**
         * Инициализирующий конструктор
         * \param surname фамилия студента
         * \param initial инициалы студента
         */
        Senior(const std::string &surname, const std::string &initials) : Junior(surname,
                                                                                 initials) {
            this->numberTeacher = 0;
            this->category = Sen;
        }
        /**
         * Инициализирующий конструктор
         * \param surname фамилия студента
         * \param initial инициалы студента
         * \param sum количество оценок студента
         */
        Senior(const std::string &surname, const std::string &initials, const int sum) : Junior(surname,
                                                                                                initials,
                                                                                                sum),
                                                                                         themeUIR("-"),
                                                                                         placeUIR("-"),
                                                                                         numberTeacher(
                                                                                                 0) { this->category = Sen; }
        /**
         * Инициализирующий конструктор
         * \param surname фамилия студента
         * \param initials инициалы студента
         * \param sumOfRating количество оценок(фактическое)
         * \param themeUIR тема УИР
         * \param placeUIR место УИР
         * \param numberTeacher оценка Научрука
         */
        Senior(const std::string &surname, const std::string &initials, int sumOfRating,
               const std::string &themeUIR,
               const std::string &placeUIR,
               double numberTeacher);

        /**
         * Получить тему УИР
         * \return строку с темой УИР
         */
        std::string getThemeUIR() const; //получить тему УИР

        /**
         * Получить место УИР
         * \return строка с местом УИР
         */
        std::string getPlaceUIR() const; //получить место выполнения УИР

        /**
         * Получить оценку научрука
         * \return оценка начрука
         */
        double getNumber() const; //получить оценку научрука

        //------------------Setters-------------------//

        /**
         * Сохранить тему УИР
         * \param theme тема УИР
         * \return ссылка на измененный элемент
         */
        Student &setThemeUIR(const std::string &theme);

        /**
         * Сохранить место УИР
         * \param place место УИР
         * \return ссылка на измененный элемент
         */
        Student &setPlaceUIR(const std::string &place);

        /**
         * Сохранить оценку научрука
         * \param count оценка Научрука
         * \return ссылка на измененный элемент
         */
        Student &setNumber(double count);
        //---------------------------------------------//
    };
}

#endif //CONTROLV3_SENIOR_H
