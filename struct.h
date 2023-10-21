#ifndef DOOMDEPTHSC_STRUCT_H
#define DOOMDEPTHSC_STRUCT_H

typedef struct
{
    int equiped;
    char *name;
    int offensive;
    int power;
    int gold;
}Item;

typedef struct
{
    char *name;
    int hp;
    int attack;
    int gold;
    int mana;
    int defense;
    Item** items;
    int sizeInventaire;
    int x;
    int y;
    int xp;
    int level;
    int xpForNextLvl;
    int lifePotion;
    int manaPotion;

} Player;

typedef struct
{
    int hp;
    char *name;
    int attackMin;
    int attackMax;
    int defense;
    int xpEarn;

} Monster;

typedef struct{
    int** map;
    int taille;
    int donjonLevel;
}Carte;

#endif


