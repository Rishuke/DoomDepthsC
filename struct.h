typedef struct
{
    int equiped;
    char *name;
    int offensive;
    int power;
    int gold;
} Item;

typedef struct
{
    char *name;
    int hp;
    int attack;
    int gold;
    int mana;
    int defense;
    Item** items;
    int x;
    int y;
    int xp;
    int level;
    int xpForNextLvl;
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


