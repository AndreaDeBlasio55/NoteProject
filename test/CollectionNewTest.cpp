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
TEST(CollectionNew, Edit_Collection_Name_GOOD){
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
TEST(CollectionNew, Edit_Collection_Editable_GOOD){
    CollectionNew c("Collection 1", true);
    bool valueEditable = c.getEditable();
    valueEditable = !valueEditable;
    ASSERT_EQ(false, valueEditable);
}
TEST(CollectionNew, Edit_Collection_Editable_BAD){
    CollectionNew c("Collection 1", false);
    bool valueEditable = c.getEditable();
    valueEditable = !valueEditable;
    ASSERT_EQ(false, valueEditable);
}



