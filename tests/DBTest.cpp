#include "gtest/gtest.h"
#include "../include/Database.hpp"
#include <iostream>

using namespace std;

int main() {
    Database myDB;
    string myGame = "myGame";

    cout << "Hello world" << endl;

    return 0;
}



/*TEST(DatabaseTestSuite, openDBTest) {

    Database* testDB;

    EXPECT_NO_THROW(testDB->openDB());

}

TEST(DatabaseTestSuite, deleteFromDBTest) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.deleteFromDB());

}

TEST(DatabaseTestSuite, selectFromDBTest) {

    Database testDB;
    testDB.openDB();

    EXPECT_NO_THROW(testDB.selectFromDB());

}*/