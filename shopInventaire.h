//
// Created by meizarkos on 07/10/23.
//
#include "struct.h"

#ifndef DOOMDEPTHSC_SHOPINVENTAIRE_H
#define DOOMDEPTHSC_SHOPINVENTAIRE_H
void buyInShop(Player* player);
int afficherInventaire(Player* player);
void afficherItem(Item* item);
Item* creerItem(char* name,int offensive);
void addItemInventaire(Player* player,Item* item);
void changerItem(Player* player);
#endif
