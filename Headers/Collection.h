//
// Created by Andrea on 14/11/21.
//

#ifndef NOTEPROJECT_COLLECTION_H
#define NOTEPROJECT_COLLECTION_H

#include "Subject.h"
#include "Note.h"
#include <list>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Collection : public Subject {
public:
    Collection(string name, bool editable);

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    // SETTER
    void editCollectionName(string name);
    void editEditable();

    // GETTERS COLLECTION
    string getCollectionName () const;
    bool getEditable () const;

    // GETTERS NOTES
    int getCountNotes() const;
    string getNoteTitle(int index) const;
    string getNoteDescription(int index) const;
    string getNoteCollection(int index) const;
    bool getNoteImportant(int index) const;
    bool getNoteEditable(int index) const;

    // NOTES METHODS
    void readNotes ();
    void createNote (string title, string description, string collection, bool important, bool editable);

    void editNoteTitle(int index, string title);
    void editNoteDescription(int index, string newDescription);
    void editNoteImportant(int index, bool newImportant);


    void deleteAllNotes();
    void deleteNote (int index);

    ~Collection() override = default;

private:
    string nameCollection;
    bool editable;
    vector<Note*> notes;
    list <Observer*> observerCollectionView;

};

#endif //NOTEPROJECT_COLLECTION_H
