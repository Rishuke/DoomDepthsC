#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>            // SDL core library
#include <SDL/SDL_image.h>      // SDL_image extension for image loading
#include <SDL/SDL_mixer.h>

SDL_Surface* initSDL(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) { //SDL OK
        SDL_Quit();
        fprintf(stderr, "SDL Initialization Error: %s\n", SDL_GetError());
        exit(1);
    }
    int imgFlags = IMG_INIT_JPG;  //Pour ajouter format; separer par |
    int imgInitResult = IMG_Init(imgFlags);
    if ((imgInitResult & imgFlags) != imgFlags) { //IMG SDL OK
        IMG_Quit();
        fprintf(stderr, "SDL_image Initialization Error: %s\n", IMG_GetError());
        exit(1);
    }
    SDL_Surface *ecran=NULL;
    ecran=SDL_SetVideoMode(800,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF| SDL_RESIZABLE);
    if(ecran==NULL) { //Ecran OK
        fprintf(stderr, "Erreur du lancement de la SDL: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_WM_SetCaption("Map Level %d",NULL);
    return ecran;
}

void closeAllSDL(){
    IMG_Quit();
    SDL_Quit();
}

void freeAll(int size,int** toFree){
    for(int i=0;i<size;i++){
        free(toFree[i]);
    }
    free(toFree);
}