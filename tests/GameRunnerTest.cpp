#include "gtest/gtest.h"
#include "../include/GameRunner.hpp"
#include <iostream>

TEST(GRTestSuite, GRDefaultConstructor) {

   EXPECT_NO_THROW(GameRunner TestRunner());

}

TEST(GRTestSuite, GROverloadedConstructor) {

    Database myDB;
    
    EXPECT_NO_THROW(GameRunner TestRunner(myDB));

}

TEST(GRTestSuite, makeChoice) {

    Database myDB;
    GameRunner TestRunner(myDB);

    EXPECT_NO_THROW(TestRunner.makeChoice());

}

TEST(GRTestSuite, loadGame) {

    Database myDB;
    GameRunner TestRunner(myDB);

    EXPECT_NO_THROW(TestRunner.loadGame(1));

}

// TEST(GRTestSuite, playGame) { seg fault currently

//     Database myDB;
//     Game currGame = Game("Test", "Test", "Test", 1);
//     GameRunner TestRunner(myDB);

//     EXPECT_NO_THROW(TestRunner.playGame(currGame));

// }

TEST(GRTestSuite, quitGame) {

    Database myDB;
    Game currGame;
    GameRunner TestRunner(myDB);

    EXPECT_NO_THROW(TestRunner.quitGame());

}

// TEST(GRTestSuite, start) { seg fault currently


//     Database myDB;
//     Game currGame = Game("Test", "Test", "Test", 1);
//     GameRunner TestRunner(myDB);

//     EXPECT_NO_THROW(TestRunner.start());

// }