//
// Created by Andrea on 30/11/21.
//

#ifndef NOTEPROJECT_COLLECTIONVIEWINTERFACE_H
#define NOTEPROJECT_COLLECTIONVIEWINTERFACE_H

#include <iostream>
#include <string>
#include "CollectionView.h"
using namespace std;

class CollectionViewInterface {
public:
    CollectionViewInterface(CollectionView* collectionView);

    void interfaceCreateCollection();
    void userEditCollection();
    void userDeleteCollection();

    bool isNumber(string str);
    ~CollectionViewInterface() =default;

private:
    CollectionView* collectionView;
};

#endif //NOTEPROJECT_COLLECTIONVIEWINTERFACE_H
