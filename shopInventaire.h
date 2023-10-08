//
// Created by meizarkos on 07/10/23.
//
#include "struct.h"

#ifndef DOOMDEPTHSC_SHOPINVENTAIRE_H
#define DOOMDEPTHSC_SHOPINVENTAIRE_H
void buyInShop(Player* player);
void afficherInventaire(Player* player);
void afficherItem(Item* item);
void creerItem(char* name,int offensive,Item* item);
void addItemInventaire(Player* player,Item* item);
#endif
