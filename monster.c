#include "struct.h"
#include <stdlib.h>
#include "string.h"
#include <stdio.h>
#include <time.h>

Monster* createDemon(int lvlMap) {
    Monster *demon = malloc(sizeof(Monster));
    demon->name = malloc(sizeof(char) * 20);
    strcpy(demon->name, "Demon");
    demon->attackMax = 20 + (lvlMap * 3);
    demon->attackMin = 10 + (lvlMap * 3);
    demon->defense = 10 + (lvlMap * 3);
    demon->xpEarn = 20 + (lvlMap * 3);
    return demon;
};

Monster* createPhantom(int lvlMap){
    Monster *phantom = malloc(sizeof(Monster));
    phantom->name = malloc(sizeof(char) * 20);
    strcpy(phantom->name, "Phantom");
    phantom->attackMax = 15 + (lvlMap * 3);
    phantom->attackMin = 1 + (lvlMap * 3);
    phantom->defense = 10 + (lvlMap * 3);
    phantom->xpEarn = 10 + (lvlMap * 3);
    return phantom;
};

Monster* createBoss(int lvlMap){
    Monster *boss = malloc(sizeof(Monster));
    boss->name = malloc(sizeof(char) * 20);
    strcpy(boss->name, "BOSS");
    boss->attackMax = 30 + (lvlMap * 3);
    boss->attackMin = 15 + (lvlMap * 3);
    boss->defense = 30 + (lvlMap * 3);
    boss->xpEarn = 50 + (lvlMap * 3);
    return boss;
};


void DisplayBoss(Monster *monster) {
    printf("%s",monster->name);
};
void DisplayDemon(Monster *monster) {
    printf("%s",monster->name);

};
void DisplayPhantom(Monster *monster) {
    printf("%s",monster->name);

};