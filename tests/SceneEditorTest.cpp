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