#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>            // SDL core library
#include <SDL/SDL_image.h>      // SDL_image extension for image loading
#include <SDL/SDL_ttf.h>        // SDL_ttf extension for TrueType fonts
#include <SDL/SDL_mixer.h>      // SDL_mixer extension for audio
#include "creationmap.h"

int main (int argc, char* argv[])
{
    printf("%d",initTest());
    return EXIT_SUCCESS;
}


