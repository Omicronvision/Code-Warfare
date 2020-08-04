#pragma once

#include <utility>

class EnabledWaves
{
public:
	void setFirstToSecond();
	bool isAllDisabled();

	static std::pair<bool, bool> enabledAdwSmallWave;
	static std::pair<bool, bool> enabledAdwBigWave;
	static std::pair<bool, bool> enabledVirSmallWave;
	static std::pair<bool, bool> enabledVirBigWave;
	static std::pair<bool, bool> enabledTroSmallWave;
	static std::pair<bool, bool> enabledDiaSmallWave;
	static std::pair<bool, bool> enabledDiaBigWave;
	static std::pair<bool, bool> enabledDroSmallWave;
	static std::pair<bool, bool> enabledSpySmallWave;
};

