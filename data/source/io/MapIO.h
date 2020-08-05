#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>

class MapIO
{
public:
	bool write(std::string filename, std::string mapData, sf::Vector2f CPU_pos, std::vector<sf::Vector2f> spawners);
	bool read(std::string filename, std::string& mapData, sf::Vector2f& CPU_pos, std::vector<sf::Vector2f>& spawners);

private:
	uint32_t spawnersSize;
	uint32_t mapSize;
};

