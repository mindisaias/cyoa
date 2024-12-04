#ifndef GAME_HPP
#define GAME_HPP
#include <map>
#include "Scene.hpp"

class Game {
    public:
        Game(): title("") , author(""), description (""), gameID(-1) {}
        Game(string t, string a, string d, int ID): title(t), author(a), description(d), gameID(ID) {}
        string title;
        string author;
        string description;
        int gameID;
        map<string, Scene*> gameScenes; 
        Scene * first = nullptr;

};



#endif