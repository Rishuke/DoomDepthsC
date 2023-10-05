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
    if(carte->donjonLevel==0){  //first malloc
        carte->taille=5+(carte->donjonLevel)/2;
        carte->map= malloc(sizeof(int*)*carte->taille);
        for(int i=0;i<carte->taille;i++){
            carte->map[i]=malloc(sizeof(int)*carte->taille);
        }
    }
    carte->donjonLevel++;
    carte->taille=5+(carte->donjonLevel)/2;
    if(carte->taille>10)carte->taille=10;
    carte->map= realloc(carte->map,sizeof(int*)*carte->taille); //realloc autre cas
    for(int i=0;i<carte->taille;i++){
        carte->map[i]=realloc(carte->map[i],sizeof(int)*carte->taille);
    }

    for(int i=0;i<carte->taille;i++){   //remettre à 0
        for(int j=0;j<carte->taille;j++){
            carte->map[i][j]=0;
        }
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

void afficherMap(Carte* carte){
    char texte[8][10]={"        |","  money |","   mob  |","  safe  |","  EXIT  |"," PLAYER |","  SHOP  |"," DANGER |"};
    for(int i=0;i<carte->taille;i++){
        for(int j=0;j<carte->taille;j++){
            printf("%s",texte[carte->map[i][j]]);
        }
        printf("\n");
        for(int k=0;k<carte->taille*9;k++){
            printf("-");
        }
        printf("\n");
    }
    printf("\n \n");
}

void initMap(Carte* carte){ //0=interdit 1=piece 2=mob 3=rien 4=porte 5=joueur 6=shop 7=boss
    int player[2]={0,0};
    int shop[2]={0,0};
    int exit[2]={0,0};
    int boss1[2]={0,0};
    int boss2[2]={0,0};
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
}

int initTest(){ //equivalent du main
    srand(time(NULL));
    Carte* carte=malloc(sizeof(carte));
    carte->donjonLevel=0;
    initCarte(carte);
    initMap(carte);
    afficherMap(carte);
    initCarte(carte);
    initMap(carte);
    afficherMap(carte);
    initCarte(carte);
    initMap(carte);
    afficherMap(carte);
    initCarte(carte);
    initMap(carte);
    afficherMap(carte);
    initCarte(carte);
    initMap(carte);
    afficherMap(carte);
    initCarte(carte);
    initMap(carte);
    afficherMap(carte);
    //gameplay

    //sauvegarde file

    //Desalloc
    freeAll(carte);
    free(carte);
    return 0;
}