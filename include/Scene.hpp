#ifndef SCENE_HPP
#define SCENE_HPP

#include "Choice.hpp"
#include <vector>

class Scene {
    public:
        Scene(): prompt("") {}
        Scene(string p): prompt(p) {}
        
        string prompt;
        vector<Choice> choices;
        
        void editPrompt();
        void editChoice();
        void display() const;
    private:
        int sceneID;
};


#endif