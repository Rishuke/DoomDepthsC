cmake_minimum_required(VERSION 3.26)
project(DoomDepthsC C)

set(CMAKE_C_STANDARD 99)

add_executable(DoomDepthsC
        main.c
        creationmap.c
        CaseAction.c
        shopInventaire.c
)
