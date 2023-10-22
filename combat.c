//
// Created by alexi on 19/10/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "monster.h"
#include "affichage.h"

int prendreMana(Player* player){
    if(player->mana==100){
        printf("Vous n'en avez pas besoin, il est temps d'attaquer \n");
        return 1;
    }
    if(player->manaPotion>0){
        player->manaPotion--;
        player->mana+=33;
        if(player->mana>100)player->mana=100;
        printf("Vous buvez une potion de mana, voici votre mana : %d, il vous reste %d potion de mana \n",player->mana,player->manaPotion);
        return 0;
    }
    else{
        printf("Vous n'avez pas de potion de mana \n");
        return 1;
    }
}

int prendreVie(Player* player){
    if(player->mana==100){
        printf("Vous n'en avez pas besoin, il est temps d'attaquer \n");
        return 1;
    }
    if(player->lifePotion>0){
        player->hp+=33;
        player->lifePotion--;
        if(player->hp>100)player->hp=100;
        printf("Vous buvez une potion de vie, voici votre vie : %d, il vous reste %d potion de vie \n",player->hp,player->lifePotion);
        return 0;
    }
    else{
        printf("Vous n'avez pas de potion de soin \n");
        return 1;
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

int allMobLife(Monster** monsters,int size){
    int res=0;
    for(int i=0;i<size;i++){
        res+=monsters[i]->hp;
    }
    return res;
}

int combat(Player* player,int boss,int fromSauvegarde, int lvlMap){
    printf("%d %d",boss,fromSauvegarde);
    Monster** monsters=NULL;
    int nbMonstre;
    if(fromSauvegarde){ //si sauvegarde
        if(boss){
            //getBoss
        }
        else {
            //getMobClassique
        }
    }
    else{
        if(boss){
            nbMonstre=1;
            monsters=malloc(sizeof(Monster*)*nbMonstre);
            monsters[0] = createBoss(lvlMap);
        }
        else{
            nbMonstre=rand()%3+1;
            monsters=malloc(sizeof(Monster*)*nbMonstre);
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
        if(boss)afficherASCIIBoss();
        else afficherASCIIMob(nbMonstre,monsters);
        int nbTour=3;
        while(1){
            if(nbTour<=0)break;
            printf("%d tours restant.",nbTour);
            printf("Appuyer sur 1 pour attaquer, 2 pour lancer un sort, 3 pour une potion de soin,4 pour une potion de mana, 5 pour finir votre tour ou 6 pour sauvegarder\n");
            fflush(stdin);
            scanf(" %d",&choice);
            if(choice<=0 || choice>6){
                printf("Entrez une valeur valide \n");
                continue;
            }
            else if(choice==1);//attaquerUnMonstre();
            else if(choice==2);//lancerSort();
            else if(choice==3){
                int notNecessary = prendreVie(player);
                if(notNecessary)continue;
            }
            else if(choice==4){
               int notNecessary = prendreMana(player);
               if(notNecessary)continue;
            }
            else if(choice==5){
                printf("Vous preferer la défense ? \n");
                break;
            }
            else if(choice==6){
                printf("Sauvegarde en cours ... \n");
                //launchSauvegarde
            }
            if(allMobLife(monsters,nbMonstre)<=0){
                //freeAllMob
                printf("Win");
                //getRecompenseFunc
                return 1;
            }
            nbTour--;
        }

        for(int i=0;i<nbMonstre;i++){
            int damage = rand()%(monsters[i]->attackMax-monsters[i]->attackMin+1)+monsters[i]->attackMin-player->defense;
            if(damage<=0){
                printf("Plus de peur que de mal suite à cette miserable attaque");
            }
            else{
                printf("Vous encaissez %d dégat de la part de %s",damage,monsters[i]->name);
                player->hp-=damage;
            }

            if(player->hp<0){
                printf("Vous etes mort au niveau %d de la map",lvlMap);
                return 0;
            }
            printf("Vous avez encore %d vie \n",player->hp);
        }
    }
}