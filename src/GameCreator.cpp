#include "../include/GameCreator.hpp"
#include "../include/SceneEditor.hpp"
#include <iostream> 
using namespace std;


void wait2(){
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}
void clearTerminal2() {
    // for (int i = 0; i < 100; i++) {
    //     cout << '\n';
    // }

    std::cout << "\033[2J\033[1;1H";
}

void GameCreator::printMenu() {
    cout << "Enter a value 1-5:\n";
    cout << "1. Add Scene\n";
    cout << "2. Edit Scene\n";
    cout << "3. Remove Scene\n";
    cout << "4. Print Scene Names\n";
    cout << "5. Quit\n";
}


void GameCreator::start(){

    int choice = 0;
    do{
        clearTerminal2();
        printMenu();
        cin >> choice;
        if(choice == 1) {
            addScene();
        }
        else if(choice == 2) {
            editScene();
        }
        else if(choice == 3) {
            //remove Scene 
        }
        else if(choice == 4) {
            printSceneNames();
        }
        else if(choice == 5) {
            return;
        }
        else {
            cin.clear();
            cin.ignore();
        }
    
    }while(true);

}
void GameCreator::addScene() {

    string name;
    string prompt;
    cout << "Enter the name of your scene: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,name);
    cout << "Enter the prompt for scene \"" << name << "\":\n";
    getline(cin,prompt);

    addScene(prompt,name);

}
void GameCreator::addScene(const string & prompt,const string & name) {

    Scene * newScene = new Scene(prompt,name);

    currGame.gameScenes[name] = newScene;
  
    if(currGame.first == nullptr) {
        currGame.first = newScene;
    }

}

void GameCreator::printSceneNames() {
    clearTerminal2();
    int i = 1;
    for(const auto & sceneName : currGame.gameScenes) {
        cout << i << ". "<< sceneName.first << "\n";
        i++;
    }
    cout << "Press Enter To Continue" << endl;
    wait2();

}


void GameCreator::editScene() {
    SceneEditor editor(currGame);
    editor.start();

}

void save() {
    
}

