//
// Created by Andrea on 12/11/21.
//

#ifndef NOTEPROJECT_COLLECTIONVIEW_H
#define NOTEPROJECT_COLLECTIONVIEW_H

#include <iostream>
#include <string>
#include "Observer.h"
#include "Collection.h"
using namespace std;

class CollectionView : public Observer{
public:

    // CONSTRUCTOR
    CollectionView();

    // METHODS
    void readCollections() const;
    int getIndexCollectionSender(string collectionName) const;

    void createCollection(string collectionName, bool isEditable);

    void editCollectionName(int value, string newNameCol) ;
    void editEditable(int index) ;
    void changeCollectionNew(int indexSender, int indexReceiver, int indexNote, string title, string description, bool important, bool editable) ;
    //void changeCollection(int index);

    int getCollectionsCount() const;
    bool getCollectionEditable(int index) const;
    void deleteCollection(int index);

    void noteMenu(int index);
    void cleanMemory();

    void summary();

    // OBSERVER PATTERN METHODS
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

    // DESTRUCTOR
    ~CollectionView() override;
private:
    //int indexCollection;
    int countCollections;                         // to manage attach and detach
    vector<int> countNotes;                       // to know how many notes are in a collection
    vector<Collection*> collectionSubj;
};
#endif //NOTEPROJECT_COLLECTIONVIEW_H
