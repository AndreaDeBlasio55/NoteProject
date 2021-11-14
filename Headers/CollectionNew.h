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
    void deleteNote ();

    /*
    void editTitle (int indexNote, string titleNote);
    void editDescription (int indexNote, string descriptionNote);
    void editCollection(int indexNote, string collectionNote);
    void editImportant(int indexNote, bool importantNote);
*/
    ~CollectionNew() override = default;

private:
    string nameCollection;
    bool editable;
    vector<NoteNew *> notes;
    list <Observer*> observerNote;

};

#endif //NOTEPROJECT_COLLECTIONNEW_H
