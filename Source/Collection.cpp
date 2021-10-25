//
// Created by Andrea on 21/10/21.
//


#include <list>
#include "../Headers/Collection.h"

using namespace std;

Collection::Collection(string name) {
    this->name = name;
}
void Collection::subscribe(Observer *o) {
    observerNote.push_back(o);
}
void Collection::unsubscribe(Observer *o) {
    observerNote.remove(o);
}
void Collection::notify() {
    for (auto itr= begin(observerNote); itr!= end(observerNote); itr++){
        (*itr)->update();
    }
}
int Collection::getCountNotes () const {
    int value = 0;
    for (auto itr= begin(observerNote); itr!= end(observerNote); itr++){
        value += 1;
    }
    return value;
}
string Collection::getCollectionName() const {
    return name;
}

void Collection::setCollectionName(string collectionName) {
    cout << "Changed collection name from: " << this->name << " to: " << endl;
    this->name = collectionName;
    cout << "\t" << collectionName << endl;
    notify();
}