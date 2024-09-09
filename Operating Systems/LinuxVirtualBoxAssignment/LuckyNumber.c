#include "LuckyNumber.h"

int checkLuckyNumber(int guess) {
	srand(time(0));
	int number = ((rand() % 5)+1);
	return (guess - number);
}

