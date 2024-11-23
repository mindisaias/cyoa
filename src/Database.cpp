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
                                 "CONSTRAINT fk_game_id FOREIGN KEY (GameID) REFERENCES Games(GameID) ON DELETE CASCADE);";


    const char* sqlChoicesTable = "CREATE TABLE IF NOT EXISTS Choices ("
                            "ChoiceID INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "SceneID INTEGER, "
                            "ChoiceText TEXT, "
                            "ResultSceneID INTEGER, "
                            "CONSTRAINT fk_scene_id FOREIGN KEY (SceneID) REFERENCES Scenes(SceneID) ON DELETE CASCADE, "
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
    // ensure cascading works with below execution
    sqlite3_exec(DB, "PRAGMA foreign_keys = ON;", 0, 0, 0);


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

Database::~Database() {
    if (DB) {
        sqlite3_close(DB);
    }
}