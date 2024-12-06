#include "gtest/gtest.h"
#include "../include/User.hpp"
#include <iostream>

TEST(UserTestSuite, UserDefaultConstructor) {

   EXPECT_NO_THROW(User testUser());

}

TEST(GRTestSuite, UserOverloadedConstructor) {
    
    EXPECT_NO_THROW(User testUser("username", "password"));

}