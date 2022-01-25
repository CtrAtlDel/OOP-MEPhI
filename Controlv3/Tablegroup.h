/**
 * \file
 * \brief Заголовочный файл c описанием класса Таблица группы,
 * содержит упорядоченную таблицу студентов определенной категории (Младшекурсник
 * или Старшекурсник). Определяет характеристики группы студентов
 *
 * Файл содержит класс Таблица учащихся.Таблица включает студентов
 * определенных типов, индекс группы, категорию студентов, максимальное количество
 * студентов в группе, максимаьлное количество оценок студентов, а также курс стужентов
 */

#ifndef CONTROLV3_TABLEGROUP_H
#define CONTROLV3_TABLEGROUP_H

#include "TableStudent.h"
#include <string>


//todo set rating by surname and initials


namespace Console {
    /**
     * \brief Таблица группы содержит таблицу учащихся и параметры учащихся
     * \author Ivan Kvasov
     * \version 1.0
     * \date декабрь 2021
     */
    class TableGroup {
    private:
        TableStudent *table; ///< таблица студентов
        int indexGroup; ///< номер группы
        int course; ///< курс по умолчанию равен 1
        int maxRatings; ///< максимальное количество оценок
        char category; ///< категория студентов
        static const int maxPeople = 1; ///< максимальное количество человек в группе
    public:
        /**
         * Инициирующий конструктор
         * @param category категория студентов
         * @param indexGroup индекс группы
         * @param maxRatings максимальное количество оценок
         */
        TableGroup(char category, int indexGroup, int maxRatings);

        TableGroup();


        /**
         * Деструктор по умолчанию
         */
        ~TableGroup() = default;;
    public:

        /**
         * Получить максимальное количество в группе
         * @return
         */
        static int getMaxPeople() { return maxPeople; };

        /**
         * Получить номер группы
         * @return
         */
        [[nodiscard]]
        int getIndexGroup() const { return indexGroup; }

        unsigned long long getSize() {return table->getSize();};
        /**
         * Получить категориб студентов
         * @return
         */
        [[nodiscard]]
        char getCategory() const { return category; }

        /**
         * Получить максимальное количество оценок
         * @return
         */
        [[nodiscard]]
        int getMaxRating() const { return maxRatings; }

        /**
         * Получить курс студентов группы
         * @return
         */
        [[nodiscard]]
        int getCourse() const { return course; }

        ///------------------Setters------------------///
        //Сохранить оценку
        TableGroup &setRating(const std::string &surname, const std::string &initials, double mark);
        //Поменять оценку
        TableGroup &setRating(const std::string &surname, const std::string &initials, double mark, int indexOfRating);

        TableGroup &setRating(Student *st, double mark);

        TableGroup &setRating(Student *st, double mark, int index);

        TableGroup &setUIR(const std::string &surname, const std::string &initials, const std::string &theme);

        TableGroup &setUIR(Student *student, const std::string &theme);

        TableGroup &setPlace(const std::string &surname, const std::string &initials, const std::string &place);

        TableGroup &setNumberTeacher(const std::string &surname, const std::string &initials, double number);

        ///-------------------------------------------///
        [[nodiscard]]
        bool isFull() const {
            if (this->table->getSize() >= maxPeople)
                return true;
            else
                return false;
        };

        //поступление на следующий курс
        TableGroup &lvlUp(int sizeOfRating);

        TableGroup &lvlUpStudent(const std::string &surname, const std::string &initials);

        /**
         * Медиана по группе
         * @return
         */
        double getMedian();

        /**
         * Добавить нового студента
         * @param surname
         * @param initials
         * @return
         */
        TableGroup &newStudent(const std::string &surname, const std::string &initials);

        TableGroup &newStudent(Student *st);

        /**
         * Получить информацию о группе
         * @param s входной поток
         * @return
         */
        std::ostream &printTable(std::ostream &s) const;

        /**
         * Получить информацию о конкретном студенте
         * @param s входной поток
         * @param surname фамилия
         * @param initials инициалы
         * @return
         */
        std::ostream &printStudent(std::ostream &s, const std::string &surname, const std::string &initials);

        bool inGroup(const std::string &surname, const std::string &initials);

        Student* getStudent(int indexOfStudent);

    private:
        /**
         * Поиск студента
         * @param surname фамилия
         * @param initials инициалы
         * @return
         */
        Student *search(const std::string &surname, const std::string &initials);

        Student *search(const std::string &surname);
    };
}

#endif
