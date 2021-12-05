//
// Created by Andrea on 11/11/21.
//

#ifndef NOTEPROJECT_NOTE_H
#define NOTEPROJECT_NOTE_H

//
// Created by Andrea on 19/10/21.
//

#include <iostream>
#include <string>
#include "Observer.h"
//#include "Collection.h"
using namespace std;

class Note{
public:

    // CONSTRUCTOR
    Note(string title, string description, string collection, bool important, bool editable);

    // GETTERS
    int getId () const;
    string getCollection () const;
    string getTitle() const;
    string getDescription () const;
    bool getEditable () const;
    bool getImportant () const;

    // SETTERS
    void editTitle (string title);
    void editDescription (string description);
    void editImportant (bool important);
    void editCollection (string collection);
    // DESTRUCTOR
    ~Note();
private:
    int noteId;
    string collection;
    string title;
    string description;
    bool editable;
    bool important;
};

#endif //NOTEPROJECT_NOTE_H
