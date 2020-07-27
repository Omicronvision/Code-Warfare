#include "Gamemodes.h"

Gamemodes::Gamemodes()
{

}

void Gamemodes::survivalMode()
{
	rules.infiniteMoney = false;
	rules.waveTimer = true;
	rules.possibleGameOver = true;
	rules.finalWave = true;
}

void Gamemodes::endlessMode()
{
	rules.infiniteMoney = false;
	rules.waveTimer = true;
	rules.possibleGameOver = true;
	rules.finalWave = false;
}

void Gamemodes::creativeMode()
{
	rules.infiniteMoney = true;
	rules.waveTimer = false;
	rules.possibleGameOver = false;
	rules.finalWave = false;
	rules.commandsEnabled = true;
}