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
                        collection->createNote();
                    } else if (inputInt == 2) {
                        collection->editNote();
                    } else if (inputInt == 3) {
                        collection->deleteNote();
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

// HELPERS
bool CollectionNew::isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}