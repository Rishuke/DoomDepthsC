//
// Created by meizarkos on 07/10/23.
//
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>
#include "struct.h"
#define tailleInventaire 6
#define DEFENSESTART 10
#define ATTACKSTART 20

Item* creerItem(char* name,int offensive){
    Item* item=malloc(sizeof(Item));
    item->name=malloc(sizeof(char)*(strlen(name)+1));
    strcpy(item->name,name);
    item->power=rand()%12+3;
    item->equiped=0;
    item->offensive=offensive;
    item->gold=rand()%200+item->power*25;
}

void afficherItem(Item* arme){
    if(arme->offensive)printf("Le %s peut inflige %d degat . ",arme->name,arme->power);
    else printf("Le %s peut encaisse %d degat . ",arme->name,arme->power);
    printf(" Son prix est de %d gold. ",arme->gold);
    if(arme->equiped && arme->offensive)printf("Cette arme est equipe \n");
    else if(arme->equiped && !arme->offensive)printf("Cette protection est equipe \n");
    else  printf("\n");
}

int afficherInventaire(Player* player){
    if(player->sizeInventaire==0){
        printf("Vous n'avez meme pas d'items mais posseder %d, allez vous battre \n",player->gold);
        return 0;
    }
    for(int i=1;i<player->sizeInventaire+1;i++){
        printf("%d ",i);
        afficherItem(player->items[i-1]);
    }
    printf("Vous posseder %d gold \n",player->gold);
    return 1;
}

void addItemInventaire(Player* player,Item *item){
    if(player->sizeInventaire < 6){
        player->sizeInventaire++;
        if(player->sizeInventaire==1){player->items=malloc(sizeof(Item*));}
        else {player->items=realloc(player->items,sizeof(Item*)*player->sizeInventaire);}
        player->items[player->sizeInventaire-1]= malloc(sizeof(Item));
        player->items[player->sizeInventaire-1]->equiped=0;
        player->items[player->sizeInventaire-1]->gold=item->gold;
        player->items[player->sizeInventaire-1]->offensive=item->offensive;
        player->items[player->sizeInventaire-1]->power=item->power;
        player->items[player->sizeInventaire-1]->name= malloc(sizeof(char)*(strlen(item->name)+1));
        strcpy(player->items[player->sizeInventaire-1]->name,item->name);
        return;
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
        player->items[player->sizeInventaire-1]->name= realloc(player->items[player->sizeInventaire-1]->name,sizeof(char)* (strlen(item->name)+1));
        strcpy(player->items[choice-1]->name,item->name);
    }
}

void changeEquiped(Player* player,Item* item){
    for(int i=0;i<player->sizeInventaire;i++){
        if(player->items[i]->equiped==1 && player->items[i]->offensive==item->offensive){
            player->items[i]->equiped=0;
            break;
        }
    }
    item->equiped=1;
    if(item->offensive){
        player->attack=ATTACKSTART+item->power+player->level*3;
    }
    else{
        player->defense=DEFENSESTART+item->power+player->level;
    }
    printf("%s a maintenant \n attaque : %d \n defense : %d \n",player->name,player->attack,player->defense);
}

void changerItem(Player* player){
    if(!afficherInventaire(player)){
        return;
    }
    if((player->items[0]->equiped && player->items[1]->equiped && !(strcmp(player->items[2]->name,"Vide")))){
        printf("Il n'y a rien à faire dans ce menu pour le moment\n");
        return;
    }
    printf("Entrez le chiffre de celui que vous voulez équipé, sinon entrez 0 \n");
    int choice;
    scanf(" %d",&choice);
    while(choice !=0){
        if(!(strcmp(player->items[choice-1]->name,"Vide"))|| choice<0 || choice > 6){
            printf("Entrez une valeur valide ! \n");
        }
        else{
            changeEquiped(player,player->items[choice-1]);
        }
        afficherInventaire(player);
        printf("Entrez le chiffre de celui que vous voulez équipe, sinon entrez 0 \n");
        scanf(" %d",&choice);
    }
}

void freeShop(Item** items,int index,int* size){
    for(int i=index;i<*size-1;i++){
        items[i]->name=realloc(items[i]->name,strlen(items[i+1]->name)+1);
        strcpy(items[i]->name,items[i+1]->name);
        items[i]->offensive=items[i+1]->offensive;
        items[i]->power=items[i+1]->power;
        items[i]->gold=items[i+1]->gold;
    }
    (*size)--;
    free(items[*size]->name);
    free(items[*size]);
    if(*size==0){
        free(items);
        return;
    }
    items=realloc(items,sizeof(Item*)*(*size));
}

void buyInShop(Player* player){
    int sizeShop=4;
    char* medievalWeapons[]= {"Sword", "Axe", "Mace", "Bow", "Crossbow", "Halberd", "Spear", "Dagger", "Warhammer", "Flail", "Longbow"};
    char* medievalArmor[] = {"Chainmail", "Plate Armor", "Scale Armor", "Leather Armor", "Brigandine", "Kettle Hat", "Greaves", "Gauntlets", "Helmet", "Shield", "Tabard"};
    int buy=0;
    Item** stockInShop=malloc(sizeof(Item*)*sizeShop);
    for(int i=0;i<sizeShop;i++){
        int offense=rand()%2;
        if(offense)stockInShop[i]= creerItem(medievalWeapons[rand()%11],1);
        else stockInShop[i]= creerItem(medievalArmor[rand()%11],0);
    }

    printf("Voici votre inventaire \n");
    afficherInventaire(player);
    printf("Voici l'offre propose \n");
    for(int i=1;i<sizeShop+1;i++){
        printf("%d ",i);
        afficherItem(stockInShop[i-1]);
    }
    printf("Pour acheter taper le chiffre correspondant ou appuyer sur 0 pour quitter \n");
    int choice;
    scanf(" %d",&choice);
    while(choice!=0){
        if(choice<0 || choice > sizeShop){
            printf("Entrez une valeur valide \n");
            scanf(" %d",&choice);
            continue;
        }
        else{
            if(player->gold>=stockInShop[choice-1]->gold){
                player->gold-=stockInShop[choice-1]->gold;
                addItemInventaire(player,stockInShop[choice-1]);
                printf("\nVoici votre inventaire \n");
                afficherInventaire(player);
                buy++;
                freeShop(stockInShop,choice-1,&sizeShop);
                if(buy>3)break;
            }
            else{printf("Vous n'avez pas assez d'or \n");}
        }
        printf("Voici l'offre restante \n");
        for(int i=1;i<sizeShop+1;i++){
                printf("%d ",i);
                afficherItem(stockInShop[i-1]);
        }
        printf("Pour continuer a acheter taper le chiffre correspondant ou appuyer sur 0 pour quitter \n");
        scanf(" %d",&choice);
    }
    for (int i = 0; i < sizeShop; i++) {
        free(stockInShop[i]->name);
        free(stockInShop[i]);
    }
    if(sizeShop!=0)free(stockInShop);
    printf("Vous sortez du shop, le marchand vous lance 'On se reverra' puis ce dernier disparait dans les profondeurs \n");
}
