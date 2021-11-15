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
    observerNote.push_back(o);
}
void CollectionNew::unsubscribe(Observer *o) {
    observerNote.remove(o);
}
void CollectionNew::notify() {
    for (auto itr= begin(observerNote); itr!= end(observerNote); itr++){
        (*itr)->update();
    }
}
// GETTERS
int CollectionNew::getCountNotes () const {
    int value = 0;
    for (auto itr= begin(observerNote); itr!= end(observerNote); itr++){
        value += 1;
    }
    return value;
}
bool CollectionNew::getEditable () const {
    return editable;
}
string CollectionNew::getCollectionName() const {
    return this->nameCollection;
}

// SETTERS
void CollectionNew::editCollectionName(string collectionName) {
    if (this->editable) {
        cout << "Changed collection name from: " << this->nameCollection << " to: " << endl;
        this->nameCollection = collectionName;
        cout << "\t" << collectionName << endl;
        notify();
    } else {
        cout << "The Collection: " << this->nameCollection << " is not editable." << endl;
    }
}

// NOTES METHODS
void CollectionNew::menuNotes () {
    bool controllerWhileMenuNotes = true;
    string inputStr = "";
    int inputInt = -1;
    while (controllerWhileMenuNotes) {
        cout << "What would you do?: "
                "\n\t0 - Read Notes"
                "\n\t1 - Create Note"
                "\n\t2 - Edit Note"
                "\n\t3 - Delete Note"
                "\n\t4 - Exit" << endl;
        cin.clear();
        cin >> inputStr;
        if (inputStr.empty()){
            cout << "Not valid input" << endl;
        } else {
            if (isNumber(inputStr)) {
                inputInt = stoi(inputStr);
                if (inputInt == 0) {
                    readNotes();
                } else if (inputInt == 1) {
                    createNote();
                } else if (inputInt == 2) {
                    editNote();
                } else if (inputInt == 3) {
                    deleteNote();
                } else if (inputInt == 4) {
                    controllerWhileMenuNotes = false;
                } else {
                    cout << "Not valid input" << endl;
                }
            } else {
                cout << "No valid input" << endl;
            }
        }
    }
}
// -------------- READ --------------
void CollectionNew::readNotes () {
    cout << boolalpha << endl;
    cout << "Reading Notes from " << endl;
    cout << notes.size() << endl;
    if (notes.empty()){
        cout << "There aren't Notes to read inside the collection: " << this->getCollectionName() << endl;
    } else {
        for (NoteNew *myNote: notes) {
            cout << "\tTitle: " << myNote->getTitle()
                 << "\t\tId: " << myNote->getId()
                 << "\t\tDescription: " << myNote->getDescription()
                 << "\t\tCollection: " << myNote->getCollection()
                 << "\t\tImportant: " << myNote->getImportant()
                 << "\t\tEditable: " << myNote->getEditable()
                 << endl;
        }
    }
}
// -------------- CREATE --------------
void CollectionNew::createNote () {
    string title = "";
    string description = " ";
    string collection = nameCollection;

    string editableStr = "0";
    bool editable = false;
    bool validateWhileEditable = false;

    string importantStr = "0";
    bool important = false;
    bool validateWhileImportant = false;

    cout << "Type the title:" << endl;
    cin.clear();
    cin.ignore();
    getline(cin, title);
    cout << "Type the description:" << endl;
    cin.clear();
    //cin.ignore();
    getline(cin, description);
    cout << "Type is editable: \n\t0 - false \n\t1 - true " << endl;
    cin >> editableStr;
    while (validateWhileEditable == false) {
        if (editableStr == "0") {
            editable = false;
            validateWhileEditable = true;
        } else if (editableStr == "1") {
            editable = true;
            validateWhileEditable = true;
        } else {
            cout << "Wrong input, please type: \n\t0 - false \n\t1 - true " << endl;
            cin >> editableStr;
        }
    }
    while (validateWhileImportant == false) {
        if (importantStr == "0") {
            important = false;
            validateWhileImportant = true;
        } else if (importantStr == "1") {
            important = true;
            validateWhileImportant = true;
        } else {
            cout << "Wrong input, please type: \n\t0 - false \n\t1 - true " << endl;
            cin.clear();
            cin.ignore();
            cin >> importantStr;
        }
    }
    NoteNew* newNote = new NoteNew(title, description, collection, editable, important);
    notes.push_back(newNote);
    cout << "Success! Note created" << endl;

}
// -------------- EDIT --------------
void CollectionNew::editNote () {
    cout << boolalpha << endl;
    bool validateWhile = false;
    bool validateWhile2 = false;
    bool validateWhile3 = false;
    string valueChoiceStr = "-1";
    cout << "Fetching Notes..." << endl;
    if (notes.size() == 0) {
        cout << "There is no Note to edit." << endl;
    } else {
        int valueChoice = -1;
        cout << "Please select one of these notes: " << endl;
        for (int i = 0; i < notes.size(); i++) {
            cout << "\t" << i << " - Id: " << notes[i]->getId()
                 << "\t Title: " << notes[i]->getTitle()
                 << "\t\tDescription: " << notes[i]->getDescription()
                 << "\t\tCollection: " << notes[i]->getCollection()
                 << "\t\tImportant: " << notes[i]->getImportant()
                 << "\t\tEditable: " << notes[i]->getEditable()
                 << endl;
        }
        // Select the note
        cin >> valueChoiceStr;
        while (validateWhile == false) {
            if (isNumber(valueChoiceStr)) {
                valueChoice = stoi(valueChoiceStr);
                if (valueChoice >= 0 && valueChoice < notes.size()) {
                    validateWhile = true;
                } else {
                    cout << "Please type here your choice in this range: ( 0 - " << notes.size() - 1 << " )" << endl;
                    cin >> valueChoiceStr;

                }
            } else {
                cout << "Please type here your choice in this range: ( 0 - " << notes.size() - 1 << " )" << endl;
                cin >> valueChoiceStr;
            }
        }
        // Check if we can edit this note:
        bool canEditNote = false;
        canEditNote = notes[valueChoice]->getEditable();
        if (canEditNote) {
            cout << "What do you want to edit: "
                 << "\n\t0 - Title "
                 << "\n\t1 - Description "
                 << "\n\t2 - Collection "
                 << "\n\t3 - Important "
                 << endl;
            string valueNoteEditStr = "";
            int valueNoteEdit = -1;
            string title = "";
            string description = "";
            string collection = "";
            int important = -1;
            bool importantBool = false;

            cin >> valueNoteEditStr;
            while (validateWhile2 == false) {
                if (isNumber(valueNoteEditStr)) {
                    valueNoteEdit = stoi(valueNoteEditStr);
                    if (valueNoteEdit == 0) {
                        cout << "Please type the new TITLE: ( " << notes[valueChoice]->getTitle() << " )" << endl;
                        cin.ignore();
                        getline(cin, title);
                        notes[valueChoice]->editTitle(title);
                        validateWhile2 = true;
                    } else if (valueNoteEdit == 1) {
                        cout << "Please type the new DESCRIPTION: ( " << notes[valueChoice]->getDescription()
                             << " )"
                             << endl;
                        cin.ignore();
                        getline(cin, description);
                        notes[valueChoice]->editDescription(description);
                        validateWhile2 = true;
                    }
                        /* todo: how to change collection without getting other collection?
                        else if (valueNoteEdit == 2) {
                            cout << "This note is inside: ( " << name << " )"
                                 << endl;
                            cin.ignore();
                            getline(cin, collection);
                            bool addNewCollection = true;
                            int indexCollection = 0;
                            int indexOfOldCollection = 0;
                            for (CollectionNew *searchColl: collections) {
                                if (searchColl->getCollectionName() == collection) {
                                    addNewCollection = false;
                                    indexOfOldCollection = indexCollection;
                                }
                                indexCollection++;
                            }
                            // add new collection if it doesn't exist
                            Collection *newCollection = new Collection(collection);
                            if (addNewCollection == true) {
                                collections.push_back(newCollection);
                                myNewNotes[valueChoice]->assignNewCollectionSubj(newCollection);
                            } else {
                                Collection *oldCollectionNoNewName = collections[indexOfOldCollection];
                                myNewNotes[valueChoice]->assignNewCollectionSubj(oldCollectionNoNewName);
                            }
                            myNewNotes[valueChoice]->editCollection(collection);
                        validateWhile2 = true;
                    }
                         */
                    else if (valueNoteEdit == 3) {
                        cout << "Please type the new IMPORTANT: " << notes[valueChoice]->getImportant()
                             << "\n\t0 - false \n\t1 - true " << endl;
                        string importantStr = "";
                        cin >> importantStr;
                        while (validateWhile3 == false) {
                            if (isNumber(importantStr)) {
                                important = stoi(importantStr);
                                if (important == 0) {
                                    importantBool = false;
                                    validateWhile3 = true;
                                } else if (important == 1) {
                                    importantBool = true;
                                    validateWhile3 = true;
                                } else {
                                    cout << "Please type a value in this range: \n\t 0 - false \n\t 1 - true " << endl;
                                    cin >> importantStr;
                                }
                            } else {
                                cout << "Please type a value in this range: \n\t 0 - false \n\t 1 - true " << endl;
                                cin >> importantStr;
                            }
                        }
                        notes[valueChoice]->editImportant(importantBool);
                        validateWhile2 = true;
                    } else {
                        cout << "Please type a valid input!" << endl;
                        cin >> valueNoteEditStr;
                    }
                } else {
                    cout << "Please type a valid input!" << endl;
                    cin >> valueNoteEditStr;
                }
            }
        } else {
            cout << "This note is not Editable" << endl;
        }
    }
}
void CollectionNew::deleteNote () {
    cout << boolalpha << endl;
    bool validateWhile = false;
    cout << "Fetching Notes..." << endl;
    if (notes.size() == 0) {
        cout << "There are no notes to delete" << endl;
    } else {
        int indexFor = 0;
        int valueChoice = -1;
        string valueChoiceStr = "-1";
        cout << "Please select one of these notes: " << endl;
        for (int i=0; i<notes.size(); i++) {
            cout << "\t" << indexFor << " - Id: " << notes[i]->getId()
                 << "\t Title: " << notes[i]->getTitle()
                 << "\t\tDescription: " << notes[i]->getDescription()
                 << "\t\tCollection: " << notes[i]->getCollection()
                 << "\t\tImportant: " << notes[i]->getImportant()
                 << "\t\tEditable: " << notes[i]->getEditable()
                 << endl;
            indexFor++;
        }
        cin >> valueChoiceStr;
        while (validateWhile == false) {
            if (isNumber(valueChoiceStr)) {
                valueChoice = stoi(valueChoiceStr);
                if (valueChoice >= 0 && valueChoice < notes.size()) {
                    validateWhile = true;
                } else {
                    cout << "Please type a valid input in this range: ( 0 - " << notes.size()-1 << " )"<< endl;
                    cin >> valueChoiceStr;
                }
            } else {
                cout << "Please type a valid input in this range: ( 0 - " << notes.size()-1 << " )"<< endl;
                cin >> valueChoiceStr;
            }
        }
        // Check if we can delete this note:
        bool canDeleteNote = false;
        canDeleteNote = notes[valueChoice]->getEditable();
        if (canDeleteNote) {
            string noteDeleted = notes[valueChoice]->getTitle();
            notes.erase(notes.begin() + valueChoice);
            cout << "Completed!\t" << noteDeleted << " deleted!" << endl;
        } else {
            cout << "You can't delete this note (not editable)" << endl;
        }
    }
}

// SINGLE NOTE METHODS
/*
void CollectionNew::editTitle(int indexNote, string title){
    if (notes[indexNote]->getEditable()) {
        notes[indexNote]->editTitle(title);
    } else {
        cout << "Edit title failed: This note is not editable..." << endl;
    }
}
void CollectionNew::editDescription(int indexNote, string description){
    if (notes[indexNote]->getEditable()) {
        notes[indexNote]->editDescription(description);
    } else {
        cout << "Edit title failed: This note is not editable..." << endl;
    }
}
void CollectionNew::editCollection(int indexNote, string collection){
    if (notes[indexNote]->getEditable()) {
        notes[indexNote]->editCollection(collection);
    } else {
        cout << "Edit title failed: This note is not editable..." << endl;
    }
}
void CollectionNew::editImportant(int indexNote, bool important) {
    if (notes[indexNote]->getEditable()) {
        notes[indexNote]->editImportant(important);
    } else {
        cout << "Edit title failed: This note is not editable..." << endl;
    }
}
 */
// ---------------------------------------------
// HELPERS
bool CollectionNew::isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}