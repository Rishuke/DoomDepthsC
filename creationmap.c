#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#define taille 5

void freeAll(int size,int** toFree){
    for(int i=0;i<size;i++){
        free(toFree[i]);
    }
    free(toFree);
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

    //debut game -> afficher map as save in SQLite + inventaire
    int** map=malloc(sizeof(int*)*taille);
    for(int i=0;i<taille;i++){
        map[i]=calloc(taille,sizeof(int));
    }
    initMap(map);
    //gameplay
    //sauvegarde file

    //Desalloc
    freeAll(taille,map);
    return 0;
}