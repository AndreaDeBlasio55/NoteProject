//
// Created by Andrea on 19/10/21.
//
#include "../Headers/Note.h"
#include <string>
using namespace std;

// CONSTRUCTOR
Note::Note(string collection, string title, string description){
    this->collection = collection;
    this->noteId = rand() % 10000;
    this->title = title;
    this->description = description;
    this-> editable = true;
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
    if (editable) {
        this->title = title;
    } else {
        cout << "This note is not editable." << endl;
    }
}
void Note::editDescription(string description){
    if (editable) {
        this->description = description;
    } else {
        cout << "This note is not editable." << endl;
    }
}
void Note::deleteNote(int noteId){

}
void Note::changeCollection(string collection){
    if (editable) {
        this->collection = collection;
    } else {
        cout << "This note is not editable." << endl;
    }
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
void Note::changeImportant(bool important) {
    this->important = important;
}
bool Note::getEditable () const{
    return editable;
}
bool Note::getImportant() const{
    return important;
}
