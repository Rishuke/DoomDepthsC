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
	int id;
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
	int id;
    int hp;
    char *name;
    int attackMin;
    int attackMax;
    int defense;
} Monster;

typedef struct{
    int** map;
    int taille;
    int donjonLevel;
}Carte;

#endif


