cmake_minimum_required(VERSION 3.20)
project(NoteProject)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES Headers/Observer.h Headers/Subject.h Headers/Note.h Source/Collection.cpp Source/Note.cpp Source/CollectionView.cpp Headers/CollectionView.h Headers/Collection.h Headers/CollectionViewInterface.h Source/CollectionViewInterface.cpp Headers/NoteInterface.h Source/NoteInterface.cpp)
add_executable(NoteProject main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(NoteProject core)
