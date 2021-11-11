//
// Created by Andrea on 11/11/21.
//

#ifndef NOTEPROJECT_NOTENEW_H
#define NOTEPROJECT_NOTENEW_H

//
// Created by Andrea on 19/10/21.
//

#include <iostream>
#include <string>
#include "Observer.h"
#include "CollectionNew.h"
using namespace std;

class NoteNew{
public:

    // CONSTRUCTOR
    NoteNew(Collection* collectionSubj, string title, string description);
    NoteNew(Collection* collectionSubj, string title, string description, bool editable);

    // GETTERS
    int getId () const;
    string getCollection () const;
    string getTitle() const;
    string getDescription () const;
    bool getEditable () const;
    bool getImportant () const;


    // DESTRUCTOR
    ~NoteNew() override= default;
private:
    int noteId;
    string collection;
    string title;
    string description;
    bool editable;
    bool important;
};

#endif //NOTEPROJECT_NOTENEW_H