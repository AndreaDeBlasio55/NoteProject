//
// Created by Andrea on 12/11/21.
//

//
// Created by Andrea on 19/10/21.
//
#include <iostream>
#include "../Headers/CollectionView.h"
#include <string>

using namespace std;

// CONSTRUCTOR
CollectionView::CollectionView() : collectionSubj(){
    this->indexCollection = -1;
    //attach();
}

// METHODS
// _________ READ ___________________________
void CollectionView::readCollections(){
    cout << "Reading Collections..." << endl;
    if (collectionSubj.empty()) {
        cout << "There aren't collections here" << endl;
    } else {
        for (int i=0; i<collectionSubj.size(); i++) {
            cout << boolalpha;
            cout << i << " - " << collectionSubj[i]->getCollectionName() << "\t\t editable: " << collectionSubj[i]->getEditable() << endl;
        }
        readCollectionNotes();
    }
}

void CollectionView::readCollectionNotes(){
    cout << "Select one of the collections to read the notes or press any other input to exit" << endl;
    string inputStr = "";
    cin >> inputStr;
    if (inputStr.length() == 0){
        cout << "Exit" << endl;
    } else if (isNumber(inputStr)){
        int inputInt = 0;
        inputInt = stoi(inputStr);
        if (inputInt >= 0 && inputInt < collectionSubj.size()){
            cout << collectionSubj[inputInt]->getCollectionName() << " selected!" << endl;
            // todo: read all notes here
            collectionSubj[inputInt]->readNotes();
        }
    } else {
        cout << "Exit" << endl;
    }
    cin.ignore();
    cin.clear();
}
// _________ CREATE ___________________________
void CollectionView::createCollection(){
    string collectionName = "Default";
    bool controllerWhileName = false;
    bool controllerWhileEditable = false;
    string editableStr = "0";
    bool isEditable = true;
    // Manage Name
    while (!controllerWhileName) {
        bool isNewCollection = true;
        cout << "Type the name of the collection. " << endl;
        getline(cin, collectionName);
        if (collectionName == ""){
            collectionName = "Default";
        }
        for (int i = 0; i < collectionSubj.size(); i++) {
            if (collectionName == collectionSubj[i]->getCollectionName()) {
                cout << "This name is already taken, try another name." << endl;
                isNewCollection = false;
            }
        }
        // Manage Editable
        if (isNewCollection == true) {
            controllerWhileName = true;
            while (!controllerWhileEditable) {
                cout << "Editable? \n\t0 - false \n\t1 - true" << endl;
                getline(cin, editableStr);
                if (editableStr == "") {
                    cout << "Not valid input... valide range ( 0 - 1 )" << endl;
                } else if (isNumber(editableStr)) {
                    int inputInt = stoi(editableStr);
                    if (inputInt == 0) {
                        isEditable = false;
                        controllerWhileEditable = true;
                    } else if (inputInt == 1) {
                        isEditable = true;
                        controllerWhileEditable = true;
                    } else {
                        cout << "Please type a valid input" << endl;
                    }
                } else {
                    cout << "Please type a number input" << endl;
                }
            }
        } else {
            controllerWhileName = false;
        }
    }
    CollectionNew* newCol = new CollectionNew(collectionName, isEditable);
    collectionSubj.push_back(newCol);

    attach();
}
// _________ EDIT ___________________________
void CollectionView::editCollection() {
    string valueChoice = "";
    bool validateWhile = false;
    int valueChoiceInt = 0;


    if (collectionSubj.empty()) {
        cout << "There aren't collections here." << endl;
    } else {
        cout << "Please select a collection to edit:" << endl;
        for (int i=0; i<collectionSubj.size(); i++) {
            cout << boolalpha;
            cout << i << " - " << collectionSubj[i]->getCollectionName() << "\t\t editable: " << collectionSubj[i]->getEditable() << endl;
        }
        cin >> valueChoice;
        while (validateWhile == false) {
            if (isNumber(valueChoice)) {
                valueChoiceInt = stoi(valueChoice);
                if (valueChoiceInt >= 0 && valueChoiceInt < collectionSubj.size()) {
                    // menu edit collection
                        cout<< "What do you want to edit? \n\t0 - Collection Name \n\t1 - Change editable \n\t2 - Notes \n\t3 - Move a note to another collection \n\tExit - use any other input"<< endl;
                        string inputEditStr = "";
                        int inputEditInt = 0;
                        cin >> inputEditStr;
                        if (isNumber(inputEditStr)) {
                            inputEditInt = stoi(inputEditStr);
                            if (inputEditInt == 0) {
                                editCollectionName(valueChoiceInt);
                            } else if (inputEditInt == 1) {
                                collectionSubj[valueChoiceInt]->editEditable();
                                cin.ignore();
                                cin.clear();
                            } else if (inputEditInt == 2) {
                                collectionSubj[valueChoiceInt]->menuNotes();
                                cin.ignore();
                                cin.clear();
                            } else if (inputEditInt == 3) {
                                collectionSubj[valueChoiceInt]->changeCollection(collectionSubj);
                                cin.ignore();
                                cin.clear();
                            } else {
                                cin.ignore();
                                cin.clear();
                                cout << "Exit" << endl;
                            }
                        } else {
                            cin.ignore();
                            cin.clear();
                            cout << "Exit" << endl;
                        }

                    validateWhile = true;
                } else {
                    cout << "Please type a value in this range: ( 0 - " << collectionSubj.size() - 1 << " )"
                         << endl;
                    cin >> valueChoice;

                    cin.ignore();
                    cin.clear();
                }
            } else {
                cout << "Please type a value in this range: ( 0 - " << collectionSubj.size() - 1 << " )" << endl;
                cin >> valueChoice;

                cin.ignore();
                cin.clear();
            }
        }
    }
}

void CollectionView::editCollectionName(int index) {
    string oldNameCollection = collectionSubj[index]->getCollectionName();
    cout << "Type the new name of the collection: ( " << oldNameCollection << " )" << endl;
    string newNameCollection = "";
    cin.ignore();
    getline(cin, newNameCollection);
    collectionSubj[index]->editCollectionName(newNameCollection);
    /*
    // Updating all Notes:
    for (Note *myCurrentNote: notes) {
        if (myCurrentNote->getCollection() == oldNameCollection) {
            myCurrentNote->editCollection(newNameCollection);
            cout << "Updating the note: \n\t "
                 << " - " << myCurrentNote->getTitle()
                 << " - " << myCurrentNote->getId() << endl;
        }
    }
     */
    cout << "Completed!" << endl;
}

// _________ DELETE ___________________________
void CollectionView::deleteCollection() {
    int valueChoiceInt = 0;
    string valueChoice = "";
    bool validateWhile = false;
    cout << "Fetching Collections..." << endl;
    for (int i=0; i<collectionSubj.size(); i++) {
        cout << "\t" << i << " - " << collectionSubj[i]->getCollectionName() << "\t editable: " << collectionSubj[i]->getEditable() << endl;
    }
    if (collectionSubj.empty()){
        cout << "There isn't Collection to delete." << endl;
    } else {
        cout << "Type here your choice: " << endl;
        cin >> valueChoice;
        while (validateWhile == false) {
            if (isNumber(valueChoice)) {
                valueChoiceInt = stoi(valueChoice);
                if (valueChoiceInt >= 0 && valueChoiceInt < collectionSubj.size()) {
                    validateWhile = true;
                    if (collectionSubj[valueChoiceInt]->getEditable()) {

                        detach();

                        collectionSubj.erase(collectionSubj.begin() + valueChoiceInt);
                        indexCollection = valueChoiceInt;
                        //detach();
                    } else {
                        cout << "This collection isn't editable" << endl;
                    }
                    indexCollection = valueChoiceInt;
                } else {
                    cout << "Please type a value in this range: ( 0 - " << collectionSubj.size() - 1 << " )" << endl;
                    cin >> valueChoice;
                }
            } else {
                cout << "Please type a value in this range: ( 0 - " << collectionSubj.size() - 1 << " )" << endl;
                cin >> valueChoice;
            }
        }
    }
    cin.ignore();
    cin.clear();

}

// OBSERVER METHODS

void CollectionView::attach() {
    this->countCollections = collectionSubj.size();
    collectionSubj[countCollections-1]->subscribe(this);
}

void CollectionView::detach() {
    this->countCollections = collectionSubj.size();
    collectionSubj[countCollections-1]->unsubscribe(this);
}

void CollectionView::update() {
    for (int i=0; i<collectionSubj.size(); i++){
        int value = collectionSubj[i]->getCountNotes();
        countNotes.push_back(value);
        cout << "\t" << collectionSubj[i]->getCollectionName() << " has " << countNotes[i] <<" notes "<< endl;
    }
}

void CollectionView::summary(){
    cout << "Summary: " << endl;
    update();

}
// GETTERS

// SETTERS

/*
void CollectionView::editCollection(bool important) {

}
void CollectionView::editCollectionSubject(Collection *collectionSubj) {
    if (editable) {
        this->collectionSubj = collectionSubj;
    } else {
        cout << "Edit collectionSubject failed: This note is not editable..." << endl;
    }
}

void CollectionView::assignNewCollectionSubj(CollectionNew *newCollectionSubject) {
    detach();
    this->collectionSubj = newCollectionSubject;
    attach();
}
 */
// HELPERS
bool CollectionView::isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}