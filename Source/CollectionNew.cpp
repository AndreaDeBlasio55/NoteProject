//
// Created by Andrea on 11/11/21.
//

//
// Created by Andrea on 21/10/21.
//


#include <list>
#include "../Headers/CollectionNew.h"
using namespace std;

CollectionNew::CollectionNew(string name, bool editable) {
    this->name = name;
    this->editable = editable;
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
string CollectionNew::getCollectionName() const {
    return name;
}

// SETTERS
void CollectionNew::editCollectionName(string collectionName) {
    if (this->editable) {
        cout << "Changed collection name from: " << this->name << " to: " << endl;
        this->name = collectionName;
        cout << "\t" << collectionName << endl;
        notify();
    } else {
        cout << "The Collection: " << this->name << " is not editable." << endl;
    }
}

// NOTES METHODS
// -------------- READ --------------
void CollectionNew::readNotes () const {
    cout << boolalpha << endl;
    cout << "Reading Notes..." << endl;
    if (notes.size() == 0){
        cout << "There is no Notes to read inside the collection: " << name << endl;
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
    string collection = name;

    string editableStr = "0";
    bool editable = false;
    bool validateWhileEditable = false;

    string importantStr = "0";
    bool important = false;
    bool validateWhileImportant = false;

    cout << "Type the title:" << endl;
    cin.ignore();
    getline(cin, title);
    cout << "Type the description:" << endl;
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
            cin >> importantStr;
        }
    }
    NoteNew* newNote = new NoteNew(title, description, collection, editable, important);
    notes.push_back(newNote);
    cout << "Success! Note created" << endl;
}
// -------------- EDIT --------------
void CollectionNew::editNote (vector<Note*> notes, vector<Collection*> collections) {
    cout << boolalpha << endl;
    vector<Note *> myNewNotes;
    bool validateWhile = false;
    bool validateWhile2 = false;
    bool validateWhile3 = false;
    string valueChoiceStr = "-1";
    cout << "Fetching Notes..." << endl;
    if (notes.size() == 0) {
        cout << "There is no Note to edit." << endl;
    } else {
        int indexFor = 0;
        int valueChoice = -1;
        cout << "Please select one of these notes: " << endl;
        for (Note *myNote: notes) {
            myNewNotes.push_back(myNote);
            cout << "\t" << indexFor << " - Id: " << myNote->getId()
                 << "\t Title: " << myNote->getTitle()
                 << "\t\tDescription: " << myNote->getDescription()
                 << "\t\tCollection: " << myNote->getCollection()
                 << "\t\tImportant: " << myNote->getImportant()
                 << "\t\tEditable: " << myNote->getEditable()
                 << endl;
            indexFor++;
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
        canEditNote = myNewNotes[valueChoice]->getEditable();
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
                        cout << "Please type the new TITLE: ( " << myNewNotes[valueChoice]->getTitle() << " )" << endl;
                        cin.ignore();
                        getline(cin, title);
                        myNewNotes[valueChoice]->editTitle(title);
                        validateWhile2 = true;
                    } else if (valueNoteEdit == 1) {
                        cout << "Please type the new DESCRIPTION: ( " << myNewNotes[valueChoice]->getDescription()
                             << " )"
                             << endl;
                        cin.ignore();
                        getline(cin, description);
                        myNewNotes[valueChoice]->editDescription(description);
                        validateWhile2 = true;
                    } else if (valueNoteEdit == 2) {
                        cout << "Please type the new COLLECTION: ( " << myNewNotes[valueChoice]->getCollection() << " )"
                             << endl;
                        cin.ignore();
                        getline(cin, collection);
                        bool addNewCollection = true;
                        int indexCollection = 0;
                        int indexOfOldCollection = 0;
                        for (Collection *searchColl: collections) {
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
                    } else if (valueNoteEdit == 3) {
                        cout << "Please type the new IMPORTANT: " << myNewNotes[valueChoice]->getImportant()
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
                        myNewNotes[valueChoice]->editImportant(importantBool);
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
    return make_tuple(myNewNotes, collections);
}
