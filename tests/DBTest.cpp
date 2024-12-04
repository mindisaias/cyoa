#include "gtest/gtest.h"
#include "../include/Database.hpp"
#include "../include/DatabaseEditor.hpp"
#include "../include/DatabaseSelector.hpp"
#include <iostream>

using namespace std;

int main() {
    Database myDB;
    string myGame = "myGame";

    cout << endl;

    myDB.DBEditor.insertToGames("Willows Game", "Willow", "This is Willow's Game");
    myDB.DBEditor.insertToScenes(1, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    myDB.DBEditor.insertToUsers("WillowThinking", "WillowsPassword");
    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);

    cout << endl;

    myDB.DBSelector.selectFromGames();

    cout << endl;
    
    myDB.DBEditor.deleteFromGames(1);

    cout << endl;
    myDB.DBSelector.selectFromScenes();

    

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