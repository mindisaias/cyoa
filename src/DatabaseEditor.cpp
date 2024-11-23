#include "DatabaseEditor.hpp"
#include <iostream>

using namespace std;

void DatabaseEditor::insertToGames(string name, string author, string description) {

    // "GameID INTEGER PRIMARY KEY AUTOINCREMENT, "
    // "Name TEXT NOT NULL, "
    // "Author TEXT NOT NULL, "
    // "Published INTEGER DEFAULT 0, " // 0 Represents False(Unpublished), 1 Represents True(Published)
    // "Description TEXT NOT NULL);";
    string query = "INSERT INTO Games (NAME, AUTHOR, DESCRIPTION) VALUES(?, ?, ?);";

    sqlite3_stmt* stmt;
    // Prepare the statement
    if (sqlite3_prepare_v2(DB.DB, query.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(DB.DB) << endl;
        return;
    }

    // Use bind to amend each variable to sql statement
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, author.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, description.c_str(), -1, SQLITE_STATIC);

    // Execute the statement using step
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Error inserting data: " << sqlite3_errmsg(DB.DB) << endl;
    } 
    else {
        cout << "Successfully inserted game into Games table." << endl;
    }

    // Finalize statement created dynamically to free memory and prevent mem leaks
    sqlite3_finalize(stmt);


}

void DatabaseEditor::insertToScenes(int GameID, string prompt, string SceneName) {

    // "CREATE TABLE IF NOT EXISTS Scenes ("
    // "SceneID INTEGER PRIMARY KEY AUTOINCREMENT, "
    // "SceneName TEXT"
    // "GameID INTEGER, "
    // "Prompt TEXT NOT NULL, "
    // "FOREIGN KEY (GameID) REFERENCES Games(GameID));";
    string query = "INSERT INTO Scenes (SceneName, GameID, Prompt) VALUES(?, ?, ?);";

    sqlite3_stmt* stmt;
    // Prepare the statement
    if (sqlite3_prepare_v2(DB.DB, query.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(DB.DB) << endl;
        return;
    }

    // Use bind to amend each variable to sql statement
    sqlite3_bind_text(stmt, 1, SceneName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, GameID);
    sqlite3_bind_text(stmt, 3, prompt.c_str(), -1, SQLITE_STATIC);

    // Execute the statement using step
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Error inserting data: " << sqlite3_errmsg(DB.DB) << endl;
    } 
    else {
        cout << "Successfully inserted scene into Scenes table." << endl;
    }

    // Finalize statement created dynamically to free memory and prevent mem leaks
    sqlite3_finalize(stmt);


}

void DatabaseEditor::insertToUsers(string username, string password) {
    // "CREATE TABLE IF NOT EXISTS Users ("
    // "UserID INTEGER PRIMARY KEY AUTOINCREMENT, "
    // "Username TEXT NOT NULL, "
    // "Password TEXT NOT NULL);";
    string query = "INSERT INTO Users (Username, Password) VALUES(?, ?);";

    sqlite3_stmt* stmt;
    // Prepare the statement
    if (sqlite3_prepare_v2(DB.DB, query.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(DB.DB) << endl;
        return;
    }

    // Use bind to amend each variable to sql statement
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    // Execute the statement using step
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Error inserting data: " << sqlite3_errmsg(DB.DB) << endl;
    } 
    else {
        cout << "Successfully inserted user into Users table." << endl;
    }

    // Finalize statement created dynamically to free memory and prevent mem leaks
    sqlite3_finalize(stmt);


}

void DatabaseEditor::insertToChoices(int SceneID, string ChoiceText, int ResultSceneID) {
    // "CREATE TABLE IF NOT EXISTS Choices ("
    // "ChoiceID INTEGER PRIMARY KEY AUTOINCREMENT, "
    // "SceneID INTEGER, "
    // "ChoiceText TEXT, "
    // "ResultSceneID INTEGER, "
    // "FOREIGN KEY (SceneID) REFERENCES Scenes(SceneID), "
    // "FOREIGN KEY (ResultSceneID) REFERENCES Scenes(SceneID));";
    string query = "INSERT INTO Choices (SceneID, ChoiceText, ResultSceneID) VALUES(?, ?, ?);";

    sqlite3_stmt* stmt;
    // Prepare the statement
    if (sqlite3_prepare_v2(DB.DB, query.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(DB.DB) << endl;
        return;
    }

    // Use bind to amend each variable to sql statement
    sqlite3_bind_int(stmt, 1, SceneID);
    sqlite3_bind_text(stmt, 2, ChoiceText.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, ResultSceneID);

    // Execute the statement using step
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Error inserting data: " << sqlite3_errmsg(DB.DB) << endl;
    } 
    else {
        cout << "Successfully inserted choice into Choices table." << endl;
    }

    // Finalize statement created dynamically to free memory and prevent mem leaks
    sqlite3_finalize(stmt);


}

void DatabaseEditor::deleteFromGames(int gameID) {
    string query = "DELETE FROM GAMES WHERE GameID = " + to_string(gameID) + ";";
    char* errmsg = nullptr;

    if (sqlite3_exec(DB.DB, query.c_str(), NULL, 0, &errmsg) != SQLITE_OK) {
        cout << "Error deleting from games: " << errmsg << endl;
    }
    
    int affected_rows = sqlite3_changes(DB.DB);

    if (affected_rows == 0) {
        cout << "Game doesn't exist" << endl;
    }
    else {
        cout << "Successfully deleted game containing ID " << gameID << endl;
    }
    
}