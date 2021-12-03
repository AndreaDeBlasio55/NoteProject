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

    // GETTERS COLLECTION
    string getCollectionName () const;
    bool getEditable () const;
    // GETTERS NOTES
    int getCountNotes() const;
    bool canEditNote(int index) const;


    // HELPER FUNCTIONS
    static bool isNumber(string isNumber);
    // NOTES METHODS
    void readNotes ();
    void createNote (string title, string description, string collection, bool editable, bool important);

    void editNote ();
    void editNoteTitle(int index, string title);
    void editNoteDescription(int index, string newDescription);
    void editNoteCollection(int index, string newCollection);
    void editNoteImportant(int index, bool newImportant);


    void deleteAllNotes();
    void deleteNote (int index);

    ~CollectionNew() override = default;

private:
    string nameCollection;
    bool editable;
    vector<NoteNew*> notes;
    list <Observer*> observerCollectionView;

};

#endif //NOTEPROJECT_COLLECTIONNEW_H
