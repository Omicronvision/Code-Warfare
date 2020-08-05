#include "EnemiesSpawning.h"

EnemiesSpawning::EnemiesSpawning()
{}

bool EnemiesSpawning::readJSON(std::string filename)
{
	std::ifstream file(filename);
	if (file.is_open())
		return false;

	std::stringstream text;
	std::string errors;
	text << file.rdbuf();

	Json::Value root;
	Json::CharReaderBuilder builder;
	Json::CharReader* reader = builder.newCharReader();
	reader->parse(text.str().c_str(), text.str().c_str() + text.str().size(), &root, &errors);
	file.close();
	delete reader;

	enemyID = root["enemyID"].asInt();
	enemyScaling = root["enemyScaling"].asInt();
	maxAmount = root["maxAmount"].asInt();
	spacingTime = root["spacingTime"].asFloat();

	return true;
}

bool EnemiesSpawning::writeJSON(std::string filename)
{
	return true;
}