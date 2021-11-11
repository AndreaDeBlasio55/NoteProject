//
// Created by Andrea on 11/11/21.
//

#ifndef NOTEPROJECT_COLLECTIONNEW_H
#define NOTEPROJECT_COLLECTIONNEW_H

#include "Subject.h"
#include "NoteNew.h"
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class CollectionNew : public Subject {
public:
    CollectionNew(string name, bool editable);
    virtual ~CollectionNew() = default;

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

    // SETTER
    void editCollectionName(string name);

    // GETTER
    string getCollectionName () const;
    int getCountNotes() const;

    // NOTES METHODS
    void readNotes () const;
    void createNote ();

private:
    string name;
    bool editable;
    vector<NoteNew *> notes;
    list <Observer*> observerNote;
};

#endif //NOTEPROJECT_COLLECTIONNEW_H
