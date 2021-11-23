//
// Created by Andrea on 21/11/21.
//

#include "gtest/gtest.h"
#include "../Headers/NoteNew.h"
#include "../Headers/Collection.h"

TEST(NoteNew, Costructor_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
    string title = note.getTitle();
    string description = note.getDescription();
    string collection = note.getCollection();
    bool editable = note.getEditable();
    bool important = note.getImportant();
    ASSERT_EQ("Note 1",
              title);
    EXPECT_EQ("Description note 1",
              description);
    ASSERT_EQ("Collection 1",
              collection);
    ASSERT_EQ(true,
              editable);
    EXPECT_EQ(false,
              important);
}
TEST(NoteNew, Costructor_BAD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
    string title = note.getTitle();
    string description = note.getDescription();
    string collection = note.getCollection();
    bool editable = note.getEditable();
    bool important = note.getImportant();
    ASSERT_EQ("Note 1",
              title);
    EXPECT_EQ("Description note 2",
              description);
    ASSERT_EQ("Collection 1",
              collection);
    EXPECT_EQ(false,
              editable);
    EXPECT_EQ(true,
              important);
}
TEST(NoteNew, Edit_Title_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
    note.editTitle("Note New Title");
    string noteTitle = note.getTitle();
    ASSERT_EQ("Note New Title", noteTitle);
}
TEST(NoteNew, Edit_Title_BAD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",false, false);
    if (note.getEditable()) {
        note.editTitle("Note New Title");
    }
    string noteTitle = note.getTitle();
    EXPECT_EQ("Note New Title", noteTitle);
}
TEST(NoteNew, Edit_Description_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
    note.editDescription("New Description");
    string noteDescription = note.getDescription();
    ASSERT_EQ("New Description", noteDescription);
}
TEST(NoteNew, Edit_Important_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
    bool noteImportant = note.getImportant();
    bool newNoteImportant = !noteImportant;
    note.editImportant(newNoteImportant);
    newNoteImportant = note.getImportant();
    ASSERT_EQ(true, newNoteImportant);
}
TEST(NoteNew, Get_Editable_GOOD){
    NoteNew note("Note 1", "Description note 1", "Collection 1",true, false);
    bool noteEditable = note.getEditable();
    ASSERT_EQ(true, noteEditable);
}