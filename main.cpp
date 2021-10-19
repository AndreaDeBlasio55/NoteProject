#include <iostream>
#include "Headers/Note.h"
using namespace std;

int main() {

    Note myFirstNote ("Lunedì", "Spesa", "Cosa comprare alla coop");
    Note mySecondNote ("Martedì", "Allenamento", "Quali esercizi fare");

    cout << endl;
    cout << "L'Id della nota" << myFirstNote.getTitle() << " è " << myFirstNote.getId() << endl;
    cout << endl;
    cout << "L'Id della nota" << mySecondNote.getTitle() << " è " << mySecondNote.getId() << endl;

    return 0;
}
