#include "gtest/gtest.h"
#include "../Headers/Note.h"

TEST(Note, TestTitle) {
    Collection* col = new Collection("Collection 1");
    Note note(col, "Title Note 1", "Description Note 1");
    ASSERT_EQ("Title Note 1",
              note.getTitle());
    ASSERT_NE("Title Note 2",
              note.getTitle());
}

TEST(Note, TestDescription) {
    Collection* col = new Collection("Collection 1");
    Note note(col, "Description Note 1", "Description Note 1", false);
    ASSERT_EQ("Description Note 1",
              note.getDescription());
    ASSERT_NE("Description Note 2",
              note.getDescription());
}

TEST(Note, TestCollection) {
    Collection* col = new Collection("Collection 1");
    Note note(col, "Description Note 1", "Description Note 1", false);
    ASSERT_EQ("Collection 1",
              note.getCollection());
}

TEST(Note, TestImportant) {
    Collection* col = new Collection("Collection 1");
    Note note(col, "Description Note 1", "Description Note 1", false);
    ASSERT_EQ(false,
              note.getImportant());
    ASSERT_NE(true,
             note.getImportant());
}