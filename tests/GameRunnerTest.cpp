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