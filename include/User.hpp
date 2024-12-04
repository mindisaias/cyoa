#ifndef USER_HPP
#define USER_HPP
#include <../sqlite3/sqlite3.h>
#include <string>
using namespace std;

class User {
    public:
        string username;
        string password;
        int id;
        User(string u, string p): username(u), password(p) {} 
        bool isValidCredentials(string username, string password, sqlite3* db);
        void addUser(string username, string password, sqlite3* db);
};  


#endif