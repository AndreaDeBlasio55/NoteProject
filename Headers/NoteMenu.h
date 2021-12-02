//
// Created by Andrea on 01/12/21.
//

#ifndef NOTEPROJECT_NOTEMENU_H
#define NOTEPROJECT_NOTEMENU_H

#include "CollectionNew.h"

class NoteMenu{
public:
    NoteMenu(CollectionNew* collection);

    // HELPER FUNCTIONS
    static bool isNumber(string isNumber);

    void openMenu();
    void readNotes() const;
    void createNote();
    void deleteNote();

    ~NoteMenu() = default;
private:
    CollectionNew* collection;
};

#endif //NOTEPROJECT_NOTEMENU_H
