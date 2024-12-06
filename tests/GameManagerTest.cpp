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