#include "gtest/gtest.h"
#include "../include/GameCreator.hpp"
#include <iostream>

TEST(GCTestSuite, GCConstructor) {

   Database myDB;

   EXPECT_NO_THROW(GameCreator GC(myDB));

}