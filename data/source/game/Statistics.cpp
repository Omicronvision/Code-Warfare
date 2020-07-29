#include "Statistics.h"

Statistics::Statistics():
enemiesDestroyed(0), buildingsCreated(0), buildingsDestroyed(0)
{}

void Statistics::reset()
{
	enemiesDestroyed = 0;
	buildingsCreated = 0;
	buildingsDestroyed = 0;
}

int Statistics::getScore(int CPU_usage)
{
	int score = 0;

	score = enemiesDestroyed * buildingsCreated;
	score -= buildingsDestroyed * 15;
	score -= CPU_usage * 50;

	return score;
}