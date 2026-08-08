cmake_minimum_required(VERSION 4.3)
project(Project_01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_01
        book.cpp
        librarian.cpp
        librarian.h
        library.cpp
        library.h
        main.cpp
        member.cpp
        member.h
        person.cpp
        person.h
        saveAndLoad.h
        saveAndLoad.cpp
)
