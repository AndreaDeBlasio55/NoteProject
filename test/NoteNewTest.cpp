//
// Created by Andrea on 21/11/21.
//

#include "gtest/gtest.h"
#include "../Headers/NoteNew.h"

TEST(NoteNew, Costructor_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, true);
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
TEST(NoteNew, Costructor_BAD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
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

TEST(NoteNew, Edit_Title_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editTitle("Note New Title");
    ASSERT_EQ("Note New Title", note.getTitle());
}
TEST(NoteNew, Edit_Title_BAD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",false, false);
    note.editTitle("Note New Title");
    ASSERT_EQ("Note New Title", note.getTitle());
}

TEST(NoteNew, Edit_Description_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editDescription("New Description");
    string noteDescription = note.getDescription();
    ASSERT_EQ("New Description", noteDescription);
}
TEST(NoteNew, Edit_Description_BAD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editDescription("New Description");
    string noteDescription = note.getDescription();
    ASSERT_EQ("New Descriptions", noteDescription);
}

TEST(NoteNew, Edit_Important_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
    bool noteImportant = note.getImportant();
    bool newNoteImportant = !noteImportant;
    note.editImportant(newNoteImportant);
    newNoteImportant = note.getImportant();
    ASSERT_EQ(true, newNoteImportant);
}
TEST(NoteNew, Edit_Important_BAD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
    bool noteImportant = note.getImportant();
    bool newNoteImportant = !noteImportant;
    note.editImportant(newNoteImportant);
    newNoteImportant = note.getImportant();
    ASSERT_EQ(false, newNoteImportant);
}

TEST(NoteNew, Edit_Collection_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editCollection("Collection new");
    ASSERT_EQ("Collection new", note.getCollection());
}
TEST(NoteNew, Edit_Collection_BAD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, true);
    note.editCollection("Collection new");
    ASSERT_EQ("Collection 1", note.getCollection());
}
