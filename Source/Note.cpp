//
// Created by Andrea on 19/10/21.
//
#include <iostream>
#include "../Headers/Note.h"
#include <string>
using namespace std;

// CONSTRUCTOR
Note::Note(Collection* collectionSubj, string collection, string title, string description):collectionSubj(collectionSubj){
    this->collection = collection;
    this->noteId = rand() % 10000;
    this->title = title;
    this->description = description;
    this-> editable = true;
    attach();
}
Note::Note(Collection* collectionSubj, string collection, string title, string description, bool editable){
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
        cout << "Edit title failed: This note is not editable..." << endl;
    }
}
void Note::editDescription(string description){
    if (editable) {
        this->description = description;
    } else {
        cout << "Edit description failed: This note is not editable..." << endl;
    }
}
void Note::deleteNote(int noteId){

}
void Note::editCollection(string collection){
    if (editable) {
        this->collection = collection;
    } else {
        cout << "Edit collection failed: This note is not editable..." << endl;
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
void Note::editImportant(bool important) {
    if (editable) {
        this->important = important;
    } else {
        cout << "Edit important failed: This note is not editable..." << endl;
    }
}
bool Note::getEditable () const{
    return editable;
}
bool Note::getImportant() const{
    return important;
}

void Note::attach() {
    collectionSubj->subscribe(this);
}

void Note::update() {
    this->collection = collectionSubj->getCollectionName();
    cout << "Updating collection name... " << this->collection << endl;
}