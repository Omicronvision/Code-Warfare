#include "WaveSystem.h"

WaveSystem::WaveSystem():
waveTime(30.f)
{}

void WaveSystem::startWaveChrono()
{
	waveChrono.start();
}

void WaveSystem::pauseWaveChrono()
{
	waveChrono.pause();
}

void WaveSystem::resetWaveChrono()
{
	waveChrono.reset();
}

void WaveSystem::nextWave()
{
	waveNumber++;
}