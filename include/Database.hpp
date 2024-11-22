#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <../sqlite3/sqlite3.h>
#include <cstring>

using namespace std;

class Database {
    public:
        Database();
        sqlite3* DB;
        void openDB();
        static int callback(void *NotUsed, int argc, char **argv, char **azColName){
            for(int i = 0; i < argc; i++){
                cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
            }
            cout << endl;
            return 0;
        }
        void insertToGames(string name, string author, string description);
        void insertToScenes(int GameID, string prompt, string SceneName);
        void insertToUsers(string username, string password);
        void insertToChoices(int SceneID, string ChoiceText, int ResultSceneID);


        void deleteFromGames(int gameID);
        void deleteFromScenes(int sceneID);
        void deleteFromChoices(int choiceID);


        void selectFromGames();
        void selectFromScenes();
        void selectFromChoices();
        void selectFromUsers();

        void updateInGames();
        void updateInScenes();
        void updateInChoices();


        ~Database();

        
};

#endif