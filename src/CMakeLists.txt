add_library(simpleLibrary
    Choice.cpp
    Database.cpp 
    DatabaseEditor.cpp
    DatabaseSelector.cpp
    Game.cpp 
    GameCreator.cpp 
    GameRunner.cpp 
    GameManager.cpp 
    Scene.cpp 
    User.cpp 
    SceneEditor.cpp
)
add_library(Choice Choice.cpp)
add_library(Database Database.cpp) 
add_library(Game Game.cpp)
add_library(GameCreator GameCreator.cpp)
add_library(GameRunner GameRunner.cpp)
add_library(GameManager GameManager.cpp)
add_library(Scene Scene.cpp)
add_library(User User.cpp)

target_link_libraries(simpleLibrary databaseLibrary) 

add_executable(${CMAKE_PROJECT_NAME} 
    main.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

target_link_libraries(${CMAKE_PROJECT_NAME} simpleLibrary)