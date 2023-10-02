#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <SDL/SDL.h>            // SDL core library
#include <SDL/SDL_image.h>      // SDL_image extension for image loading
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_mixer.h>
#include "StartEndGame.h"
#define taille 5

void initImg(SDL_Surface **img){ //initialisation des pointeurs sans malloc
    /**img[0]=IMG_Load("../images/piece.jpg"); //piece
    img[0]=rotozoomSurfaceXY(img[0],0.0,0.22,0.22,1);
    SDL_SetColorKey(img[0],SDL_SRCCOLORKEY,SDL_MapRGB(img[0]->format,255,255,255));
    if(!img[0])exit(1);
    img[1]= IMG_Load("../images/mob.jpg"); //mob sur chemin
    img[1]=rotozoomSurfaceXY(img[1],0.0,0.22,0.22,1);
    SDL_SetColorKey(img[1],SDL_SRCCOLORKEY,SDL_MapRGB(img[1]->format,255,255,255));
    if(!img[1])exit(1);
    img[2]= IMG_Load("../images/rien.jpg"); //si il n'y a rien sur le chemin
    img[2]=rotozoomSurfaceXY(img[2],0.0,0.22,0.22,1);
    SDL_SetColorKey(img[2],SDL_SRCCOLORKEY,SDL_MapRGB(img[2]->format,255,255,255));
    if(!img[2])exit(1);
    img[3]= IMG_Load("../images/porte.jpg"); //Exit
    img[3]=rotozoomSurfaceXY(img[3],0.0,0.22,0.22,1);
    if(!img[3])exit(1);
    img[4]= IMG_Load("../images/player.jpg"); //Player
    img[4]=rotozoomSurfaceXY(img[4],0.0,0.22,0.22,1);
    if(!img[4])exit(1);
    img[5]= IMG_Load("../images/shop.jpg"); //shop
    img[5]=rotozoomSurfaceXY(img[5],0.0,0.22,0.22,1);
    SDL_SetColorKey(img[5],SDL_SRCCOLORKEY,SDL_MapRGB(img[1]->format,255,255,255));
    if(!img[5])exit(1);
    img[6]= IMG_Load("../images/BOSS.jpg"); //Boss a la fin des chemins
    img[6]=rotozoomSurfaceXY(img[6],0.0,0.22,0.22,1);
    SDL_SetColorKey(img[6],SDL_SRCCOLORKEY,SDL_MapRGB(img[6]->format,255,255,255));
    if(!img[6])exit(1);**/
}

void initMap(int** map){ //0=interdit 1=piece 2=mob 3=rien 4=porte 5=joueur 6=shop 7=boss
    srand(time(NULL));
    int xPlayer=rand()%taille;
    int yPlayer=rand()%taille;
    map[xPlayer][yPlayer]=5;
    int xShop=rand()%taille;
    int yShop=rand()%taille;
    while(map[xShop][yShop]!=0){
        xShop=rand()%taille;
        yShop=rand()%taille;
    }
    map[xShop][yShop]=6;
    int xExit=rand()%taille;
    int yExit=rand()%taille;
    while(map[xExit][yExit]!=0){
        xExit=rand()%taille;
        yExit=rand()%taille;
    }
    map[xExit][yExit]=4;
    int xBoss1=rand()%taille;
    int yBoss1=rand()%taille;
    while(map[xBoss1][yBoss1]!=0){
        xBoss1=rand()%taille;
        yBoss1=rand()%taille;
    }
    map[xBoss1][yBoss1]=7;
    int xBoss2=rand()%taille;
    int yBoss2=rand()%taille;
    while(map[xBoss2][yBoss2]!=0){
        xBoss2=rand()%taille;
        yBoss2=rand()%taille;
    }
    map[xBoss2][yBoss2]=7;
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

int initTest(){ //equivalent du main
    SDL_Surface *ecran=initSDL();
    SDL_Rect FondGlob;
    //initia Image
    SDL_Surface* Img[6];
    initImg(Img);
    //Init map
    //debut game -> afficher map as save in SQLite + inventaire
    int** map=malloc(sizeof(int*)*taille);
    for(int i=0;i<taille;i++){
        map[i]=calloc(taille,sizeof(int));
    }
    initMap(map);
    //gameplay
    SDL_Event event;
    int continuer=1;
    SDL_EnableKeyRepeat(10,10);
    /**while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
        }
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
        FondGlob.x=50;
        FondGlob.y=0;
        SDL_BlitSurface(Img[0], NULL, ecran, &FondGlob);
        FondGlob.x=600;
        FondGlob.y=500;
        SDL_BlitSurface(Img[1], NULL, ecran, &FondGlob);
        FondGlob.x=0;
        FondGlob.y=500;
        SDL_BlitSurface(Img[2], NULL, ecran, &FondGlob);
        SDL_Flip(ecran);
    }**/
    //sauvegarde file

    //Tout fermer
    closeAllSDL();
    freeAll(taille,map);
    return 0;
}