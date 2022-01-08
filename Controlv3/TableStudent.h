/**
 * \file
 * \brief Заголовочный файл c описанием класса Таблица учащихся,
 * содержит упорядоченную таблицу студентов определенной категории (Младшекурсник
 * или Старшекурсник)
 *
 * Файл содержит класс Таблица учащихся.Таблица включает студентов
 * определенных типов.
 */

#ifndef CONTROLV3_TABLESTUDENT_H
#define CONTROLV3_TABLESTUDENT_H

#include <vector>
#include "getSome.h"
#include "Student.h"
#include "vector.h"

namespace Console {
    /**
     * \brief Таблица учащихся содержит студентов.
     * представленных классами Junior или Senior
     * \author Ivan Kvasov
     * \version 1.0
     * \date декабрь 2021
     *
     * Упорядоченная таблица студентов, определенной категории.
     *
     */
    class TableStudent {
    public:
        templates::vector<Student*> table;
        char category; ///< категория студентов
        int sizeRatings;///< максимальное количество оценок

    public:
        /**
         * Конструктор с категорией и максимальным количеством оценок студента
         * \param category категория студентов
         * \param sizeRatings количество оценок
         */
        explicit TableStudent(char category, int sizeRatings);

        TableStudent& lvlUp(int sizeRating);

        TableStudent& lvlUpJS();
        /**
         * Получить максимальное количество оценок
         * \return максимальное количество оценок студентов
         */
        [[nodiscard]]
        unsigned long long getSize() const { return table.size(); }; //получить количество студентов в группе

        /**
         * Получить количество оценом студента (максимальное)
         * \return количество оценок
         */
        [[nodiscard]]
        int getMaxRating() const { return this->sizeRatings; }

        /**
         * Категорию студентов в таблице
         * \return категорию
         */
        [[nodiscard]]
        char getCategory() const { return this->category; }

        /**
         * Получить номер студента в таблице по имени и фамиилии
         * \param surname фамилия студента
         * \param initials инициалы студента
         * \return номер студента
         */
        [[nodiscard]]
        int indexOfStudent(const std::string &surname,
                           const std::string &initials) const; //получить номер студента в таблице по имени и фамиилии

        /**
         * Сохранить тему УИР
         * @param indexStudent номер студента
         * @param newUIR новая тема УИР
         * @return ссылка на измененный класс
         */
        TableStudent &setUIR(int indexStudent, const std::string &newUIR);

        /**
         * Сохранить новое место УИР
         * @param indexStudent номер студента
         * @param place новое место УИР
         * @return ссылка на измененный класс
         */
        TableStudent &setPlace(int indexStudent, const std::string &place);

        /**
         * Сохранить оценку научрука
         * @param indexStudent номер студента
         * @param number оценка научрука
         * @return ссылка на измененный класс
         */
        TableStudent &setNumberTeacher(int indexStudent, double number);

        /**
         * Сохранить нового студента
         * @param student указать на класс нового студента
         * @return ссылка на измененный класс
         */
        TableStudent &setNewStudent(Student *student);

        /**
         * Сохранить оценку
         * @param indexStudent номер студента
         * @param rating оценка
         * @return ссылка на измененный класс
         */
        TableStudent &setRating(int indexStudent, double rating);

        /**
         * Слхранить оценку
         * @param indexStudent номер студента
         * @param rating оценка
         * @param indexOfRating номер оценки
         * @return ссылка на измененный класс
         */
        TableStudent &setRating(int indexStudent, double rating, int indexOfRating);

        /**
         * Удолить студента из таблицы
         * @param indexStudent номер студента
         * @return ссылка на измененный класс
         */
        TableStudent &deleteStudent(int indexStudent);

        /**
         * Перевести студента на следующий курс
         * @param indexStudent номер студента
         * @return ссылка на измененный класс
         */
        TableStudent &lvlup(int indexStudent);

        /**
         * Получить средний балл студента
         * @param indexStudent номер студента
         * @return ссылка на измененный класс
         */
        double getMedian(int indexStudent);

        TableStudent& addStudent(Student* st);


    private:
        /**
         * Поиск студента
         * @param surname фамилия студента
         * @param initials инициалы студента
         * @return указаетль на изменный класс студента
         */
        [[nodiscard]]
        Student *search(const std::string &surname, const std::string &initials) const;

    public:

        /**
         * Получить студента
         * @param s входной поток
         * @param indexStudent номер студента
         * @return сслыка на измененный поток
         */
        std::ostream &getStudent(std::ostream &s, int indexStudent) const;

        /**
         * Деструктор по умолчанию
         */
        ~TableStudent() = default;

        void setMark(Student *pStudent, double d);

        void setMark(Student *pStudent, double d, int indexRating);
    };
}

#endif
