#ifndef GAME_RUNNER_HPP
#define GAME_RUNNER_HPP

#include "Game.hpp"
#include "Database.hpp"

class GameRunner {
    public:
        Database DB;
        GameRunner(Database& db) : DB(db) {}
        void makeChoice();
        void loadGame(int gameID);
        void playGame(Game);
        void quitGame();
        void start();

    private:
        Scene* currScene;
        Game currGame;
};

#endif