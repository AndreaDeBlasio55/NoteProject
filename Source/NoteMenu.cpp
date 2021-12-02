//
// Created by Andrea on 01/12/21.
//

#include "../Headers/NoteMenu.h"
#include <string>
using namespace std;


NoteMenu::NoteMenu(CollectionNew *collection) {
    this->collection = collection;
}

void NoteMenu::openMenu() {
    if (collection->getEditable()) {
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
            if (inputStr.empty()) {
                cout << "Not valid input" << endl;
            } else {
                if (isNumber(inputStr)) {
                    inputInt = stoi(inputStr);
                    if (inputInt == 0) {
                        collection->readNotes();
                    } else if (inputInt == 1) {
                        createNote();
                    } else if (inputInt == 2) {
                        collection->editNote();
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
    } else {
        cout << "The Collection: " << collection->getCollectionName() << " isn't editable" << endl;
    }
}

// -------------- CREATE --------------
void NoteMenu::createNote () {
    string title = "";
    string description = " ";
    string collection = this->collection->getCollectionName();

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
    this->collection->createNote(title, description,collection, editable, important);
}

void NoteMenu::deleteNote () {
    cout << boolalpha << endl;
    bool validateWhile = false;
    int notesCount = collection->getCountNotes();
    if (notesCount == 0) {
        cout << "There aren't notes to delete" << endl;
    } else {
        int indexFor = 0;
        int valueChoice = -1;
        string valueChoiceStr = "-1";
        cout << "Please select one of these notes: " << endl;

        // getting notes
        collection->readNotes();

        cin >> valueChoiceStr;
        while (validateWhile == false) {
            if (isNumber(valueChoiceStr)) {
                valueChoice = stoi(valueChoiceStr);
                if (valueChoice >= 0 && valueChoice < notesCount) {
                    validateWhile = true;
                } else {
                    cout << "Please type a valid input in this range: ( 0 - " << notesCount-1 << " )"<< endl;
                    cin >> valueChoiceStr;
                }
            } else {
                cout << "Please type a valid input in this range: ( 0 - " << notesCount-1 << " )"<< endl;
                cin >> valueChoiceStr;
            }
        }
        collection->deleteNote(valueChoice);
    }
}
// HELPERS
bool NoteMenu::isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}