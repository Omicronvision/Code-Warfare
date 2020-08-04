#pragma once

#include <fstream>
#include <json/json.h>

class EnemiesSpawning
{
public:
	EnemiesSpawning();

	bool readJSON(std::string filename);
	bool writeJSON(std::string filename);

	static const int never = INT_MAX;
	// number of waves from which the enemies can spawn
	int begin = 0;
	// number of waves from which the enemies can't spawn anymore
	int end = never;
	// maximum amount of enemies for the wave
	int maxAmount = 80;
	// enemy type (ID)
	int enemyID = 0;
	// current amount
	int amount = 0;
	// waves that need to pass to increase the amount of enemies
	int enemyScaling = never;
	// waves that need to pass between each spawn
	int waveSpacing = 1;
	// time in seconds between each enemy to spawn
	float spacingTime = 0.5f;

	enum idtype
	{
		ADWARE = 1,
		VIRUS = 2,
		TROJAN = 3,
		DIALER = 4,
		DROPPER = 5,
		SPYWARE = 6
	};
};

