//
// Created by alexi on 19/10/2023.
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "monster.h"


int allMobLife(Monster** monsters,int size){
    int res=0;
    for(int i=0;i<size;i++){
        res+=monsters[i]->hp;
    }
    return res;
}

int combat(Player* player,Monster** monsters,int boss,int fromSauvegarde, int lvlMap){
    char* imgPlayer[]={
            "       .-\'\'-.        ",
            "      /-.{}  \\        ",
            "      | _\\__.|        ",
            "      \\/^)^ \\/       ",
            "       \\ =  /         ",
            "  .---./`--`\\.--._    ",
            " /     `;--'`     \\   ",
            ";        /`       ;    ",
            "|       |*        |    ",
            "/   |   |     |    \\  ",
            "|    \\  |*    /    |  ",
            "\\_   |\\_|____/|  __/ ",
            "  \\__//======\\\\__/  ",
            "  / //_      _\\\\ \\  ",
            "  -'  |`\"\"\"`|  `-   ",
    };


    int nbMonstre;
    if(fromSauvegarde){ //si sauvegarde

    }
    else{
        if(boss){
            nbMonstre=0;
        }
        else{
            nbMonstre=rand()%3;
            for(int i=0;i<nbMonstre;i++){
                int type=rand()%2;
                if(type){
                    monsters[i]= createDemon(lvlMap);
                }
                else{
                    monsters[i]= createPhantom(lvlMap);
                }
            }
        }
    }
    int choice;
    printf("Au non c'est une embuscade \n");
    while(1){
        int nbTour=3;
        while(1){
            if(nbTour<=0)break;
            printf("%d tours restant.",nbTour);
            printf("Appuyer sur 1 pour attaquer, 2 pour lancer un sort, 3 pour une potion de soin, "
                   "4 pour une potion de mana, 5 pour finir votre tour ou 6 pour sauvegarder\n");
            fflush(stdin);
            scanf(" %d",&choice);
            if(choice<=0 || choice>6){
                printf("Entrez une valeur valide \n");
                continue;
            }
            else if(choice==1);//attaquerUnMonstre();
            else if(choice==2);//lancerSort();
            else if(choice==3){
                if(player->lifePotion>0){
                    printf("Vous buvez une potion de mana, voici votre vie : %d, il vous reste %d potion de vie \n",player->hp,player->hp);
                    player->hp+=33;
                    player->lifePotion--;
                    if(player->hp>100)player->hp=100;
                }
                else{
                    printf("Vous n'avez pas de potion de soin \n");
                    continue;
                }
            }
            else if(choice==4){
                if(player->manaPotion>0){
                    printf("Vous buvez une potion de mana, voici votre mana : %d, il vous reste %d potion de mana \n",player->mana,player->manaPotion);
                    player->manaPotion--;
                    player->mana+=33;
                    if(player->mana>100)player->mana=100;
                }
                else{
                    printf("Vous n'avez pas de potion de mana \n");
                    continue;
                }
            }
            else if(choice==5){
                printf("Vous préferer la défense ? \n");
                break;
            }
            else if(choice==6){
                printf("Sauvegarde en cours ... \n");
                //launchSauvegarde
            }
            if(allMobLife(monsters,nbMonstre)<=0){
                //freeAllMob
                printf("Win");
                return 1;
            }
            nbTour--;
        }
        for(int i=0;i<nbMonstre;i++){
            int damage = rand()%(monsters[i]->attackMax-monsters[i]->attackMin+1)+monsters[i]->attackMin;
            player->hp-=damage;
            printf("Vous encaissez %d dégat de la part de %s",damage,monsters[i]->name);
            if(player->hp<0){
                printf("Vous êtes mort au niveau %d de la map",lvlMap);
                return 0;
            }
            printf("Vous avez encore %d vie \n",player->hp);
        }
    }




    /**int size=strlen(imgPlayer[0])+strlen(imgPlayer2[0]);


    for(int i=0;i<14;i++){
        for(int j=0; j<strlen(imgPlayer[i]);j++){
            printf("%c",imgPlayer[i][j]);
        }
        printf("   ");
        for(int j=0;j< strlen(imgPlayer2[i]);j++){
            printf("%c",imgPlayer[i][j]);
        }
        printf("\n");
    }**/

}