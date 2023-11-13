#include "sqlite3.h"
#include "struct.h"  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sauvegarderMonstres(Monster **monsters, int nombreMonstres) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("game.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, &err_msg);

    for (int i = 0; i < nombreMonstres; i++) {
        char *sql = sqlite3_mprintf("INSERT INTO monsters (id, name, hp, attack_min, attack_max, defense) VALUES (%d, %Q, %d, %d, %d, %d);",
                                    1, monsters[i]->name, monsters[i]->hp, monsters[i]->attackMin, monsters[i]->attackMax, monsters[i]->defense);

        rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

        sqlite3_free(sql);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", err_msg);
            sqlite3_free(err_msg);
            sqlite3_exec(db, "ROLLBACK TRANSACTION;", NULL, NULL, &err_msg);
            sqlite3_close(db);
            return;
        }
    }

    sqlite3_exec(db, "COMMIT TRANSACTION;", NULL, NULL, &err_msg);
    sqlite3_close(db);
}


int chargerMonstre(Monster **monsters, int id) {
    sqlite3 *db;
    sqlite3_stmt *stmt;

    int rc = sqlite3_open("game.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }

    char *sql = sqlite3_mprintf("SELECT name, hp, attack_min, attack_max, defense FROM monsters WHERE id = %d;", id);
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_free(sql);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }

    int sizeActu=0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Monster* actu= malloc(sizeof(Monster ));
        actu->name = strdup(sqlite3_column_text(stmt, 0));
        actu->hp=sqlite3_column_int(stmt, 1);
        actu->attackMin=sqlite3_column_int(stmt, 2);
        actu->attackMax=sqlite3_column_int(stmt, 3);
        actu->defense=sqlite3_column_int(stmt, 4);
        if(sizeActu==0){
            monsters= malloc(sizeof(Monster*));
        }
        else{
            monsters=realloc(monsters,sizeof(Monster*)*(sizeActu+1));
        }
        monsters[sizeActu]->name=malloc(sizeof(char)*(strlen(actu->name)+1));
        strcpy(monsters[sizeActu]->name,actu->name);
        monsters[sizeActu]->hp=actu->hp;
        monsters[sizeActu]->attackMax=actu->attackMax;
        monsters[sizeActu]->attackMin=actu->attackMin;
        monsters[sizeActu]->defense=actu->defense;
        free(actu);
        sizeActu++;
    }


    sqlite3_close(db);
    sqlite3_finalize(stmt);
    return sizeActu;
}


