#ifndef PLAYER_H
#define PLAYER_H

#include "sqlite3.h"
#include "Player.h"

void save_player_to_db(Player *player);
void load_player_from_db(Player *player);

#endif // PLAYER_H

