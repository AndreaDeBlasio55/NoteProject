//
// Created by Andrea on 20/11/21.
//

#include "gtest/gtest.h"
#include "../Headers/Collection.h"

TEST(Collection, Costructor_GOOD){
    Collection c("Collection 1", false);
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 1",
              collectionName);
}
TEST(Collection, Costructor_BAD){
    Collection c("Collection 1", false);
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 2",
              collectionName);
}

TEST(Collection, Edit_Collection_Name_GOOD){
    Collection c("Collection 1", true);
    c.editCollectionName("Collection 1 Edited");
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 1 Edited",
              collectionName);
}
TEST(Collection, Edit_Collection_Name_BAD){
    Collection c("Collection 1", true);
    c.editCollectionName("Collection 1 Edited");
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 1",
              collectionName);
}

TEST(Collection, Edit_Collection_Editable_GOOD){
    Collection c("Collection 1", true);
    bool valueEditable = c.getEditable();
    valueEditable = !valueEditable;
    ASSERT_EQ(false, valueEditable);
}
TEST(Collection, Edit_Collection_Editable_BAD){
    Collection c("Collection 1", false);
    bool valueEditable = c.getEditable();
    valueEditable = !valueEditable;
    ASSERT_EQ(false, valueEditable);
}

TEST(Collection, Create_Note_GOOD){
    Collection c("Collection 1", true);
    c.createNote("Nota 1", "Description 1", c.getCollectionName(), false, true);
    EXPECT_EQ("Nota 1", c.getNoteTitle(0));
}
TEST(Collection, Create_Note_BAD){
    Collection c("Collection 1", true);
    c.createNote("Nota 1", "Description 1", c.getCollectionName(), false, true);
    c.editNoteTitle(0,"Note 2");
    EXPECT_EQ("Nota 1", c.getNoteTitle(0));
}

TEST(Collection, Edit_Note_GOOD){
    Collection c("Collection 1", true);
    c.createNote("Note 1", "Description 1", c.getCollectionName(), false, true);
    c.editNoteTitle(0, "Note 2");
    c.editNoteDescription(0,"Description 2");
    c.editNoteImportant(0, false);
    EXPECT_EQ("Note 2", c.getNoteTitle(0));
    EXPECT_EQ("Description 2", c.getNoteDescription(0));
    EXPECT_EQ(false, c.getNoteImportant(0));
}
TEST(Collection, Edit_Note_BAD){
    Collection c("Collection 1", true);
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

TEST(Collection, Delete_Note_GOOD){
    Collection c("Collection 1", true);
    c.createNote("Note 1", "Description 1", c.getCollectionName(), false, true);
    c.createNote("Note 2", "Description 2", c.getCollectionName(), true, false);
    c.deleteNote(0);
    c.deleteNote(0);
    int countNotes = c.getCountNotes();
    ASSERT_EQ(countNotes, 1);
}
TEST(Collection, Delete_Note_BAD){
    Collection c("Collection 1", false);
    c.createNote("Note 1", "Description 1", c.getCollectionName(), false, true);
    c.createNote("Note 2", "Description 2", c.getCollectionName(), true, true);
    c.deleteNote(0);
    c.deleteNote(0);
    int countNotes = c.getCountNotes();
    ASSERT_EQ(countNotes, 0);
}




