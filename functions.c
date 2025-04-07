#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int getRandomNumber(int min, int max) {
	return ((rand() % (max - min + 1)) ) + min;
}

enum CHAMPION createChampion() {

	int pick = (rand() % 3);

	return (enum CHAMPION) pick;
}

int getChampionPoints(enum CHAMPION player) {
	switch(player) {
	case 0:
		return getRandomNumber(1, 8);

	case 1:
		return getRandomNumber(3, 7);

	case 2:
		return getRandomNumber(5, 9);

	default:
		return 0;
	}
}

void printChampion(enum CHAMPION player) {
	switch(player) {
	case MAGE:
		printf("MAGE");
		break;
	case FIGHTER:
		printf("FIGHTER");
		break;
	case TANK:
		printf("TANK");
		break;
	}

}

void playRound(int* p1_total, int* p2_total, enum CHAMPION c1,
               int c1_points, enum CHAMPION c2, int c2_points) {
	// c1 is the mage
	if(c1 == MAGE) {
		if(c2 == MAGE) {
			if (c1_points > c2_points) {
				printf("Player 1 (MAGE) wins and gains their current points.\nPlayer 2 (MAGE) loses their current points.\n");
				*p1_total += c1_points;
				*p2_total -= c2_points;
			} else if (c1_points < c2_points) {
				printf("Player 1 (MAGE) loses their current points.\nPlayer 2 (MAGE) wins and gains their current points.\n");
				*p2_total += c2_points;
				*p1_total -= c1_points;
			}
			else {
				printf("Nothing happened...\n");
			}
		}
		else if(c2 == FIGHTER) {
			if (c1_points > c2_points) {
				printf("Player 1 (MAGE) wins and gains their current points.\nPlayer 2 (FIGHTER) loses but with no penalty.\n");
				*p1_total += c1_points;
			} else if (c1_points < c2_points) {
				printf("Player 1 (MAGE) loses their current points.\nPlayer 2 (FIGHTER) wins and keeps their current points.\n");
				*p1_total -= c1_points;
			}
			else {
				printf("Nothing happened...\n");
			}
		}
		else if(c2 == TANK) {
			printf("Player 1 (MAGE) wins and gains their current points.\nPlayer 2 (TANK) loses their current points.\n");
			*p2_total -= c2_points;
			*p1_total += c1_points;
		}
	}
	//c1 is the fighter
	else if(c1 == FIGHTER) {
		if(c2 == MAGE) {
			if (c1_points > c2_points) {
				printf("Player 1 (FIGHTER) wins and gains their current points.\nPlayer 2 (MAGE) loses but with no penalty.\n");
				*p1_total += c1_points;
			} else if (c1_points < c2_points) {
				printf("Player 1 (FIGHTER) loses their current points.\nPlayer 2 (MAGE) wins and keeps their current points.\n");
				*p1_total -= c1_points;
			}
			else {
				printf("Nothing happened...\n");
			}
		}
		else if(c2 == FIGHTER) {
			printf("Both players win and gain all their current points.\n");
			*p2_total += c2_points;
			*p1_total += c1_points;
		}
		else if(c2 == TANK) {
			printf("Player 1 (FIGHTER) wins and gains their current points.\nPlayer 2 (TANK) loses but with no penalty.\n");
			*p1_total += c1_points;
		}
	}
	//c1 is the tank
	else if(c1 == TANK) {
		if(c2 == MAGE) {
			printf("Player 1 (TANK) loses their current points.\nPlayer 2 (MAGE) wins and gains their current points.\n");
			*p2_total += c2_points;
			*p1_total -= c1_points;
		}
		else if(c2 == FIGHTER) {
			printf("Player 1 (TANK) loses but with no penalty.\nPlayer 2 (FIGHTER) wins and gains current points.\n");
			*p1_total += c1_points;
		}
		else if(c2 == TANK) {
			printf("Nothing happened...\n");
		}
	}
}