#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <../sqlite3/sqlite3.h>
#include <cstring>

using namespace std;

class Database {
    public:
        Database();
        sqlite3* DB;
        void openDB();


        ~Database();

        
};

#endif