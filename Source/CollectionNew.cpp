//
// Created by Andrea on 11/11/21.
//

//
// Created by Andrea on 21/10/21.
//


#include <list>
#include "../Headers/CollectionNew.h"
using namespace std;

CollectionNew::CollectionNew(string name, bool editable) {
    this->name = name;
    this->editable = editable;
}
void CollectionNew::subscribe(Observer *o) {
    observerNote.push_back(o);
}
void CollectionNew::unsubscribe(Observer *o) {
    observerNote.remove(o);
}
void CollectionNew::notify() {
    for (auto itr= begin(observerNote); itr!= end(observerNote); itr++){
        (*itr)->update();
    }
}
// GETTERS
int CollectionNew::getCountNotes () const {
    int value = 0;
    for (auto itr= begin(observerNote); itr!= end(observerNote); itr++){
        value += 1;
    }
    return value;
}
string CollectionNew::getCollectionName() const {
    return name;
}

// SETTERS
void CollectionNew::editCollectionName(string collectionName) {
    if (this->editable) {
        cout << "Changed collection name from: " << this->name << " to: " << endl;
        this->name = collectionName;
        cout << "\t" << collectionName << endl;
        notify();
    } else {
        cout << "The Collection: " << this->name << " is not editable." << endl;
    }
}