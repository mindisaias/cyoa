#include "../include/GameRunner.hpp"
#include "Game.hpp"
#include "GameCreator.hpp"
#include "Scene.hpp"

void GameRunner::makeChoice() {

    Scene choice;
    choice.display(cout);
}
void GameRunner::loadGame(int gameID) {
    auto scenes = DB.DBSelector.selectFromScenes(gameID);
    map<int, string> SIDtoName;
    for (const auto sceneRow : scenes) {
        currScene = new Scene(sceneRow[3], sceneRow[1]);
        currGame.gameScenes[currScene->sceneName] = currScene;
        SIDtoName[stoi(sceneRow[0])] = currScene->sceneName;
    }

    for (const auto sceneRow : scenes) {
        auto choiceRows = DB.DBSelector.selectFromChoices(stoi(sceneRow[0]));
        for (const auto choiceRow : choiceRows) {
            Choice* currChoice = new Choice(choiceRow[3], SIDtoName[stoi(choiceRow[4])]);
            currGame.gameScenes[sceneRow[1]]->addChoice(currChoice);
        }

        
    }
    
}
void GameRunner::quitGame() {
    return;
}

void GameRunner::start() {

    //Show games to play
    vector<vector<string>> games = DB.DBSelector.selectFromGames();

    map<int, vector<string>> itoGame;
    int i = 1;
    for (const auto game : games) {
            cout << i << ". " << game[1] << " by " << game[2] << endl;
            cout << "    " << game[4] << endl;
            itoGame[i] = game;
            i++;
    }
    

    //User picks game to play (choosegame)
    int gameNum;
    cout << "Choose Game" << endl;
    cin >> gameNum;
    int gameID = stoi(itoGame[gameNum].at(0));
    currGame = Game(itoGame[gameNum][1], itoGame[gameNum][2], itoGame[gameNum][4], stoi(itoGame[gameNum][0]));

    //Game gets loaded into memory
    loadGame(gameID);

    
    //Play game (makechoice)
    playGame(currGame);
    
    //Quit game (quitgame)
}

void GameRunner::playGame(Game currentGame) {

    // Initialize variables
    Scene* currentScene = currentGame.first;
    string nextScene = "";
    int userChoice = -1;
    bool endReached = false; 

    // run the game while the end has not been reached
    while(!endReached) {
        currentScene->display(cout); // print the scene
        cin >> userChoice; // get the option
        nextScene = currentScene->getResultScene(userChoice); // find the next scene
        endReached = currentGame.gameScenes[nextScene]->choices.size() == 0; // reassign endReached
    }
    cout << "Thank you for playing " << currentGame.title << ". To return to the main menu, press any key.\n";
    int buffer;
    cin >> buffer; 
}
