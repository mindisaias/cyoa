#include "../include/User.hpp"
#include <iostream>
#include <../sqlite3/sqlite3.h>
#include <string>

using namespace std;

bool User::isValidCredentials(string name, string password, sqlite3* db){

    sqlite3_stmt* stmt;
    bool found = false;

    // SQL query to check username and password
    const char* query = "SELECT 1 FROM users WHERE username = ? AND password = ? LIMIT 1";

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return false;
    }

    // Bind the username and password to the query
    if (sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC) != SQLITE_OK) {
        cerr << "Failed to bind parameters: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }

    // Execute the query
    int result = sqlite3_step(stmt);

    if (result == SQLITE_ROW) {
        // Username exists, check password
        const char* dbPassword = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        sqlite3_finalize(stmt);

        if (password == dbPassword) {
            found = true; // Username and password are correct
        } 
        else {
            found = false; // Username exists but password is incorrect
        }
    }
    else {
        // Username does not exist
        sqlite3_finalize(stmt);
        return 0;
    }

    return found;

}

void addUser(string username, string password, sqlite3* db){
    sqlite3_stmt* stmt;
    bool found = false;

    // SQL query to check username and password
    const char* query = "SELECT 1 FROM users WHERE username = ? AND password = ? LIMIT 1";

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    if (sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC) != SQLITE_OK) {
        cerr << "Failed to bind username: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }
     int result = sqlite3_step(stmt);
    if (result == SQLITE_ROW) {
        cerr << "User already exists." << endl;
        sqlite3_finalize(stmt);
        return; // Exit as the user already exists
    }
    sqlite3_finalize(stmt);

    // Prepare SQL to insert new user
    const char* insertQuery = "INSERT INTO users (username, password) VALUES (?, ?)";
    if (sqlite3_prepare_v2(db, insertQuery, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Failed to prepare insert statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Bind username and password to the insert query
    if (sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC) != SQLITE_OK) {
        cerr << "Failed to bind parameters: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }

    // Execute the insert query
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cerr << "Failed to insert user: " << sqlite3_errmsg(db) << endl;
    } else {
        cout << "User added successfully!" << endl;
    }

    sqlite3_finalize(stmt);
}

