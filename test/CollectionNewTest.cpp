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
TEST(CollectionNew, Create_Note_GOOD){
    CollectionNew c("Collection 1", true);
    c.createNote("Nota 1", "Description 1", c.getCollectionName(), false, true);
    EXPECT_EQ("Nota 1", c.getNoteTitle(0));
}
TEST(CollectionNew, Create_Note_BAD){
    CollectionNew c("Collection 1", false);
    c.createNote("Nota 1", "Description 1", c.getCollectionName(), false, true);
    c.editNoteTitle(0,"Note 2");
    EXPECT_EQ("Nota 1", c.getNoteTitle(0));
}
TEST(CollectionNew, Edit_Note_GOOD){
    CollectionNew c("Collection 1", true);
    c.createNote("Note 1", "Description 1", c.getCollectionName(), false, true);
    c.editNoteTitle(0, "Note 2");
    c.editNoteDescription(0,"Description 2");
    c.editNoteImportant(0, false);
    EXPECT_EQ("Note 2", c.getNoteTitle(0));
    EXPECT_EQ("Description 2", c.getNoteDescription(0));
    EXPECT_EQ(false, c.getNoteImportant(0));
}
TEST(CollectionNew, Edit_Note_BAD){
    CollectionNew c("Collection 1", true);
    c.createNote("Note 1", "Description 1", c.getCollectionName(), false, true);
    c.editNoteTitle(0, "Note 2");
    c.editNoteDescription(0,"Description 2");
    c.editNoteImportant(0, false);
    EXPECT_EQ("Note 1", c.getNoteTitle(0));
    EXPECT_EQ("Description 1", c.getNoteDescription(0));
    EXPECT_EQ(true, c.getNoteImportant(0));
    int countNotes = c.getCountNotes();
    ASSERT_EQ(countNotes, 2);
}

TEST(CollectionNew, Delete_Note_GOOD){
    CollectionNew c("Collection 1", false);
    c.createNote("Note 1", "Description 1", c.getCollectionName(), false, true);
    c.editNoteTitle(0, "Note 2");
    c.editNoteDescription(0,"Description 2");
    c.editNoteImportant(0, false);
    EXPECT_EQ("Note 2", c.getNoteTitle(0));
    EXPECT_EQ("Description 2", c.getNoteDescription(0));
    EXPECT_EQ(false, c.getNoteImportant(0));
}




