#ifndef GAME_RUNNER_HPP
#define GAME_RUNNER_HPP

#include "Game.hpp"

class GameRunner {
    public:
        void makeChoice();
        void chooseGame();
        void quitGame();

    private:
        Scene currScene;
        Game currGame;
};

#endif