cmake_minimum_required(VERSION 4.1)
project(CS210Proj2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS210Proj2
        .idea/.gitignore
        .idea/CS210Proj2.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        ArrayStack.h
        main.cpp
        README.md)
