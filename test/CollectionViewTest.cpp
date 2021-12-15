//
// Created by Andrea on 21/11/21.
//
#include "gtest/gtest.h"
#include "../Headers/CollectionView.h"

TEST(CollectionView, Edit_Collection_Name){
    CollectionView c;
    c.createCollection("Collection 5", true);
    if (c.getCollectionEditable(0)) {
        c.editCollectionName(0, "New Name Collection");
        string colName = c.getCollectionName(0);
        ASSERT_EQ("New Name Collection", colName);
    } else {
        ASSERT_EQ("Collection 5", c.getCollectionName(0));
    }
}

TEST(CollectionView, Edit_Editable_Collection){
    CollectionView c;
    c.createCollection("Collection 1", true);
    c.editEditable(0);
    ASSERT_EQ(false, c.getCollectionEditable(0));
}

TEST(CollectionView, Change_Collection){
    CollectionView* c = new CollectionView();
    c->createCollection("Collection 1", true);
    c->createCollection("Collection 2", true);
    Collection* col1 = c->getCollection(0);
    Collection* col2 = c->getCollection(1);

    if (col1->getEditable() && col2->getEditable()) {
        col1->createNote("Nota di Col 1", "Descr 1", col1->getCollectionName(), true, true);
        col2->createNote("Nota di Col 2", "Descr 2", col1->getCollectionName(), true, true);

        if(col1->getNoteEditable(0) && col2->getNoteEditable(0)) {
            c->changeCollection(0,
                                1,
                                0,
                                col1->getNoteTitle(0),
                                col1->getNoteDescription(0),
                                col1->getNoteImportant(0),
                                col1->getNoteEditable(0)
            );

            ASSERT_EQ("Nota di Col 1", col2->getNoteTitle(1));

        } else {
            ASSERT_EQ(0, col1->getCountNotes());
        }
    } else {
        ASSERT_EQ(0, col1->getCountNotes());
    }
}

TEST(CollectionView, Delete_Collection){
    CollectionView c;
    c.createCollection("Collection 3", true);
    c.createCollection("Collection 4", true);
    c.deleteCollection(1);
    int collectionsCount = c.getCollectionsCount();
    ASSERT_EQ(1, collectionsCount);
}