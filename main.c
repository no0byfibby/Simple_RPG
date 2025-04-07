#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main(void) {
	srand(time(NULL));
	char* result = "TIE";
	int rounds = 0;
	int p_total1 = 0;
	int p_total2 = 0;
	enum CHAMPION c1;
	enum CHAMPION c2;
	int c1_points;
	int c2_points;

	printf("Enter the number of rounds: ");
	scanf(" %d", &rounds);


	for(int i = 1; i <= rounds; ++i) {
		c1 = createChampion();
		c2 = createChampion();
		c1_points = getChampionPoints(c1);
		c2_points = getChampionPoints(c2);

		printf("ROUND %d\n--------\nPlayer points at the start of the round  --  P1 = %d\tP2 = %d\n", i, p_total1, p_total2);

		printf("P1 : ");
		printChampion(c1);
		printf("-%d\tvs\t", c1_points);
		printf("P2 : ");
		printChampion(c2);
		printf("-%d\n", c2_points);

		playRound(&p_total1, &p_total2, c1, c1_points, c2, c2_points);

		printf("\nPlayer points at the end of the round  --  P1 = %d\tP2 = %d\n\n",p_total1, p_total2);
	}

	result = (p_total1 > p_total2) ? "P1 Won" : "P2 Won";

	printf("GAME OVER!!\n%s\n", result);

	return 0;
}