//
// Created by Andrea on 21/11/21.
//
#include "gtest/gtest.h"
#include "../Headers/CollectionView.h"

TEST(CollectionView, Create_Collection_GOOD){
    CollectionView c;
    c.createCollection("Collection 1", true);
    c.createCollection("Collection 2", true);
    int collectionsCount = c.getCollectionsCount();
    ASSERT_EQ(2, collectionsCount);
}
TEST(CollectionView, Create_Collection_BAD){
    CollectionView c;
    c.createCollection("Collection 1", true);
    c.createCollection("Collection 2", true);
    c.deleteCollection(1);
    int collectionsCount = c.getCollectionsCount();
    ASSERT_EQ(2, collectionsCount);
}

TEST(CollectionView, Edit_Collection_Name_GOOD){
    CollectionView c;
    c.createCollection("Collection 1", true);
    c.editCollectionName(0, "New Name Collection");
    string colName = c.getCollectionName(0);
    ASSERT_EQ("New Name Collection", colName);
}
TEST(CollectionView, Edit_Collection_Name_BAD){
    CollectionView c;
    c.createCollection("Collection 1", false);
    c.editCollectionName(0, "New Name Collection");
    string colName = c.getCollectionName(0);
    ASSERT_EQ("New Name Collection", colName);
}

TEST(CollectionView, Edit_Editable_Collection_GOOD){
    CollectionView c;
    c.createCollection("Collection 1", true);
    c.editEditable(0);
    bool editable = c.getCollectionEditable(0);
    EXPECT_EQ(false, editable);
}
