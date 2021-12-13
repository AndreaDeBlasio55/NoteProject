//
// Created by Andrea on 21/11/21.
//
#include "gtest/gtest.h"
#include "../Headers/CollectionView.h"

TEST(CollectionView, Count_Collections){
    CollectionView c;
    c.createCollection("Collection 1", true);
    c.createCollection("Collection 2", true);
    int collectionsCount = c.getCollectionsCount();
    ASSERT_EQ(2, collectionsCount);
}
TEST(CollectionView, Delete_Collection){
    CollectionView c;
    c.createCollection("Collection 3", true);
    c.createCollection("Collection 4", true);
    c.deleteCollection(1);
    int collectionsCount = c.getCollectionsCount();
    ASSERT_EQ(1, collectionsCount);
}

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


