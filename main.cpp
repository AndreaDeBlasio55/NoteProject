#include <iostream>
#include "Headers/Note.h"
using namespace std;

int main() {

    Note myFirstNote ("Lunedì", "Spesa", "Cosa comprare alla coop");

    cout << "L'Id della nota" << myFirstNote.getTitle() << " è " << myFirstNote.getId();

    return 0;
}
