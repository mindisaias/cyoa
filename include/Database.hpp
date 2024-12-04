#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include "../sqlite3/sqlite3.h"
#include "Database.hpp"
#include "DatabaseEditor.hpp"
#include "DatabaseSelector.hpp"
#include <cstring>

using namespace std;

class Database {
    public:
        Database();
        sqlite3* DB;
        DatabaseEditor DBEditor;
        DatabaseSelector DBSelector;
        void openDB();


        ~Database();

        
};

#endif