#include "EnabledWaves.h"

void EnabledWaves::setFirstToSecond()
{
	enabledAdwBigWave.second = enabledAdwBigWave.first;
	enabledAdwSmallWave.second = enabledAdwSmallWave.first;
	enabledDiaBigWave.second = enabledDiaBigWave.first;
	enabledDiaSmallWave.second = enabledDiaSmallWave.first;
	enabledDroSmallWave.second = enabledDroSmallWave.first;
	enabledSpySmallWave.second = enabledSpySmallWave.first;
	enabledTroSmallWave.second = enabledTroSmallWave.first;
	enabledVirBigWave.second = enabledVirBigWave.first;
	enabledVirSmallWave.second = enabledVirSmallWave.first;
}

bool EnabledWaves::isAllDisabled()
{
	if ((!enabledAdwBigWave.second) && (!enabledAdwSmallWave.second) && (!enabledDiaBigWave.second) &&
		(!enabledDiaSmallWave.second) && (!enabledDroSmallWave.second) && (!enabledSpySmallWave.second) &&
		(!enabledTroSmallWave.second) && (!enabledVirBigWave.second) && (!enabledVirSmallWave.second))
		return true;
	else
		return false;
}