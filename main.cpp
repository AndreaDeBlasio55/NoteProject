#include <iostream>
#include "Headers/Note.h"
using namespace std;

int main() {

    Note* myFirstNotePtr = new Note("Importanti", "Spesa", "Cosa comprare alla coop", false);
    Note myFirstNote ("Lunedì", "Spesa", "Cosa comprare alla coop");
    Note mySecondNote ("Martedì", "Allenamento", "Quali esercizi fare");

    cout << boolalpha << endl;

    cout << "L'Id della nota" << myFirstNote.getTitle() << " è " << myFirstNote.getId() << "- editable: " << myFirstNote.getEditable() << endl;
    cout << endl;

    cout << "L'Id della nota" << mySecondNote.getTitle() << " è " << mySecondNote.getId() << "- editable: " << mySecondNote.getEditable() << endl;
    cout << endl;

    cout << "Nota con puntatori - Id: " << myFirstNotePtr->getId()
    << " - editable: " << myFirstNotePtr->getEditable()
    << " - Title: " << myFirstNotePtr->getTitle()
    << " - important: "  << myFirstNotePtr->getImportant()
    << endl;

    myFirstNotePtr->changeImportant(true);
    cout << "Cambio importanza di una nota: " << " - important: " << myFirstNotePtr->getImportant() << endl;

    delete myFirstNotePtr;

    myFirstNotePtr = nullptr;

    return 0;
}
