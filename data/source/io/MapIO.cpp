#include "MapIO.h"

bool MapIO::write(std::string filename, std::string mapData, sf::Vector2f CPU_pos,
    std::vector<sf::Sprite> spawners)
{
    std::ofstream file;
    file.open(filename, std::ios::out | std::ios::binary);
    if (!file.is_open())
        return false;

    mapSize = (uint32_t)mapData.size();
    spawnersSize = (uint32_t)spawners.size();
    // write map
    file.write((char*)&mapSize, sizeof(mapSize));
    file.write((char*)mapData.data(), mapData.size());
    // write CPU position
    file.write((char*)&CPU_pos.x, sizeof(CPU_pos.x));
    file.write((char*)&CPU_pos.y, sizeof(CPU_pos.y));
    // write spawners sprite
    file.write((char*)&spawnersSize, sizeof(spawnersSize));
    file.write((char*)spawners.data(), spawnersSize * sizeof(sf::Sprite));

    file.close();

    return true;
}

bool MapIO::read(std::string filename, std::string& mapData, sf::Vector2f& CPU_pos,
    std::vector<sf::Sprite>& spawners)
{
    std::ifstream file;
    file.open(filename, std::ios::in | std::ios::binary);
    if (!file.is_open())
        return false;

    // read map
    file.read((char*)&mapSize, sizeof(mapSize));
    mapData.resize(mapSize);
    file.read((char*)mapData.data(), mapData.size());
    // read CPU position
    file.read((char*)&CPU_pos.x, sizeof(CPU_pos.x));
    file.read((char*)&CPU_pos.y, sizeof(CPU_pos.y));
    // read spawners sprite
    //file.read((char*)&spawnersSize, sizeof(spawnersSize));
    //file.read((char*)spawners.data(), spawnersSize * sizeof(sf::Sprite));

    file.close();

    return true;
}