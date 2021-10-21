//
// Created by Andrea on 19/10/21.
//

#ifndef NOTEPROJECT_NOTE_H
#define NOTEPROJECT_NOTE_H

#include <iostream>
#include <string>
#include "Observer.h"
#include "Collection.h"
using namespace std;

class Note : public Observer{
public:

    // CONSTRUCTOR
    Note(Collection* collectionSubj, string collection, string title, string description);
    Note(Collection* collectionSubj, string collection, string title, string description, bool editable);

    // METHODS
    void editTitle(string title);
    void editDescription(string description);
    void deleteNote(int noteId);
    void editCollection(string collection);
    void editImportant(bool important);

    // GETTERS
    int getId () const;
    string getCollection ();
    string getTitle();
    string getDescription ();
    bool getEditable () const;
    bool getImportant () const;

    // OBSERVER PATTERN METHODS
    virtual void update() override;
    virtual void attach() override;

    // DESTRUCTOR
    ~Note() override= default;
private:
    int noteId;
    string collection;
    string title;
    string description;
    bool editable;
    bool important;

    Collection* collectionSubj;
};
#endif //NOTEPROJECT_NOTE_H
