//
// Created by Andrea on 19/10/21.
//

#ifndef NOTEPROJECT_NOTE_H
#define NOTEPROJECT_NOTE_H

#include <iostream>
#include <string>
using namespace std;

class Note {
public:
    // CONSTRUCTOR
    Note(string collection, string title, string description);
    Note(string collection, string title, string description, bool editable);
    // METHODS
    void editTitle(string title);
    void editDescription(string description);
    void deleteNote(string noteId);
    void changeCollection(string collection);
    // GETTERS
    int getId () const;
    string getCollection ();
    string getTitle();
    string getDescription ();
    bool getEditable () const;

private:
    int noteId;
    string collection;
    string title;
    string description;
    bool editable;
};
#endif //NOTEPROJECT_NOTE_H
