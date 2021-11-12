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
CollectionView::CollectionView():collectionSubj(){
    this->indexCollection = -1;
    //attach();
}
// METHODS
// _________ READ ___________________________
void CollectionView::readCollections() const {
    cout << "Reading Collections..." << endl;
    if (collectionSubj.size() == 0){
        cout << "There aren't collections here" << endl;
    } else {
        for (auto &collection: collectionSubj) {
            cout << boolalpha;
            cout << "\t" << collection->getCollectionName() << "\t\t editable: " << collection->getEditable() << endl;
        }
    }
}
// _________ CREATE ___________________________
void CollectionView::createCollection () {
    string collectionName = "";
    bool controllerWhileName = false;
    bool isNewCollection = true;
    bool controllerWhileEditable = false;
    string editableStr = "0";
    bool isEditable = true;
    // Manage Name
    while (!controllerWhileName) {
        cout << "Type the name of the collection. " << endl;
        getline(cin, collectionName);
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
                if (isNumber(editableStr)) {
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
    auto* newCol = new CollectionNew(collectionName, isEditable);
    collectionSubj.push_back(newCol);
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

void CollectionView::deleteCollection(){
    detach();
}
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