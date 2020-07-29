#pragma once

#include "Waves.h"
#include "../framework/Chrono.h"

class WaveSystem
{
public:
	WaveSystem();

	void pauseWaveChrono();
	void startWaveChrono();
	void resetWaveChrono();
	void nextWave();

	unsigned int waveNumber = 0;
	float waveTime;
	Chrono waveChrono;
};

