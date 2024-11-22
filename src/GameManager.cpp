#include "../include/GameManager.hpp"

GameManager::~GameManager() {
    for(const auto& it : screens) {
        delete screens[it.first];
    }
}

User GameManager::signin() const { // MOCK FUNCTION
    User newUser;
    newUser.username = "nander100";
    newUser.password = "password";
    return newUser;
}

User GameManager::createAccount() { // MOCK FUNCTION
    User newUser;
    newUser.username = "nander100";
    newUser.password = "password";
    return newUser;
}

void GameManager::loadScreens() { 
    // welcome
    screens[WELCOME_NAME] = new Scene();
    screens[WELCOME_NAME]->setSceneName(WELCOME_NAME);
    screens[WELCOME_NAME]->editPrompt("Welcome to Make Your Own Adventure (MYOA)!");
    screens[WELCOME_NAME]->addChoice(new Choice("Sign-In", SIGNIN_NAME));
    screens[WELCOME_NAME]->addChoice(new Choice("Create Account", CREATE_ACCOUNT_NAME));
    
    // sign in page
    screens[SIGNIN_NAME] = new Scene();
    screens[SIGNIN_NAME]->setSceneName(SIGNIN_NAME);
    screens[SIGNIN_NAME]->addChoice(new Choice("To Main Menu", MAIN_MENU_NAME));

    // create account
    screens[CREATE_ACCOUNT_NAME] = new Scene();
    screens[CREATE_ACCOUNT_NAME]->setSceneName(CREATE_ACCOUNT_NAME);
    screens[CREATE_ACCOUNT_NAME]->addChoice(new Choice("To Main Menu", MAIN_MENU_NAME));

    // main menu
    screens[MAIN_MENU_NAME] = new Scene();
    screens[MAIN_MENU_NAME]->setSceneName(MAIN_MENU_NAME);
    screens[MAIN_MENU_NAME]->editPrompt("What would you like to do?");
    screens[MAIN_MENU_NAME]->addChoice(new Choice("Play a user created game", MAIN_MENU_NAME));
    screens[MAIN_MENU_NAME]->addChoice(new Choice("Start/resume game editing", CREATE_GAMES_NAME));

    //play game
    screens[PLAY_GAMES_NAME] = new Scene();
    screens[PLAY_GAMES_NAME]->setSceneName(PLAY_GAMES_NAME);
    screens[PLAY_GAMES_NAME]->editPrompt("Selecte a game to play");
    // TODO: choices to be added later afte the user signs in 

}


void GameManager::run() {
    loadScreens(); // Initialize Screnes

    // placeholder variable for scene transitions
    string nextSceneName; 
    int userDecision;

    // starting screen = welcome page 
    currentScene = screens[WELCOME_NAME];
    currentScene->display(cout); // prints out the options
    cin >> userDecision;
    nextSceneName = currentScene->getResultScene(userDecision);
    while(nextSceneName == "") { // checks for valid input
        cout << "Invalid choice. Select a valid option." << endl;
        currentScene->display(cout);
        cin >> userDecision;
        nextSceneName = currentScene->getResultScene(userDecision);
    }

    // sign in or create an account function calls
    if(nextSceneName == SIGNIN_NAME)
        currUser = signin();
    else if(nextSceneName == CREATE_ACCOUNT_NAME)
        currUser = createAccount();

    // Once the user is signed in display the main menu 
    currentScene = screens[MAIN_MENU_NAME];
    cout << "Welcome " << currUser.username << "! ";
    currentScene->display(cout);
    cin >> userDecision;
    nextSceneName = currentScene->getResultScene(userDecision);
    
    // TODO: fill a string list with all the possible playable games from the database
    // TODO: create 


    // create a scene to display the games
}