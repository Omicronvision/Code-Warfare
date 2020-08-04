#include "Waves.h"

Waves::Waves()
{
	adwSmallWave.enemyID = EnemiesSpawning::ADWARE;
	adwSmallWave.end = 10;
	adwSmallWave.enemyScaling = 2;
	adwSmallWave.amount = 1;

	adwBigWave.enemyID = EnemiesSpawning::ADWARE;
	adwBigWave.begin = 11;
	adwBigWave.enemyScaling = 1;
	adwBigWave.waveSpacing = 2;

	virSmallWave.enemyID = EnemiesSpawning::VIRUS;
	virSmallWave.begin = 6;
	virSmallWave.enemyScaling = 2;
	virSmallWave.waveSpacing = 2;
	virSmallWave.maxAmount = 10;

	troSmallWave.enemyID = EnemiesSpawning::TROJAN;
	troSmallWave.begin = 15;
	troSmallWave.enemyScaling = 5;
	troSmallWave.waveSpacing = 3;
}