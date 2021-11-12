#include <iostream>
#include <string>
#include "Headers/Note.h"
#include "Headers/CollectionNew.h"
#include <fstream>
#include "Headers/CollectionView.h"
using namespace std;
#include <vector>
#include <tuple>


bool isNumber(string str);

int choice1 ();         // Collection or Note
// COLLECTIONS
void readCollection(vector<Collection*> col);
tuple<vector<Collection*>, bool> createCollection (vector<Collection*> col);
tuple<vector<Collection*>, vector<Note*>> editCollection (vector<Collection*> col, vector<Note*> notes);
tuple<vector<Collection*>, vector<Note*>> deleteCollection (vector<Collection*> col, vector<Note*> notes);
// NOTES
void readNotes(vector<Note*> notes);
Note* createNote (vector<Collection*> collections, vector<Note*> notes);
tuple<vector<Note*>, vector<Collection*>> editNote (vector<Note*> notes, vector<Collection *> collections);
tuple<vector<Note*>, vector<Collection*>> deleteNote (vector<Note*> notes, vector<Collection*> collections);

int main() {

    bool controllerWhileMain = true;
    string firstInputStr = "";
    int firstInput = -1;
    CollectionView* controllerCollections = new CollectionView();
    while (controllerWhileMain) {
        cout << "What would you do?: "
                "\n\t0 - Read Collections"
                "\n\t1 - Create Collection"
                "\n\t2 - Edit Collection"
                "\n\t3 - Delete Collection"
                "\n\t4 - Exit" << endl;
        getline(cin, firstInputStr);
        if (firstInputStr == ""){
            cout << "Not valid input" << endl;
        } else if (isNumber(firstInputStr)) {
            firstInput = stoi(firstInputStr);
            if (firstInput == 0) {
                controllerCollections->readCollections();
            } else if (firstInput == 1) {
                controllerCollections->createCollection();
            } else if (firstInput == 3) {
                controllerCollections->deleteCollection();
            } else if (firstInput == 4) {
                controllerWhileMain = false;
            } else {
                cout << "Not valid input" << endl;
            }
        } else {
            cout << "No valid input" << endl;
        }
    }
    //] OLD CODE
    /*
    // --- COLLECTIONS ---
    vector<Collection *> collections;
    // Init collections with the Default Collection
    Collection* defaultCollection = new Collection("Default");
    collections.push_back(defaultCollection);
    // --- NOTES ---
    vector<Note *> notes;

    // init var
    int controllerCollectionOrNote = -1;
    bool controllerWhileCollectionNote = false;

    string controllerReadCreateEdit = "";
    bool controllerWhileReadCreateEdit = false;


    // First Question: Working on Collection or Note
//    controllerCollectionOrNote = choice1();
    while (!controllerWhileCollectionNote) {
        if (controllerCollectionOrNote != 0 && controllerCollectionOrNote != 1) {
            controllerCollectionOrNote = choice1();
        } else {
            controllerWhileCollectionNote = true;
        }
    }


    // Second Question - READ CREATE EDIT
    while (!controllerWhileReadCreateEdit) {
        cout << "\tWhat do you want to do?:" << endl;
        cout << "\t\t0 - Read \n\t\t1 - Create \n\t\t2 - Edit \n\t\t3 - Delete \n\t\t4 - Go Back \n\t\t5 - Exit"
             << endl;
        cin >> controllerReadCreateEdit;
        if (controllerReadCreateEdit == "0") {
            if (controllerCollectionOrNote == 0) {
                readCollection(collections);                               // Read Collections
            } else {
                readNotes(notes);                                        // Read Notes
            }
        } else if (controllerReadCreateEdit == "1") {
            if (controllerCollectionOrNote == 0) {
                bool isNewCollection = true;
                tie(collections, isNewCollection) = createCollection(collections);                 // Edit Collection
                if (!isNewCollection){
                    collections.pop_back();
                }
            } else {
                notes.push_back(createNote(collections, notes));    // Create Note
            }
        } else if (controllerReadCreateEdit == "2") {
            if (controllerCollectionOrNote == 0) {
                tie(collections, notes) = editCollection(collections, notes);                 // Edit Collection
            } else {
                tie(notes, collections) = editNote(notes, collections);                                 // Edit Note
            }
        } else if (controllerReadCreateEdit == "3") {
            if (controllerCollectionOrNote == 0) {
                tie(collections, notes) = deleteCollection(collections, notes);
            } else {
                tie(notes, collections) = deleteNote(notes,collections);                                 // Edit Note
            }
        } else if (controllerReadCreateEdit == "4") {
            controllerCollectionOrNote = choice1();                             // Go Back
        } else if (controllerReadCreateEdit == "5") {
            controllerWhileReadCreateEdit = true;                               // TERMINATE PROGRAM
        } else {
            cout << "Please type a valid input." << endl;
        }
    }


    cout << "Summary Collections:" << endl;
    int indexCollection = 0;
    for (Collection* currentCollection : collections){
        cout << "\tName: " << currentCollection[indexCollection].getCollectionName()
        << "\t\t\t notes: " <<  currentCollection[indexCollection].getCountNotes()
        << endl;
    }

    // --- Release Memory: ---
    // COLLECTIONS
    for (int i=0; i<collections.size(); i++){
        delete collections[i];
        collections[i] = nullptr;
    }
    // NOTES
    for (int i=0; i<notes.size(); i++){
        delete notes[i];
        notes[i] = nullptr;
    }
    // ------
     */

    return 0;
}


bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

// First Question
int choice1 (){
    string value = "";
    cout << "Start working with: \n\t0 - Collections \n\t1 - Notes" << endl;
    bool validInput = false;
    while (!validInput) {
        cin >> value;
        if (isNumber(value)) {
            if (value == "0") {
                cout << "Great! Let's start working on Collections" << endl;
                validInput = true;
            } else if (value == "1") {
                cout << "Great! Let's start working on Notes" << endl;
                validInput = true;
            } else {
                cout << "Please type a valid input... Try again! Range: 0 - 1" << endl;
            }
        } else {
            cout << "Please type a valid input... Try again! Range: 0 - 1" << endl;
            value = "2";  // -> invalid input
        }
    }
    return stoi(value);
}
// todo: collections methods need to be inside CollectionView Class
// COLLECTIONS
// __________ READ ____________________________
void readCollection (vector<Collection*> collections) {
    cout << "Reading Collections..." << endl;
    for (auto & collection : collections) {
        cout << "\t" << collection->getCollectionName() << "\t\t count: " << collection->getCountNotes() << endl;
    }
}
// _________ CREATE ___________________________
tuple<vector<Collection*>, bool> createCollection (vector<Collection*> col) {
    string collectionName = "";
    bool isNewCollection = true;
    cout << "Type the name of the collection. " << endl;
    cin.ignore();
    getline(cin, collectionName);
    for (int i=0; i<col.size(); i++){
        if (collectionName == col[i]->getCollectionName()){
            cout << "This name is already taken, try another name." << endl;
            isNewCollection = false;
        }
    }
    Collection* newCol = new Collection(collectionName);
    col.push_back(newCol);
    return make_tuple(col, isNewCollection);
}
// _________ EDIT _____________________________
tuple<vector<Collection*>, vector<Note*>> editCollection (vector<Collection*> col, vector<Note*> notes) {
    vector<Collection *> myNewCollections;
    string oldNameCollection = "";       // to update the notes in that collection
    cout << "Fetching Collections..." << endl;

    int indexFor = 0;
    string valueChoice = "";
    bool validateWhile = false;
    int valueChoiceInt = 0;
    cout << "Please select one of these collections: " << endl;
    for (Collection *myCollection: col) {
        myNewCollections.push_back(myCollection);
        cout << "\t" << indexFor << " - " << myCollection->getCollectionName() << endl;
        indexFor++;
    }
    if (col.size() == 1) {
        cout << "There is only the collection:\n\t0 - Default \n so you can't edit this one." << endl;
    } else {
        cout << "Type here: " << endl;
        cin >> valueChoice;
        while (validateWhile == false) {
            if (isNumber(valueChoice)) {
                valueChoiceInt = stoi(valueChoice);
                if (valueChoiceInt >= 1 && valueChoiceInt < col.size()) {
                    validateWhile = true;
                } else {
                    cout << "Please type a value in this range: ( 1 - " << col.size() - 1 << " )" << endl;
                    cin >> valueChoice;
                }
            } else {
                cout << "Please type a value in this range: ( 1 - " << col.size() - 1 << " )" << endl;
                cin >> valueChoice;
            }
        }
        oldNameCollection = myNewCollections[valueChoiceInt]->getCollectionName();
        cout << "Type the new name of the collection: ( " << oldNameCollection << " )" << endl;
        string newNameCollection = "";
        cin.ignore();
        getline(cin, newNameCollection);
        col[valueChoiceInt]->setCollectionName(newNameCollection);

        // Updating all Notes:
        for (Note *myCurrentNote: notes) {
            if (myCurrentNote->getCollection() == oldNameCollection) {
                myCurrentNote->editCollection(newNameCollection);
                cout << "Updating the note: \n\t "
                     << " - " << myCurrentNote->getTitle()
                     << " - " << myCurrentNote->getId() << endl;
            }
        }
        cout << "Completed!" << endl;
    }
    return make_tuple(myNewCollections, notes);
}
// --------- DELETE ---------------------------
tuple<vector<Collection*>, vector<Note*>> deleteCollection (vector<Collection*> col, vector<Note*> notes) {
    vector<Collection*> myNewCollections;
    string oldNameCollection = "";       // to update the notes in that collection
    int valueChoiceInt = 0;
    cout << "Fetching Collections..." << endl;
    int indexFor = 0;
    string valueChoice = "";
    bool validateWhile = false;
    cout << "Please select one of these collections: " << endl;
    for (Collection *myCollection: col) {
        myNewCollections.push_back(myCollection);
        cout << "\t" << indexFor << " - " << myCollection->getCollectionName() << endl;
        indexFor++;
    }
    if (col.size() <= 1){
        cout << "There is no Collection to delete." << endl;
    } else {
        cout << "Type here: " << endl;
        cin >> valueChoice;
        while (validateWhile == false) {
            if (isNumber(valueChoice)) {
                valueChoiceInt = stoi(valueChoice);
                if (valueChoiceInt == 0){
                    cout << "You can't delete the Default collection" << endl;
                    validateWhile = true;
                } else if (valueChoiceInt >= 1 && valueChoiceInt < col.size()) {
                    oldNameCollection = myNewCollections[valueChoiceInt]->getCollectionName();
                    myNewCollections.erase(myNewCollections.begin() + valueChoiceInt);
                    validateWhile = true;
                } else {
                    cout << "Please type a value in this range: ( 1 - " << col.size() - 1 << " )" << endl;
                    cin >> valueChoice;
                }
            } else {
                cout << "Please type a value in this range: ( 1 - " << col.size() - 1 << " )" << endl;
                cin >> valueChoice;
            }
        }
        // Updating all Notes:
        for (Note *myCurrentNote: notes) {
            if (myCurrentNote->getCollection() == oldNameCollection) {
                myCurrentNote->editCollection("Default");
                myCurrentNote->assignNewCollectionSubj(myNewCollections[0]);
                cout << "Updating the note: \n\t "
                     << " - " << myCurrentNote->getTitle()
                     << " - " << myCurrentNote->getId()
                     << " - Collection reset to " << myCurrentNote->getCollection()
                     << endl;
            }
        }
        cout << "Completed!" << endl;
    }
    return make_tuple(myNewCollections, notes);
}
// NOTES
// __________ READ ____________________________
void readNotes (vector<Note*> notes) {
    cout << boolalpha << endl;
    cout << "Reading Notes..." << endl;
    if (notes.size() == 0){
        cout << "There is no Notes to read" << endl;
    } else {
        for (Note *myNote: notes) {
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
// _________ CREATE ___________________________
Note* createNote (vector<Collection*> collections, vector<Note*> notes) {
    string title = "";
    string description = " ";
    string collection = "Default";
    string editableStr = "0";
    bool editable = false;
    bool validateWhile = false;

    cout << "Type the title:" << endl;
    cin.ignore();
    getline(cin, title);
    cout << "Type the description:" << endl;
    //cin.ignore();
    getline(cin, description);
    cout << "Type is editable: \n\t0 - false \n\t1 - true " << endl;
    cin >> editableStr;
    while (validateWhile == false) {
        if (editableStr == "0") {
            editable = false;
            validateWhile = true;
        } else if (editableStr == "1") {
            editable = true;
            validateWhile = true;
        } else {
            cout << "Wrong input, please type: \n\t0 - false \n\t1 - true " << endl;
            cin >> editableStr;
        }
    }

    Note* newNote = new Note(collections[0], title, description, editable);
    cout << "Success! Note created" << endl;
    return newNote;
}
// _________ EDIT _____________________________
tuple<vector<Note*>, vector<Collection*>> editNote (vector<Note*> notes, vector<Collection*> collections) {
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
// --------- DELETE ---------------------------
tuple<vector<Note*>, vector<Collection*>> deleteNote (vector<Note*> notes, vector<Collection*> collections) {
    cout << boolalpha << endl;
    vector<Note *> myNewNotes;
    bool validateWhile = false;
    cout << "Fetching Notes..." << endl;
    if (notes.size() == 0) {
        cout << "There is no Note to delete." << endl;
    } else {
        int indexFor = 0;
        int valueChoice = -1;
        string valueChoiceStr = "-1";
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
        canDeleteNote = myNewNotes[valueChoice]->getEditable();
        if (canDeleteNote) {
            string noteDeleted = myNewNotes[valueChoice]->getTitle();
            myNewNotes[valueChoice]->deleteNote();
            myNewNotes.erase(myNewNotes.begin() + valueChoice);
            cout << "Completed!\t" << noteDeleted << " deleted!" << endl;
        } else {
            cout << "You can't delete this note (not editable)" << endl;
        }
    }
    return make_tuple(myNewNotes, collections);
}