//
// Created by alexi on 19/10/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "monster.h"
#include "Player.h"
#include "affichage.h"
#include "shopInventaire.h"

void attaqueMonstre(Monster** monsters,int *size,Player* player){
    int choice;
    printf("Qui voulez vous attaquer \n");
    scanf(" %d",&choice);
    while(choice<1 || choice>*size){
        printf("Entrez une valeur valide \n");
        scanf(" %d",&choice);
    }
    int damage = player->attack-(monsters[choice-1]->defense/2);
    if(damage<=0){
        printf("C'est pitoyable \n");
    }else{
        printf("%s inflige %d degat a %s \n",player->name,damage,monsters[choice-1]->name);
        monsters[choice-1]->hp-=damage;
    }
    if(monsters[choice-1]->hp<=0){
        printf("Vous avez tue %s \n",monsters[choice-1]->name);
        for(int i=choice-1;i<*size-1;i++){
            monsters[i]->name= realloc(monsters[i]->name,sizeof(char)*(strlen(monsters[i+1]->name)+1));
            strcpy(monsters[i]->name,monsters[i+1]->name);
            monsters[i]->hp=monsters[i+1]->hp;
            monsters[i]->attackMax=monsters[i+1]->attackMax;
            monsters[i]->attackMin=monsters[i+1]->attackMin;
            monsters[i]->defense=monsters[i+1]->defense;
            monsters[i]->xpEarn=monsters[i+1]->xpEarn;
        }
        (*size)--;
        free(monsters[*size]->name);
        free(monsters[*size]);
        if(*size!=0){
            afficherASCIIMob(*size,monsters);
        }
        if(*size==0){
            free(monsters);
            return;
        }
        monsters= realloc(monsters,sizeof(Monster*)*(*size));
    }
}

void freeAllMob(Monster** monsters,int size){
    for(int i=0;i<size;i++){
        free(monsters[i]->name);
        free(monsters[i]);
    }
    if(size!=0)free(monsters);
}

char randomChar() {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const size_t charsetSize = sizeof(charset) - 1;
    return charset[rand() % charsetSize];
}

char* generateRandomName(int length) {
    char* name= malloc(sizeof(char)*(length+1));
    for (int i = 0; i < length; i++) {
        name[i] = randomChar();
    }
    name[length] = '\0';
    return name;
}

void xpAllMob(Monster** monsters,int size,int* xp,int* gold){
    for(int i=0;i<size;i++){
        *gold+=monsters[i]->xpEarn;
        *xp+=monsters[i]->hp+monsters[i]->attackMax+monsters[i]->defense;
    }
}


int prendreMana(Player* player){
    if(player->mana==100){
        printf("Vous n'en avez pas besoin, il est temps d'attaquer \n");
        return 1;
    }
    if(player->manaPotion>0){
        player->manaPotion--;
        player->mana+=33;
        if(player->mana>100)player->mana=100;
        printf("Vous buvez une potion de mana: il vous reste %d potion de mana \n",player->manaPotion);
        afficherManaJoueur(player->mana);
        return 0;
    }
    else{
        printf("Vous n'avez pas de potion de mana \n");
        return 1;
    }
}

int prendreVie(Player* player){
    if(player->hp==100){
        printf("Vous n'en avez pas besoin, il est temps d'attaquer \n");
        return 1;
    }
    if(player->lifePotion>0){
        player->hp+=33;
        player->lifePotion--;
        if(player->hp>100)player->hp=100;
        printf("Vous buvez une potion de vie: il vous reste %d potion de vie \n",player->lifePotion);
        afficherVieJoueur(player->hp);
        return 0;
    }
    else{
        printf("Vous n'avez pas de potion de soin \n");
        return 1;
    }
}

void winCase(Player* player,int goldEarn,int xpEarn){
    int randPotV=rand()%3;
    int randPotM=rand()%3;
    player->gold+=goldEarn;
    player->xp=xpEarn;
    player->lifePotion+=randPotV;
    player->manaPotion+=randPotM;
    printf("Vous vainquez au travers des tenebres et repartez avec %d gold et %d xp et %d potion de vie et %d potion de mana\n",goldEarn,xpEarn,randPotV,randPotM);
    changeLevel(player);
    printf("Dans leur debauche les ennemis perdent une de leurs arme \n");
    char* name= generateRandomName(rand()%20+4);
    Item* loot= creerItem(name,rand()%2);
    free(name);
    afficherItem(loot);
    addItemInventaire(player,loot);
    printf("Vous voici de retour vers les profondeurs, et les dangers sont nombreux \n");
}

int combat(Player* player,int boss,int fromSauvegarde, int lvlMap){
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
    int xpEarn=0;
    int goldEarn=0;
    xpAllMob(monsters,nbMonstre,&xpEarn,&goldEarn);
    int choice;
    printf("Au non c'est une embuscade \n");
    while(1){
        afficherVieJoueur(player->hp);
        afficherManaJoueur(player->mana);
        if(boss)afficherASCIIBoss();
        else afficherASCIIMob(nbMonstre,monsters);
        int nbTour=3;
        while(1){
            if(nbTour<=0)break;
            printf("%d tours restant \n",nbTour);
            printf("Appuyer sur 1 pour attaquer, 2 pour lancer un sort, 3 pour une potion de soin,4 pour une potion de mana, 5 pour finir votre tour ou 6 pour sauvegarder\n");
            fflush(stdin);
            scanf(" %d",&choice);
            if(choice<=0 || choice>6){
                printf("Entrez une valeur valide \n");
                continue;
            }
            else if(choice==1){
                attaqueMonstre(monsters,&nbMonstre,player);
            }
            else if(choice==2);//lancerSort(); //=>supprimer monstre liste monstre
            else if(choice==3){
                int notNecessary = prendreVie(player);
                if(notNecessary)continue;
            }
            else if(choice==4){
               int notNecessary = prendreMana(player);
               if(notNecessary)continue;
            }
            else if(choice==5){
                printf("Vous preferer la defense ? \n");
                break;
            }
            else if(choice==6){
                printf("Sauvegarde en cours ... \n");
                //launchSauvegarde
            }
            if(nbMonstre==0){
                winCase(player,goldEarn,xpEarn);
                return 1;
            }
            nbTour--;
        }
        printf("Vous regagnez 15 point de mana \n");
        player->mana+=15;
        if(player->mana>=100)player->mana=100;
        afficherManaJoueur(player->mana);
        for(int i=0;i<nbMonstre;i++){
            int damage = rand()%(monsters[i]->attackMax-monsters[i]->attackMin+1)+monsters[i]->attackMin-(player->defense/2);
            if(damage<=0){
                printf("Plus de peur que de mal suite à cette miserable attaque \n");
            }
            else{
                printf("Vous encaissez %d degat de la part de %s \n",damage,monsters[i]->name);
                player->hp-=damage;
            }

            if(player->hp<0){
                freeAllMob(monsters,nbMonstre);
                printf("Vous etes mort au niveau %d de la map \n",lvlMap);
                afficherGameOver();
                return 0;
            }
            printf("Vous avez encore %d vie \n",player->hp);
        }
    }
}