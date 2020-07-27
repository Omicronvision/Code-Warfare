#pragma once

#include "Rules.h"

class Gamemodes
{
public:
	Gamemodes();

	void survivalMode();
	void creativeMode();
	void endlessMode();

private:
	Rules rules;
};