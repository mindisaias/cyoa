
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"
#include "GameRunner.hpp"
#include "GameCreator.hpp"
#include "Database.hpp"
#include "DatabaseEditor.hpp"
#include "DatabaseSelector.hpp"
#include "User.hpp"
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
        Game currGame;
        
        //TODO: add database
        Database myDB;
        DatabaseEditor DBEditor;
        DatabaseSelector DBSelector;

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
        GameManager() : DBEditor(myDB.DB), DBSelector(myDB.DB) {}
        void run();
        ~GameManager();
};


#endif