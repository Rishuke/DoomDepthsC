//
// Created by meizarkos on 06/10/23.
//
#include "struct.h"

#ifndef DOOMDEPTHSC_CASEACTION_H
#define DOOMDEPTHSC_CASEACTION_H
void caseAction(Player *player,Carte* carte,Monster** monster);
int isOK(int x,int y,Carte* carte);
void PlayerMouv(Player* player,Carte* carte, char a);
#endif //DOOMDEPTHSC_CASEACTION_H
