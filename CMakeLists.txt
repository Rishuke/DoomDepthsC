cmake_minimum_required(VERSION 3.26)
project(DoomDepthsC C)

set(CMAKE_C_STANDARD 99)

add_executable(DoomDepthsC main.c
        struct.h
        creationmap.c
        creationmap.h
        CaseAction.c
        CaseAction.h
        shopInventaire.h
        shopInventaire.c
        combat.h
        combat.c
        Player.h
        Player.c
        monster.h
        monster.c
        affichage.h
        affichage.c
)
