#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <sqlite3.h>

using namespace std;

class Database {
    public:
        sqlite3* DB;
        void openDB();
        void createGameTable(string &tableName);
        void insertToDB();
        void deleteFromDB();
        void selectFromDB();
        ~Database();

        
};

#endif