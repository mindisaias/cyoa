#ifndef USER_HPP
#define USER_HPP
#include "../sqlite3/sqlite3.h"
#include "Database.hpp"
#include "DatabaseEditor.hpp"
#include "DatabaseSelector.hpp"
#include <string>
using namespace std;

class User {
    public:
        string username;
        string password;
        int id;
        User() {};
        User(string u, string p): username(u), password(p) {} 
};  


#endif