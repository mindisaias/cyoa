#ifndef DATABASESELECTOR_HPP
#define DATABASESELECTOR_HPP
#include <iostream>
#include <../sqlite3/sqlite3.h>
#include "Database.hpp"
#include "DatabaseEditor.hpp"
#include "DatabaseSelector.hpp"
#include <cstring>

using namespace std;

class DatabaseSelector {
    public: 
        sqlite3* DB;
        
        static int callback(void *NotUsed, int argc, char **argv, char **azColName){
            for(int i = 0; i < argc; i++){
                cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
            }
            cout << endl;
            return 0;
        }

        DatabaseSelector(sqlite3* db) : DB(db) {}
        
        void selectFromGames();
        void selectFromScenes();
        void selectFromChoices();
        void selectFromUsers();
};

#endif