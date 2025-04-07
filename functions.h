#ifndef FUNCTIONS_H
#define FUNCTIONS_H

enum CHAMPION {MAGE, FIGHTER, TANK};

int getRandomNumber( int min, int max );
int getChampionPoints(enum CHAMPION player);
enum CHAMPION createChampion( );
void printChampion(enum CHAMPION c );
void playRound(int* p1_total, int* p2_total, enum CHAMPION c1, int c1_points, enum CHAMPION c2, int c2_points);

#endif