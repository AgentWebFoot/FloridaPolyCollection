#include "Record.h"
#include "LuckyNumber.h"

int main() {
	//Declaring Variables
	int guess;
	GameStats stats = {0, 0, 0, 0};
	char again = 'y';

	while (again == 'y') {
		//Requesting Inputs
		printf("Enter a Guess Between 1 and 5: ");
		scanf("%d", &guess);

		//Check Number
		incrementGameCount(&stats, checkLuckyNumber(guess));

		//Stats
		printf("Total Games: %d \nWins: %d \nLosses Over: %d \nLosses Under: %d\n", getGameCount(&stats), getWinCount(&stats), getOverCount(&stats), getUnderCount(&stats));

		//Play Again
		printf("Do you want to play again (y/n): ");
		scanf(" %c", &again);
	}

	return 0;
}
