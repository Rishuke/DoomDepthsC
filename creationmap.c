#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>            // SDL core library
#include <SDL/SDL_image.h>      // SDL_image extension for image loading
#include <SDL/SDL_ttf.h>        // SDL_ttf extension for TrueType fonts
#include <SDL/SDL_mixer.h>

SDL_Surface* initSDL(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { //SDL OK
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

void initImg(SDL_Surface **img){ //initialisation des pointeurs sans malloc
    img[0]=IMG_Load("../images/piece.jpg");
    if(!img[0])exit(1);
    img[1]= IMG_Load("../images/player.jpg");
    if(!img[1])exit(1);
    img[2]= IMG_Load("../images/porte.jpg");
}


int initTest(){
    SDL_Surface *ecran=initSDL();
    SDL_Rect FondGlob;
    //initia Image
    SDL_Surface* Img[3];
    initImg(Img);
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
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
        FondGlob.x=0;
        FondGlob.y=0;
        SDL_BlitSurface(Img[0], NULL, ecran, &FondGlob);
        FondGlob.x=600;
        FondGlob.y=600;
        SDL_BlitSurface(Img[1], NULL, ecran, &FondGlob);
        FondGlob.x=0;
        SDL_BlitSurface(Img[2], NULL, ecran, &FondGlob);
        SDL_Flip(ecran);
    }
    //sauvegarde file

    //Tout fermer
    closeAllSDL();
    return 0;
}