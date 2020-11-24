# cmake_minimum_required(VERSION <specify CMake version here>)
project(RGZOOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(RGZOOP main.cpp Authorization.cpp Authorization.h User.cpp User.h Credentials.h DB.cpp DB.h Record.cpp Record.h)