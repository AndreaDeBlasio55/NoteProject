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
