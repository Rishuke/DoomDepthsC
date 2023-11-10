#include "creationmap.h"
#include "sqlite3.h"
#include <stdio.h>


void initData() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("game.db", &db); // Open connection to the database

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    const char *sql_player = "CREATE TABLE IF NOT EXISTS player ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "name TEXT NOT NULL, "
                         "hp INTEGER, "
                         "attack INTEGER, "
                         "gold INTEGER, "
                         "mana INTEGER, "
                         "defense INTEGER, "
                         "sizeInventaire INTEGER, "
                         "x INTEGER, "
                         "y INTEGER, "
                         "xp INTEGER, "
                         "level INTEGER, "
                         "xpForNextLvl INTEGER, "
                         "lifePotion INTEGER, "
                         "manaPotion INTEGER"
                         ");";

    const char *sql_inventory = "CREATE TABLE IF NOT EXISTS inventory ("
                                "player_id INTEGER, "
                                "item_name TEXT, "
                                "power INTEGER, "
                                "equipped INTEGER, "
                                "offensive INTEGER, "
                                "gold INTEGER, "
                                "FOREIGN KEY(player_id) REFERENCES player(id));";

    const char *sql_monsters = "CREATE TABLE IF NOT EXISTS monsters ("
                               "id INTEGER PRIMARY KEY, "
                               "name TEXT, "
                               "hp INTEGER, "
                               "attack_min INTEGER, "
                               "attack_max INTEGER, "
                               "defense INTEGER, "
                               "xp_earn INTEGER);";
	
	
	// Execute SQL for creating player table
    rc = sqlite3_exec(db, sql_player, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Execute SQL for creating inventory table
    rc = sqlite3_exec(db, sql_inventory, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Execute SQL for creating monsters table
    rc = sqlite3_exec(db, sql_monsters, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    
   sqlite3_close(db); 
    
}
int main ()
{
	initData();
    initTest();
    
    return 0;
}


