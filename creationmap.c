#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#define taille 10

void freeAll(int size,int** toFree){
    for(int i=0;i<size;i++){
        free(toFree[i]);
    }
    free(toFree);
}

void creerCoordo(int* coordo,int** map,int res){
    int x=rand()%taille;
    int y=rand()%taille;
    while(map[x][y]!=0){
        x=rand()%taille;
        y=rand()%taille;
    }
    coordo[0]=x;
    coordo[1]=y;
    map[x][y]=res;
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

void initMap(int** map){ //0=interdit 1=piece 2=mob 3=rien 4=porte 5=joueur 6=shop 7=boss
    srand(time(NULL));
    int player[2];
    int shop[2];
    int exit[2];
    int boss1[2];
    int boss2[2];
    creerCoordo(player,map,5);
    creerCoordo(shop,map,6);
    creerCoordo(exit,map,4);
    creerCoordo(boss1,map,7);
    creerCoordo(boss2,map,7);
    linkedPoint(player,shop,map);   //player[0]=horizontale player[1]=verticale
    linkedPoint(player,boss2,map);
    linkedPoint(player,boss1,map);
    linkedPoint(player,exit,map);
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("%d    %d  %d \n",map[exit[0]][exit[1]],exit[0],exit[1]);
    printf("%d    %d  %d \n",map[shop[0]][shop[1]],shop[0],shop[1]);
    printf("%d    %d  %d \n",map[boss1[0]][boss1[1]],boss1[0],boss1[1]);
    printf("%d    %d  %d \n",map[boss2[0]][boss2[1]],boss2[0],boss2[1]);
}

int initTest(){ //equivalent du main
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