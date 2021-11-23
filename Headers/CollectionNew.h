//
// Created by Andrea on 14/11/21.
//

#ifndef NOTEPROJECT_COLLECTIONNEW_H
#define NOTEPROJECT_COLLECTIONNEW_H

#include "Subject.h"
#include "NoteNew.h"
#include <list>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CollectionNew : public Subject {
public:
    CollectionNew(string name, bool editable);

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    // SETTER
    void editCollectionName(string name);
    void editEditable();
    void changeCollection(vector<CollectionNew*> destinationCollection);

    // GETTER
    string getCollectionName () const;
    int getCountNotes() const;
    bool getEditable () const;

    // HELPER FUNCTIONS
    bool isNumber(string isNumber);
    // NOTES METHODS
    void menuNotes();
    void readNotes ();
    void createNote ();
    void editNote ();
    void deleteAllNotes();
    void deleteNote ();

    ~CollectionNew() override = default;

private:
    string nameCollection;
    bool editable;
    vector<NoteNew*> notes;
    list <Observer*> observerCollectionView;

};

#endif //NOTEPROJECT_COLLECTIONNEW_H
