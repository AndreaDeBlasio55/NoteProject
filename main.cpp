#include <iostream>
#include <string>
#include "Headers/CollectionView.h"
#include "Headers/CollectionViewInterface.h"
using namespace std;

bool isNumber(string str);

int main() {

    bool controllerWhileMain = true;
    string firstInputStr = "";
    int firstInput = -1;

    CollectionView* controllerCollections = new CollectionView();
    CollectionViewInterface* inputController = new CollectionViewInterface(controllerCollections);
    while (controllerWhileMain) {
        cout << "What would you do?: "
                "\n\t0 - Read Collections"
                "\n\t1 - Create Collection"
                "\n\t2 - Edit Collection"
                "\n\t3 - Delete Collection"
                "\n\t4 - Exit" << endl;
        getline(cin, firstInputStr);
        if (firstInputStr == ""){
            cout << "Not valid input" << endl;
        } else if (isNumber(firstInputStr)) {
            firstInput = stoi(firstInputStr);
            if (firstInput == 0) {
                inputController->interfaceReadCollections();
            } else if (firstInput == 1) {
                inputController->interfaceCreateCollection();
            } else if (firstInput == 2) {
                inputController->interfaceEditCollection();
            } else if (firstInput == 3) {
                inputController->interfaceDeleteCollection();
            } else if (firstInput == 4) {
                controllerWhileMain = false;
            } else {
                cout << "Not valid input" << endl;
            }
        } else {
            cout << "No valid input" << endl;
        }
    }
    controllerCollections->summary();

    return 0;
}

bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}