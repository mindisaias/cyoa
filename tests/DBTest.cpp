#include "gtest/gtest.h"
#include "../include/Database.hpp"
#include "../include/DatabaseEditor.hpp"
#include "../include/DatabaseSelector.hpp"
#include <iostream>

using namespace std;

int main() {
    Database myDB;
    DatabaseSelector DBSelector(myDB.DB);
    DatabaseEditor DBEditor(myDB.DB);
    string myGame = "myGame";

    cout << endl;

    DBEditor.insertToGames("Willows Game", "Willow", "This is Willow's Game");
    DBEditor.insertToScenes(1, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    DBEditor.insertToUsers("WillowThinking", "WillowsPassword");
    DBEditor.insertToChoices(1, "This is your choice.", 1);

    cout << endl;

    DBSelector.selectFromGames();

    cout << endl;
    
    DBEditor.deleteFromGames(1);

    cout << endl;
    DBSelector.selectFromScenes();

    

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