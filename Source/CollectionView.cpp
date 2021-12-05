//
// Created by Andrea on 12/11/21.
//

//
// Created by Andrea on 19/10/21.
//
#include <iostream>
#include "../Headers/CollectionView.h"
#include "../Headers/NoteInterface.h"
#include <string>

using namespace std;

// CONSTRUCTOR
CollectionView::CollectionView() : collectionSubj(){
    this->countCollections = 0;
}

// METHODS
// _________ READ ___________________________
void CollectionView::readCollections() const{
    if (collectionSubj.empty()) {
        cout << "There aren't collections here" << endl;
    } else {
        for (int i=0; i<collectionSubj.size(); i++) {
            cout << boolalpha;
            cout << i << " - " << collectionSubj[i]->getCollectionName() << "\t\t editable: " << collectionSubj[i]->getEditable() << endl;
        }
    }
}

// _________ CREATE _________________________
void CollectionView::createCollection(string collectionName, bool isEditable) {
    bool isNewCollection = true;

    if (!collectionSubj.empty()) {
        for (int i = 0; i < collectionSubj.size(); i++) {
            if (collectionName == collectionSubj[i]->getCollectionName()) {
                isNewCollection = false;
            }
        }
    }
    if (isNewCollection) {
        Collection *newCol = new Collection(collectionName, isEditable);
        collectionSubj.push_back(newCol);
    } else {
        cout << "This name is already used, try to create another collection" << endl;
    }
    attach();
}

// --------- EDIT ---------------------------
void CollectionView::editCollectionName(int index, string newNameCol)  {
    string oldNameCollection = collectionSubj[index]->getCollectionName();
    if (collectionSubj[index]->getEditable()) {
        string newNameCollection = newNameCol;
        bool newName = true;
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

    }
}
void CollectionView::editEditable(int index)  {
    collectionSubj[index]->editEditable();
}

void CollectionView::changeCollectionNew(int indexSender, int indexReceiver, int indexNote, string title, string description, bool important, bool editable)  {
    string collectionReceiver = collectionSubj[indexReceiver]->getCollectionName();
    collectionSubj[indexReceiver]->createNote(title, description, collectionReceiver, important, editable);
    collectionSubj[indexSender]->deleteNote(indexNote);
}

// _________ DELETE ___________________________
void CollectionView::deleteCollection(int index)  {
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

// _________ GETTERS ___________________________
int CollectionView::getCollectionsCount () const{
    int collectionCount = 0;
    collectionCount = collectionSubj.size();
    return collectionCount;
}
bool CollectionView::getCollectionEditable (int index) const{
    return collectionSubj[index]->getEditable();
}
int CollectionView::getIndexCollectionSender(string collectionName) const{
    int indexCollection = 0;
    for (int i=0; i<collectionSubj.size(); i++){
        if (collectionSubj[i]->getCollectionName() == collectionName){
            indexCollection = i;
            return indexCollection;
        }
    }
    return indexCollection;
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

CollectionView::~CollectionView(){
    for (int i=0; i<collectionSubj.size(); i++){
        collectionSubj[i]->deleteAllNotes();
        delete collectionSubj[i];
        collectionSubj[i] = nullptr;
    }
}

void CollectionView::summary(){
    cout << "Summary: " << endl;
    update();
}

// INTERFACE MENU
void CollectionView::noteMenu(int index) {
    NoteInterface* noteMenu = new NoteInterface(collectionSubj[index], this);
    noteMenu->openMenu();
}
