#include "sqlite3.h"
#include "struct.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sauvegarderInventaire(Player *player) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("game.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, &err_msg);

    // Supprimez les anciens éléments de l'inventaire
    char *sql_delete = sqlite3_mprintf("DELETE FROM inventory WHERE player_id = %d;", player->id);
    rc = sqlite3_exec(db, sql_delete, 0, 0, &err_msg);
    sqlite3_free(sql_delete);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_exec(db, "ROLLBACK TRANSACTION;", NULL, NULL, &err_msg);
        sqlite3_close(db);
        
    }

    // Insérez les nouveaux éléments de l'inventaire
    for (int i = 0; i < player->sizeInventaire; ++i) {
        char *sql_insert = sqlite3_mprintf("INSERT INTO inventory (player_id, item_name, power, equipped, offensive, gold) VALUES (%d, %Q, %d, %d, %d, %d);",
                                           1, player->items[i]->name, player->items[i]->power, player->items[i]->equiped, player->items[i]->offensive, player->items[i]->gold);
        rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
        sqlite3_free(sql_insert);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", err_msg);
            sqlite3_free(err_msg);
            sqlite3_exec(db, "ROLLBACK TRANSACTION;", NULL, NULL, &err_msg);
            sqlite3_close(db);
            
        }
    }

    sqlite3_exec(db, "COMMIT TRANSACTION;", NULL, NULL, &err_msg);
    sqlite3_close(db);
}

void chargerInventaire(Player *player) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc = sqlite3_open("game.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    char *sql_select = sqlite3_mprintf("SELECT item_name, power, equipped, offensive, gold FROM inventory WHERE player_id = %d;", 1);
    rc = sqlite3_prepare_v2(db, sql_select, -1, &stmt, 0);
    sqlite3_free(sql_select);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    
	

    player->items=malloc(sizeof(Item*)*player->sizeInventaire);
    int sizeActu=0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Item *item = malloc(sizeof(Item));
        item->name = strdup((const char *)sqlite3_column_text(stmt, 0));
        item->power = sqlite3_column_int(stmt, 1);
        item->equiped = sqlite3_column_int(stmt, 2);
        item->gold = sqlite3_column_int(stmt, 4);
        item->offensive = sqlite3_column_int(stmt, 3);

        player->items[sizeActu]=malloc(sizeof(Item));
        player->items[sizeActu]->name = malloc(sizeof(char)*(strlen(item->name)+1));
        strcpy(player->items[sizeActu]->name,item->name);
        player->items[sizeActu]->offensive=item->offensive;
        player->items[sizeActu]->power=item->power;
        player->items[sizeActu]->gold=item->gold;
        player->items[sizeActu]->equiped=item->equiped;
        sizeActu++;
    }
    sqlite3_close(db);
    sqlite3_finalize(stmt);
}

