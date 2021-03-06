//
// Created by Andrea on 11/11/21.
//
#include <list>
#include "../Headers/Collection.h"
#include <iostream>
#include <vector>
using namespace std;

Collection::Collection(string nameCollection, bool editable):notes() {
    this->nameCollection = nameCollection;
    this->editable = editable;
    for (int i=0; i<notes.size(); i ++){
        notes[i]->editTitle("");
        notes[i]->editDescription("");
        notes[i]->editCollection(nameCollection);
        notes[i]->editImportant(false);
    }
}

void Collection::subscribe(Observer *o) {
    observerCollectionView.push_back(o);
}
void Collection::unsubscribe(Observer *o) {
    observerCollectionView.remove(o);
}
void Collection::notify() {
    for (auto itr= begin(observerCollectionView); itr != end(observerCollectionView); itr++){
        (*itr)->update();
    }
}

// GETTERS COLLECTION
bool Collection::getEditable () const {
    return editable;
}
string Collection::getCollectionName() const {
    return this->nameCollection;
}

// SETTERS COLLECTION
void Collection::editCollectionName(string collectionName) {
    cout << "Changed collection name from " << this->nameCollection << " to " << collectionName << endl;
    this->nameCollection = collectionName;
    // change the collection name to all the notes
    for (int i = 0; i < notes.size(); i++) {
        notes[i]->editCollection(collectionName);
    }
    //notify();
}
void Collection::editEditable(){
    bool controllerEditable = this->editable;
    this->editable = !controllerEditable;
    cout << "Changed editable! \t" << nameCollection << " - editable: " << this->editable << endl;
}

// ------- NOTES GETTERS -------
int Collection::getCountNotes () const {
    int value = 0;
    //for (auto itr= begin(observerCollectionView); itr!= end(observerCollectionView); itr++){
    //    value += 1;
    //}
    value = (int)notes.size();
    return value;
}
string Collection::getNoteTitle(int index) const{
    return notes[index]->getTitle();
}
string Collection::getNoteDescription(int index) const{
    return notes[index]->getDescription();
}
string Collection::getNoteCollection(int index) const{
    return notes[index]->getCollection();
}
bool Collection::getNoteImportant(int index) const{
    return notes[index]->getImportant();
}
bool Collection::getNoteEditable(int index) const{
    return notes[index]->getEditable();
}
// -------------- READ ------------------
void Collection::readNotes () {
    cout << boolalpha << endl;
    cout << "Reading Notes from Collection: " << nameCollection << endl;
    if (notes.empty()){
        cout << "There aren't Notes to read inside the collection: " << this->getCollectionName() << endl;
    } else {
        for (int i=0; i<notes.size(); i++) {
            cout << i << " - "
                 << "Title: " << notes[i]->getTitle()
                 << "\t\tId: " << notes[i]->getId()
                 << "\t\tDescription: " << notes[i]->getDescription()
                 << "\t\tCollection: " << notes[i]->getCollection()
                 << "\t\tImportant: " << notes[i]->getImportant()
                 << "\t\tEditable: " << notes[i]->getEditable()
                 << endl;
        }
    }
}
// -------------- CREATE ----------------
void Collection::createNote (string title, string description, string collection, bool important, bool editable) {
    if (this->editable) {
        Note *newNote = new Note(title, description, collection, important, editable);
        notes.push_back(newNote);
    } else {
        cerr << "This collection: " << nameCollection << ", is not editable, so you can't create new notes" << endl;
    }
}
// -------------- EDIT ------------------
void Collection::editNoteTitle(int index, string newTitle) {
    if (editable) {
        if (notes[index]->getEditable()) {
            notes[index]->editTitle(newTitle);
            cout << "New title: " << notes[index]->getTitle() << endl;
        } else {
            cerr << "Note not editable" << endl;
        }
    } else {
        cerr << nameCollection << " is not editable" << endl;
    }
}
void Collection::editNoteDescription(int index, string newDescription){
    if (editable){
        if (notes[index]->getEditable()) {
            notes[index]->editDescription(newDescription);
            cout << "New description: " << notes[index]->getDescription() << endl;
        } else {
            cerr << "Note not editable" << endl;
        }
    } else {
        cerr << nameCollection << " is not editable" << endl;
    }
}
void Collection::editNoteImportant(int index, bool newImportant){
    if (editable){
        if (notes[index]->getEditable()) {
            notes[index]->editImportant(newImportant);
            cout << boolalpha;
            cout << "New important: " << notes[index]->getImportant() << endl;
        } else {
            cerr << "Note not editable" << endl;
        }
    } else {
        cerr << nameCollection << " is not editable" << endl;
    }
}
// -------------- DELETE ----------------
void Collection::deleteNote (int index) {
    if (editable) {
        bool canDeleteNote = false;
        canDeleteNote = notes[index]->getEditable();
        if (canDeleteNote) {
            string noteDeleted = notes[index]->getTitle();
            //delete notes[index];
            //notes[index] = nullptr;
            notes.erase(notes.begin() + index);
        } else {
            cerr << "You can't delete this note: " << notes[index]->getTitle() << endl;
        }
    } else {
        cerr << nameCollection << " is not editable" << endl;
    }
}

void Collection::deleteAllNotes() {
    cout << "\tDeleting all notes from: " << nameCollection << endl;
    if (notes.size() > 0) {
        for (int i = 0; i < notes.size(); i++) {
            cout << "\t" << notes[i]->getTitle() << " deleted" << endl;
            delete notes[i];
            notes[i] = nullptr;
        }
    }
}

Collection::~Collection() {
    for (int i=0; i<notes.size(); i++) {
        //cout << "\t" << notes[i]->getTitle() << " deleted" <<endl;
        delete notes[i];
        //notes[i] = nullptr;
    }
}

// ---------------------------------------------