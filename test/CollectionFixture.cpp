#include "gtest/gtest.h"

#include "../Headers/Collection.h"


class CollectionSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        c1->setCollectionName("Collection 1");
        c2->setCollectionName("Collection 2");
    }

    virtual void TearDown()
    {
        delete c1;
        delete c2;
    }

    Collection* c1;
    Collection* c2;
};

TEST_F(CollectionSuite, TestTRUE){
    c2->setCollectionName("Collection 1");
    ASSERT_EQ(c1->getCollectionName(),
              c2->getCollectionName());
}
TEST_F(CollectionSuite, TestFALSE){
    c2->setCollectionName("Collection 3");
    ASSERT_EQ(c1->getCollectionName(),
              c2->getCollectionName());
}
