#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>
#include "struct.h"
#include "CaseAction.h"
#include "combat.h"
#include "Player.h"
#include "shopInventaire.h"
#include "sauvegarde_player.h"
#include "sauvegarde_inventaire.h"
#include "sauvegarde_mob.h"



void afficherAll(Carte* carte,Player* player){
    printf("%s a \n mana : %d \n hp : %d \n attaque : %d \n defense : %d \n niveau : %d \n xp : %d/%d \n gold : %d \n potion vie : %d \n potion mana : %d \n levelMap : %d \n"
    ,player->name,player->mana,player->hp,player->attack,player->defense,player->level,player->xp,player->xpForNextLvl,player->gold,player->lifePotion,player->manaPotion,carte->donjonLevel);

}
void freeAll(Carte* carte,Player* player){
    for(int i=0;i<carte->taille;i++){
        free(carte->map[i]);
    }
    free(carte->map);
    free(carte);
    for(int i=0;i<player->sizeInventaire;i++){
        free(player->items[i]->name);
        free(player->items[i]);
    }
    if(player->sizeInventaire!=0)free(player->items);
    free(player);
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
        if(carte->donjonLevel%2==0){  //cela veut dire que taille a changé par rapport tours précédents
            carte->map=realloc(carte->map,sizeof(int*)*carte->taille); //realloc autre cas
            carte->map[carte->taille-1]=malloc(sizeof(int)*carte->taille);
            for(int i=0;i<carte->taille-1;i++){
                carte->map[i]=realloc(carte->map[i],sizeof(int)*carte->taille);
            }
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

void safeZone(int* coordo,Carte* carte){
    for(int i=coordo[0]-1;i<=coordo[0]+1;i++){
        for(int j=coordo[1]-1;j<=coordo[1]+1;j++){
            if(i>=0 && j>=0 && j<carte->taille && i<carte->taille && carte->map[i][j]!=4 && carte->map[i][j]!=6){
                carte->map[i][j]=rand()%3+1;
            }
        }
    }
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
    safeZone(shop,carte);
    safeZone(exit,carte);
    carte->map[player[0]][player[1]]=3;
}

int initTest(){ //equivalent du main  
    srand(time(NULL));
    Player* player;
    Carte* carte;
    player= createPlayer();
    Monster** monsters =  NULL;
    int nbMonstre =  chargerMonstre(monsters, 1);
    int win;
    if(nbMonstre){
    	if(!strcmp(monsters[0]->name,"BOSS")){
    			win =combat(player,1,1, 0,NULL);
    	}else{
    		win = combat(player,0,1, 0,NULL);
    	}
    }	
    
    freeAllMob(monsters,nbMonstre);
    
    if(!win){
	for(int i=0;i<player->sizeInventaire;i++){
        free(player->items[i]->name);
        free(player->items[i]);
    }
    if(player->sizeInventaire!=0)free(player->items);
    free(player);
	}
    carte=malloc(sizeof(Carte));
    carte->donjonLevel=0;
    initCarte(carte);
    initMap(carte,player);
    afficherMap(carte,player->x,player->y);
    char choice;
    //gameplay
    while(1){
        printf("Entrez z / q / s / d , 0 pour changer d'arme, 1 pour des infos sur la partie, 7 pour sauvegarder,  8 pour quitter et sauvegarder et  9 pour recommencer \n");
        fflush(stdin);
        scanf(" %c",&choice);
        if(choice=='8'){
            resetDatabase("game.db");
            save_player_to_db(player);
            sauvegarderInventaire(player);
            break;
        }
        else if(choice=='z' || choice=='q' || choice=='s' || choice=='d'){
            char preMouv=PlayerMouv(player,carte,choice);
            int isDead=caseAction(player,carte,preMouv);
            if(!isDead){
                freeAll(carte,player);
                return 0;
            }
        }
        else if(choice=='0'){
            changerItem(player);
        }
        else if(choice=='1'){
            afficherAll(carte,player);   //voir état joueur
        }
        else if(choice =='7' ){
            resetDatabase("game.db");
        	save_player_to_db(player);
        	sauvegarderInventaire(player);
        	
        }
        else if(choice =='9' ){
        	
        }
        else{printf("La valeur n'est pas valide \n");}
        afficherMap(carte,player->x,player->y);
    }
    //Desalloc
    freeAll(carte,player);
    return 0;
}
