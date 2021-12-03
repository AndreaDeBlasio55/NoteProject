//
// Created by Andrea on 01/12/21.
//

#ifndef NOTEPROJECT_NOTEINTERFACE_H
#define NOTEPROJECT_NOTEINTERFACE_H

#include "CollectionNew.h"
#include "CollectionView.h"

class NoteInterface{
public:
    NoteInterface(CollectionNew* collection, CollectionView* colView);

    // HELPER FUNCTIONS
    static bool isNumber(string isNumber);

    void openMenu();
    void readNotes() const;
    void createNote();
    void changeCollection(int indexNote);
    void editNote();
    void deleteNote();

    ~NoteInterface() = default;
private:
    CollectionNew* collection;
    CollectionView* colView;
};

#endif //NOTEPROJECT_NOTEINTERFACE_H
