//
// Created by meizarkos on 07/10/23.
//
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>
#include "struct.h"
#define tailleInventaire 6

void creerItem(char* name,int offensive,Item* item){
    item->name=malloc(sizeof(char)*(strlen(name)+1));
    strcpy(item->name,name);
    item->power=rand()%12+3;
    item->equiped=0;
    item->offensive=offensive;
    item->gold=rand()%200+item->power*25;
}

void afficherItem(Item* arme){
    if(arme->offensive)printf("Le %s peut infligé %d degat . ",arme->name,arme->power);
    else printf("Le %s peut encaissé %d degat . ",arme->name,arme->power);
    printf(" Son prix est de %d gold. ",arme->gold);
    if(arme->equiped && arme->offensive)printf("Cette arme est équipé \n");
    else if(arme->equiped && !arme->offensive)printf("Cette protection est équipé \n");
    else  printf("\n");
}

void afficherInventaire(Player* player){
    for(int i=1;i<tailleInventaire+1;i++){
        if(strcmp(player->items[i-1]->name,"Vide")){
            printf("%d ",i);
            afficherItem(player->items[i-1]);
        }
    }
    printf("Vous posséder %d gold \n",player->gold);
}

void addItemInventaire(Player* player,Item *item){
    for(int i=0;i<tailleInventaire;i++){
        if(!strcmp(player->items[i]->name,"Vide")){
            player->items[i]->equiped=0;
            player->items[i]->gold=item->gold;
            player->items[i]->offensive=item->offensive;
            player->items[i]->power=item->power;
            strcpy(player->items[i]->name,item->name);
            return;
        }
    }
    printf("Votre inventaire est plein. Voici l'item que vous venez de récupérer \n");
    afficherItem(item);
    printf("Voici votre inventaire \n");
    afficherInventaire(player);
    printf("Choisissez l'arme à supprimer dans votre inventaire en tapant son numéro sinon taper 0 \n");
    int choice;
    scanf(" %d",&choice);
    while(choice>tailleInventaire || choice<0){
        printf("Entrer une valeur valide \n");
        scanf(" %d",&choice);
    }
    if(choice==0){
        printf("L'item est jeté à la poubelle \n");
        return;
    }
    else {
        player->items[choice-1]->equiped=0;
        player->items[choice-1]->gold=item->gold;
        player->items[choice-1]->offensive=item->offensive;
        player->items[choice-1]->power=item->power;
        strcpy(player->items[choice-1]->name,item->name);
    }
}

void buyInShop(Player* player){
    int buy=0;
    Item** stockInShop=malloc(sizeof(Item*)*3);
    for(int i=0;i<3;i++){
        stockInShop[i]=malloc(sizeof(Item));
        if(stockInShop[i]==NULL)exit(1);
    }
    creerItem("Arme offensive",1,stockInShop[0]);
    creerItem("Armure",0,stockInShop[1]);
    creerItem("Arme offensive 2",1,stockInShop[2]);
    printf("Voici votre inventaire \n");
    afficherInventaire(player);
    printf("Voici l'offre proposé \n");
    for(int i=1;i<4;i++){
        printf("%d ",i);
        afficherItem(stockInShop[i-1]);
    }
    printf("Pour acheter taper le chiffre correspondant ou appuyer sur 0 pour quitter \n");
    int choice;
    scanf(" %d",&choice);
    while(choice!=0){
        if(choice<0 || choice > 4){
            printf("Entrez une valeur valide \n");
            scanf(" %d",&choice);
            continue;
        }
        else if(strcmp(stockInShop[choice-1]->name,"Unable")){
            if(player->gold>=stockInShop[choice-1]->gold){
                player->gold-=stockInShop[choice-1]->gold;
                addItemInventaire(player,stockInShop[choice-1]);
                printf("\nVoici votre inventaire \n");
                afficherInventaire(player);
                buy++;
                strcpy(stockInShop[choice-1]->name,"Unable");
                if(buy>2)break;
            }
            else{printf("Vous n'avez pas assez d'or \n");}
        }
        else {printf("le produit n'est plus disponible \n");}
        printf("Voici l'offre restante \n");
        for(int i=1;i<4;i++){
            if(strcmp(stockInShop[i-1]->name,"Unable")){
                printf("%d ",i);
                afficherItem(stockInShop[i-1]);
            }
        }
        printf("Pour continuer à acheter taper le chiffre correspondant ou appuyer sur 0 pour quitter \n");
        scanf(" %d",&choice);
    }
    fflush(stdin);
    for (int i = 0; i < 3; i++) {
        free(stockInShop[i]->name);
        free(stockInShop[i]);
    }
    free(stockInShop);
    printf("Vous sortez du shop, le marchand vous lance 'On se reverra' puis ce dernier disparait dans les profondeurs \n");
}
