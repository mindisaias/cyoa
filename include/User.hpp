#ifndef USER_HPP
#define USER_HPP

#include <string>
using namespace std;

class User {
    public:
        string username;
        string password;
        int id;
        bool isValidCredentials(string username, string password);
    
};


#endif