
#include <iostream>
#include "../Headers/Collection.h"
#include <vector>
using namespace std;

// CONSTRUCTOR
Note::Note(string title, string description, string collection, bool important, bool editable){
    this->noteId = rand() % 10000;
    this->title = title;
    this->description = description;
    this->collection = collection;
    this->editable = editable;
    this->important = important;
}
// METHODS
void Note::editTitle(string title) {
    this->title = title;
}
void Note::editDescription(string description){
        this->description = description;
}
void Note::editCollection(string collection){
        this->collection = collection;
}
void Note::editImportant(bool important) {
    this->important = important;
}
// GETTERS
int Note::getId () const{
    return noteId;
}
string Note::getTitle() const{
    return title;
}
string Note::getDescription () const{
    return description;
}
string Note::getCollection () const{
    return collection;
}
bool Note::getEditable () const{
    return editable;
}
bool Note::getImportant() const{
    return important;
}

