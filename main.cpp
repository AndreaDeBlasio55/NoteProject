#include <iostream>
#include "Headers/Note.h"
#include <fstream>
#include <iomanip>
using namespace std;

#include "Headers/GameCharacter.h"

void printNote(Note* printNote);

int main() {

    // get Notes count data from input.txt
    ifstream inputFile;
    inputFile.open("/Users/andrea/CLionProjects/NoteProject/Output/input.txt");
    int notesCount = 0;
    inputFile >> notesCount;
    inputFile.close();
    cout << "Notes: " << notesCount << endl;

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

    GameCharacter* gc = new GameCharacter(0,0);
    GameCharacter* gc2 = new GameCharacter(2,5);

    cout << "Posizione personaggio x: " << gc->getPosX() << endl;
    cout << "Posizione personaggio y: " << gc->getPosY() << endl;
    cout << "Posizione personaggio x: " << gc2->getPosX() << endl;
    cout << "Posizione personaggio y: " << gc2->getPosY() << endl;

    return 0;
}


void printNote(Note* printNote){
    cout << boolalpha << endl;
    cout << "Title: " << printNote->getTitle()
         << "\n     - Id: " << printNote->getId()
         << "\n     - description: " << printNote->getDescription()
         << "\n     - editable: " << printNote->getEditable()
         << "\n     - important: "  << printNote->getImportant()
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