#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>
#include "struct.h"
#include "CaseAction.h"
#include "player.h"
#include "shopInventaire.h"
#define tailleInventaire 6

void freeAll(Carte* carte){
    for(int i=0;i<carte->taille;i++){
        free(carte->map[i]);
    }
    free(carte->map);
}

void initCarte(Carte* carte){
    carte->donjonLevel++;
    carte->taille=5+(carte->donjonLevel/2);
    if(carte->taille>10)carte->taille=10;
    if(carte->donjonLevel==1){  //first malloc
        carte->map= malloc(sizeof(int*)*carte->taille);
        for(int i=0;i<carte->taille;i++){
            carte->map[i]=malloc(sizeof(int)*carte->taille);
        }
    }
    else{
        carte->map=realloc(carte->map,sizeof(int*)*carte->taille); //realloc autre cas
        for(int i=0;i<carte->taille;i++){
            carte->map[i]=realloc(carte->map[i],sizeof(int)*carte->taille);
        }
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

void afficherMap(Carte* carte,int x,int y){
    char texte[8][10]={"        |","  money |","   mob  |","  safe  |","  EXIT  |"," PLAYER |","  SHOP  |"," DANGER |"};
    for(int i=0;i<carte->taille;i++){
        for(int j=0;j<carte->taille;j++){
            if(i==x && j==y){
                printf("%s",texte[5]);
            }
            else{
                printf("%s",texte[carte->map[i][j]]);
            }
        }
        printf("\n");
        for(int k=0;k<carte->taille*9;k++){
            printf("-");
        }
        printf("\n");
    }
    printf("\n \n");
}

void initMap(Carte* carte,Player* playInit){ //0=interdit 1=piece 2=mob 3=rien 4=porte 5=joueur 6=shop 7=boss
    int player[2]={0,0};
    player[0]=rand()%carte->taille;
    player[1]=rand()%carte->taille;
    playInit->x=player[0];
    playInit->y=player[1];  //initialisé joueur position en le dissociant de la map
    carte->map[player[0]][player[1]]=3;
    int shop[2]={0,0};
    int exit[2]={0,0};
    int boss1[2]={0,0};
    int boss2[2]={0,0};
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
    Player* player= createPlayer();
    Monster** listDeMonstre = NULL;
    Carte* carte=malloc(sizeof(Carte));
    carte->donjonLevel=0;
    initCarte(carte);
    initMap(carte,player);
    afficherMap(carte,player->x,player->y);
    char choice;
    //gameplay
    while(1){
        printf("Entrez z / q / s / d , 0 pour changer d'arme, 1 pour des infos sur la partie, 7 pour sauvegarder ou 8 pour quitter \n");
        fflush(stdin);
        scanf(" %c",&choice);
        if(choice=='8')break;
        else if(choice=='z' || choice=='q' || choice=='s' || choice=='d'){
            caseAction(player,carte,listDeMonstre);
            PlayerMouv(player,carte,choice);
            caseAction(player,carte,listDeMonstre);
        }
        else if(choice=='0'){
            changerItem(player);
        }
        else if(choice=='1'){
            printf("%d or \n",player->gold);   //voir état joueur
        }
        else{printf("La valeur n'est pas valide \n");}
        afficherMap(carte,player->x,player->y);
    }
    //sauvegarde file

    //Desalloc
    freeAll(carte);
    free(carte);
    for(int i=0;i<tailleInventaire;i++){
        free(player->items[i]->name);
        free(player->items[i]);
    }
    free(player->items);
    free(player);
    return 0;
}