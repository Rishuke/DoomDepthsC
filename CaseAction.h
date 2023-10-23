//
// Created by meizarkos on 06/10/23.
//
#include "struct.h"

#ifndef DOOMDEPTHSC_CASEACTION_H
#define DOOMDEPTHSC_CASEACTION_H
int caseAction(Player *player,Carte* carte,char preMouv);
int isOK(int x,int y,Carte* carte);
char PlayerMouv(Player* player,Carte* carte, char a);
#endif //DOOMDEPTHSC_CASEACTION_H
