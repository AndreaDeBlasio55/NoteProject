
#include <iostream>
#include "../Headers/CollectionNew.h"
#include <vector>
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
    this->title = title;
}
void NoteNew::editDescription(string description){
    this->description = description;
}
void NoteNew::editCollection(string collection){
    this->collection = collection;
}
void NoteNew::editImportant(bool important) {
    this->important = important;
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

NoteNew::~NoteNew() {

}
