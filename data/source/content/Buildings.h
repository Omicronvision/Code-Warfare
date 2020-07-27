#pragma once

#include <SFML/Graphics.hpp>
#include "../entities/buildings/Productive.h"
#include "../entities/buildings/Turret.h"
#include "../entities/buildings/Defensive.h"
#include "../entities/buildings/Optimizer.h"

class Buildings
{
public:
	Buildings();
	
	// Productives
	Productive greenCoinMiner, electroPieceMiner;

	// Turrets
	Turret defender1, defender2, lag, hawk, scanner, multi;

	// Defensives
	Defensive dp1, dp2, dp3;

	// Optimizers
	Optimizer optimizer1, optimizer2;
};

