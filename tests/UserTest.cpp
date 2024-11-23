#include "gtest/gtest.h"
#include "../include/User.hpp"
#include <../sqlite3/sqlite3.h>

sqlite3* db; // some database name
TEST(UserValid, isValid){
    User* user1 = new User("Angel", "Angel123");
    EXPECT_TRUE(user1->isValidCredentials("Angel", "Angel123", db));
}

TEST(UserValid, isNotValidPassword){
    User* user2 = new User("Angel", "Angel122");
    EXPECT_FALSE(user2->isValidCredentials("Angel", "Angel122", db));
}

TEST(UserValid, isNotValid){
    User* user3 = new User("Angle", "Angel3");
    EXPECT_FALSE(user3->isValidCredentials("Angle", "Angel3", db));
}