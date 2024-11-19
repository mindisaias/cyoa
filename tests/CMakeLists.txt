cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(googletest)

add_executable(runChoiceTests
    ChoiceTest.cpp
)

add_executable(runDBTests
    DBTest.cpp
)

add_executable(runGameTests
    GameTest.cpp
)

add_executable(runGameCreatorTests
    GameCreatorTest.cpp
)

add_executable(runGameRunnerTests
    GameRunnerTest.cpp
)

add_executable(runGameManagerTests
    GameManagerTest.cpp
)

add_executable(runSceneTests
    SceneTest.cpp
)

add_executable(runUserTests
    UserTest.cpp
)

target_link_libraries(runChoiceTests gmock gtest gtest_main)
target_link_libraries(runChoiceTests simpleLibrary databaseLibrary) 

target_link_libraries(runDBTests gmock gtest gtest_main)
target_link_libraries(runDBTests simpleLibrary databaseLibrary) 

target_link_libraries(runGameTests gmock gtest gtest_main)
target_link_libraries(runGameTests simpleLibrary databaseLibrary) 

target_link_libraries(runGameCreatorTests gmock gtest gtest_main)
target_link_libraries(runGameCreatorTests simpleLibrary databaseLibrary) 

target_link_libraries(runGameRunnerTests gmock gtest gtest_main)
target_link_libraries(runGameRunnerTests simpleLibrary databaseLibrary) 

target_link_libraries(runGameManagerTests gmock gtest gtest_main)
target_link_libraries(runGameManagerTests simpleLibrary databaseLibrary) 

target_link_libraries(runSceneTests gmock gtest gtest_main)
target_link_libraries(runSceneTests simpleLibrary databaseLibrary) 

target_link_libraries(runUserTests gmock gtest gtest_main)
target_link_libraries(runUserTests simpleLibrary databaseLibrary) 


