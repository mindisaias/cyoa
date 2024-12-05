#ifndef SCENE_HPP
#define SCENE_HPP

#include "Choice.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Scene {
    public:
        Scene(): prompt("") {}
        Scene(const string p, const string n): prompt(p), sceneName(n) {}
        ~Scene();
        void editPrompt(const string p) ;
        int editChoice(int, Choice);
        void addChoice(Choice*);
        void display(ostream&) const;
        string getSceneName() const { return sceneName; }
        string getResultScene(int) const; // takes in the index of the choice and returns the name of the scene
        void setSceneName(const string n) { this->sceneName = n; }
        string prompt;
        vector<Choice*> choices;
        string sceneName;
};

#endif 