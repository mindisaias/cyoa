#ifndef DATABASESELECTOR_HPP
#define DATABASESELECTOR_HPP
#include <iostream>
#include <../sqlite3/sqlite3.h>
#include "Database.hpp"
#include "DatabaseEditor.hpp"
#include "DatabaseSelector.hpp"
#include <cstring>
#include <vector>

using namespace std;

class DatabaseSelector {
    public: 
        sqlite3* DB;
       
        static int outputCallback(void *NotUsed, int argc, char **argv, char **azColName){
            for(int i = 0; i < argc; i++){
                cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
            }
            cout << endl;
            return 0;
        }

        static int dataCallback(void *data, int argc, char **argv, char **azColName){
            auto* rows = static_cast<vector<vector<string>>*>(data);

            vector<string> currentRow;
            for (int i = 0; i < argc; i++) {
                if (argv[i]) {
                    currentRow.push_back(argv[i]);
                } else {
                    currentRow.push_back("NULL");
                }
            }
            rows->push_back(currentRow);
            return 0;
        }

        DatabaseSelector(sqlite3* db) : DB(db) {}
        
        vector<vector<string>> selectFromGames();
        vector<vector<string>> selectFromScenes(int gameID);
        vector<vector<string>> selectFromChoices(int sceneID);
        void selectFromUsers();
};

#endif