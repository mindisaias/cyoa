#include "../include/GameManager.hpp"

GameManager::~GameManager() {
    for(const auto& it : screens) {
        delete screens[it.first];
    }
}

User GameManager::createAccount() { // MOCK FUNCTION
    User newUser;
    // newUser.username = "nander100";
    // newUser.password = "password";
    // return newUser;
    string username;
    string pwd;

    // USERNAME LOOP
    while(1) {
        // init flags 
        bool validName = true;

        // get the username
        cout << "Enter your username: ";
        cin.ignore();
        getline(cin, username);

        // check for spaces in the username
        for(char c: username) {
            if(isspace(c)){
                validName = false;
                break;
            }
        } 

        // verify and break while loop
        if(!validName) 
            cout << "Invalid Username. Username must not contain a space character." << endl;
        else break;

    } // end username loop

    // PASSWORD LOOP
    while(1) {
        // init flags
        bool validPwd       = 0;
        bool containsUpper  = 0;
        bool containsLower  = 0;
        bool containsNumber = 0;
        
        // get password
        cout << "Enter your password: ";
        getline(cin, pwd);

        // ensure bounds to reduce runtime and database size
        if(pwd.length() < 8 || pwd.length() > 64) {
            cout << "Password must be within range [8, 64]" << endl;
            continue;
        }
        
        // checks validity
        for (char c : pwd) {
            if (isupper(c)) {
                containsUpper = true;
            }
            if (islower(c)) {
                containsLower = true;
            }
            if (isdigit(c)) {
                containsNumber = true;
            }
        }
        //password is valid
        if(containsUpper && containsLower && containsNumber) break;

        // password is not valid
        if(!containsUpper)
            cout << "Password must contain at least one uppercase character." << endl;

        if(!containsLower)
            cout << "Password must contain at least one lowercase character." << endl;

        if(!containsNumber) 
            cout << "Password must contain at least one numeric digit (0-9)." << endl;
    } // end password check

    // assign the values and return
    cout << username << endl;
    cout << pwd << endl;
    
    newUser.username = username;
    newUser.password = pwd;

    return newUser;  
}

User GameManager::signin() const { // MOCK FUNCTION
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