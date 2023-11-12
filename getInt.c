//
// Created by meizarkos on 11/11/23.
//
#include <stdio.h>

int getInt(){
    int res;
    char c;
    int ok=scanf(" %d",&res);
    while(ok!=1){
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Entrez une valeur valide \n\n");
        ok=scanf(" %d",&res);
    }
    return res;
}
