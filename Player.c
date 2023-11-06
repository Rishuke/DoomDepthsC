#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
<<<<<<< HEAD
#include <conio.h>
#include <windows.h>
=======
//#include <windows.h>
>>>>>>> origin
#define DEFENSESTART 10
#define ATTACKSTART 20

Player* createPlayer(){
    char name[10];
    printf("Entrez un nom : ");
    fflush(stdin);
    int result = scanf(" %s", name);

    while (1) {
        if (result == 1 && strlen(name) < 10) {
            Player *player = malloc(sizeof(Player));
            player->name = malloc(strlen(name) + 1);
            strcpy(player->name, name);
            player->hp = 100;
            player->defense = DEFENSESTART+1;
            player->attack = ATTACKSTART+3;
            player->gold = 0;
            player->mana = 100;
            player->xp = 0;
            player->xpForNextLvl = 10;
            player->level = 1;
            player->x = -1;
            player->y = -1;
            player->lifePotion = 1;
            player->manaPotion = 1;
            player->sizeInventaire=0;
            return player;
        } else {
            printf("La saisie n'était pas valide.\n");
            fflush(stdin);
            printf("Entrez un nom : ");
            result = scanf("%s", name);
        }
    }
}

void changeLevel(Player* player){
    while(player->xp>player->xpForNextLvl){
        player->level++;
        player->xp-=player->xpForNextLvl;
        player->attack+=3;
        player->defense+=1;
        player->xpForNextLvl*=1.2;
        printf("%s augmente d'un niveau, vous voilà au niveau %d avec \n attaque : %d \n defense : %d\n",player->name,player->level,player->attack,player->defense);
    }
}
<<<<<<< HEAD

void setTextColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void afficherVieJoueur(int hp){
    setTextColor(12);
=======
/*
void setTextColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}*/

void afficherVieJoueur(int hp){
   // setTextColor(12);
>>>>>>> origin
    printf("Vie : [ ");
    for(int i=0;i<100;i++){
        if(i<hp){
            printf("#");
        }
        else{
            printf("-");
        }
    }
    printf(" ] %d/100 \n",hp);
<<<<<<< HEAD
    setTextColor(7);
=======
   // setTextColor(7);
>>>>>>> origin
}


void afficherManaJoueur(int mana){
<<<<<<< HEAD
    setTextColor(9);
=======
   // setTextColor(9);
>>>>>>> origin
    printf("Mana: [ ");
    for(int i=0;i<100;i++){
        if(i<mana){
            printf("#");
        }
        else{
            printf("-");
        }
    }
    printf(" ] %d/100\n",mana);
<<<<<<< HEAD
    setTextColor(7);
}
=======
   // setTextColor(7);
}
>>>>>>> origin
