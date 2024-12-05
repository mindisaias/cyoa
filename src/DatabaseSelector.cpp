#include "Database.hpp"
#include "DatabaseEditor.hpp"
#include "DatabaseSelector.hpp"
#include <iostream>

using namespace std;


vector<vector<string>> DatabaseSelector::selectFromGames() {
    vector<vector<string>> rows;
    string query = "SELECT * FROM GAMES";

    char* errmsg;

    if (sqlite3_exec(DB, query.c_str(), dataCallback, &rows, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg;
    }

    sqlite3_exec(DB, query.c_str(), outputCallback, 0, &errmsg);

    return rows;
}

vector<vector<string>> DatabaseSelector::selectFromChoices(int sceneID) {
    string query = "SELECT * FROM CHOICES WHERE sceneID = " + to_string(sceneID); + ";";
    vector<vector<string>> rows;

    char* errmsg;

    if (sqlite3_exec(DB, query.c_str(), dataCallback, &rows, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg << endl;
    }

    return rows;

}

vector<vector<string>> DatabaseSelector::selectFromScenes(int gameID) {
    string query = "SELECT * FROM SCENES WHERE GAMEID = " + to_string(gameID); + ";";
    vector<vector<string>> rows;
    char* errmsg;

    if (sqlite3_exec(DB, query.c_str(), dataCallback, &rows, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg << endl;
    }

    return rows;

}

vector<vector<string>> DatabaseSelector::selectFromUsers() {
    string query = "SELECT * FROM USERS;";
    vector<vector<string>> rows;

    char* errmsg;

    if (sqlite3_exec(DB, query.c_str(), dataCallback, &rows, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg << endl;
    }
    
    return rows;
}