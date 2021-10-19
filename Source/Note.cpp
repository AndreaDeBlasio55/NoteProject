//
// Created by Andrea on 19/10/21.
//
#include "../Headers/Note.h";
#include <string>
using namespace std;

// CONSTRUCTOR
Note::Note(string collection, string title, string description){
    this->collection = collection;
    this->noteId = rand() % 10000;
    this->title = title;
    this->description = description;
}
Note::Note(string collection, string title, string description, bool editable){
    this->collection = collection;
    this->noteId = rand() % 10000;
    this->title = title;
    this->description = description;
    this->editable = editable;
}
// METHODS
void Note::editTitle(string title){
    this->title = title;
}
void Note::editDescription(string description){
    this->description = description;
}
void Note::deleteNote(string noteId){
    this->noteId = noteId;
}
void Note::changeCollection(string collection){
    this->collection = collection;
}
// GETTERS
int Note::getId () const{
    return noteId;
}
string Note::getCollection (){
    return collection;
}
string Note::getTitle(){
    return title;
}
string Note::getDescription (){
    return description;
}
bool Note::getEditable () const{
    return editable;
}
