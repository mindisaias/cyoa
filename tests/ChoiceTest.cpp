#include "gtest/gtest.h"
#include "../include/Choice.hpp"
#include <iostream>

using namespace std;

TEST(ChoiceTestSuite, choiceDefaultConstructor) {

    Choice choice;

    EXPECT_TRUE(choice.text == "");
    EXPECT_TRUE(choice.resultScene == "");

}

TEST(ChoiceTestSuite, choiceOverloadedConstructor) {

    Choice choice("ChoiceText", "ChoiceResultSceneNum");

    EXPECT_TRUE(choice.text == "ChoiceText");
    EXPECT_TRUE(choice.resultScene == "ChoiceResultSceneNum");

}
