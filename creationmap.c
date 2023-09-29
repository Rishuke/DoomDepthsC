#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>            // SDL core library
#include <SDL/SDL_image.h>      // SDL_image extension for image loading
#include <SDL/SDL_ttf.h>        // SDL_ttf extension for TrueType fonts
#include <SDL/SDL_mixer.h>

SDL_Surface* initSDL(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { //SDL OK
        fprintf(stderr, "SDL Initialization Error: %s\n", SDL_GetError());
        exit(1);
    }
    int imgFlags = IMG_INIT_JPG;  //Pour ajouter format; separer par |
    int imgInitResult = IMG_Init(imgFlags);
    if ((imgInitResult & imgFlags) != imgFlags) { //IMG SDL OK
        fprintf(stderr, "SDL_image Initialization Error: %s\n", IMG_GetError());
        exit(1);
    }
    SDL_Surface *ecran=NULL;
    ecran=SDL_SetVideoMode(scree,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF| SDL_RESIZABLE);
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

void initImg(SDL_Surface **piece,SDL_Surface **player){ //Stocké image dans un tableau + initialisation
    *piece= IMG_Load("../images/piece.jpg");
    if(!*piece)exit(1); //2 = problème de chargement
    *player= IMG_Load("../images/player.jpg");
    if(!*player)exit(1);
}


int initTest(){
    SDL_Surface *ecran=initSDL();
    //initia Image
    //SDL_Rect* FondImg=malloc(sizeof(SDL_Rect)*4); //Stocker les fonds associer img;
    SDL_Surface *piece=NULL;
    SDL_Rect FondPiece;
    SDL_Surface *player=NULL;
    initImg(&piece,&player);
    //debut game -> afficher map as save in SQLite + inventaire

    //gameplay
    SDL_Event event;
    int continuer=1;
    SDL_EnableKeyRepeat(10,10);
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
        }
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,125,125,125));
        FondPiece.x=0;
        FondPiece.y=0;
        SDL_BlitSurface(piece, NULL, ecran, &FondPiece);
        FondPiece.x=600;
        FondPiece.y=600;
        SDL_BlitSurface(player, NULL, ecran, &FondPiece);
        SDL_Flip(ecran);
    }
    //sauvegarde file

    //Tout fermer
    closeAllSDL();
    return 0;
}