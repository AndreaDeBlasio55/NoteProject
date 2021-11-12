//
// Created by Andrea on 19/10/21.
//

#ifndef NOTEPROJECT_NOTE_H
#define NOTEPROJECT_NOTE_H

#include <iostream>
#include <string>
#include "Observer.h"
#include "CollectionNew.h"
using namespace std;

class CollectionView : public Observer{
public:

    // CONSTRUCTOR
    CollectionView();

    // METHODS


    // GETTERS
    void readCollections() const;
    void createCollection();
    static bool isNumber(string str);

    // OBSERVER PATTERN METHODS
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

    // DESTRUCTOR
    ~CollectionView() override= default;
private:
    vector<CollectionNew*> collectionSubj;
};
#endif //NOTEPROJECT_NOTE_H