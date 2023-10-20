#include "struct.h"
#include "monster.h"
#include <stdlib.h>
#include "string.h"
#include <stdio.h>
#include <time.h>

Monster* createDemon(int lvlMap) {
    Monster *demon = malloc(sizeof(Monster));
    demon->name = malloc(sizeof(char) * 6);
    strcpy(demon->name, "Demon");
    demon->hp=20+(lvlMap*3);
    demon->attackMax = 20 + (lvlMap * 3);
    demon->attackMin = 10 + (lvlMap * 3);
    demon->defense = 10 + (lvlMap * 3);
    demon->xpEarn = 20 + (lvlMap * 3);
    return demon;
};

Monster* createPhantom(int lvlMap){
    Monster *phantom = malloc(sizeof(Monster));
    phantom->name = malloc(sizeof(char) * 8);
    strcpy(phantom->name, "Phantom");
    phantom->hp=10+(lvlMap*3);
    phantom->attackMax = 15 + (lvlMap * 3);
    phantom->attackMin = 1 + (lvlMap * 3);
    phantom->defense = 10 + (lvlMap * 3);
    phantom->xpEarn = 10 + (lvlMap * 3);
    return phantom;
};

Monster* createBoss(int lvlMap){
    Monster *boss = malloc(sizeof(Monster));
    boss->name = malloc(sizeof(char) * 5);
    strcpy(boss->name, "BOSS");
    boss->hp=50+(lvlMap*3);
    boss->attackMax = 30 + (lvlMap * 3);
    boss->attackMin = 15 + (lvlMap * 3);
    boss->defense = 30 + (lvlMap * 3);
    boss->xpEarn = 50 + (lvlMap * 3);
    return boss;
};


char** DisplayDemon() {
    const char *imgDemon[] = {
            "              v     ",
            "        (__)v | v    ",
            "        /\\/\\\\_|_/ ",
            "       _\\__/  |     ",
            "      /  \\/`<`)     ",
            "      \\ (  |\\_/    ",
            "      /)))-(  |      ",
            "     / /^ ^ \\ |     ",
            "    /  )^/\\^( |     ",
            "    )_//`__>> |      ",
            "      #   #`  |      ",
            "                     ",
            "       DEMON         ",
            "                     ",
            "                     ",
    };
    return imgDemon;
}
char** DisplayPhantom() {
    const char* imgPhantom={
            " .-.      ",
            "(o o) boo!",
            "| O \\    ",
            " \\   \\  ",
            "  `~~~'   ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "  PHANTOM ",
            "          "
    };
    return imgPhantom;
}