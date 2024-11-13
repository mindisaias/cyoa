add_library(simpleLibrary
    Choice.cpp
    Database.cpp 
    Game.cpp 
    GameCreator.cpp 
    GameRunner.cpp 
    Program.cpp 
    Scene.cpp 
    User.cpp 
)

add_executable(Program 
    main.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})