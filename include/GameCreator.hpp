#ifndef GAME_CREATOR_HPP
#define GAME_CREATOR_HPP

#include "Game.hpp"

class GameCreator {
    public:
        void chooseScene();
        void addScene();
        void editScecne();
        void removeScene();
        void publish();
        void saveScene();
        void chooseGame();
        
    private:
        Scene currScene;
        Game currGame;
};

#endif