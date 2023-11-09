#include "struct.h"
#include <stdlib.h>
#include <string.h>

Monster* createDemon(int lvlMap) {
    Monster *demon = malloc(sizeof(Monster));
    demon->name = malloc(sizeof(char) * 6);
    strcpy(demon->name, "Demon");
    demon->hp=rand()%20+20+(lvlMap*3);
    demon->attackMax = 20 + (lvlMap * 3);
    demon->attackMin = 10 + (lvlMap * 3);
    demon->defense = 10 + (lvlMap * 3);
    return demon;
};

Monster* createPhantom(int lvlMap){
    Monster *phantom = malloc(sizeof(Monster));
    phantom->name = malloc(sizeof(char) * 8);
    strcpy(phantom->name, "Phantom");
    phantom->hp=10+(lvlMap*3);
    phantom->attackMax = rand()%15+10+(lvlMap * 3);
    phantom->attackMin = 1 + (lvlMap * 3);
    phantom->defense = 10 + (lvlMap * 3);
    return phantom;
};

Monster* createBoss(int lvlMap){
    Monster *boss = malloc(sizeof(Monster));
    boss->name = malloc(sizeof(char) * 5);
    strcpy(boss->name, "BOSS");
    boss->hp=rand()%25+50+(lvlMap*3);
    boss->attackMax = 30 + (lvlMap * 3);
    boss->attackMin = 15 + (lvlMap * 3);
    boss->defense = 30 + (lvlMap * 3);
    return boss;
};