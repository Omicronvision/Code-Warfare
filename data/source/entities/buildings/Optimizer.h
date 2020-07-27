#pragma once

#include <SFML/Graphics.hpp>
#include "Building.h"
#include "../../framework/DataTypes.h"

using namespace dt;

class Optimizer
{
public:
	Optimizer(std::string name, Int32 ID);
	Int32 getOptimization();
	
	Building building;
	Int32 optimization;
};

