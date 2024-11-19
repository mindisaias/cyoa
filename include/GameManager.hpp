
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"
#include "GameRunner.hpp"
#include "GameCreator.hpp"
#include "User.hpp"


class GameManager {
    private:
        Game currGame;
        //TODO: add database
        User currUser;
        GameCreator GC;
        GameRunner GR;
    public:
        void run();
};


#endif