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
            cout << "\033[2J\033[1;1H";
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
        cout << "\033[2J\033[1;1H";
        if(!containsUpper)
            cout << "Password must contain at least one uppercase character." << endl;

        if(!containsLower)
            cout << "Password must contain at least one lowercase character." << endl;

        if(!containsNumber) 
            cout << "Password must contain at least one numeric digit (0-9)." << endl;
    } // end password check

    // assign the values and return
    newUser.username = username;
    newUser.password = pwd;
    gameDatabase.DBEditor.insertToUsers(newUser.username, newUser.password);
    return newUser;  
}

User GameManager::signin()  {
    User newUser;
    bool flag = true;
    string userName = "";
    string pwd = "";
    vector<vector<string>> users = gameDatabase.DBSelector.selectFromUsers();
    
    do {
        // get the username
        cout << "Enter your username: ";
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        getline(cin, userName);

        //get password
        cout << "Enter your password: ";
        getline(cin, pwd);


        for (const auto user : users) {
            cout << user[1] << " " << user[2] << endl;
            if (user[1] == userName && user[2] == pwd) {
                flag = false;
            }
            else if (user[1] == userName && user[2] != pwd) {
                cout << "Invalid password" << endl;
            }
        }
        if (flag == true) {
            cout << "User not found, please try again" << endl << endl;
            userName = "";
            pwd = "";
        }

    } while (flag == true);

    // assign the values and return
    newUser.username = userName;
    newUser.password = pwd;
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

    // main menua
    screens[MAIN_MENU_NAME] = new Scene();
    screens[MAIN_MENU_NAME]->setSceneName(MAIN_MENU_NAME);
    screens[MAIN_MENU_NAME]->editPrompt("What would you like to do?");
    screens[MAIN_MENU_NAME]->addChoice(new Choice("Play a user created game", PLAY_GAMES_NAME));
    screens[MAIN_MENU_NAME]->addChoice(new Choice("Start/resume game editing", CREATE_GAMES_NAME));
    screens[MAIN_MENU_NAME]->addChoice(new Choice("Quit game", QUIT_GAME_NAME));

    //play game
    screens[PLAY_GAMES_NAME] = new Scene();
    screens[PLAY_GAMES_NAME]->setSceneName(PLAY_GAMES_NAME);
    screens[PLAY_GAMES_NAME]->editPrompt("Selecte a game to play");
    // TODO: choices to be added later afte the user signs in 

}


void GameManager::run() {
    loadScreens(); // Initialize Screnes
    cout << "\033[2J\033[1;1H";
    // placeholder variable for scene transitions
    string nextSceneName; 
    int userDecision;

    // prints the welcome screen
    currentScene = screens[WELCOME_NAME];
    currentScene->display(cout); // prints out the options
    cin >> userDecision;
    cout << "\033[2J\033[1;1H";
    nextSceneName = currentScene->getResultScene(userDecision);
    while(nextSceneName == "") { // checks for valid input
        cout << "Invalid choice. Select a valid option." << endl;
        currentScene->display(cout);
        cin >> userDecision;
        cout << "\033[2J\033[1;1H";
        nextSceneName = currentScene->getResultScene(userDecision);
    }

    // sign in or create an account function calls
    if(nextSceneName == SIGNIN_NAME)
        currUser = signin();
    else if(nextSceneName == CREATE_ACCOUNT_NAME)
        currUser = createAccount();

    // Once the user is signed in display the main menu 
    cout << "\033[2J\033[1;1H";
    currentScene = screens[MAIN_MENU_NAME];
    cout << "Welcome " << currUser.username << "! ";

    while(nextSceneName != QUIT_GAME_NAME) {
        currentScene->display(cout);
        cin >> userDecision;
        cout << "\033[2J\033[1;1H";
        nextSceneName = currentScene->getResultScene(userDecision);

        if(nextSceneName == PLAY_GAMES_NAME){
            GR.start();
            cout << "\033[2J\033[1;1H";
        }  
        else if(nextSceneName == CREATE_GAMES_NAME) {
            GC.start();
            cout << "\033[2J\033[1;1H";
        }
        else if(nextSceneName == QUIT_GAME_NAME) {
            return; // end the program
        }
    }
    return;
}