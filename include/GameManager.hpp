
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"
#include "GameRunner.hpp"
#include "GameCreator.hpp"
#include "User.hpp"
#include <map>

class GameManager {
    private:
        Game currGame;
        //TODO: add database
        User currUser;
        GameCreator GC;
        GameRunner GR;
        map<string, Scene> screnes; 

        // HELPER FUNCTIONS
        void loadScrenes(); // loads all of the default screnes         
    public:
        void run();
};


#endif