#pragma once

class Statistics
{
public:
	Statistics();

	void reset();
	int getScore(int CPU_usage);

	int enemiesDestroyed;
	int buildingsCreated;
	int buildingsDestroyed;
};

