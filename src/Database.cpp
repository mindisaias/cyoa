#include "Database.hpp"
#include <iostream>

using namespace std;

Database::Database() {
// Open database
    openDB();
// Create tables if they don't already exist
    const char* sqlGamesTable =  "CREATE TABLE IF NOT EXISTS Games ("
                            "UID INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "Name TEXT NOT NULL, "
                            "Author TEXT NOT NULL, "
                            "Published INTEGER DEFAULT 0, "
                            "Description TEXT);";

    const char* sqlChoiceTable = "CREATE TABLE IF NOT EXISTS Choices ("
                            "CID INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "UID INTEGER, "
                            "Choice TEXT, "
                            "Result INTEGER, "
                            "FOREIGN KEY (UID) REFERENCES Games(UID), "
                            "FOREIGN KEY (Result) REFERENCES Game(SID);";
    char** DB_err = nullptr;
    if (sqlite3_exec(DB, sqlGamesTable, NULL, 0, DB_err) != SQLITE_OK) {
        cout << "SQL Error: " << DB_err << endl;
        sqlite3_free(DB_err);
    }
    if (sqlite3_exec(DB, sqlChoiceTable, NULL, 0, DB_err) != SQLITE_OK) {
        cout << "SQL Error: " << DB_err << endl;
        sqlite3_free(DB_err);
    }


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

void Database::createGameTable(string &tableName) {

    string sqlGameTable =  "CREATE TABLE IF NOT EXISTS " + tableName + " ("
                            "SID INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "UID INTEGER, "
                            "Prompt TEXT, "
                            "FOREIGN KEY (UID) REFERENCES Games(UID));";


    char** GameTableErr = nullptr;
    if (sqlite3_exec(DB, sqlGameTable.c_str(), NULL, 0, GameTableErr) != SQLITE_OK) {
        cout << "SQL Error: " << GameTableErr << endl;
        sqlite3_free(GameTableErr);
    }
}

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