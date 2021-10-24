#include <iostream>
#include "Headers/Note.h"
#include <fstream>
#include <iomanip>
using namespace std;
#include <vector>

#include "Headers/GameCharacter.h"
#include "Headers/VideogameMapView.h"



int choice1 ();

void printNote(Note* printNote);

int choiceCollectionOrNote(int controllerStart);

void createNote();
void readCollection(vector<Collection*> col);
Collection* createCollections (vector<Collection*> col);

int main() {

    // First Question: Working on Collection or Note
    int controllerCollectionOrNote = 0;
    bool controllerWhile = false;
    controllerCollectionOrNote = choice1();
    while (!controllerWhile) {
        if (controllerCollectionOrNote != 0 && controllerCollectionOrNote != 1) {
            controllerCollectionOrNote = choice1();
        } else {
            controllerWhile = true;
        }
    }

    // --- COLLECTIONS ---
    vector<Collection *> collections;
    // Read Collection
    readCollection(collections);
    // Create Collection
    collections.push_back(createCollections(collections));
    cout << collections.size() << endl;
    // ____________________

    vector<Note *> notes;

    int controllerStart = 0;

    // First Question - READ CREATE EDIT
    cout << "What do you want to do?:" << endl;
    cout << "\t0 - Read \n\t1 - Create \n\t2 - Edit" << endl;
    cin >> controllerStart;
    int noteOrCollection = 0;
    noteOrCollection = choiceCollectionOrNote(controllerStart);


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
void readCollection (vector<Collection*> col) {
    cout << "Reading Collections..." << endl;
    for(Collection* myCollection : col){
        cout << "\t" << myCollection->getCollectionName() << endl;
    }
}
Collection* createCollections (vector<Collection*> col) {
    Collection* newCol = new Collection("Prova");
    cout << newCol->getCollectionName() << endl;
    return newCol;
}



// Secondo Choice
int choiceCollectionOrNote(int controllerStart) {
    int collectionOrNote = 0;

    if (controllerStart == 0) {
        // Second Question
        cout << "What do you want to read?" << endl;
        cout << "\t0 - Collection \n\t1 - Note" << endl;
        cin >> collectionOrNote;
    } else if (controllerStart == 1) {
        // Second Question
        cout << "What do you want to create?" << endl;
        cout << "\t0 - Collection \n\t1 - Note" << endl;
        cin >> collectionOrNote;
    } else if (controllerStart == 2) {
        // Second Question
        cout << "What do you want to edit?" << endl;
        cout << "\t0 - Collection \n\t1 - Note" << endl;
        cin >> collectionOrNote;
    } else {
        cout << "Please enter a valid input\n\t0 - Read \n\t1 - Create \n\t2 - Edit" << endl;
        cin >> controllerStart;
        choiceCollectionOrNote(controllerStart);
    }
    return controllerStart;
}


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