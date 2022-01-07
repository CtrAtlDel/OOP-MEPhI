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

namespace Console {
    /**
     * \brief Таблица группы содержит таблицу учащихся и параметры учащихся
     * \author Ivan Kvasov
     * \version 1.0
     * \date декабрь 2021
     */
    class TableGroup {
    private:
        TableStudent *table;///< таблица студентов
        int indexGroup; ///< номер группы
        int course; ///< курс по умолчанию равен 1
        int maxRatings; ///< максимальное количество оценок
        char category; ///< категория студентов
        static const int maxPeople = 30; ///< максимальное количество человек в группе
    public:
        /**
         * Инициирующий конструктор
         * @param category категория студентов
         * @param indexGroup индекс группы
         * @param maxRatings максимальное количество оценок
         */
        explicit TableGroup(char category, int indexGroup, int maxRatings);

        /**
         * Деструктор по умолчанию
         */
        ~TableGroup() { delete table; };
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

        //поступление на следующий курс
        TableGroup &lvlup();

        TableGroup &lvlup(const std::string &surname, const std::string &initials);

        /**
         * Медиана по группе
         * @return
         */
        double getMediana();

//        //создать студента
        std::istream &createStudentByConsole(std::istream &s); //todo добавить студента в таблицу

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

    private:
        /**
         * Поиск студента
         * @param surname фамилия
         * @param initials инициалы
         * @return
         */
        Student *search(const std::string &surname, const std::string &initials);
    };
}

#endif
