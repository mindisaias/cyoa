#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <../sqlite3/sqlite3.h>

using namespace std;

class Database {
    public:
        Database();
        sqlite3* DB;
        void openDB();
        void insertToDB();
        void deleteFromDB();
        void selectFromDB();
        ~Database();

        
};

#endif