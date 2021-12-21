//
// Created by Andrea on 21/11/21.
//
#include "gtest/gtest.h"
#include "../Headers/Note.h"

TEST(Note, Costructor){
    Note note("Note 1", "Description note 1", "Collection 1",true, true);
    ASSERT_EQ("Note 1",
              note.getTitle());
    EXPECT_EQ("Description note 1",
              note.getDescription());
    ASSERT_EQ("Collection 1",
              note.getCollection());
    ASSERT_EQ(true,
              note.getImportant());
    EXPECT_EQ(true,
              note.getEditable());
}

TEST(Note, Edit_Note) {
    Note note("Note 1", "Description note 1", "Collection 1", true, false);
    note.editTitle("Note New Title");
    note.editImportant(false);
    note.editDescription("New Description");
    note.editCollection("New Collection");
    ASSERT_EQ("Note New Title", note.getTitle());
    ASSERT_EQ(false, note.getImportant());
    ASSERT_EQ("New Description", note.getDescription());
    ASSERT_EQ("New Collection", note.getCollection());
}

