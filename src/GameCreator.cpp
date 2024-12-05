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
    //make sure to add game detail stuffs 
    DB.DBEditor.insertToGames(currGame.title,currGame.author,currGame.description);

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
            save();
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

void GameCreator::save() {

    auto games = DB.DBSelector.selectFromGames();
    int gameid;
    for(const auto game : games) {
        if(game.at(1) == currGame.title) {
            gameid = stoi(game.at(0));
        }
    }
    DB.DBEditor.deleteFromGames(gameid);
    DB.DBEditor.insertToGames(currGame.title,currGame.author,currGame.description);
    games = DB.DBSelector.selectFromGames();
    for(const auto game : games) {
        if(game.at(1) == currGame.title) {
            gameid = stoi(game.at(0));
        }
    }
    for(const auto tuple : currGame.gameScenes) {
        DB.DBEditor.insertToScenes(gameid,tuple.second->prompt,tuple.first);
    }

    auto scenes = DB.DBSelector.selectFromScenes(gameid);

    int resultid = -1;
    int i = 0; //curr scene row
    for (const auto tuple : currGame.gameScenes) { //scene from gamescenes

        for(const auto mychoice : tuple.second->choices) {  // choice from scene
            for(const auto sceneRow : scenes) {
                if(sceneRow.at(1) == mychoice->resultScene) {
                    resultid = stoi(sceneRow.at(0));
                    break;
                }
            }
            DB.DBEditor.insertToChoices(stoi(scenes.at(i).at(0)),mychoice->text,resultid);
        }
        i++;
    }
    
    
}

