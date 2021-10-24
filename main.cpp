#include <iostream>
#include "Headers/Note.h"
#include <fstream>
#include <iomanip>
using namespace std;
#include <vector>

#include "Headers/GameCharacter.h"
#include "Headers/VideogameMapView.h"


int choice1 ();         // Collection or Note
// COLLECTIONS
void readCollection(vector<Collection*> col);
Collection* createCollection (vector<Collection*> col);
vector<Collection*> editCollection (vector<Collection*> col);


void printNote(Note* printNote);

int main() {


    // --- COLLECTIONS ---
    vector<Collection *> collections;

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
        cout << "COLLECTIONS \n\tWhat do you want to do?:" << endl;
        cout << "\t\t0 - Read \n\t\t1 - Create \n\t\t2 - Edit \n\t\t3 - Exit" << endl;
        cin >> controllerReadCreateEdit;
        if (controllerReadCreateEdit == 0) {
            readCollection(collections);        // Read Collection
        } else if (controllerReadCreateEdit == 1) {
            collections.push_back(createCollection(collections));
        } else if (controllerReadCreateEdit == 2) {
            editCollection(collections);
        } else if (controllerReadCreateEdit == 3) {
            controllerWhileReadCreateEdit = true;
        } else {
            cout << "Please type a valid input." << endl;
        }
    }

    vector<Note *> notes;



    // Second Question - Action to: COLLECTION or NOTE


    // get Notes count data from input.txt
    /*
    ifstream inputFile;
    inputFile.open("/Users/andrea/CLionProjects/NoteProject/Output/input.txt");
    int notesCount = 0;
    inputFile >> notesCount;
    inputFile.close();
    cout << "Notes: " << notesCount << endl;
     */
    /*
    //
    Note* myFirstNotePtr = new Note("Importanti", "Spesa", "Cosa comprare alla coop", false);
    printNote(myFirstNotePtr);

    myFirstNotePtr->editImportant(true);
    myFirstNotePtr->editTitle("This is a new title");
    myFirstNotePtr->editDescription("This is a new description");
    cout << "Editing note... \nNew Note:" << endl;
    printNote(myFirstNotePtr);

    // release pointers
    delete myFirstNotePtr;
    myFirstNotePtr = nullptr;
*/
    //GameCharacter* gc1 = new GameCharacter(1,3);
    // Creating Subjects
    Collection* collection1 = new Collection("Monday");
    Collection* collection2 = new Collection("Thursday");

    cout << "Collection : " << collection1->getCollectionName() << endl;

    // Creating Observers
    Note* note1 = new Note(collection1, "Note number 1", "First description for note 1");
    Note* note2 = new Note(collection1, "Note number 2", "Second description for note 2");
    Note* note3 = new Note(collection1, "Note number 3", "Thirs description for note 3");

    printNote(note1);
    collection1->setCollectionName("Monday Edited");
    printNote(note1);

    //VideogameMapView* videoG1 = new VideogameMapView(gc1);
    //videoG1->update();

    int countNoteCollection1 = collection1->getCountNotes();
    cout << "Notes in " << collection1->getCollectionName() << ": " << countNoteCollection1 << endl;
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

// --- COLLECTIONS METHODS ---
// __________ READ ____________________________
void readCollection (vector<Collection*> col) {
    cout << "Reading Collections..." << endl;
    if (col.size() == 0){
        cout << "There is no Collections to read" << endl;
    } else {
        for (Collection *myCollection: col) {
            cout << "\t" << myCollection->getCollectionName() << endl;
        }
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
vector<Collection*> editCollection (vector<Collection*> col) {
    vector<Collection*> myNewCollections;
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
        cout << "Type the new name of the collection: " << endl;
        string newNameCollection = "";
        cin >> newNameCollection;
        myNewCollections[valueChoice]->setCollectionName(newNameCollection);
        cout << "Completed!" << endl;
    }
    return myNewCollections;
}

/*
int getTotalNoteCount () {
    ifstream inputFile;
    inputFile.open("/Users/andrea/CLionProjects/NoteProject/Output/input.txt");
    int notesCount = 0;
    inputFile >> notesCount;
    inputFile.close();
    cout << "Notes: " << notesCount << endl;
}
 */

void printNote(Note* printNote){
    cout << boolalpha << endl;
    cout << "Title: " << printNote->getTitle()
         << "\n     - Id: " << printNote->getId()
         << "\n     - description: " << printNote->getDescription()
         << "\n     - editable: " << printNote->getEditable()
         << "\n     - important: "  << printNote->getImportant()
         << "\n     - collection: " << printNote->getCollection()
         << endl;
}

// output
/*
ofstream outFile;
cout << "Writing to file..." << endl;
outFile.open("/Users/andrea/CLionProjects/NoteProject/Output/output.txt");
outFile << fixed << showpoint;
cout << fixed << showpoint;
outFile << "Prova 2 ---";
outFile.close();
*/