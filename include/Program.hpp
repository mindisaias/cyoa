
#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Game.hpp"
#include "GameRunner.hpp"
#include "GameCreator.hpp"
#include "User.hpp"

class Program {
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