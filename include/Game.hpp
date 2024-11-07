#ifndef GAME_HPP
#define GAME_HPP

#include "Scene.hpp"

class Game {
    public:
        string title;
        string author;
        string description;
        
    private:
        int gameID;
        vector<Scene> scenes; 

};



#endif