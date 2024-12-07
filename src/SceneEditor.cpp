#include "../include/SceneEditor.hpp"
#include <iostream> 
#include <limits>
using namespace std;

void wait(){
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}
void clearTerminal() {

    std::cout << "\033[2J\033[1;1H";
}

void SceneEditor::printEditMenu() {
    if(currScene == nullptr) {
        cout << "Current Scene: No Scene"<<  "\n";
    }
    else {
        cout << "Current Scene: " << currScene->getSceneName() <<  "\n";
    }
    cout << "Enter a value 1-5:\n";
    cout << "1. Add Choice\n";
    cout << "2. Edit Choice\n";
    cout << "3. Edit Prompt\n";
    cout << "4. Display Scene\n";
    cout << "5. Change Scene\n";
    cout << "6. Quit\n";
}
void SceneEditor::changeScene() {
    clearTerminal();
    if(currGame.gameScenes.size() == 0) {
        cout << "No Scenes\n";
        cout << "Press Enter to continue" << endl;
        wait();
        return;
    }
    vector<Scene*> scenes;
    scenes.reserve(currGame.gameScenes.size());
    int i = 1;
    for(const auto & sceneName : currGame.gameScenes) {
        cout << i << ". "<< sceneName.first << "\n";
        scenes.push_back(sceneName.second);
        i++;
    }
    cout << "Select Scene: ";
    int choice;
    cin >> choice;
    currScene = (scenes.at(choice - 1));
}

void SceneEditor::addChoice() {
    clearTerminal();
    cout << "Current Scene:\n";
    currScene->display(cout);

    cout << "Enter Choice Text:\n";
    string text;
    cin.ignore();
    getline(cin,text);
    
    cout <<"\n Select the Resultant Scene:\n";
    string resultScene;

    vector<Scene*> scenes;
    scenes.reserve(currGame.gameScenes.size());
    int i = 1;
    for(const auto & sceneName : currGame.gameScenes) {
        cout << i << ". "<< sceneName.first << "\n";
        scenes.push_back(sceneName.second);
        i++;
    }
    cout << "Select Scene: ";
    int choice;
    cin >> choice;
    resultScene = scenes.at(choice - 1)->getSceneName();
    
    Choice * newChoice = new Choice(text,resultScene);

    currScene->addChoice(newChoice);


}

void SceneEditor::start() {
    int choice = 0;
    do{
        clearTerminal();
        printEditMenu();
        cin >> choice;
        if(choice == 1 && (currScene->getSceneName() != "")) {
            addChoice();
        }
        else if(choice == 2 && (currScene->getSceneName() != "")) { // edit choice
            editChoice();
        }
        else if(choice == 3 && (currScene->getSceneName() != "")) { // edit scene prompt
            editPrompt();
        }
        else if(choice == 4 && (currScene->getSceneName() != "")) {
            clearTerminal();
            currScene->display(cout);
            cout << "Press Enter to continue\n";
            wait();
        }
        else if(choice == 5) {
            changeScene();
        }
        else if(choice == 6) {
            return;
        }
        else {
            cin.clear();
            cin.ignore();
        }
    
    }while(true);
}

void SceneEditor::editChoice() {
    if(currScene->choices.size() == 0) {
        return;
    }
    cout << "Which choice would you like the edit?" << endl;
    currScene->display(cout);
    int input;
    cin >> input;
    // int i = 1;
    // for(const auto & sceneName : currGame.gameScenes) {
    //     cout << i << ". "<< sceneName.first << "\n";
    //     i++;
    // }
    // cout << "Press Enter To Continue" << endl;

    
    if (input <= currScene->choices.size()) {
        string newText = "dsfsdf";
        string newResult = "sdfdsfs";

        cout << "Enter new choice text: ";
        cin.ignore();
        getline(cin, newText);
        cout << endl;

        int i = 1;
        for(const auto & sceneName : currGame.gameScenes) {
            cout << i << ". "<< sceneName.first << "\n";
            i++;
        }
        
        cout << "Pick a result: ";
        cin.ignore();
        getline(cin, newResult);
        cout << endl;        
        currScene->choices.at(input - 1)->text = newText;
        currScene->choices.at(input - 1)->resultScene = newResult;
        
    }    
}

void SceneEditor::editPrompt() {
    cout << "What would you like to change the scene to? (Press enter to quit)" << endl;
    string userInput;
    cin.ignore();
    getline(cin, userInput);
    if(userInput[0] == '\n') {
        return;
    }
    else {
        currScene->editPrompt(userInput);
    }
}