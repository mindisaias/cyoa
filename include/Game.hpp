#ifndef GAME_HPP
#define GAME_HPP

#include "Scene.hpp"

class Game {
    public:
        Game(): title("") , author(""), description (""), gameID(-1) {}
        Game(string t, string a, string d, int ID): title(t), author(a), description(d), gameID(ID) {}
        string title;
        string author;
        string description;
        
    private:
        int gameID;
        vector<Scene> scenes; 

};



#endif