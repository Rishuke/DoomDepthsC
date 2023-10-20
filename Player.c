#include "struct.h"
#include <stdlib.h>
#include "string.h"
#include <stdio.h>

Player* createPlayer(){
    char name[50];
    printf("Entrez un nom : ");
    fflush(stdin);
    int result = scanf(" %s", name);

    while (1) {
        if (result == 1 && strlen(name) < 10) {
            Player *player = malloc(sizeof(Player));
            player->name = malloc(strlen(name) + 1);
            strcpy(player->name, name);
            player->hp = 100;
            player->defense = 15;
            player->attack = 20;
            player->gold = 0;
            player->items = malloc(sizeof (Item*) * 6);
            for(int i=0;i<6;i++){
                player->items[i]=malloc(sizeof(Item));
                player->items[i]->name=malloc(sizeof(char)*100);
                strcpy(player->items[i]->name,"Vide");
            }
            player->mana = 100;
            player->xp = 0;
            player->xpForNextLvl = 10;
            player->level = 1;
            player->x = -1;
            player->y = -1;
            player->lifePotion = 1;
            player->manaPotion = 1;
            return player;
        } else {
            printf("La saisie n'était pas valide.\n");
            fflush(stdin);
            printf("Entrez un nom : ");
            result = scanf("%s", name);
        }
    }
};