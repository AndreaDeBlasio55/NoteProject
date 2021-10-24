#include <iostream>
#include "Headers/Note.h"
#include <fstream>
#include <iomanip>
using namespace std;
#include <vector>

#include "Headers/GameCharacter.h"
#include "Headers/VideogameMapView.h"


int choice1 ();                             // Collection or Note

void printNote(Note* printNote);

void choice2(int controllerReadCreateEdit);           // Read Create Edit

void createNote();
void readCollection(vector<Collection*> col);
Collection* createCollections (vector<Collection*> col);

int main() {


    // --- COLLECTIONS ---
    vector<Collection *> collections;

    // First Question: Working on Collection or Note
    int controllerCollectionOrNote = -1;
    bool controllerWhileCollectionNote = false;
    controllerCollectionOrNote = choice1();
    while (!controllerWhileCollectionNote) {
        if (controllerCollectionOrNote != 0 && controllerCollectionOrNote != 1) {
            controllerCollectionOrNote = choice1();
        } else {
            controllerWhileCollectionNote = true;
        }
    }


    int controllerReadCreateEdit = -1;
    bool controllerWhileReadCreateEdit = false;
    // Second Question - READ CREATE EDIT
    while (!controllerWhileReadCreateEdit) {
        if (controllerReadCreateEdit != 0 && controllerReadCreateEdit != 1 && controllerReadCreateEdit != 2) {
            cout << "What do you want to do?:" << endl;
            cout << "\t0 - Read \n\t1 - Create \n\t2 - Edit" << endl;
            cin >> controllerReadCreateEdit;
            if (controllerReadCreateEdit == 0) {
                readCollection(collections);        // Read Collection
            } else if (controllerReadCreateEdit == 1) {
                collections.push_back(createCollections(collections));
            } else if (controllerReadCreateEdit == 2) {

            } else {
                cout << "Please type a valid input." << endl;
            }
        } else {
            controllerWhileReadCreateEdit = true;
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
    for(Collection* myCollection : col){
        cout << "\t" << myCollection->getCollectionName() << endl;
    }
}
// _________ CREATE ___________________________
Collection* createCollections (vector<Collection*> col) {
    string collectionName = "";
    cout << "Type the name of the collection. " << endl;
    cin >> collectionName;
    Collection* newCol = new Collection(collectionName);
    cout << "Collection name is: " << newCol->getCollectionName() << endl;
    return newCol;
}
// _________ EDIT _____________________________
// todo: leggere tutte le collection e tramite un selettore scegliere quella da modificare

void createCollection(Collection* newCol){
    string collectionName;
    cout << "Type the collection name:" << endl;
    cin >> collectionName;
    Collection* newCollection = new Collection(collectionName);

}
void createNote(){
    cout << "Please choice the Collection or it'll be created one with the new name: " << endl;
    string title;
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