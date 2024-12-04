#ifndef DATABASEEDITOR_HPP
#define DATABASEEDITOR_HPP

#include <iostream>
#include "Database.hpp"
#include <../sqlite3/sqlite3.h>
#include <cstring>

using namespace std;

class DatabaseEditor {
    public:
        sqlite3* DB;

        DatabaseEditor(sqlite3* db) : DB(db) {}
        
        void insertToGames(string name, string author, string description);
        void insertToScenes(int GameID, string prompt, string SceneName);
        void insertToUsers(string username, string password);
        void insertToChoices(int SceneID, string ChoiceText, int ResultSceneID);

        void deleteFromGames(int gameID);
};

#endif