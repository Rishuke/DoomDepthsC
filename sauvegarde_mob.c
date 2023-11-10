#include "sqlite3.h"
#include "struct.h"  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sauvegarderMonstre(Monster *monster, int id) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("game.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql = sqlite3_mprintf("REPLACE INTO monsters (id, name, hp, attack_min, attack_max, defense, xp_earn) VALUES (%d, %Q, %d, %d, %d, %d, %d);",
                                id, monster->name, monster->hp, monster->attackMin, monster->attackMax, monster->defense, monster->xpEarn);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    sqlite3_free(sql);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return;
    }

    sqlite3_close(db);
}

void chargerMonstre(Monster *monster, int id) {
    sqlite3 *db;
    sqlite3_stmt *stmt;

    int rc = sqlite3_open("game.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql = sqlite3_mprintf("SELECT name, hp, attack_min, attack_max, defense, xp_earn FROM monsters WHERE id = %d;", id);

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_free(sql);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        monster->name = strdup((const char *)sqlite3_column_text(stmt, 0));
        monster->hp = sqlite3_column_int(stmt, 1);
        monster->attackMin = sqlite3_column_int(stmt, 2);
        monster->attackMax = sqlite3_column_int(stmt, 3);
        monster->defense = sqlite3_column_int(stmt, 4);
        monster->xpEarn = sqlite3_column_int(stmt, 5);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

