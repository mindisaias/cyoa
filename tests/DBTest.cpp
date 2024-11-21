#include "gtest/gtest.h"
#include "../include/Database.hpp"
#include <iostream>

using namespace std;

int main() {
    Database myDB;
    string myGame = "myGame";

    cout << "Hello world" << endl;
    myDB.insertToGames("Willows Game", "Willow", "This is Willow's Game");
    myDB.insertToScenes(3, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    myDB.insertToUsers("WillowThinking", "WillowsPassword");
    myDB.insertToChoices(1, "This is your choice.", 2);
    myDB.deleteFromGames("Willows Game");
    myDB.deleteFromScenes(1);

    return 0;
}

/*TEST(DatabaseTestSuite, openDBTest) {

    Database testDB;

    EXPECT_NO_THROW(testDB.openDB());

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

}*/