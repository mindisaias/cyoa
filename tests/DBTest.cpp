#include "gtest/gtest.h"
#include "../include/Database.hpp"
#include "../include/DatabaseEditor.hpp"
#include "../include/DatabaseSelector.hpp"
#include <iostream>

using namespace std;

TEST(DatabaseTestSuite, openDBTest) {

    Database testDB;

    EXPECT_NO_THROW(testDB.openDB());

}

TEST(DatabaseTestSuite, selectFromScenes) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBSelector.selectFromScenes(1));

}

TEST(DatabaseTestSuite, selectFromGames) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBSelector.selectFromGames());

}

TEST(DatabaseTestSuite, selectFromChoices) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBSelector.selectFromChoices(1));

}

TEST(DatabaseTestSuite, selectFromUsers) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBSelector.selectFromUsers());

}

TEST(DatabaseTestSuite, insertToGames) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBEditor.insertToGames("GameName", "GameAuthor", "GameDescription"));

}

TEST(DatabaseTestSuite, insertToScenes) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBEditor.insertToScenes(1, "TestPrompt", "TestSceneName"));

}

TEST(DatabaseTestSuite, insertToChoices) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBEditor.insertToChoices(1, "ChoiceText", 2));

}

TEST(DatabaseTestSuite, insertToScenes) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBEditor.insertToScenes(1, "TestPrompt", "TestSceneName"));

}

TEST(DatabaseTestSuite, insertToUsers) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.DBEditor.insertToUsers("Username", "Password"));

}