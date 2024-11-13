cmake_minimum_required(VERSION 3.2)

# Add the library
add_library(databaseLibrary
sqlite3.c 
)

# Set properties for SQLite to be treated as C code
set_source_files_properties(sqlite3.c PROPERTIES LANGUAGE C)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find and link libraries necessary for pthread and dynamic loading
find_package(Threads REQUIRED)
target_link_libraries(databaseLibrary PRIVATE ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS})
