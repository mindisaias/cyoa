#include "../include/GameCreator.hpp"
#include <iostream> 
using namespace std;


void clearTerminal() {
    for (int i = 0; i < 100; i++) {
        cout << '\n';
    }
}

void GameCreator::printMenu() {
    clearTerminal();
    cout << "1. Add Scene\n";
    cout << "2. Edit Scene\n";
    cout << "3. Remove Scene\n";
    cout << "4. Print Scene Names\n";
    cout << "5. Quit\n";

    

}


void GameCreator::start(){

    int choice = 0;
    do{

        if(choice == 1) {
            //add scene
        }
        else if(choice == 2) {

        }
        else if(choice == 3) {

        }
        else if(choice == 4) {

        }
        else if(choice == 5) {

        }
        else {
            
        }


        cin >> choice;
    }while(choice)

}
void GameCreator::addScene() {

    string name;
    string prompt;
    cout << "Enter the name of your scene (One Word): "; 
    cin >> name;
    
    cout << "Enter the prompt for scene \"" << name << "\":\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,prompt);

    addScene(prompt,name);

}
void GameCreator::addScene(const string & prompt,const string & name) {

    Scene * newScene = new Scene(prompt,name);

    currGame.gameScenes[name] = newScene;

}

void GameCreator::printSceneNames() {
    int i = 1;
    for(const auto & sceneName : currGame.gameScenes) {
        cout << i << ". "<< sceneName.first << "\n";
        i++;
    }
}

