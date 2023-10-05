cmake_minimum_required(VERSION 3.26)
project(DoomDepthsC C)

set(CMAKE_C_STANDARD 99)

add_executable(DoomDepthsC main.c
        struct.h
        creationmap.c
        creationmap.h
)

target_link_libraries(DoomDepthsC SDL)
target_link_libraries(DoomDepthsC SDL_image)
target_link_libraries(DoomDepthsC SDL_ttf)
target_link_libraries(DoomDepthsC SDL_mixer)
target_link_libraries(DoomDepthsC SDL_gfx)
