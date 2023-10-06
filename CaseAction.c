#include<stdlib.h>
#include<stdio.h>
#include "creationmap.h"
#include "struct.h"

int isOK(int x,int y,Carte* carte){
    if(x<0 || x>=carte->taille || y<0 || y>=carte->taille || carte->map[x][y]==0){
        return 0;
    }
    return 1;
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

void caseAction(Player* player,Carte* carte){
    char var;
    if(carte->map[player->x][player->y]==1){
        printf("Vous gagnez 50 d'or ! \n");
        player->gold+=50;
        carte->map[player->x][player->y]=3;
    }
    else if(carte->map[player->x][player->y]==4){
        printf("Vous êtes sur la sorite appuyer sur e pour sortir \n");
        scanf(" %c",&var);
        if(var=='e'){
            initCarte(carte);
            printf("Vous êtes au niveau %d Voici une nouvelle carte",carte->donjonLevel);
            initMap(carte,player);
        }
    }
    else if(carte->map[player->x][player->y]==6){
        printf("Vous êtes sur la sorite appuyer sur e pour entrez dans le shop \n");
        scanf(" %c",&var);
        if(var=='e'){
            printf("Achetez au shop !! \n");
        }
    }
}
