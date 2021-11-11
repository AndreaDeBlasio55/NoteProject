
#include <iostream>
#include "../Headers/NoteNew.h"
#include <string>
using namespace std;

// CONSTRUCTOR
NoteNew::NoteNew(string title, string description, string collection, bool editable, bool important){
    this->noteId = rand() % 10000;
    this->title = title;
    this->description = description;
    this->collection = collection;
    this->editable = editable;
    this->important = important;
}
// METHODS
void NoteNew::editTitle(string title){
    if (editable) {
        this->title = title;
    } else {
        cout << "Edit title failed: This note is not editable..." << endl;
    }
}
void NoteNew::editDescription(string description){
    if (editable) {
        this->description = description;
    } else {
        cout << "Edit description failed: This note is not editable..." << endl;
    }
}
void NoteNew::editCollection(string collection){
    if (editable) {
        this->collection = collection;
    } else {
        cout << "Edit collection failed: This note is not editable..." << endl;
    }
    //this->collection = collectionSubj->getCollectionName();
}
void NoteNew::editImportant(bool important) {
    if (editable) {
        this->important = important;
    } else {
        cout << "This note ( " << title << " - " << noteId << " ) is not editable..." << endl;
    }
}
// GETTERS
int NoteNew::getId () const{
    return noteId;
}
string NoteNew::getTitle() const{
    return title;
}
string NoteNew::getDescription () const{
    return description;
}
string NoteNew::getCollection () const{
    return collection;
}
bool NoteNew::getEditable () const{
    return editable;
}
bool NoteNew::getImportant() const{
    return important;
}
