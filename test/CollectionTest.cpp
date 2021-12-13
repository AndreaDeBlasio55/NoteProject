//
// Created by Andrea on 20/11/21.
//

#include "gtest/gtest.h"
#include "../Headers/Collection.h"

TEST(Collection, Costructor){
    Collection c("Collection 1", false);
    string collectionName = c.getCollectionName();
    ASSERT_EQ("Collection 1",
              collectionName);
}


TEST(Collection, Edit_Collection){
    Collection c("Collection 1", true);
    if (c.getEditable()) {
        c.editCollectionName("Collection 1 Edited");
        c.editEditable();

        ASSERT_EQ(false, c.getEditable());
        ASSERT_EQ("Collection 1 Edited",c.getCollectionName());
    } else {
        ASSERT_EQ(true, c.getEditable());
        ASSERT_EQ("Collection 1", c.getCollectionName());
    }
}


TEST(Collection, Create_Note){
    Collection c("Collection 1", true);
    if (c.getEditable()) {
        c.createNote("Nota 1", "Description 1", c.getCollectionName(), false, true);
        ASSERT_EQ("Nota 1", c.getNoteTitle(0));
    }
    Collection c2("Collection 1", false);
    if (c2.getEditable()){
        c.createNote("Nota 2", "Description 2", c.getCollectionName(), false, false);
        ASSERT_EQ("Nota 2", c.getNoteTitle(0));
    }
    ASSERT_EQ(1,  c.getCountNotes());
    ASSERT_NE(1,  c2.getCountNotes());

}

TEST(Collection, Edit_Note){
    Collection c("Collection 1", true);
    c.createNote("Note 1", "Description 1", c.getCollectionName(), false, true);
    if (c.getNoteEditable(0)) {
        c.editNoteTitle(0, "Note 2");
        c.editNoteDescription(0, "Description 2");
        c.editNoteImportant(0, false);
        EXPECT_EQ("Note 2", c.getNoteTitle(0));
        EXPECT_EQ("Description 2", c.getNoteDescription(0));
        EXPECT_EQ(false, c.getNoteImportant(0));
    } else {
        EXPECT_EQ("Note 1", c.getNoteTitle(0));
        EXPECT_EQ("Description 1", c.getNoteDescription(0));
        EXPECT_EQ(true, c.getNoteImportant(0));
    }
}


TEST(Collection, Delete_Note){
    Collection c("Collection 1", true);
    if (c.getEditable()) {
        c.createNote("Note 1", "Description 1", c.getCollectionName(), false, true);
        c.createNote("Note 2", "Description 2", c.getCollectionName(), true, true);
        c.deleteNote(0);
        c.deleteNote(0);
        ASSERT_EQ(0, c.getCountNotes());
    } else {
        ASSERT_EQ(0, c.getCountNotes());
    }
}




