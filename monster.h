#include "struct.h"

#ifndef DOOMDEPTHSC_MONSTER_H
#define DOOMDEPTHSC_MONSTER_H
Monster *createDemon(int lvlMap);
Monster *createPhantom(int lvlMap);
Monster *createBoss(int lvlMap);
Monster *DisplayBoss(int lvlMap);
void DisplayBoss();
void DisplayDemon();
void DisplayPhantom();


#endif