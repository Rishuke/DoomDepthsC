//
// Created by alexi on 19/10/2023.
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

void combat(Player* player,Monster** monsters,int boss,int fromSauvegarde, int lvlMap){
    char* imgPlayer[]= {
            "       .-\'\'-.        ",
            "      /-.{}  \\        ",
            "      | _\\__.|        ",
            "      \\/^)^ \\/       ",
            "       \\ =  /         ",
            "  .---./`--`\\.--._    ",
            " /     `;--'`     \\   ",
            ";        /`       ;    ",
            "|       |*        |    ",
            "/   |   |     |    \\  ",
            "|    \\  |*    /    |  ",
            "\\_   |\\_|____/|  __/ ",
            "  \\__//======\\\\__/  ",
            "  / //_      _\\\\ \\  ",
            "  -'  |`\"\"\"`|  `-   ",
    };

    char* imgPlayer2 []={
            "       .-\'\'-.        ",
            "      /-.{}  \\        ",
            "      | _\\__.|        ",
            "      \\/^)^ \\/       ",
            "       \\ =  /         ",
            "  .---./`--`\\.--._    ",
            " /     `;--'`     \\   ",
            ";        /`       ;    ",
            "|       |*        |    ",
            "/   |   |     |    \\  ",
            "|    \\  |*    /    |  ",
            "\\_   |\\_|____/|  __/ ",
            "  \\__//======\\\\__/  ",
            "  / //_      _\\\\ \\  ",
            "  -'  |`\"\"\"`|  `-   ",
    };


    int nbMonstre = rand()%3+1;
    if(fromSauvegarde){ //si sauvegarde

    }
    else{
        if(boss){

        }
        else{
            for(int i=0;i<nbMonstre;i++){
                monsters[i]=malloc(sizeof(Monster));
                monsters[i]->hp=100;
                monsters[i]->attackMin=10;
                monsters[i]->attackMax=100;
            }
        }
    }
    int choice;
    printf("Au non c'est une embuscade \n");
    while(1){
        int nbTour=3;
        while(1){
            if(nbTour<=0)break;
            printf("%d tours restant.",nbTour);
            printf("Appuyer sur 1 pour attaquer, 2 pour lancer un sort, 3 pour une potion de soin, "
                   "4 pour une potion de mana, 5 pour finir votre tour ou 6 pour sauvegarder\n");
            fflush(stdin);
            scanf(" %d",&choice);
            if(choice<=0 || choice>6){
                printf("Entrez une valeur valide \n");
                continue;
            }
            else if(choice==1);//attaquerUnMonstre();
            else if(choice==2);//lancerSort();
            else if(choice==3){
                if(player->)
            }
            else if(choice==4){
                if(player->manaPotion>0){
                    player->manaPotion--;
                    player->mana+=33;
                    if(player->mana>100)player->mana=100;
                }
            }
            else if(choice==5){
                nbTour=3;
                break;
            }
            nbTour--;
        }
    }


    int size=strlen(imgPlayer[0])+strlen(imgPlayer2[0]);


    for(int i=0;i<14;i++){
        for(int j=0; j<strlen(imgPlayer[i]);j++){
            printf("%c",imgPlayer[i][j]);
        }
        printf("   ");
        for(int j=0;j< strlen(imgPlayer2[i]);j++){
            printf("%c",imgPlayer[i][j]);
        }
        printf("\n");
    }

}