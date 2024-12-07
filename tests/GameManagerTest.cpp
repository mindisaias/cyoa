#include "gtest/gtest.h"
#include "../include/GameManager.hpp"
#include <iostream>

TEST(GMTestSuite, GMDefaultConstructor) {

   EXPECT_NO_THROW(GameManager TestManager);

}

TEST(GMTestSuite, GMOverloadedConstructor) {

    Database myDB;
    
    EXPECT_NO_THROW(GameManager TestManager(myDB));

}

TEST(GMTestSuite, loadScreens) {

    Database myDB;
    GameManager TestManager(myDB);

    EXPECT_NO_THROW(TestManager.loadScreens());

}

// TEST(GMTestSuite, signIn) { Loops for some reason

//     Database gameDatabase;
//     GameManager TestManager(gameDatabase);

//     EXPECT_NO_THROW(TestManager.signin());

// }

TEST(GMTestSuite, createAccount) {

    Database myDB;
    GameManager TestManager(myDB);

    EXPECT_NO_THROW(TestManager.createAccount());

}