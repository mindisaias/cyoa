#include "gtest/gtest.h"
#include "../include/SceneEditor.hpp"
#include <iostream>

TEST(SceneEditorSuite, SceneEditorConstructor) {

   EXPECT_NO_THROW(SceneEditor SE());

}

TEST(SceneEditorSuite, SceneEditorOverloadedConstructor) {

    Game testGame;
    
    EXPECT_NO_THROW(SceneEditor SE(testGame));

}

TEST(SceneEditorSuite, printEditMenu) {

    Game testGame;
    SceneEditor SE(testGame);
    
    EXPECT_NO_THROW(SE.printEditMenu());

}

TEST(SceneEditorSuite, changeScene) {
    
}
