cmake_minimum_required(VERSION 3.20)
project(NoteProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(NoteProject main.cpp Headers/Note.h Source/Note.cpp)
