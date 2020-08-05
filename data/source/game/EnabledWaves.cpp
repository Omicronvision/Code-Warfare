#include "EnabledWaves.h"

std::pair<bool, bool> EnabledWaves::enabledAdwBigWave = { false, false };
std::pair<bool, bool> EnabledWaves::enabledAdwSmallWave = { false, false };
std::pair<bool, bool> EnabledWaves::enabledDiaBigWave = { false, false };
std::pair<bool, bool> EnabledWaves::enabledDiaSmallWave = { false, false };
std::pair<bool, bool> EnabledWaves::enabledDroSmallWave = { false, false };
std::pair<bool, bool> EnabledWaves::enabledSpySmallWave = { false, false };
std::pair<bool, bool> EnabledWaves::enabledTroSmallWave = { false, false };
std::pair<bool, bool> EnabledWaves::enabledVirBigWave = { false, false };
std::pair<bool, bool> EnabledWaves::enabledVirSmallWave = { false, false };

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