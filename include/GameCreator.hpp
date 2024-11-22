#ifndef GAME_CREATOR_HPP
#define GAME_CREATOR_HPP

#include "Game.hpp"
#include <map> 
#include <limits>

using namespace std;

class GameCreator {
    public:
        //helpers
        void start();
        void printMenu();
        //functions for game
        void addScene();
        void printSceneNames();
        //void removeScene();
       
        void editScene();

        //void publish();
        //void saveScene();
        //void chooseGame();
        
    private:
        void addScene(const string & prompt, const string & name);
        Game currGame;

};

#endif