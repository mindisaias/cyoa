#ifndef SCENE_EDITOR_HPP
#define SCENE_EDITOR_HPP

#include "Game.hpp"
#include "Scene.hpp"

class SceneEditor {
    public:
        SceneEditor(Game & currGame) : currGame(currGame) {}
        void start();
        void printEditMenu();
        void changeScene();
        void addChoice();
        void editChoice();
        void editPrompt();
        Scene * currScene;
        Game & currGame;
    
};


#endif 