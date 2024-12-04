#include "DatabaseSelector.hpp"
#include <iostream>

using namespace std;


void DatabaseSelector::selectFromGames() {
    string query = "SELECT * FROM GAMES";

    char* errmsg;

    if (sqlite3_exec(DB, query.c_str(), callback, 0, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg;
    }
    else {

    }
}

void DatabaseSelector::selectFromChoices() {

}

void DatabaseSelector::selectFromScenes() {
    string query = "SELECT * FROM SCENES";

    char* errmsg;

    if (sqlite3_exec(DB, query.c_str(), callback, 0, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg << endl;
    }
    else {
        
    }
}

void DatabaseSelector::selectFromUsers() {

}