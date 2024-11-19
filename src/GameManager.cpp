#include "../include/GameManager.hpp"

void GameManager::loadScrenes() {
    // Scene declaration
    Scene* welcomePage = new Scene();
    welcomePage->setSceneName("WP");

    Scene* signIn = new Scene();
    signIn->setSceneName("SI");

    Scene* createAccount = new Scene();
    createAccount->setSceneName("CA");

    Scene* mainMenu = new Scene();
    mainMenu->setSceneName("MM");

    // ADD SCENE OPTIONS
    // Welcome page
    welcomePage->editPrompt("Welcome to Make Your Own Adventure (MYOA)!");
    welcomePage->addChoice(new Choice("Sign-In", "SI"));
    welcomePage->addChoice(new Choice("Create Account", "CA"));

    // Sign-in
    // Create Account
    // Main Menu
    mainMenu->editPrompt("What would you like to do?");
    

    


}

void GameManager::run() {

}