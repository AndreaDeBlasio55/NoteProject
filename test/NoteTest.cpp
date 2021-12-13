//
// Created by Andrea on 21/11/21.
//
#include "gtest/gtest.h"
#include "../Headers/Note.h"

TEST(Note, Costructor){
    Note note("Note 1", "Description note 1", "Collection 1",true, true);
    string title = note.getTitle();
    string description = note.getDescription();
    string collection = note.getCollection();
    bool important = note.getImportant();
    bool editable = note.getEditable();
    ASSERT_EQ("Note 1",
              title);
    EXPECT_EQ("Description note 1",
              description);
    ASSERT_EQ("Collection 1",
              collection);
    ASSERT_EQ(true,
              important);
    EXPECT_EQ(true,
              editable);
}

TEST(Note, Edit_Note){
    Note note("Note 1", "Description note 1", "Collection 1",true, false);
    if (note.getEditable()){
        note.editTitle("Note New Title");
        note.editImportant(false);
        note.editDescription("New Description");
        note.editCollection("New Collection");
        ASSERT_EQ("Note New Title", note.getTitle());
        ASSERT_EQ(false, note.getImportant());
        ASSERT_EQ("New Description", note.getDescription());
        ASSERT_EQ("New Collection", note.getCollection());
    } else {
        ASSERT_EQ("Note 1", note.getTitle());
        ASSERT_EQ(true, note.getImportant());
        ASSERT_EQ("Description note 1", note.getDescription());
        ASSERT_EQ("Collection 1", note.getCollection());
    }
}

