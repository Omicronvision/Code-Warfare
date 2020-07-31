#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "TileMap.h"
#include "../framework/DataTypes.h"
#include "../content/Enemies.h"
#include "../content/Buildings.h"
#include "../content/Bullets.h"
#include "../content/Animations.h"
#include "../game/WaveSystem.h"
#include "../game/Statistics.h"
#include "../game/Rules.h"

class MapRes
{
public:
	MapRes();
	void resetGame();
	void updateBuildings();
	void updateEnemies();
	void updateAnimations();

	TileMap tilemap;
	WaveSystem waveSystem;
	Statistics stats;
	Rules rules;

	enum class GameState{NOTHING, WON, LOST};
	int CPU_usage = 0, greencoin = 0, electropiece = 0;
	bool spawning = false;
	char map[2500];
	GameState gameState = GameState::NOTHING;

	Buildings buildings;
	Bullets bullets;
	Animations animations;

	/// vectors
	std::vector<int>								v_takenPos;
	std::vector<sf::Vertex>							v_vertBuildings;
	std::vector<std::unique_ptr<Enemy>>				v_enemies;
	std::vector<std::unique_ptr<Productive>>		v_proBuildings;
	std::vector<std::unique_ptr<Turret>>			v_turBuildings;
	std::vector<std::unique_ptr<Defensive>>			v_defBuildings;
	std::vector<std::unique_ptr<Optimizer>>			v_optBuildings;
	std::vector<std::unique_ptr<Bullet>>			v_bullets;
	std::vector<std::unique_ptr<AnimationSprite>>   v_animations;
};

