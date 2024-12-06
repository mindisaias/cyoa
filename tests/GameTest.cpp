#include "gtest/gtest.h"
#include "../include/Game.hpp"
#include <iostream>

TEST(GameTestSuite, GameDefaultConstructor) {

   EXPECT_NO_THROW(Game testGame());

}

TEST(GameTestSuite, GameOverloadedConstructor) {
    
    EXPECT_NO_THROW(Game testGame("title", "author", "description", 1));

}