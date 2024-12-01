#include <gtest/gtest.h>
#include "../include/Scene.hpp"
using namespace std;

TEST(SceneDisplayTest, PromptOnly) { // TEST 1
    ostringstream output; // create a string stream

    //initialization
    Scene myScene("Sample Prompt", "Scene Name");

    // output 
    myScene.display(output);
    string res = output.str();

    EXPECT_EQ(res, "Sample Prompt\n\n");
}

TEST(SceneDisplayTest, Nothing) { // TEST 1
    ostringstream output; // create a string stream

    //initialization
    Scene myScene;

    // output 
    myScene.display(output);
    string res = output.str();

    EXPECT_EQ(res, "");
}


TEST(SceneDisplayTest, OneOptions) { // TEST 3
    ostringstream output; // create a string stream

    //initialization
    Scene myScene("Sample Prompt", "Scene Name");
    Choice* choice1 = new Choice("Option 1", "Scene 3");

    // add the choices to the scene
    myScene.addChoice(choice1);
    myScene.display(output);


    string res = output.str();
    EXPECT_EQ(res, "Sample Prompt\n\t1. Option 1\n\n");
}

TEST(SceneDisplayTest, ThreeOptions) { // TEST 4
    ostringstream output; // create a string stream

    //initialization
    Scene myScene("Sample Prompt", "Scene 654");
    Choice* choice1 = new Choice("Option 1", "Scene Name");
    Choice* choice2 = new Choice("Option 2", "Scene Name");
    Choice* choice3 = new Choice("Option 3", "Scene Name");

    // add the choices to the scene
    myScene.addChoice(choice1);
    myScene.addChoice(choice2);
    myScene.addChoice(choice3);

    myScene.display(output);


    string res = output.str();
    EXPECT_EQ(res, "Sample Prompt\n\t1. Option 1\n\t2. Option 2\n\t3. Option 3\n\n");
}

TEST(SceneEditPrompt, ChangePrompt) { // TEST 5
    ostringstream output; // create a string stream

    //initialization
    Scene myScene("Sample Prompt", "Scene 654");
    myScene.editPrompt("New Prompt");

    // output 
    myScene.display(output);
    string res = output.str();

    EXPECT_EQ(res, "New Prompt\n\n");
}

TEST(SceneEditChoice, ChangeOneScene) { // TEST 6
    ostringstream output; // create a string stream

    //initialization
    Scene myScene("Sample Prompt", "Scene 654");
    Choice* choice1 = new Choice("Option 1", "Scene 654");
    Choice newChoice("New Choice", "Scene 654");

    // add the choices to the scene
    myScene.addChoice(choice1);
    myScene.editChoice(1, newChoice);
    // output 
    myScene.display(output);
    string res = output.str();
    EXPECT_EQ(res, "Sample Prompt\n\t1. New Choice\n\n");
}

TEST(SceneName, GetSceneName) { // TEST 7
    Scene myScene("Sample Prompt", "Scene 654");
    string res = myScene.getSceneName();

    EXPECT_EQ(res, "Scene 654");
}

TEST(SceneName, SetSceneName) { // TEST 7
    Scene myScene("Sample Prompt", "Scene 654");
    myScene.setSceneName("Scene 4");
    string res = myScene.getSceneName();

    EXPECT_EQ(res, "Scene 4");
}