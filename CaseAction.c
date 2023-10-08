#include<stdlib.h>
#include<stdio.h>
#include "creationmap.h"
#include "struct.h"
#include "shopInventaire.h"

int isOK(int x,int y,Carte* carte){
    if(x<0 || x>=carte->taille || y<0 || y>=carte->taille || carte->map[x][y]==0){
        return 0;
    }
    return 1;
}

void caseAction(Player* player,Carte* carte){
    char var;
    if(carte->map[player->x][player->y]==1){
        player->gold+=50;
        printf("Vous gagnez 50 d'or! Vous avez maintenant %d or \n",player->gold);
        carte->map[player->x][player->y]=3;
    }
    else if(carte->map[player->x][player->y]==4){
        printf("Vous êtes sur la sorite appuyer sur e pour sortir ou refuser \n");
        scanf(" %c",&var);
        if(var=='e'){
            initCarte(carte);
            printf("Vous êtes au niveau %d Voici une nouvelle carte",carte->donjonLevel);
            initMap(carte,player);
        }
        else{
            return;
        }
    }
    else if(carte->map[player->x][player->y]==6){
        printf("Vous êtes sur le shop appuyer sur e pour entrez ou refuser poliment \n");
        scanf(" %c",&var);
        if(var=='e'){
            buyInShop(player);
            carte->map[player->x][player->y]=3;
        }
        else{
            return;
        }
    }
}

void PlayerMouv(Player* player,Carte* carte, char a){
    if(a=='z'){
        if(isOK(player->x-1,player->y,carte)){
            player->x--;
        }
    }
    else if(a=='s'){
        if(isOK(player->x+1,player->y,carte)){
            player->x++;
        }
    }
    else if(a=='q'){
        if(isOK(player->x,player->y-1,carte)){
            player->y--;
        }
    }
    else if(a=='d'){
        if(isOK(player->x,player->y+1,carte)){
            player->y++;
        }
    }
}
