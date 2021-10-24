#include "gtest/gtest.h"
#include "../Headers/Collection.h"

TEST(Collection, DefaultConstructor) {
    Collection c("Collection 1") ;
    ASSERT_EQ("Collection 1",
              c.getCollectionName());
}

TEST(Collection, NoName) {
    Collection c("") ;
    ASSERT_EQ("",
              c.getCollectionName());
}
/*
TEST(Collection, WrongCollectionName) {
    Collection c("Collection 1") ;
    ASSERT_EQ("Coll 1",
              c.getCollectionName());
}
 */
TEST(Collection, RightCollectionName) {
    Collection c("Collection 1") ;
    ASSERT_EQ("Collection 1",
              c.getCollectionName());
}