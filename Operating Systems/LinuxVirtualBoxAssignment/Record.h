#ifndef RECORD_H
#define RECORD_H

typedef struct {
	int gamesPlayed;
	int gamesWon;
	int guessesUnder;
	int guessesOver;
} GameStats;

static inline void incrementGameCount(GameStats* stats, int guess){
	stats->gamesPlayed++;
	if (guess == 0){
		stats->gamesWon++;
	}
	else if (guess < 0){
		stats->guessesUnder++;
	}
	else if (guess > 0){
		stats->guessesOver++;
	}
}

static inline int getGameCount(const GameStats* stats){
	return stats->gamesPlayed;
}

static inline int getWinCount(const GameStats* stats){
	return stats->gamesWon;
}

static inline int getUnderCount(const GameStats* stats){
	return stats->guessesUnder;
}

static inline int getOverCount(const GameStats* stats){
	return stats-> guessesOver;
}

#endif
