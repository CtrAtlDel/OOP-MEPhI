cmake_minimum_required(VERSION 3.20)
project(Control)

set(CMAKE_CXX_STANDARD 20)

add_executable(Control main.cpp Lib/src/Junior.cpp Lib/src/Junior.h Lib/src/Senior.cpp Lib/src/Senior.h Lib/src/TableStudents.cpp Lib/src/TableStudents.h Lib/src/TableGroup.cpp Lib/src/TableGroup.h Lib/src/ConsoleAplication.cpp Lib/src/ConsoleAplication.h)
