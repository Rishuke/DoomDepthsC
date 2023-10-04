#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include "struct.h"

void freeAll(Carte* carte){
    for(int i=0;i<carte->taille;i++){
        free(carte->map[i]);
    }
    free(carte->map);
}

void initCarte(Carte* carte){
    freeAll(carte); //remettre tout à 0
    carte->taille=10+(carte->donjonLevel)/2;
    carte->donjonLevel++;
    carte->map=malloc(sizeof(int*)*carte->taille);
    for(int i=0;i<carte->taille;i++){
        carte->map[i]=calloc(carte->taille,sizeof(int));
    }
}

void creerCoordo(int* coordo,Carte* carte,int res){
    int x=rand()%(carte->taille);
    int y=rand()%(carte->taille);
    while(carte->map[x][y]!=0){
        x=rand()%(carte->taille);
        y=rand()%(carte->taille);
    }
    coordo[0]=x;
    coordo[1]=y;
    carte->map[x][y]=res;
}

void linkedPoint(int* coordoStart,int* coordoEnd,int** map){
    int actuX=coordoStart[0]; //horizontale
    int actuY=coordoStart[1]; //verticale
    while(actuX!=coordoEnd[0] || actuY!=coordoEnd[1]){
        if(map[actuX][actuY]==0){
            if(actuX<coordoEnd[0]){
                map[actuX][actuY]=rand()%3+1;
                actuX++;
            }
            else if(actuX>coordoEnd[0]){
                map[actuX][actuY]=rand()%3+1;
                actuX--;
            }
            else if(actuY>coordoEnd[1]){
                map[actuX][actuY]=rand()%3+1;
                actuY--;
            }
            else{
                map[actuX][actuY]=rand()%3+1;
                actuY++;
            }
        }
        else{
            if(actuX<coordoEnd[0]){
                actuX++;
            }
            else if(actuX>coordoEnd[0]){
                actuX--;
            }
            else if(actuY>coordoEnd[1] && actuX==coordoEnd[0]){
                actuY--;
            }
            else{
                actuY++;
            }
        }
    }
}

void initMap(Carte* carte){ //0=interdit 1=piece 2=mob 3=rien 4=porte 5=joueur 6=shop 7=boss
    srand(time(NULL));
    int player[2];
    int shop[2];
    int exit[2];
    int boss1[2];
    int boss2[2];
    creerCoordo(player,carte,5);
    creerCoordo(shop,carte,6);
    creerCoordo(exit,carte,4);
    creerCoordo(boss1,carte,7);
    creerCoordo(boss2,carte,7);
    linkedPoint(player,shop,carte->map);   //player[0]=horizontale player[1]=verticale
    linkedPoint(player,boss2,carte->map);
    linkedPoint(player,boss1,carte->map);
    linkedPoint(player,exit,carte->map);
    linkedPoint(boss1,exit,carte->map);
    linkedPoint(boss2,exit,carte->map);
    linkedPoint(boss1,boss2,carte->map);
    linkedPoint(boss1,shop,carte->map);
    linkedPoint(boss2,shop,carte->map);
    for(int i=0;i<carte->taille;i++){
        for(int j=0;j<carte->taille;j++){
            printf("%d ",carte->map[i][j]);
        }
        printf("\n");
    }
    printf("%d    %d  %d \n",carte->map[exit[0]][exit[1]],exit[0],exit[1]);
    printf("%d    %d  %d \n",carte->map[shop[0]][shop[1]],shop[0],shop[1]);
    printf("%d    %d  %d \n",carte->map[boss1[0]][boss1[1]],boss1[0],boss1[1]);
    printf("%d    %d  %d \n",carte->map[boss2[0]][boss2[1]],boss2[0],boss2[1]);
}

int initTest(){ //equivalent du main
    Carte* carte=malloc(sizeof(carte));
    carte->donjonLevel=0;
    initCarte(carte);
    initMap(carte);
    //gameplay

    //sauvegarde file

    //Desalloc
    freeAll(carte);
    free(carte);
    return 0;
}