#ifndef GAME_CREATOR_HPP
#define GAME_CREATOR_HPP

#include "Game.hpp"
#include "User.hpp"
#include "Database.hpp"
#include <map> 
#include <limits>

using namespace std;

class GameCreator {
    public:
        GameCreator(Database& db) : DB(db) {}
        //helpers
        void start(User currUser);
        void printMenu();
        //functions for game
        void addScene();
        void printSceneNames();
        //void removeScene();
       
        void editScene();

        //void publish();
        void save();
        //void chooseGame();

        
    private:
        void addScene(const string & prompt, const string & name);
        Game currGame;
        User currUser;
        Database DB;


};

#endif