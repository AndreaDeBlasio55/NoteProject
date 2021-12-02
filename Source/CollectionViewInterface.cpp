//
// Created by Andrea on 30/11/21.
//

#include <iostream>
#include "../Headers/CollectionViewInterface.h"
#include <string>
using namespace std;

CollectionViewInterface::CollectionViewInterface(CollectionView* collectionView) {
    this->collectionView = collectionView;
}

// INTERFACE READ COLLECTION
void CollectionViewInterface::interfaceReadCollections() {
    collectionView->readCollections();
}

// INTERFACE CREATE COLLECTION
void CollectionViewInterface::interfaceCreateCollection() {
    string collectionName = "Default";
    bool controllerWhileName = false;
    bool controllerWhileEditable = false;
    string editableStr = "0";
    bool isEditable = true;
    // Manage Name
    while (!controllerWhileName) {
        cout << "Type the name of the collection. " << endl;
        getline(cin, collectionName);
        if (collectionName.empty()) {
            collectionName = "Default";
        }
        // Manage Editable
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
    }
    collectionView->createCollection(collectionName, isEditable);
}

// INTERFACE CREATE COLLECTION
void CollectionViewInterface::interfaceEditCollection() {
    string valueChoice = "";
    bool validateWhile = false;
    int valueChoiceInt = 0;
    int collectionCount = collectionView->getCollectionsCount();

    collectionView->readCollections();

    cin >> valueChoice;
    while (validateWhile == false) {
        if (isNumber(valueChoice)) {
            valueChoiceInt = stoi(valueChoice);
            if (valueChoiceInt >= 0 && valueChoiceInt < collectionCount) {
                // menu edit collection
                cout
                        << "What do you want to edit? \n\t0 - Collection Name \n\t1 - Change editable \n\t2 - Notes \n\t3 - Move a note to another collection \n\tExit - use any other input"
                        << endl;
                string inputEditStr = "";
                int inputEditInt = 0;
                cin >> inputEditStr;
                if (isNumber(inputEditStr)) {
                    inputEditInt = stoi(inputEditStr);
                    if (inputEditInt == 0) {
                        cout << "Type the new name of the collection: " << endl;
                        string newNameCollection = "";
                        cin.clear();
                        cin.ignore();
                        getline(cin, newNameCollection);
                        collectionView->editCollectionName(valueChoiceInt, newNameCollection);                     // change collection name
                    } else if (inputEditInt == 1) {
                        collectionView->editEditable(valueChoiceInt);        // change editable
                        cin.ignore();
                        cin.clear();
                    } else if (inputEditInt == 2) {
                        collectionView->noteMenu(valueChoiceInt);      // open notes menu
                        cin.ignore();
                        cin.clear();
                    } else if (inputEditInt == 3) {
                        collectionView->changeCollection(valueChoiceInt);
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
                cout << "Please type a value in this range: ( 0 - " << collectionCount - 1 << " )"
                     << endl;
                cin >> valueChoice;

                cin.ignore();
                cin.clear();
            }
        } else {
            cout << "Please type a value in this range: ( 0 - " << collectionCount - 1 << " )" << endl;
            cin >> valueChoice;

            cin.ignore();
            cin.clear();
        }
    }
}

// INTERFACE DELETE COLLECTION
void CollectionViewInterface::interfaceDeleteCollection() {
    int valueChoiceInt = 0;
    string valueChoice = "";
    bool validateWhile = false;
    int collectionCounts = collectionView-> getCollectionsCount();
    cout << "Fetching Collections... Type here your choice: " << endl;
    // get all the collections name
    collectionView->readCollections();
    cin >> valueChoice;
    while (validateWhile == false) {
        if (isNumber(valueChoice)) {
            valueChoiceInt = stoi(valueChoice);
            if (valueChoiceInt >= 0 && valueChoiceInt < collectionCounts) {
                validateWhile = true;
                collectionView->deleteCollection(valueChoiceInt);
                //indexCollection = valueChoiceInt;
            } else {
                cout << "Please type a value in this range: ( 0 - " << collectionCounts - 1 << " )" << endl;
                cin >> valueChoice;
            }
        } else {
            cout << "Please type a value in this range: ( 0 - " << collectionCounts - 1 << " )" << endl;
            cin >> valueChoice;
        }
    }
    cin.ignore();
    cin.clear();
}

// HELPER
bool CollectionViewInterface::isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}