#include "Database.hpp"
#include <iostream>

using namespace std;

Database::Database() {
// Open database
    openDB();
// Create tables if they don't already exist
    const char* sqlGamesTable =  "CREATE TABLE IF NOT EXISTS Games ("
                            "GameID INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "Name TEXT NOT NULL, "
                            "Author TEXT NOT NULL, "
                            "Published INTEGER DEFAULT 0, " // 0 Represents False(Unpublished), 1 Represents True(Published)
                            "Description TEXT NOT NULL);";


    const char* sqlScenesTable = "CREATE TABLE IF NOT EXISTS Scenes ("
                                 "SceneID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "SceneName TEXT, "
                                 "GameID INTEGER, "
                                 "Prompt TEXT NOT NULL, "
                                 "FOREIGN KEY (GameID) REFERENCES Games(GameID));";


    const char* sqlChoicesTable = "CREATE TABLE IF NOT EXISTS Choices ("
                            "ChoiceID INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "SceneID INTEGER, "
                            "ChoiceText TEXT, "
                            "ResultSceneID INTEGER, "
                            "FOREIGN KEY (SceneID) REFERENCES Scenes(SceneID), "
                            "FOREIGN KEY (ResultSceneID) REFERENCES Scenes(SceneID));";


    const char* sqlUsersTable = "CREATE TABLE IF NOT EXISTS Users ("
                                "UserID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                "Username TEXT NOT NULL, "
                                "Password TEXT NOT NULL);";


// Output error if table creation/initialization phase fails
    char* errmsg = nullptr;
    if (sqlite3_exec(DB, sqlGamesTable, NULL, 0, &errmsg) != SQLITE_OK) {
        cout << "SQL Error Games Table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    else {
        cout << "Games Table successfully created/initialized" << endl;
    }


    if (sqlite3_exec(DB, sqlChoicesTable, NULL, 0, &errmsg) != SQLITE_OK) {
        cout << "SQL Error Choice Table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    else {
        cout << "Choices Table successfully created/initialized" << endl;
    }


    if (sqlite3_exec(DB, sqlScenesTable, NULL, 0, &errmsg) != SQLITE_OK) {
        cout << "SQL Error Scenes Table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    else {
        cout << "Scenes Table successfully created/initialized" << endl;
    }


    if (sqlite3_exec(DB, sqlUsersTable, NULL, 0, &errmsg) != SQLITE_OK) {
        cout << "SQL Error Choice Table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    else {
        cout << "Users Table successfully created/initialized" << endl;
    }
    // Whether or not tables already exist, database is now loaded with these tables existing in it

}


void Database::openDB() {
        int exit = 0;
        exit = sqlite3_open("MYOA.db", &DB);

        if (exit) {
            cout << "Error opening database, please try rerunning your program" << sqlite3_errmsg << endl;
        }
        else {
            cout << "Database opened successfully" << endl;
        }
};

void Database::insertToGames(string name, string author, string description) {

    // "GameID INTEGER PRIMARY KEY AUTOINCREMENT, "
    // "Name TEXT NOT NULL, "
    // "Author TEXT NOT NULL, "
    // "Published INTEGER DEFAULT 0, " // 0 Represents False(Unpublished), 1 Represents True(Published)
    // "Description TEXT NOT NULL);";
    string query = "INSERT INTO Games (NAME, AUTHOR, DESCRIPTION) VALUES(?, ?, ?);";

    sqlite3_stmt* stmt;
    // Prepare the statement
    if (sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(DB) << endl;
        return;
    }

    // Use bind to amend each variable to sql statement
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, author.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, description.c_str(), -1, SQLITE_STATIC);

    // Execute the statement using step
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Error inserting data: " << sqlite3_errmsg(DB) << endl;
    } 
    else {
        cout << "Successfully inserted game into Games table." << endl;
    }

    // Finalize statement created dynamically to free memory and prevent mem leaks
    sqlite3_finalize(stmt);


}

void Database::insertToScenes(int GameID, string prompt, string SceneName) {

    // "CREATE TABLE IF NOT EXISTS Scenes ("
    // "SceneID INTEGER PRIMARY KEY AUTOINCREMENT, "
    // "SceneName TEXT"
    // "GameID INTEGER, "
    // "Prompt TEXT NOT NULL, "
    // "FOREIGN KEY (GameID) REFERENCES Games(GameID));";
    string query = "INSERT INTO Scenes (SceneName, GameID, Prompt) VALUES(?, ?, ?);";

    sqlite3_stmt* stmt;
    // Prepare the statement
    if (sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(DB) << endl;
        return;
    }

    // Use bind to amend each variable to sql statement
    sqlite3_bind_text(stmt, 1, SceneName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, GameID);
    sqlite3_bind_text(stmt, 3, prompt.c_str(), -1, SQLITE_STATIC);

    // Execute the statement using step
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Error inserting data: " << sqlite3_errmsg(DB) << endl;
    } 
    else {
        cout << "Successfully inserted scene into Scenes table." << endl;
    }

    // Finalize statement created dynamically to free memory and prevent mem leaks
    sqlite3_finalize(stmt);


}

void Database::insertToUsers(string username, string password) {
    // "CREATE TABLE IF NOT EXISTS Users ("
    // "UserID INTEGER PRIMARY KEY AUTOINCREMENT, "
    // "Username TEXT NOT NULL, "
    // "Password TEXT NOT NULL);";
    string query = "INSERT INTO Users (Username, Password) VALUES(?, ?);";

    sqlite3_stmt* stmt;
    // Prepare the statement
    if (sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(DB) << endl;
        return;
    }

    // Use bind to amend each variable to sql statement
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    // Execute the statement using step
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Error inserting data: " << sqlite3_errmsg(DB) << endl;
    } 
    else {
        cout << "Successfully inserted user into Users table." << endl;
    }

    // Finalize statement created dynamically to free memory and prevent mem leaks
    sqlite3_finalize(stmt);


}

void Database::insertToChoices(int SceneID, string ChoiceText, int ResultSceneID) {
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
    if (sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(DB) << endl;
        return;
    }

    // Use bind to amend each variable to sql statement
    sqlite3_bind_int(stmt, 1, SceneID);
    sqlite3_bind_text(stmt, 2, ChoiceText.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, ResultSceneID);

    // Execute the statement using step
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Error inserting data: " << sqlite3_errmsg(DB) << endl;
    } 
    else {
        cout << "Successfully inserted choice into Choices table." << endl;
    }

    // Finalize statement created dynamically to free memory and prevent mem leaks
    sqlite3_finalize(stmt);


}

void Database::deleteFromGames() {

}

void Database::deleteFromScenes() {

}

void Database::deleteFromChoices() {

}

void Database::selectFromGames() {

}

void Database::selectFromGames() {

}

void Database::selectFromScenes() {

}

void Database::selectFromUsers() {

}

void Database::updateInGames() {

}

void Database::updateInChoices() {

}

void Database::updateInScenes() {

}

Database::~Database() {
    if (DB) {
        sqlite3_close(DB);
    }
}