//
// Created by meizarkos on 29/09/23.
//

#ifndef DOOMDEPTHSC_CREATIONMAP_H
#define DOOMDEPTHSC_CREATIONMAP_H
int initTest();
void initMap(int** map);
void freeAll(int size,int** toFree);
void creerCoordo(int* coordo,int** map,int res);
void linkedPoint(int* coordoStart,int* coordoEnd,int** map);
#endif //DOOMDEPTHSC_CREATIONMAP_H
