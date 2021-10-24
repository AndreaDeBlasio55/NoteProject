#include <iostream>
#include "Headers/Note.h"
#include <fstream>
#include <iomanip>
using namespace std;

#include "Headers/GameCharacter.h"
#include "Headers/VideogameMapView.h"

void printNote(Note* printNote);

void choiceCollectionOrNote(int controllerStart);

int main() {

    int controllerStart = 0;

    // First Question - READ CREATE EDIT
    enum ControllerChoice1 {READ, CREATE, EDIT};
    cout << "What do you want to do?:" << endl;
    cout << "\t0 - Read \n\t1 - Create \n\t2 - Edit" << endl;
    cin >> controllerStart;
    choiceCollectionOrNote(controllerStart);

    // Second Question - Action to: COLLECTION or NOTE
    enum ControllerChoice2 {COLLECTION, NOTE};

    // get Notes count data from input.txt
    ifstream inputFile;
    inputFile.open("/Users/andrea/CLionProjects/NoteProject/Output/input.txt");
    int notesCount = 0;
    inputFile >> notesCount;
    inputFile.close();
    cout << "Notes: " << notesCount << endl;
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
    GameCharacter* gc1 = new GameCharacter(1,3);
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

// Secondo Choice
void choiceCollectionOrNote(int controllerStart){
    enum CollectionOrNote {COLLECTION, NOTE};
    int collectionOrNote = 0;

    if (controllerStart == 0){
        // Second Question
        cout << "What do you want to read?" << endl;
        cout << "\t0 - Collection \n\t1 - Note" << endl;
        cin >> collectionOrNote;
    }
    else if (controllerStart == 1){
        // Second Question
        cout << "What do you want to create?" << endl;
        cout << "\t0 - Collection \n\t1 - Note" << endl;
        cin >> collectionOrNote;
    }
    else if (controllerStart == 2){
        // Second Question
        cout << "What do you want to edit?" << endl;
        cout << "\t0 - Collection \n\t1 - Note" << endl;
        cin >> collectionOrNote;
    } else {
        cout << "Please enter a valid input\n\t0 - Read \n\t1 - Create \n\t2 - Edit" << endl;
        cin >> controllerStart;
        choiceCollectionOrNote(controllerStart);
    }
}

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