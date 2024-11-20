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
                            "Description TEXT);";

    const char* sqlScenesTable = "CREATE TABLE IF NOT EXISTS Scenes ("
                                 "SceneID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "GameID Integer, "
                                 "Prompt TEXT NOT NULL, "
                                 "FOREIGN KEY (GameID) REFERENCES Games(GameID));";

    const char* sqlChoicesTable = "CREATE TABLE IF NOT EXISTS Choices ("
                            "ChoiceID INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "SceneID INTEGER, "
                            "ChoiceText TEXT, "
                            "ResultSceneID INTEGER, "
                            "FOREIGN KEY (SceneID) REFERENCES Scenes(SceneID), "
                            "FOREIGN KEY (ResultSceneID) REFERENCES Scenes(SceneID));";


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
    // Whether or not tables already exist, database is now loaded with these tables existing in it
    // Also possibility that game tables already exist as well, but everything that is needed now exists for sure


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

void Database::insertToDB() {

}
void Database::deleteFromDB() {

}
void Database::selectFromDB() {

}
Database::~Database() {
    if (DB) {
        sqlite3_close(DB);
    }
}