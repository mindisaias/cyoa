#include "../include/Scene.hpp"
using namespace std;

void Scene::editPrompt(string p) {
    this->prompt = p;
}

Scene::~Scene() {
    for(unsigned int i = 0; i < choices.size(); ++i) {
        delete choices[i];
    }
}

void Scene::addChoice(Choice* choiceToAdd) { choices.push_back(choiceToAdd); }

int Scene::editChoice(int choiceNumber, Choice newChoice) {
    // 0 = success
    // 1 = invalid choice index
    if (choiceNumber > choices.size()) return 1;

    Choice* choiceToChange = choices[choiceNumber];
    choiceToChange->resultScene = newChoice.resultScene;
    choiceToChange->text = newChoice.text;
    return 0;
}

// to output to the screen call display(cout)
void Scene::display(ostream& output) const {
    if(this->prompt == "") return;
    output << this->prompt << endl;
    for(unsigned int i = 0; i < choices.size(); ++i) {
        output << '\t' << i + 1 << ". " << choices[i]->text << endl;
    }
    output << endl;
}

string Scene::getResultScene(int choiceIndex) const {
    if(choiceIndex > choices.size()) return "";
    else return choices[choiceIndex]->resultScene;
}