#include "Player.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <windows.h>
#include "sqlite3.h"

void save_player_to_db(Player *player) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("game.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    char *sql = sqlite3_mprintf("REPLACE INTO player (id, name, hp, defense, attack, gold, mana, xp, xpForNextLvl, level, x, y, lifePotion, manaPotion, sizeInventaire) VALUES (1, %Q, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d);",
                                player->name, player->hp, player->defense, player->attack, player->gold, player->mana, player->xp, player->xpForNextLvl, player->level, player->x, player->y, player->lifePotion, player->manaPotion, player->sizeInventaire);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    sqlite3_free(sql);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        
    }

    sqlite3_close(db);
    
}

void load_player_from_db(Player *player) {
    sqlite3 *db;
    sqlite3_stmt *res;
    
    int rc = sqlite3_open("game.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    rc = sqlite3_prepare_v2(db, "SELECT * FROM player WHERE id = 1", -1, &res, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW) {
        // Suppose that the player name will not exceed 49 characters + null terminator
        strncpy(player->name, (const char*)sqlite3_column_text(res, 1), 49);
        player->hp = sqlite3_column_int(res, 2);
        player->defense = sqlite3_column_int(res, 3);
        player->attack = sqlite3_column_int(res, 4);
        player->gold = sqlite3_column_int(res, 5);
        player->mana = sqlite3_column_int(res, 6);
        player->xp = sqlite3_column_int(res, 7);
        player->xpForNextLvl = sqlite3_column_int(res, 8);
        player->level = sqlite3_column_int(res, 9);
        player->x = sqlite3_column_int(res, 10);
        player->y = sqlite3_column_int(res, 11);
        player->lifePotion = sqlite3_column_int(res, 12);
        player->manaPotion = sqlite3_column_int(res, 13);
        player->sizeInventaire = sqlite3_column_int(res, 14);
    }

    sqlite3_finalize(res);
    sqlite3_close(db);
}




