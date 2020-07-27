#pragma once

class Rules
{
public:
	// infinite money. Player can build anything.
	bool infiniteMoney;
	// timer for waves
	bool waveTimer;
	// enabled tutorial
	bool tutorialEnabled = false;
	// if false game over can't happen after reaching cpu max usage
	bool possibleGameOver;
	// if waves are infinite
	bool finalWave;
	// if commands are enabled
	bool commandsEnabled = false;
	// default time between each wave in seconds
	float waveSpacing = 30.f;
};

