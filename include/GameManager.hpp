
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"
#include "GameRunner.hpp"
#include "GameCreator.hpp"
#include "User.hpp"
#include "Database.hpp"
#include "DatabaseEditor.hpp"
#include "DatabaseSelector.hpp"
#include "../sqlite3/sqlite3.h"
#include <map>

// SCREEN NAME DEF
#define WELCOME_NAME          "WP"
#define SIGNIN_NAME           "SI"
#define CREATE_ACCOUNT_NAME   "CA"
#define MAIN_MENU_NAME        "MM"
#define LIST_GAMES_NAME       "LG"
#define PLAY_GAMES_NAME       "PG"
#define CREATE_GAMES_NAME     "CG"
#define QUIT_GAME_NAME        "QG"

class GameManager {
    private:
        Database gameDatabase;
        Game currGame;
        User currUser;
        GameCreator GC;
        GameRunner GR;
        map<string, Scene*> screens; 
        Scene* currentScene;

        // HELPER FUNCTIONS
        void loadScreens(); // loads all of the default screens
        User signin() ; // returns the name of the user that was signed in
        User createAccount(); // returns the name of the
    public:
        GameManager();
        GameManager(Database* db) : gameDatabase(db) {}
        void run();
        ~GameManager();
};


#endif