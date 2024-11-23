#include "DatabaseSelector.hpp"
#include <iostream>

using namespace std;


void DatabaseSelector::selectFromGames(int gameID) {
    string query = "SELECT * FROM GAMES";

    char* errmsg;

    if (sqlite3_exec(DB.DB, query.c_str(), callback, 0, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg;
    }
    else {

    }
}

void DatabaseSelector::selectFromChoices(int choiceID) {

}

void DatabaseSelector::selectFromScenes(int sceneID) {
    string query = "SELECT * FROM SCENES";

    char* errmsg;

    if (sqlite3_exec(DB.DB, query.c_str(), callback, 0, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg << endl;
    }
    else {
        
    }
}

void DatabaseSelector::selectFromUsers(string username, string password) {

}