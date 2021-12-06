//
// Created by Andrea on 21/11/21.
//

#include "gtest/gtest.h"
#include "../Headers/Note.h"

TEST(Note, Costructor_GOOD){
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
TEST(Note, Costructor_BAD){
    Note note("Note 1", "Description note 1", "Collection 1",true, false);
    string title = note.getTitle();
    string description = note.getDescription();
    string collection = note.getCollection();
    bool important = note.getImportant();
    bool editable = note.getEditable();
    EXPECT_EQ("Note 1",
              title);
    EXPECT_EQ("Description note 2",
              description);
    ASSERT_EQ("Collection 1",
              collection);
    EXPECT_EQ(false,
              important);
    EXPECT_EQ(true,
              editable);
}

TEST(Note, Edit_Title_GOOD){
    Note note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editTitle("Note New Title");
    ASSERT_EQ("Note New Title", note.getTitle());
}
TEST(Note, Edit_Title_BAD){
    Note note("Note 1", "Description note 1", "Collection 1",false, false);
    note.editTitle("Note New Title");
    ASSERT_EQ("Note New Title", note.getTitle());
}

TEST(Note, Edit_Description_GOOD){
    Note note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editDescription("New Description");
    string noteDescription = note.getDescription();
    ASSERT_EQ("New Description", noteDescription);
}
TEST(Note, Edit_Description_BAD){
    Note note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editDescription("New Description");
    string noteDescription = note.getDescription();
    ASSERT_EQ("New Descriptions", noteDescription);
}

TEST(Note, Edit_Important_GOOD){
    Note note("Note 1", "Description note 1", "Collection 1",true, false);
    bool noteImportant = note.getImportant();
    bool newNoteImportant = !noteImportant;
    note.editImportant(newNoteImportant);
    newNoteImportant = note.getImportant();
    ASSERT_EQ(true, newNoteImportant);
}
TEST(Note, Edit_Important_BAD){
    Note note("Note 1", "Description note 1", "Collection 1",true, false);
    bool noteImportant = note.getImportant();
    bool newNoteImportant = !noteImportant;
    note.editImportant(newNoteImportant);
    newNoteImportant = note.getImportant();
    ASSERT_EQ(false, newNoteImportant);
}

TEST(Note, Edit_Collection_GOOD){
    Note note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editCollection("Collection new");
    ASSERT_EQ("Collection new", note.getCollection());
}
TEST(Note, Edit_Collection_BAD){
    Note note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editCollection("Collection new");
    ASSERT_EQ("Collection 1", note.getCollection());
}
