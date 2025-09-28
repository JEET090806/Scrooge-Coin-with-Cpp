# Minimum version of CMake needed
cmake_minimum_required(VERSION 3.10)

# Name of our project
project(ScroogeCoin)

# Use modern C++ (version 11 is simple and has all we need)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where our header files are (the "include" folder)
include_directories(include)

# Create the final program named "scrooge_coin" from our .cpp files
add_executable(scrooge_coin 
    src/main.cpp 
    src/Transaction.cpp
    src/UTXOPool.cpp
    src/TxHandler.cpp
)