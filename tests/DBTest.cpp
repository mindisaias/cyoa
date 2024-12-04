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
    myDB.DBEditor.insertToGames("Angels Game", "Angel", "This is Angel's Game");
    myDB.DBEditor.insertToGames("Lynvys Game", "Lynvy", "This is Lynvy's Game");    
    myDB.DBEditor.insertToGames("Alex Game", "Alex", "This is Alex's Game");


    myDB.DBEditor.insertToScenes(1, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    myDB.DBEditor.insertToScenes(1, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    myDB.DBEditor.insertToScenes(2, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    myDB.DBEditor.insertToScenes(2, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    myDB.DBEditor.insertToScenes(3, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    myDB.DBEditor.insertToScenes(3, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");
    myDB.DBEditor.insertToScenes(3, "What will you do? {Choice 1}, {Choice 2}", "Time to Decide");

    myDB.DBEditor.insertToUsers("WillowThinking", "WillowsPassword");

    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);
    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);
    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);
    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);
    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);
    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);
    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);
    myDB.DBEditor.insertToChoices(1, "This is your choice.", 1);

    cout << endl;

    vector<vector<string>> rows = myDB.DBSelector.selectFromGames();

    cout << endl;

    for (const auto row : rows) {
        cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << endl << endl;
    }

    cout << endl;

    rows = myDB.DBSelector.selectFromScenes(1);

    for (const auto row : rows) {
        cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << endl << endl;
    }

    cout << endl;

    rows = myDB.DBSelector.selectFromChoices(1);

    for (const auto row : rows) {
        cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << endl << endl;
    }

    myDB.DBEditor.deleteFromGames(1);
    

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