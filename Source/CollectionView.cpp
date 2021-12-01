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
    this->countCollections = 0;
    //this->indexCollection = -1;
    //attach();
}

// METHODS
// _________ READ ___________________________
void CollectionView::readCollections(){
    if (collectionSubj.empty()) {
        cout << "There aren't collections here" << endl;
    } else {
        for (int i=0; i<collectionSubj.size(); i++) {
            cout << boolalpha;
            cout << i << " - " << collectionSubj[i]->getCollectionName() << "\t\t editable: " << collectionSubj[i]->getEditable() << endl;
        }
        //readCollectionNotes();
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

// _________ CREATE ___________________________ DONE
void CollectionView::createCollection(string collectionName, bool isEditable){
    bool isNewCollection = true;

    if (!collectionSubj.empty()) {
        for (int i = 0; i < collectionSubj.size(); i++) {
            if (collectionName == collectionSubj[i]->getCollectionName()) {
                isNewCollection = false;
            }
        }
    }
    if (isNewCollection) {
        CollectionNew *newCol = new CollectionNew(collectionName, isEditable);
        collectionSubj.push_back(newCol);
    } else {
        cout << "This name is already used, try to create another collection" << endl;
    }
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
                                editCollectionName(valueChoiceInt);                     // change collection name
                            } else if (inputEditInt == 1) {
                                collectionSubj[valueChoiceInt]->editEditable();         // change editable
                                cin.ignore();
                                cin.clear();
                            } else if (inputEditInt == 2) {
                                collectionSubj[valueChoiceInt]->menuNotes();            // open notes menu
                                cin.ignore();
                                cin.clear();
                            } else if (inputEditInt == 3) {
                                if (collectionSubj[valueChoiceInt]->getEditable()) {
                                    collectionSubj[valueChoiceInt]->changeCollection(collectionSubj);   // change the collection of a note
                                    cin.ignore();
                                    cin.clear();
                                } else {
                                    cout << "The Collection: " << collectionSubj[valueChoiceInt]->getCollectionName() << " isn't editable" << endl;
                                    cin.ignore();
                                    cin.clear();
                                }
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
    if (collectionSubj[index]->getEditable()) {
        cout << "Type the new name of the collection: ( " << oldNameCollection << " )" << endl;
        string newNameCollection = "";
        bool newName = true;
        cin.clear();
        cin.ignore();
        getline(cin, newNameCollection);
        for (int i = 0; i < collectionSubj.size(); i++) {
            if (newNameCollection == collectionSubj[i]->getCollectionName()) {
                newName = false;
            }
        }
        if (newName) {
            collectionSubj[index]->editCollectionName(newNameCollection);
        } else {
            cout << "The name is already taken." << endl;
            cin.clear();
            cin.ignore();
        }
    } else {
        cout << "The Collection: " << oldNameCollection << " is not editable." << endl;
        cin.clear();
        cin.ignore();
    }
}
void CollectionView::editEditable(int index){
    collectionSubj[index]->editEditable();
}

// _________ DELETE ___________________________
void CollectionView::deleteCollection(int index) {
    if (collectionSubj[index]->getEditable()) {
        detach();
        // release memory
        collectionSubj[index]->deleteAllNotes();
        delete collectionSubj[index];
        collectionSubj[index] = nullptr;
        // ---
        collectionSubj.erase(collectionSubj.begin() + index);
        //indexCollection = valueChoiceInt;
        //detach();
    } else {
        cout << "This collection isn't editable" << endl;
    }
}

int CollectionView::getCollectionsCount (){
    int collectionCount = 0;
    collectionCount = collectionSubj.size();
    return collectionCount;
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

// ------------

void CollectionView::summary(){
    cout << "Summary: " << endl;
    update();
    cleanMemory();
}

void CollectionView::cleanMemory() {
    for (int i=0; i<collectionSubj.size(); i++){
        collectionSubj[i]->deleteAllNotes();
        cout << "Deleted " << collectionSubj[i]->getCollectionName() << endl;
        delete collectionSubj[i];
        collectionSubj[i] = nullptr;
    }

}

// HELPER
bool CollectionView::isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}