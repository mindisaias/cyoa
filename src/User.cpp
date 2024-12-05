#include "../include/User.hpp"
#include <iostream>
#include <../sqlite3/sqlite3.h>
#include "Database.hpp"
#include "DatabaseEditor.hpp"
#include "DatabaseSelector.hpp"
#include <string>

using namespace std;

bool User::isValidCredentials(string name, string password, Database myDB){

    string query = "SELECT * FROM USERS WHERE Username = '" + name + "' AND Password = '" + password + "';";

    bool found = false;

    char* errmsg;

    vector<vector<string>> rows;

    if (sqlite3_exec(myDB.DB, query.c_str(), myDB.DBSelector.dataCallback, &rows, &errmsg) != SQLITE_OK) {
        cout << "Error selecting: " << errmsg;
    }

    for (const auto row : rows) {
        cout << row[1] << " " << row[2] << endl << endl; 
        if (row[1] == name && row[2] == password) {
            found = true;
        }
    }

    return found;

    // sqlite3_stmt* stmt;
    // bool found = false;

    // // SQL query to check username and password
    // const char* query = "SELECT 1 FROM users WHERE username = ? AND password = ? LIMIT 1";

    // // Prepare the SQL statement
    // if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
    //     cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
    //     sqlite3_close(db);
    //     return false;
    // }

    // // Bind the username and password to the query
    // if (sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
    //     sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC) != SQLITE_OK) {
    //     cerr << "Failed to bind parameters: " << sqlite3_errmsg(db) << endl;
    //     sqlite3_finalize(stmt);
    //     sqlite3_close(db);
    //     return false;
    // }

    // // Execute the query
    // int result = sqlite3_step(stmt);

    // if (result == SQLITE_ROW) {
    //     // Username exists, check password
    //     const char* dbPassword = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    //     sqlite3_finalize(stmt);

    //     if (password == dbPassword) {
    //         found = true; // Username and password are correct
    //     } 
    //     else {
    //         found = false; // Username exists but password is incorrect
    //     }
    // }
    // else {
    //     // Username does not exist
    //     sqlite3_finalize(stmt);
    //     return 0;
    // }

    // return found;

}
