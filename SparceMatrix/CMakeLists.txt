cmake_minimum_required(VERSION 3.21)
project(SparceMatrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(SparceMatrix main.cpp SparceMatrix.h SparceMatrix.cpp Bib.h Bib.cpp)
