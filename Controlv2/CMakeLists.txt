cmake_minimum_required(VERSION 3.20)
project(Controlv2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Controlv2 main.cpp Student.h Junior.cpp Junior.h Senior.cpp Senior.h TableStudents.cpp TableStudents.h TableGroup.cpp TableGroup.h Console.cpp Console.h)
