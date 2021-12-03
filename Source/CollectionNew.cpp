//
// Created by Andrea on 11/11/21.
//
#include <list>
#include "../Headers/CollectionNew.h"
#include <iostream>
#include <vector>
using namespace std;

CollectionNew::CollectionNew(string nameCollection, bool editable):notes() {
    this->nameCollection = nameCollection;
    this->editable = editable;
    for (int i=0; i<notes.size(); i ++){
        notes[i]->editTitle("");
        notes[i]->editDescription("");
        notes[i]->editCollection(nameCollection);
        notes[i]->editImportant(false);
    }
}
void CollectionNew::subscribe(Observer *o) {
    observerCollectionView.push_back(o);
}
void CollectionNew::unsubscribe(Observer *o) {
    observerCollectionView.remove(o);
}
void CollectionNew::notify() {
    for (auto itr= begin(observerCollectionView); itr != end(observerCollectionView); itr++){
        (*itr)->update();
    }
}
// GETTERS
bool CollectionNew::getEditable () const {
    return editable;
}
string CollectionNew::getCollectionName() const {
    return this->nameCollection;
}

// SETTERS
void CollectionNew::editCollectionName(string collectionName) {
    cout << "Changed collection name from " << this->nameCollection << " to " << collectionName << endl;
    this->nameCollection = collectionName;
    // change the collection name to all the notes
    for (int i = 0; i < notes.size(); i++) {
        notes[i]->editCollection(collectionName);
    }
    notify();
}
void CollectionNew::editEditable(){
    bool controllerEditable = this->editable;
    this->editable = !controllerEditable;
    cout << "Changed editable! \t" << nameCollection << " - editable: " << this->editable << endl;
}
void CollectionNew::changeCollection(vector<CollectionNew*> destinationCollection) {
    NoteNew *currentNoteSelected;
    bool validatorWhile = false;
    if (this->editable) {
        if (!notes.empty()) {
            while (!validatorWhile) {
                string indexNoteStr = "";
                int indexNote = -1;
                cout << "Please select the note you want to move" << endl;
                for (int i = 0; i < notes.size(); i++) {
                    cout << i << " - " << notes[i]->getTitle() << endl;
                }
                cin >> indexNoteStr;
                if (isNumber(indexNoteStr)) {
                    indexNote = stoi(indexNoteStr);
                    if (indexNote >= 0 && indexNote < notes.size()) {
                        cout << notes[indexNote]->getTitle() << " Selected!" << endl;
                        if (notes[indexNote]->getEditable()) {
                            currentNoteSelected = notes[indexNote];
                            validatorWhile = true;

                            string destinationCollectionStr = "";
                            cout << "Type the index of the destination or another value to exit:" << endl;
                            int currentIndexCollection = -1;
                            for (int i = 0; i < destinationCollection.size(); i++) {
                                if (destinationCollection[i]->getCollectionName() == nameCollection) {
                                    currentIndexCollection = i;
                                    cout << i << " - " << destinationCollection[i]->getCollectionName()
                                         << " - The note is here " << endl;
                                } else {
                                    cout << i << " - " << destinationCollection[i]->getCollectionName() << endl;
                                }
                            }
                            cin >> destinationCollectionStr;
                            if (isNumber(destinationCollectionStr)) {
                                int destinationInt = stoi(destinationCollectionStr);
                                if (destinationCollection[destinationInt]->getEditable()) {
                                    destinationCollection[destinationInt]->notes.push_back(currentNoteSelected);
                                    cout << "Moved to " << destinationCollection[destinationInt]->getCollectionName()
                                         << " from: " << nameCollection << endl;
                                    notes.erase(notes.begin() + indexNote);
                                    validatorWhile = true;
                                    notify();
                                } else {
                                    cout << "Target collection is not editable, you can't add/edit/delete notes" << endl;
                                }
                            } else {
                                cout << "Exit" << endl;
                                validatorWhile = true;
                            }
                        } else {
                            cout << "This note is not editable - It can be edit/deleted only deleting the collection: " << nameCollection << endl;
                            validatorWhile = false;
                        }
                    } else {
                        cout << "Wrong input" << endl;
                        validatorWhile = false;
                    }
                } else {
                    cout << "Wrong input" << endl;
                    validatorWhile = false;
                }
            }
        } else {
            cout << "There aren't notes here" << endl;
        }
    } else {
        cout << "Collection note editable" << endl;
    }
}

// ------- NOTES GETTERS -------
int CollectionNew::getCountNotes () const {
    int value = 0;
    //for (auto itr= begin(observerCollectionView); itr!= end(observerCollectionView); itr++){
    //    value += 1;
    //}
    value = (int)notes.size();
    return value;
}
int CollectionNew::getNoteId(int index) const{
    return notes[index]->getId();
}
string CollectionNew::getNoteTitle(int index) const{
    return notes[index]->getTitle();
}
string CollectionNew::getNoteDescription(int index) const{
    return notes[index]->getDescription();
}
string CollectionNew::getNoteCollection(int index) const{
    return notes[index]->getCollection();
}
bool CollectionNew::getNoteImportant(int index) const{
    return notes[index]->getImportant();
}
bool CollectionNew::getNoteEditable(int index) const{
    return notes[index]->getEditable();
}
// -------------- READ --------------
void CollectionNew::readNotes () {
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
// -------------- CREATE --------------
void CollectionNew::createNote (string title, string description, string collection, bool editable, bool important) {
    NoteNew* newNote = new NoteNew(title, description, collection, editable, important);
    notes.push_back(newNote);
}
// -------------- EDIT  --------------
// -------------- EDIT NOTE SETTERS ------------------
void CollectionNew::editNoteTitle(int index, string newTitle) {
    notes[index]->editTitle(newTitle);
}
void CollectionNew::editNoteDescription(int index, string newDescription){
    notes[index]->editDescription(newDescription);
}
void CollectionNew::editNoteCollection(int index, string newCollection){
    notes[index]->editCollection(newCollection);
}
void CollectionNew::editNoteImportant(int index, bool newImportant){
    notes[index]->editImportant(newImportant);
}
// ------------------------------------------------
// -------------- DELETE ------------
void CollectionNew::deleteNote (int index) {
    bool canDeleteNote = false;
    canDeleteNote = notes[index]->getEditable();
    if (canDeleteNote) {
        string noteDeleted = notes[index]->getTitle();
        delete notes[index];
        notes[index] = nullptr;
        notes.erase(notes.begin() + index);
        cout << "Completed!\t" << noteDeleted << " deleted!" << endl;
    } else {
        cout << "You can't delete this note" << endl;
    }
}

void CollectionNew::deleteAllNotes() {
    cout << "Deleting all notes from: " << nameCollection << endl;
    for (int i=0; i<notes.size(); i++){
        cout << "\t" << notes[i]->getTitle() << " deleted" <<endl;
        delete notes[i];
        notes[i] = nullptr;
    }
}
// ---------------------------------------------
// HELPERS
bool CollectionNew::isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}