#include "gtest/gtest.h"
#include <iostream>
#include "../Junior.h"
#include "../Senior.h"
#include "../Student.h"
#include "../TableStudent.h"
#include "../Tablegroup.h"
#include "../vector.h"
#include "../Application.h"

TEST(Junior, Junior_Default_Constructor) {
    Console::Junior jun;
    ASSERT_EQ(0, jun.getSumOfRating());
    ASSERT_EQ(Console::Jun, jun.getCategory());
    Console::Junior jun2("Ivan", "Ivanov");
    ASSERT_EQ("Ivan", jun2.getSurname());
    ASSERT_EQ("Ivanov", jun2.getInitials());
    Console::Junior jun3("Ivanov", "I.I.", 5);
    ASSERT_EQ("Ivanov", jun3.getSurname());
    ASSERT_EQ("I.I.", jun3.getInitials());
    ASSERT_EQ(5, jun3.getSumOfRating());
}

TEST(Junior, Junior_getters_Test) {
    Console::Junior jun("ivan", "ivanov");
    ASSERT_EQ("ivan", jun.getSurname());
    ASSERT_EQ("ivanov", jun.getInitials());
    ASSERT_EQ(0, jun.getSumOfRating());
    ASSERT_EQ(Console::Jun, jun.getCategory());
}

TEST(Junior, Junior_setters_Test) {
    Console::Junior jun;
    jun.setRating(0);
    jun.setRating(1);
    jun.setRating(2);
    templates::vector<double> tmp;
    tmp = jun.getRating();
    for (int i = 0; i < tmp.size(); ++i) {
        ASSERT_EQ(i, tmp[i]);
    }
    jun.setRating(1, 0);
    tmp = jun.getRating();
    ASSERT_EQ(1, tmp[0]);
    jun.setCategories(Console::Jun);
    jun.setInitials("ii");
    jun.setSurname("ivanov");
    ASSERT_EQ(Console::Jun, jun.getCategory());
    ASSERT_EQ("ivanov", jun.getSurname());
    ASSERT_EQ("ii", jun.getInitials());
}

TEST(Senior, SeniorConstructors) {
    Console::Senior sen("Ivanov", "II");
    Console::Senior sen2("Ivanov", "EE", 3);
    Console::Senior sen3("Ivanov", "EE", 4, "Atom", "Atom", 0.5);
    ASSERT_EQ("Ivanov", sen.getSurname());
    ASSERT_EQ("II", sen.getInitials());
    ASSERT_EQ(Console::Sen, sen.getCategory());
    ASSERT_EQ(3, sen2.getSumOfRating());
    ASSERT_EQ("Atom", sen3.getThemeUIR());
    ASSERT_EQ("Atom", sen3.getPlaceUIR());
    ASSERT_EQ(0.5, sen3.getNumber());
}

TEST(Senior, SeniorMethods) {
    Console::Senior sen("Ivanov", "II");
    sen.setNumber(4);
    ASSERT_EQ(4, sen.getNumber());
    sen.setPlaceUIR("ATOM");
    ASSERT_EQ("ATOM", sen.getPlaceUIR());
    sen.setThemeUIR("BAD_THINGS");
    ASSERT_EQ("BAD_THINGS", sen.getThemeUIR());
    sen.setNumber(11);
    ASSERT_EQ(11, sen.getNumber());
}

TEST(TableStudent, TableStudentConstructor) {
    Console::TableStudent table(Console::Jun, 5);
    Console::TableStudent tableSen(Console::Sen, 6);
    ASSERT_EQ(Console::Jun, table.getCategory());
    ASSERT_EQ(Console::Sen, tableSen.getCategory());
    ASSERT_EQ(5, table.getMaxRating());
    ASSERT_EQ(6, tableSen.getMaxRating());
}

TEST(TableStudent, TableStudentMethods) {
    Console::TableStudent tableJuniors(Console::Jun, 10);
    Console::TableStudent tableSeniors(Console::Sen, 20);

    Console::Junior *jun1 = new Console::Junior("Small1", "AA");
    Console::Junior *jun2 = new Console::Junior("Small2", "BB");
    Console::Junior *jun3 = new Console::Junior("Small3", "CC");

    Console::Student *st1 = jun1;
    Console::Student *st2 = jun2;
    Console::Student *st3 = jun3;

    tableJuniors.setNewStudent(st1);
    tableJuniors.setNewStudent(st2);
    tableJuniors.setNewStudent(st3);

    Console::Senior *sen1 = new Console::Senior("Big1", "AA");
    Console::Senior *sen2 = new Console::Senior("Big2", "BB");
    Console::Senior *sen3 = new Console::Senior("Big3", "CC");

    Console::Student *stS1 = sen1;
    Console::Student *stS2 = sen2;
    Console::Student *stS3 = sen3;

    tableSeniors.setNewStudent(stS1);
    tableSeniors.setNewStudent(stS2);
    tableSeniors.setNewStudent(stS3);

    ASSERT_EQ("Small1", tableJuniors.table[0]->getSurname());
    ASSERT_EQ("Small2", tableJuniors.table[1]->getSurname());
    ASSERT_EQ("Small3", tableJuniors.table[2]->getSurname());

    ASSERT_EQ("Big1", tableSeniors.table[0]->getSurname());
    ASSERT_EQ("Big2", tableSeniors.table[1]->getSurname());
    ASSERT_EQ("Big3", tableSeniors.table[2]->getSurname());

    for (int i = 0; i < tableJuniors.getSize(); ++i) {
        ASSERT_EQ(Console::Jun, tableJuniors.getCategory());
    }

    for (int i = 0; i < tableSeniors.getSize(); ++i) {
        ASSERT_EQ(Console::Sen, tableSeniors.getCategory());
    }

    tableJuniors.setRating(0, 1);
    tableJuniors.setRating(0, 1);
    tableJuniors.setRating(0, 2, 1);
    tableJuniors.setRating(0, 2);
    tableJuniors.setRating(0, 3);

    templates::vector<double> tmp = tableJuniors.table[0]->getRating();

    ASSERT_EQ(1, tmp[0]);
    ASSERT_EQ(2, tmp[1]);
    ASSERT_EQ(2, tableJuniors.getMedian(0));
    tableSeniors.setUIR(0, "ATOM");
    tableSeniors.setPlace(0, "ROSATOM");
    Console::Student *st = nullptr;

}

TEST(TableGroup, Mediana) {
    Console::TableGroup table1(Console::Jun, 1, 30);
    Console::TableGroup table2(Console::Sen, 2, 30);
    Console::TableGroup table3(Console::Jun, 2, 30);

    auto *jun1 = new Console::Junior("Small1", "AA");
    auto *jun2 = new Console::Junior("Small2", "BB");
    auto *jun3 = new Console::Junior("Small3", "CC");

    auto *sen1 = new Console::Senior("Big1", "AA");
    auto *sen2 = new Console::Senior("Big2", "BB");
    auto *sen3 = new Console::Senior("Big3", "CC");

    Console::Student *st1 = jun1;
    Console::Student *st2 = jun2;
    Console::Student *st3 = jun3;

    Console::Student *stS1 = sen1;
    Console::Student *stS2 = sen2;
    Console::Student *stS3 = sen3;

    table2.newStudent(stS1);
    table2.newStudent(stS2);
    table2.newStudent(stS3);
    table2.setUIR("Big1", "AA", "rosatom");
    table2.setUIR("Big2", "BB", "gigabyte");

//    table2.printTable(std::cout);

    table1.newStudent(st1);
    table1.newStudent(st2);

    table1.setRating(st1, 1);
    table1.setRating(st1, 1);
    table1.setRating(st1, 2);
    table1.setRating(st1, 3);

//    table1.printTable(std::cout);
    table1.setRating(st1, 5, 1);
//    table1.printTable(std::cout);

}

TEST(Tablegroup, TablegroupMethods) {
    auto *table = new Console::TableGroup(Console::Jun, 101, 30);
    ASSERT_EQ(Console::Jun, table->getCategory());
    ASSERT_EQ(101, table->getIndexGroup());
    ASSERT_EQ(30, table->getMaxRating());
}
//test vector

TEST(Iterator, Iterator_Constructor) {
    int size = 4;
    int defaultEq = 3;
    templates::vector<int> vector(size, defaultEq);
    templates::iterator<int> iterator;
    iterator = vector.begin();
    templates::iterator<int> iterator1(iterator);
    ASSERT_EQ(iterator, vector.begin());
    ASSERT_EQ(iterator1, vector.begin());
    bool flag = false;
    if (iterator == iterator1)
        flag = true;
    ASSERT_EQ(true, flag);
    if (iterator != iterator1)
        flag = false;
    ASSERT_EQ(true, flag);
}

TEST(Iterator, Iterator_Methods) {
    int size = 10;
    int *tmp = new int[size];
    for (int i = 0; i < size; ++i)
        tmp[i] = i;
    templates::iterator<int> iterator(tmp);
    for (int i = 0; i < size; ++i) {
        ASSERT_EQ(i, *iterator.operator->());
        ++iterator;
    }
    templates::iterator<int> iterator1(tmp);
    iterator = tmp;
    int adress = iterator.operator*();
    ASSERT_EQ(adress, iterator1.operator*());
    bool fg = false;
    if (iterator1 == tmp) { fg = true; }
    ASSERT_EQ(true, fg);
    bool fg2 = false;
    ++iterator1;
    if (tmp == iterator1) { fg = true; }
    ASSERT_EQ(false, fg2);
}

TEST(Vector, Vector_Constructors) {
    templates::vector<int> tmpVector;
    ASSERT_EQ(0, tmpVector.size());
    int size = 5;
    templates::vector<int> tmpVector2(size);
    ASSERT_EQ(size, tmpVector2.size());
    templates::vector<int> tmpVector3(size, 0);
    for (int i = 0; i < tmpVector3.size(); ++i) {
        ASSERT_EQ(0, tmpVector3[i]);
    }
}

TEST(Vector, Vector_throw) {
    templates::vector<int> vector;
    ASSERT_ANY_THROW(vector.get(-1));
    ASSERT_ANY_THROW(vector.get(5));
    ASSERT_ANY_THROW(vector.erase(3));
    ASSERT_ANY_THROW(vector.erase(-1));
    vector.push_back(1);
    vector.erase(0);
    ASSERT_ANY_THROW(vector.get(0));
    int size = 10;
    int error = 20;
    templates::vector<int> vector1(10, 1);
    vector1.set(3, 123);
    ASSERT_ANY_THROW(vector1.set(error, 123));
    ASSERT_EQ(123, vector1.get(3));
    vector1.push_back(123);
    ASSERT_ANY_THROW(templates::vector<int> vector3(-1, 5));
}

TEST(Vector, Vector_Methods) {
    templates::vector<int> vector1;
    templates::vector<int> vector2;
    templates::vector<int> vector3;
    templates::iterator<int>();
    ASSERT_EQ(0, vector1.size()); // size
    ASSERT_EQ(true, vector1.empty()); // is Empty
    int size = 10;
    for (int i = 0; i < size; ++i) {
        vector1.push_back(i);
    }
    vector1.begin();
    int size2 = 20;
    for (int i = 0; i < size2; ++i) {
        vector2.push_back(i);
    }
    for (int i = 0; i < size2; ++i) {
        ASSERT_EQ(i, vector2.get(i));
    }
    int s = 20;
    templates::vector<int> vector;
    for (int i = 0; i < size; ++i) {
        vector.push_back(1);
    }
    templates::iterator<int> iter = vector.begin();
    for (int i = 0; i < vector.size(); ++i) {
        ASSERT_EQ(1, vector.get(i));
    }
    for (int &i: vector) {
        ASSERT_EQ(1, i);
    }
    for (int i = 0; i < size; ++i) {
        vector[i] = 2;
    }
    for (int i = 0; i < size; ++i) {
        ASSERT_EQ(2, vector[i]);
    }
    for (int i = 0; i < vector.size(); ++i) {
        vector[i] = i;
    }
    int i = 0;
    for (iter = vector.begin(), i = 0; iter == vector.end(); ++iter, ++i) {
        ASSERT_EQ(i, *iter);
        bool flag = false;
    }
    int index = 0;
    for (auto &it: vector) {
        ASSERT_EQ(index, it);
        index++;
    }
}

TEST(Vector, New_test) {
    templates::vector<int> vector;
    int size = 10;
    for (int i = 0; i < size; ++i) {
        vector.push_back(i);
    }
    int count = 0;
    for (auto &it: vector) {
        count++;
    }
    ASSERT_EQ(10, count);
    templates::vector<double> vector11;
    int size11 = 10;
    for (int i = 0; i < size11; ++i)
        vector11.push_back(i);
    vector11.clear();
    ASSERT_EQ(0, vector11.size());
    ASSERT_EQ(true, vector11.empty());
    for (int i = 0; i < size11; ++i) {
        vector11.push_back(i);
    }
    ASSERT_EQ(10, vector11.size());
}

TEST(Application, NewStudent) {
    auto *app = new Console::Application();

    std::string firS1 = "Jun1";
    std::string initS1 = "Jun1Initials";

    std::string firS2 = "Jun2";
    std::string initS2 = "Jun2Initials";

    std::string firS3 = "Jun3";
    std::string initS3 = "Jun3Initials";
    /// add only Junior
    app->addStudentInGroup(firS1, initS1);
    app->addStudentInGroup(firS2, initS2);
    app->addStudentInGroup(firS3, initS3);
    app->printAllTable(std::cout);

    app->addStudentInGroup("Sen1", "Sen1Initials");
    app->addStudentInGroup("Sen2", "Sen2Initials");
    app->addStudentInGroup("Sen3", "Sen3Initials");

    app->printAllTable(std::cout);

}

TEST(Application, Mediana) {
    auto *app = new Console::Application();

    std::string firS1 = "Jun1";
    std::string initS1 = "Jun1Initials";
    std::string firS2 = "Jun2";
    std::string initS2 = "Jun2Initials";
    std::string firS3 = "Jun3";
    std::string initS3 = "Jun3Initials";

    /// add only Junior
    app->addStudentInGroup(firS1, initS1);
    app->addStudentInGroup(firS2, initS2);
    app->addStudentInGroup(firS3, initS3);
    app->printAllTable(std::cout);
    app->addStudentInGroup("Sen1", "Sen1Initials");
    app->addStudentInGroup("Sen2", "Sen2Initials");
    app->addStudentInGroup("Sen3", "Sen3Initials");
    for (int i = 0; i < app->getSizeOfGroupsWithStudent(); ++i) {

    }
}

TEST(Application, ExceptionTest) {
    auto *app = new Console::Application();

    std::string firS1 = "Jun1";
    std::string initS1 = "Jun1Initials";

    std::string firS2 = "Jun2";
    std::string initS2 = "Jun2Initials";

    std::string firS3 = "Jun3";
    std::string initS3 = "Jun3Initials";
    /// add only Junior
    app->addStudentInGroup(firS1, initS1);
    app->addStudentInGroup(firS2, initS2);
    app->addStudentInGroup(firS3, initS3);
    app->printAllTable(std::cout);
    app->addStudentInGroup("Sen1", "Sen1Initials");
    app->addStudentInGroup("Sen2", "Sen2Initials");
    app->addStudentInGroup("Sen3", "Sen3Initials");
    ASSERT_ANY_THROW(app->lvlUp(1, 3));
}

int _tmain(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}