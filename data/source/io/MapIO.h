#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>

class MapIO
{
public:
	bool write(std::string filename, std::string mapData, sf::Vector2f CPU_pos, std::vector<sf::Sprite> spawners);
	bool read(std::string filename, std::string& mapData, sf::Vector2f& CPU_pos, std::vector<sf::Sprite>& spawners);

private:
	uint32_t mapSize;
	uint32_t spawnersSize;
};

