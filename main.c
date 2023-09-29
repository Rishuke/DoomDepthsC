#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>            // SDL core library
#include <SDL/SDL_image.h>      // SDL_image extension for image loading
#include <SDL/SDL_ttf.h>        // SDL_ttf extension for TrueType fonts
#include <SDL/SDL_mixer.h>      // SDL_mixer extension for audio


int main (int argc, char* argv[])
{
    SDL_Surface *ecran=NULL;
    SDL_Init(SDL_INIT_VIDEO);
    ecran=SDL_SetVideoMode(800,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF| SDL_RESIZABLE);
    SDL_WM_SetCaption("Lourd ca marche pas",NULL);
    if(ecran==NULL)
    {
        fprintf(stderr,"Erreur du lancement de la SDL: %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_Flip(ecran);
    SDL_Quit();
    return EXIT_SUCCESS;
}

