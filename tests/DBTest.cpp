#include "gtest/gtest.h"
#include "../include/Database.hpp"


TEST(DatabaseTestSuite, openDBTest) {

    Database* testDB;

    EXPECT_NO_THROW(testDB->openDB());

}

TEST(DatabaseTestSuite, createGameTableTest) {

    Database* testDB;

    EXPECT_NO_THROW(testDB->createGameTable("cool"));

}

TEST(DatabaseTestSuite, deleteFromDBTest) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.deleteFromDB());

}

TEST(DatabaseTestSuite, selectFromDBTest) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.selectFromDB());

}