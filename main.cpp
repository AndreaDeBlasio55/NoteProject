#include <iostream>
#include "Headers/Note.h"
#include <fstream>
using namespace std;
#include <vector>
#include <tuple>


int choice1 ();         // Collection or Note
// COLLECTIONS
void readCollection(vector<Collection*> col);
Collection* createCollection (vector<Collection*> col);
tuple<vector<Collection*>, vector<Note*>> editCollection (vector<Collection*> col, vector<Note*> notes);
tuple<vector<Collection*>, vector<Note*>> deleteCollection (vector<Collection*> col, vector<Note*> notes);
// NOTES
void readNotes(vector<Note*> notes);
Note* createNote (vector<Collection*> collections, vector<Note*> notes);
tuple<vector<Note*>, vector<Collection*>> editNote (vector<Note*> notes, vector<Collection *> collections);
tuple<vector<Note*>, vector<Collection*>> deleteNote (vector<Note*> notes, vector<Collection*> collections);

int main() {
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

    int controllerReadCreateEdit = -1;
    bool controllerWhileReadCreateEdit = false;


    // First Question: Working on Collection or Note
    controllerCollectionOrNote = choice1();
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
        cout << "\t\t0 - Read \n\t\t1 - Create \n\t\t2 - Edit \n\t\t3 - Delete \n\t\t4 - Go Back \n\t\t5 - Exit" << endl;
        cin >> controllerReadCreateEdit;
        if (controllerReadCreateEdit == 0) {
            if (controllerCollectionOrNote == 0) {
                readCollection(collections);                               // Read Collections
            } else {
                readNotes(notes);                                        // Read Notes
            }
        } else if (controllerReadCreateEdit == 1) {
            if (controllerCollectionOrNote == 0) {
                collections.push_back(createCollection(collections));      // Create Collection
            } else {
                notes.push_back(createNote(collections,notes));    // Create Note
            }
        } else if (controllerReadCreateEdit == 2) {
            if (controllerCollectionOrNote == 0) {
                tie(collections, notes) = editCollection(collections, notes);                 // Edit Collection
            } else {
                tie(notes, collections) = editNote(notes, collections);                                 // Edit Note
            }
        } else if (controllerReadCreateEdit == 3) {
            if (controllerCollectionOrNote == 0) {
                tie(collections, notes) = deleteCollection(collections, notes);
            } else {
                tie(notes, collections) = deleteNote(notes, collections);                                 // Edit Note
            }
        } else if (controllerReadCreateEdit == 4) {
            controllerCollectionOrNote = choice1();                             // Go Back
        } else if (controllerReadCreateEdit == 5) {
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

    return 0;
}

// First Question
int choice1 (){
    int value = 0;
    cout << "Start working with: \n\t0 - Collections \n\t1 - Notes" << endl;
    cin >> value;
    if (value == 0){
        cout << "Great! Let's start working on Collections" << endl;
    } else if (value == 1){
        cout << "Great! Let's start working on Notes" << endl;
    } else {
        cout << "Please type a valid input... Try again!" << endl;
    }
    return value;
}

// COLLECTIONS
// __________ READ ____________________________
void readCollection (vector<Collection*> collections) {
    cout << "Reading Collections..." << endl;
    for (auto & collection : collections) {
        cout << "\t" << collection->getCollectionName() << "\t\t count: " << collection->getCountNotes() << endl;
    }
}
// _________ CREATE ___________________________
Collection* createCollection (vector<Collection*> col) {
    string collectionName = "";
    cout << "Type the name of the collection. " << endl;
    cin >> collectionName;
    Collection* newCol = new Collection(collectionName);
    cout << "Collection name is: " << newCol->getCollectionName() << endl;
    return newCol;
}
// _________ EDIT _____________________________
tuple<vector<Collection*>, vector<Note*>> editCollection (vector<Collection*> col, vector<Note*> notes) {
    vector<Collection*> myNewCollections;
    string oldNameCollection = "";       // to update the notes in that collection
    cout << "Fetching Collections..." << endl;
    if (col.size() == 0){
        cout << "There is no Collection to edit." << endl;
    } else {
        int indexFor = 0;
        int valueChoice = -1;
        cout << "Please select one of these collections: " << endl;
        for (Collection *myCollection: col) {
            myNewCollections.push_back(myCollection);
            cout << "\t" << indexFor << " - " << myCollection->getCollectionName() << endl;
            indexFor++;
        }
        while (valueChoice < 0 || valueChoice > col.size()) {
            cout << "Type here: " << endl;
            cin >> valueChoice;
        }
        oldNameCollection = myNewCollections[valueChoice]->getCollectionName();
        cout << "Type the new name of the collection: " << endl;
        string newNameCollection = "";
        cin >> newNameCollection;
        col[valueChoice]->setCollectionName(newNameCollection);

        // Updating all Notes:
        for (Note* myCurrentNote : notes){
            if (myCurrentNote->getCollection() == oldNameCollection) {
                myCurrentNote->editCollection(newNameCollection);
                cout << "Updating the note: \n\t "
                << " - " << myCurrentNote->getTitle()
                << " - " <<  myCurrentNote->getId() << endl;
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
    cout << "Fetching Collections..." << endl;
    if (col.size() == 0){
        cout << "There is no Collection to edit." << endl;
    } else {
        int indexFor = 0;
        int valueChoice = -1;
        cout << "Please select one of these collections: " << endl;
        for (Collection *myCollection: col) {
            myNewCollections.push_back(myCollection);
            cout << "\t" << indexFor << " - " << myCollection->getCollectionName() << endl;
            indexFor++;
        }
        while (valueChoice < 0 || valueChoice > col.size()) {
            cout << "Type here: " << endl;
            cin >> valueChoice;
        }
        if (valueChoice > 0) {
            oldNameCollection = myNewCollections[valueChoice]->getCollectionName();
            myNewCollections.erase(myNewCollections.begin() + valueChoice);
        } else {
            cout << "You can't delete the Default collection" << endl;
        }

        // Updating all Notes:
        for (Note* myCurrentNote : notes){
            if (myCurrentNote->getCollection() == oldNameCollection) {
                myCurrentNote->editCollection("Default");
                myCurrentNote->assignNewCollectionSubj(myNewCollections[0]);
                cout << "Updating the note: \n\t "
                     << " - " << myCurrentNote->getTitle()
                     << " - " <<  myCurrentNote->getId()
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
    string description = "";
    string collection = "Default";
    int editableInt = -1;
    bool editable = false;

    cout << "Type the title: " << endl;
    cin >> title;
    cout << "Type the description: " << endl;
    cin >> description;
    cout << "Type is editable: \n\t0 - false \n\t1 - true " << endl;
    cin >> editableInt;
    if (editableInt == 0){
        editable = false;
    } else {
        editable = true;
    }

    Note* newNote = new Note(collections[0], title, description, editable);
    cout << "Success! Note created" << endl;
    return newNote;
}
// _________ EDIT _____________________________
tuple<vector<Note*>, vector<Collection*>> editNote (vector<Note*> notes, vector<Collection*> collections) {
    cout << boolalpha << endl;
    vector<Note *> myNewNotes;
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
        while (valueChoice < 0 || valueChoice > notes.size()) {
            cout << "Type here your choice: " << endl;
            cin >> valueChoice;
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
            int valueNoteEdit = -1;
            string title = "";
            string description = "";
            string collection = "";
            int important = -1;
            bool importantBool = false;
            cin >> valueNoteEdit;
            if (valueNoteEdit == 0) {
                cout << "Please type the new TITLE: ( " << myNewNotes[valueChoice]->getTitle() << " )" << endl;
                cin >> title;
                myNewNotes[valueChoice]->editTitle(title);
            } else if (valueNoteEdit == 1) {
                cout << "Please type the new DESCRIPTION: ( " << myNewNotes[valueChoice]->getDescription() << " )" << endl;
                cin >> description;
                myNewNotes[valueChoice]->editDescription(description);
            } else if (valueNoteEdit == 2) {
                cout << "Please type the new COLLECTION: ( " << myNewNotes[valueChoice]->getCollection() << " )" << endl;
                cin >> collection;
                bool addNewCollection = true;
                int indexCollection = 0;
                int indexOfOldCollection = 0;
                for(Collection* searchColl : collections){
                    if (searchColl->getCollectionName() == collection){
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
                    Collection* oldCollectionNoNewName = collections[indexOfOldCollection];
                    myNewNotes[valueChoice]->assignNewCollectionSubj(oldCollectionNoNewName);
                }
                myNewNotes[valueChoice]->editCollection(collection);
                //myNewNotes[valueChoice]->editCollectionSubject(newCollection);
                // todo: cerca se la collection esiste, altrimenti creala
            } else if (valueNoteEdit == 3) {
                cout << "Please type the new IMPORTANT: ( " << myNewNotes[valueChoice]->getImportant() << " )\n\t0 - false \n\t1 - true" << endl;
                cin >> important;
                if (important == 0) {
                    importantBool = false;
                } else {
                    importantBool = true;
                }
                myNewNotes[valueChoice]->editImportant(importantBool);
            }
            cout << "Completed!" << endl;
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
    cout << "Fetching Notes..." << endl;
    if (notes.size() == 0) {
        cout << "There is no Note to delete." << endl;
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
        while (valueChoice < 0 || valueChoice > notes.size()) {
            cout << "Type here your choice: " << endl;
            cin >> valueChoice;
        }
        // Check if we can delete this note:
        bool canDeleteNote = false;
        canDeleteNote = myNewNotes[valueChoice]->getEditable();
        if (canDeleteNote) {
            string noteDeleted = myNewNotes[valueChoice]->getTitle();
            myNewNotes[valueChoice]->deleteNote();
            myNewNotes.erase(myNewNotes.begin() + valueChoice);
            cout << "Completed! - \t" << noteDeleted << " deleted!" << endl;
        } else {
            cout << "You can't delete this note (not editable)" << endl;
        }
    }
    return make_tuple(myNewNotes, collections);
}