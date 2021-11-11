cmake_minimum_required(VERSION 3.20)
project(NoteProject)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES Headers/Note.h Source/Note.cpp Headers/Observer.h Headers/Subject.h Headers/Collection.h Source/Collection.cpp Headers/CollectionNew.h Headers/NoteNew.h Source/CollectionNew.cpp)
add_executable(NoteProject main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(NoteProject core)
