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
        //void editScene();
        //void addChoice();
        void printSceneNames();
        //void chooseScene();
        //void removeScene();
        //void publish();
        //void saveScene();
        //void chooseGame();
        
    private:
        void addScene(const string & prompt, const string & name);




        Scene currScene;
        Game currGame;

};

#endif