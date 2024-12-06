#include "gtest/gtest.h"
#include "../include/GameCreator.hpp"
#include <iostream>

using namespace std;

TEST(GCTestSuite, GCConstructor) {

   Database myDB;

   EXPECT_NO_THROW(GameCreator GC(myDB));

}

TEST(GCTestSuite, PrintMenu) {

   Database myDB;
   GameCreator GC(myDB);

   EXPECT_NO_THROW(GC.printMenu());

}

TEST(GCTestSuite, PrintSceneNames) {

   Database myDB;
   GameCreator GC(myDB);

   EXPECT_NO_THROW(GC.printSceneNames());

}


TEST(GCTestSuite, addScene) {

   Database myDB;
   GameCreator GC(myDB);

   string prompt = "Prompt";
   string sceneName = "sceneName";

   EXPECT_NO_THROW(GC.addScene());

}

TEST(GCTestSuite, start) {

   Database myDB;
   User currUser;
   GameCreator GC(myDB);

   EXPECT_NO_THROW(GC.start(currUser));
}