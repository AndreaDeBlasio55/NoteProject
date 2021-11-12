//
// Created by Andrea on 12/11/21.
//

#ifndef NOTEPROJECT_COLLECTIONVIEW_H
#define NOTEPROJECT_COLLECTIONVIEW_H

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
    void deleteCollection();
    static bool isNumber(string str);

    // OBSERVER PATTERN METHODS
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

    // DESTRUCTOR
    ~CollectionView() override= default;
private:
    int indexCollection;
    vector<CollectionNew*> collectionSubj;
};
#endif //NOTEPROJECT_COLLECTIONVIEW_H