#include<stdio.h>
#include <conio.h>
#include "creationmap.h"
#include "struct.h"
#include "shopInventaire.h"
#include "combat.h"

int isOK(int x,int y,Carte* carte){
    if(x<0 || x>=carte->taille || y<0 || y>=carte->taille || carte->map[x][y]==0){
        return 0;
    }
    return 1;
}

void stepBack(char preMouv,Player* player){
    if(preMouv=='z')player->x++;
    else if(preMouv=='s')player->x--;
    else if(preMouv=='d')player->y--;
    else if(preMouv=='q')player->y++;
}

int caseAction(Player* player,Carte* carte,char preMouv){
    char var;
    if(carte->map[player->x][player->y]==1){
        player->gold+=50;
        printf("Vous gagnez 50 d'or! Vous avez maintenant %d or \n",player->gold);
        carte->map[player->x][player->y]=3;
    }
    else if(carte->map[player->x][player->y]==2){
        int win = combat(player,0,0,carte->donjonLevel,carte);
        if(!win){
            printf("C'est la fin de votre aventure adieu \n");
            return 0;
        }
        carte->map[player->x][player->y]=3;
    }
    else if(carte->map[player->x][player->y]==4){
        printf("Vous etes sur la sorite appuyer sur e pour sortir ou refuser \n");
        fflush(stdin);
        scanf(" %c",&var);
        if(var=='e'){
            initCarte(carte);
            printf("Vous etes au niveau %d Voici une nouvelle carte \n",carte->donjonLevel);
            initMap(carte,player);
        }
        else{
            stepBack(preMouv,player);
        }
    }
    else if(carte->map[player->x][player->y]==6){
        printf("Vous etes sur le shop appuyer sur e pour entrez ou refuser poliment \n");
        fflush(stdin);
        scanf(" %c",&var);
        if(var=='e'){
            buyInShop(player);
            carte->map[player->x][player->y]=3;
        }
        else{
            stepBack(preMouv,player);
        }
    }
    else if(carte->map[player->x][player->y]==7){
        int win = combat(player,1,0,carte->donjonLevel,carte);
        if(!win){
            printf("C'est la fin de votre aventure adieu \n");
            return 0;
        }
        carte->map[player->x][player->y]=3;
    }
    return 1;
}

char PlayerMouv(Player* player,Carte* carte, char a){
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
    return a;
}
