#include "struct.h"

#ifndef DOOMDEPTHSC_PLAYER_H
#define DOOMDEPTHSC_PLAYER_H
Player* createPlayer();
void changeLevel(Player* player);
void afficherVieJoueur(int hp);
void afficherManaJoueur(int mana);
int resetDatabase(const char* path);
#endif

