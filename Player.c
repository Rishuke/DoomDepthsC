#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sqlite3.h"
#include "sauvegarde_player.h"
//#include <windows.h>
#define DEFENSESTART 10
#define ATTACKSTART 20




int doesPlayerExist(const char *name) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("game.db", &db); 

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }
    
    const char *query = "SELECT COUNT(*) FROM player WHERE name = ?";
    sqlite3_stmt *stmt;
    int exists = 0;

    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL); // Ajout de rc pour récupérer le code de retour
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erreur de préparation de la requête: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt); // Finaliser le stmt avant de retourner
        sqlite3_close(db); // Fermer la DB avant de retourner
        return 0;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        exists = sqlite3_column_int(stmt, 0) > 0;
    } else {
        fprintf(stderr, "Erreur lors de la vérification de l'existence du joueur: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db); // Fermer la DB
    return exists;
}

Player* createPlayer(){
    char name[11];
    printf("Entrez un nom : ");
    fflush(stdin);
    int result = scanf(" %10s", name);
    while (1) {
        if (result == 1 && strlen(name) <= 10) {
            Player *player = malloc(sizeof(Player));
            player->name = malloc(strlen(name) + 1);
            
            if(doesPlayerExist( name)){
            	load_player_from_db(player);
            	return player;
            }
            
            strcpy(player->name, name);
            player->hp = 100;
            player->defense = DEFENSESTART+1;
            player->attack = ATTACKSTART+3;
            player->gold = 0;
            player->mana = 100;
            player->xp = 0;
            player->xpForNextLvl = 10;
            player->level = 1;
            player->x = -1;
            player->y = -1;
            player->lifePotion = 1;
            player->manaPotion = 1;
            player->sizeInventaire=0;
            return player;
        } else {
            printf("La saisie n'était pas valide.\n");
            fflush(stdin);
            printf("Entrez un nom : ");
            
            result = scanf(" %10s", name);
        }
    }
}

void changeLevel(Player* player){
    while(player->xp>=player->xpForNextLvl){
        player->level++;
        player->xp-=player->xpForNextLvl;
        player->attack+=3;
        player->defense+=1;
        player->xpForNextLvl*=1.2;
        printf("%s augmente d'un niveau, vous voilà au niveau %d avec \n attaque : %d \n defense : %d\n",player->name,player->level,player->attack,player->defense);
    }
}

/**void setTextColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}**/

void afficherVieJoueur(int hp){
    //setTextColor(12);
    printf("Vie : [ ");
    for(int i=0;i<100;i++){
        if(i<hp){
            printf("#");
        }
        else{
            printf("-");
        }
    }
    printf(" ] %d/100 \n",hp);
    //setTextColor(7);
}


void afficherManaJoueur(int mana) {
    //setTextColor(9);
    printf("Mana: [ ");
    for (int i = 0; i < 100; i++) {
        if (i < mana) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf(" ] %d/100\n", mana);
    //setTextColor(7);
}
