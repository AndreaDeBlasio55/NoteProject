//
// Created by Andrea on 20/11/21.
//

#include "gtest/gtest.h"
#include "../Headers/CollectionNew.h"

TEST(CollectionNew, Costructor_GOOD){
    CollectionNew c("Collection 1", false);
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 1",
              collectionName);
}
// FAIL
TEST(CollectionNew, Costructor_BAD){
    CollectionNew c("Collection 1", false);
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 2",
              collectionName);
}
TEST(CollectionNew, Edit_Collection_Name){
    CollectionNew c("Collection 1", true);
    c.editCollectionName("Collection 1 Edited");
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 1 Edited",
              collectionName);
}
TEST(CollectionNew, Edit_Collection_Name_BAD){
    CollectionNew c("Collection 1", true);
    c.editCollectionName("Collection 1 Edited");
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 1",
              collectionName);
}
TEST(CollectionNew, Create_Note){
    CollectionNew c("Collection 1", true);
    c.createNote("Note 1", "Description Note 1", true, false);
    string noteName = c.notes[0]->getTitle();
    ASSERT_EQ("Note 1",
              collectionName);
}




