#include "Wave.h"

bool Wave::isEnemiesRemaining()
{
	if ((remainingAdwares + remainingDialers + remainingDroppers + remainingSpywares + remainingTrojans +
		remainingVirus) != 0)
		return true;
	else
		return false;
}