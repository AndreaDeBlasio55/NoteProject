//
// Created by Andrea on 11/11/21.
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

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

    // SETTER
    void editCollectionName(string name);

    // GETTER
    string getCollectionName () const;
    int getCountNotes() const;

    // HELPER FUNCTIONS
    bool isNumber(string isNumber);
    // NOTES METHODS
    void readNotes () const;
    void createNote ();
    void editNote ();
    void deleteNote ();

    void editTitle (int indexNote, string titleNote);
    void editDescription (int indexNote, string descriptionNote);
    void editCollection(int indexNote, string collectionNote);
    void editImportant(int indexNote, bool importantNote);

    virtual ~CollectionNew() = default;

private:
    string name;
    bool editable;
    std::vector<NoteNew *> notes;
    list <Observer*> observerNote;

    int indexNote;
    string titleNote;
    string descriptionNote;
    string collectionNote;
    bool importantNote;
};

#endif //NOTEPROJECT_COLLECTIONNEW_H
