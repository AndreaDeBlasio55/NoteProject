//
// Created by Andrea on 01/12/21.
//

#include "../Headers/NoteInterface.h"
#include <string>
using namespace std;


NoteInterface::NoteInterface(CollectionNew *collection) {
    this->collection = collection;
}

void NoteInterface::openMenu() {
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
                        readNotes();
                    } else if (inputInt == 1) {
                        createNote();
                    } else if (inputInt == 2) {
                        editNote();
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

// -------------- READ --------------
void NoteInterface::readNotes () const{
    collection->readNotes();
}
// -------------- CREATE --------------
void NoteInterface::createNote () {
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
// -------------- EDIT --------------
void NoteInterface::editNote () {
    cout << boolalpha << endl;
    bool validateWhile = false;
    bool validateWhile2 = false;
    bool validateWhile3 = false;
    string valueChoiceStr = "-1";
    int notesCount = collection->getCountNotes();
    cout << "Fetching Notes..." << endl;
    if (notesCount == 0) {
        cout << "There is no Note to edit." << endl;
    } else {
        int valueChoice = -1;
        cout << "Please select one of these notes: " << endl;
        readNotes();
        // Select the note
        cin >> valueChoiceStr;
        while (validateWhile == false) {
            if (isNumber(valueChoiceStr)) {
                valueChoice = stoi(valueChoiceStr);
                if (valueChoice >= 0 && valueChoice < notesCount) {
                    validateWhile = true;
                } else {
                    cout << "Please type here your choice in this range: ( 0 - " << notesCount - 1 << " )" << endl;
                    cin >> valueChoiceStr;

                }
            } else {
                cout << "Please type here your choice in this range: ( 0 - " << notesCount - 1 << " )" << endl;
                cin >> valueChoiceStr;
            }
        }
        // Check if we can edit this note:
        bool canEditNote = false;
        canEditNote = collection->getNoteEditable(valueChoice);
        if (canEditNote) {
            cout << "What do you want to edit: "
                 << "\n\t0 - Title "
                 << "\n\t1 - Description "
                 << "\n\t2 - Important "
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
                        cout << "Please type the new TITLE: " << endl;
                        cin.ignore();
                        getline(cin, title);
                        this->collection->editNoteTitle(valueChoice, title);
                        validateWhile2 = true;
                    } else if (valueNoteEdit == 1) {
                        cout << "Please type the new DESCRIPTION: " << endl;
                        cin.ignore();
                        getline(cin, description);
                        this->collection->editNoteDescription(valueChoice, description);
                        validateWhile2 = true;
                    } else if (valueNoteEdit == 2) {
                        cout << "Please type the new IMPORTANT: " << "\n\t0 - false \n\t1 - true " << endl;
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
                        this->collection->editNoteImportant(valueChoice, importantBool);
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
}
// -------------- DELETE --------------
void NoteInterface::deleteNote () {
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
bool NoteInterface::isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

void NoteInterface::changeCollection(int indexNote, vector<CollectionNew*> destinationCollection) {
    bool validatorWhile = false;
    int notesCount = collection->getCountNotes();

    // FETCHING NOTE DATA
    int id = collection->getNoteId();
    string title = collection->getNoteTitle();
    string description = collection->getNoteDescription();
    string newCollection = collection->getNoteCollection();
    bool important = collection->getNoteImportant();
    bool editable = collection->getNoteEditable();

    if (collection->getEditable()) {
        if (notesCount > 0) {
            while (!validatorWhile) {
                string indexNoteStr = "";
                int indexNote = -1;
                cout << "Please select the note you want to move" << endl;
                collection->readNotes();
                cin >> indexNoteStr;
                if (isNumber(indexNoteStr)) {
                    indexNote = stoi(indexNoteStr);
                    if (indexNote >= 0 && indexNote < notesCount) {
                        cout << collection->getNoteTitle(indexNote) << " Selected!" << endl;
                        if (collection->getNoteEditable(indexNote)) {
                            //currentNoteSelected = notes[indexNote];
                            validatorWhile = true;

                            string destinationCollectionStr = "";
                            cout << "Type the index of the destination or another value to exit:" << endl;
                            int currentIndexCollection = -1;



                            for (int i = 0; i < destinationCollection.size(); i++) {
                                if (destinationCollection[i]->getCollectionName() == nameCollection) {
                                    currentIndexCollection = i;
                                    cout << i << " - " << destinationCollection[i]->getCollectionName()
                                         << " - The note is here " << endl;
                                } else {
                                    cout << i << " - " << destinationCollection[i]->getCollectionName() << endl;
                                }
                            }
                            cin >> destinationCollectionStr;
                            if (isNumber(destinationCollectionStr)) {
                                int destinationInt = stoi(destinationCollectionStr);
                                if (destinationCollection[destinationInt]->getEditable()) {
                                    destinationCollection[destinationInt]->notes.push_back(currentNoteSelected);
                                    cout << "Moved to " << destinationCollection[destinationInt]->getCollectionName()
                                         << " from: " << nameCollection << endl;
                                    notes.erase(notes.begin() + indexNote);
                                    validatorWhile = true;
                                    notify();
                                } else {
                                    cout << "Target collection is not editable, you can't add/edit/delete notes" << endl;
                                }
                            } else {
                                cout << "Exit" << endl;
                                validatorWhile = true;
                            }
                        } else {
                            cout << "This note is not editable - It can be edit/deleted only deleting the collection: " << nameCollection << endl;
                            validatorWhile = false;
                        }
                    } else {
                        cout << "Wrong input" << endl;
                        validatorWhile = false;
                    }
                } else {
                    cout << "Wrong input" << endl;
                    validatorWhile = false;
                }
            }
        } else {
            cout << "There aren't notes here" << endl;
        }
    } else {
        cout << "Collection note editable" << endl;
    }
}