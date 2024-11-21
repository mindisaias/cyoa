#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <../sqlite3/sqlite3.h>

using namespace std;

class Database {
    public:
        Database();
        sqlite3* DB;
        void openDB();
        void insertToGames(string name, string author, string description);
        void insertToScenes(int GameID, string prompt, string SceneName);
        void insertToUsers(string username, string password);
        void insertToChoices(int SceneID, string ChoiceText, int ResultSceneID);
        void deleteFromDB();
        void selectFromDB();
        ~Database();

        
};

#endif