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
CollectionView::CollectionView() : collectionSubj() {
    this->indexCollection = -1;
    //attach();
}

// METHODS
// _________ READ ___________________________
void CollectionView::readCollections() const {
    cout << "Reading Collections..." << endl;
    if (collectionSubj.empty()) {
        cout << "There aren't collections here" << endl;
    } else {
        for (auto &collection: collectionSubj) {
            cout << boolalpha;
            cout << "\t" << collection->getCollectionName() << "\t\t editable: " << collection->getEditable() << endl;
        }
    }
}

// _________ CREATE ___________________________
void CollectionView::createCollection() {
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
    auto *newCol = new CollectionNew(collectionName, isEditable);
    collectionSubj.push_back(newCol);
}

// _________ EDIT ___________________________


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
                        collectionSubj.erase(collectionSubj.begin() + valueChoiceInt);
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
    collectionSubj[indexCollection]->subscribe(this);
}

void CollectionView::detach() {
    collectionSubj[indexCollection]->unsubscribe(this);
}

void CollectionView::update() {

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