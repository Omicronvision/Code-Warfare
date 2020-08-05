#include "Map.h"

Map::Map():
chosenCategory(1), chosenBuild(0), drawBuildInfo(false)
{
	mapRenderer.setPosition(1280, 720, 0, 0);
}

void Map::loadTileMap(std::string filename)
{
	std::string mapData;
	sf::Vector2f CPU_pos;
	std::vector<sf::Vector2f> v_spawners;
	if(!mapIO.read(filename, mapData, CPU_pos, v_spawners))
		exit(6);
	mapData.copy(mapRes.map, mapData.size() + 1);
	mapRes.map[mapData.size()] = '\0';
	for (unsigned int i = 0; i < v_spawners.size(); i++)
	{
		sf::Sprite spawner;
		spawner.setTexture(mapRenderer.Tspawner.texture);
		spawner.setPosition(v_spawners[i]);
		mapRes.v_spawners.push_back(spawner);
	}
	mapRenderer.CPU.setPosition(CPU_pos);
	mapRes.tilemap.getMap(mapRes.map);
	mapRes.tilemap.loadTileMap(50, 50);
}

void Map::draw(sf::RenderWindow& window, bool paused)
{
	window.draw(mapRenderer.background);
	window.draw(mapRes.tilemap);
	window.draw(&mapRes.v_vertBuildings[0], mapRes.v_vertBuildings.size(), sf::Quads, &mapRenderer.Tbuildings.texture);
	mapRenderer.render(window, chosenCategory, chosenBuild, drawBuildInfo, mapRes.v_spawners);

	if (paused)
	{
		window.draw(mapRenderer.pauseBg.rectform);
		window.draw(mapRenderer.m1.rectform);
		window.draw(mapRenderer.m2.rectform);
		window.draw(mapRenderer.tm1.text);
		window.draw(mapRenderer.tm2.text);
		window.draw(mapRenderer.tpaused.text);
	}
}

void Map::update(Int32 x, Int32 y, Int32 width, Int32 height)
{
	updateCoins();
	updateWaveTime();
	mapRes.updateBuildings();
	switch(chosenCategory)
	{
	case 1:
		mapRenderer.selectedCategory.rectform.setPosition(sf::Vector2f(x + 10, y + 10)); break;
	case 2:
		mapRenderer.selectedCategory.rectform.setPosition(sf::Vector2f(x + 60, y + 10)); break;
	case 3:
		mapRenderer.selectedCategory.rectform.setPosition(sf::Vector2f(x + 110, y + 10)); break;
	case 4:
		mapRenderer.selectedCategory.rectform.setPosition(sf::Vector2f(x + 160, y + 10)); break;
	}
	switch(chosenBuild)
	{
	case 1:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 10, y + 80)); break;
	case 2:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 60, y + 80)); break;
	case 10:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 10, y + 80)); break;
	case 11:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 60, y + 80)); break;
	case 12:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 110, y + 80)); break;
	case 13:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 160, y + 80)); break;
	case 14:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 10, y + 130)); break;
	case 15:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 60, y + 130)); break;
	case 20:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 10, y + 80)); break;
	case 21:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 60, y + 80)); break;
	case 22:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 110, y + 80)); break;
	case 30:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 10, y + 80)); break;
	case 31:
		mapRenderer.selectedBuilding.rectform.setPosition(sf::Vector2f(x + 60, y + 80)); break;
	}
	mapRenderer.setPosition(x, y, width, height);
	if (mapRes.waveSystem.waveChrono.getTimeAsSeconds() >= mapRes.waveSystem.waveTime)
	{
		mapRes.waveSystem.resetWaveChrono();
		mapRes.waveSystem.nextWave();
		mapRes.spawning = true;
		mapRes.waveSystem.startWaveChrono();
		mapRes.enabledWaves.setFirstToSecond();
	}
	if (mapRes.spawning)
	{
		if (!mapRes.enabledWaves.isAllDisabled())
			if (!mapRes.wave.isEnemiesRemaining())
				mapRes.setEnemiesWave();
			else
				mapRes.spawnEnemies();
		
		if (mapRes.enabledWaves.isAllDisabled())
			if (!mapRes.wave.isEnemiesRemaining())
				mapRes.spawning = false;
	}
}

void Map::mouseMoved(sf::Vector2f MP, sf::Vector2f MPC, bool paused, Int32 width, Int32 height)
{
	const int tmx = (int)MPC.x / 50 + 1;
	const int tmy = (int)MPC.y / 50;
	const int tmpos = tmx + (tmy * 50) - 1;
	const int x = tmpos % 50;
	const int y = tmpos / 50;
	mapRenderer.selectedTile.rectform.setPosition(sf::Vector2f(50 * x, 50 * y));

	if (!paused)
	{
		switch (chosenCategory)
		{
		case 1:
			if (sf::FloatRect(10, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.greenCoinMiner.building.getName(),
					mapRes.buildings.greenCoinMiner.building.getCPU_usage(),
					mapRes.buildings.greenCoinMiner.building.ID, 0, 0, 0,
					mapRes.buildings.greenCoinMiner.building.getPriceGC(),
					mapRes.buildings.greenCoinMiner.building.getPriceEP());
			else if (sf::FloatRect(60, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.electroPieceMiner.building.getName(),
					mapRes.buildings.electroPieceMiner.building.getCPU_usage(),
					mapRes.buildings.electroPieceMiner.building.ID, 0, 0, 0,
					mapRes.buildings.electroPieceMiner.building.getPriceGC(),
					mapRes.buildings.electroPieceMiner.building.getPriceEP());
			break;
		case 2:
			if (sf::FloatRect(10, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.defender1.building.getName(),
					mapRes.buildings.defender1.building.getCPU_usage(),
					mapRes.buildings.defender1.building.ID,
					mapRes.buildings.defender1.damage,
					mapRes.buildings.defender1.radius.getRadius(),
					mapRes.buildings.defender1.shootingTime,
					mapRes.buildings.defender1.building.getPriceGC(),
					mapRes.buildings.defender1.building.getPriceEP());
			else if (sf::FloatRect(60, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.defender2.building.getName(),
					mapRes.buildings.defender2.building.getCPU_usage(),
					mapRes.buildings.defender2.building.ID,
					mapRes.buildings.defender2.damage,
					mapRes.buildings.defender2.radius.getRadius(),
					mapRes.buildings.defender2.shootingTime,
					mapRes.buildings.defender2.building.getPriceGC(),
					mapRes.buildings.defender2.building.getPriceEP());
			else if (sf::FloatRect(110, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.lag.building.getName(),
					mapRes.buildings.lag.building.getCPU_usage(),
					mapRes.buildings.lag.building.ID,
					mapRes.buildings.lag.damage,
					mapRes.buildings.lag.radius.getRadius(),
					mapRes.buildings.lag.shootingTime,
					mapRes.buildings.lag.building.getPriceGC(),
					mapRes.buildings.lag.building.getPriceEP());
			else if (sf::FloatRect(160, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.hawk.building.getName(),
					mapRes.buildings.hawk.building.getCPU_usage(),
					mapRes.buildings.hawk.building.ID,
					mapRes.buildings.hawk.damage,
					mapRes.buildings.hawk.radius.getRadius(),
					mapRes.buildings.hawk.shootingTime,
					mapRes.buildings.hawk.building.getPriceGC(),
					mapRes.buildings.hawk.building.getPriceEP());
			else if (sf::FloatRect(10, 130, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.scanner.building.getName(),
					mapRes.buildings.scanner.building.getCPU_usage(),
					mapRes.buildings.scanner.building.ID,
					mapRes.buildings.scanner.damage,
					mapRes.buildings.scanner.radius.getRadius(),
					mapRes.buildings.scanner.shootingTime,
					mapRes.buildings.scanner.building.getPriceGC(),
					mapRes.buildings.scanner.building.getPriceEP());
			else if (sf::FloatRect(60, 130, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.multi.building.getName(),
					mapRes.buildings.multi.building.getCPU_usage(),
					mapRes.buildings.multi.building.ID,
					mapRes.buildings.multi.damage,
					mapRes.buildings.multi.radius.getRadius(),
					mapRes.buildings.multi.shootingTime,
					mapRes.buildings.multi.building.getPriceGC(),
					mapRes.buildings.multi.building.getPriceEP());
			break;
		case 3:
			if (sf::FloatRect(10, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.dp1.building.getName(),
					mapRes.buildings.dp1.building.getCPU_usage(),
					mapRes.buildings.dp1.building.ID,
					mapRes.buildings.dp1.damage, 0, 0,
					mapRes.buildings.dp1.building.getPriceGC(),
					mapRes.buildings.dp1.building.getPriceEP());
			else if (sf::FloatRect(60, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.dp2.building.getName(),
					mapRes.buildings.dp2.building.getCPU_usage(),
					mapRes.buildings.dp2.building.ID,
					mapRes.buildings.dp2.damage, 0, 0,
					mapRes.buildings.dp2.building.getPriceGC(),
					mapRes.buildings.dp2.building.getPriceEP());
			else if (sf::FloatRect(110, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.dp3.building.getName(),
					mapRes.buildings.dp3.building.getCPU_usage(),
					mapRes.buildings.dp3.building.ID,
					mapRes.buildings.dp3.damage, 0, 0,
					mapRes.buildings.dp3.building.getPriceGC(),
					mapRes.buildings.dp3.building.getPriceEP());
			break;
		case 4:
			if (sf::FloatRect(10, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.optimizer1.building.getName(),
					mapRes.buildings.optimizer1.building.getCPU_usage(),
					mapRes.buildings.optimizer1.building.ID, 0, 0, 0,
					mapRes.buildings.optimizer1.building.getPriceGC(),
					mapRes.buildings.optimizer1.building.getPriceEP());
			else if (sf::FloatRect(60, 80, 50, 50).contains(MP))
				updateBuildingInfo(mapRes.buildings.optimizer2.building.getName(),
					mapRes.buildings.optimizer2.building.getCPU_usage(),
					mapRes.buildings.optimizer2.building.ID, 0, 0, 0,
					mapRes.buildings.optimizer2.building.getPriceGC(),
					mapRes.buildings.optimizer2.building.getPriceEP());
			break;
		}
	} else
	{
		const sf::FloatRect button1(width / 2 - mapRenderer.m1.rectform.getSize().x / 2, height / 2 - 200, 300, 80);
		const sf::FloatRect button2(width / 2 - mapRenderer.m2.rectform.getSize().x / 2, height / 2 - 80, 300, 80);
		if (button1.contains(MP))
			mapRenderer.m1.rectform.setFillColor(sf::Color(115, 22, 17));
		else
			mapRenderer.m1.rectform.setFillColor(sf::Color::Black);

		if (button2.contains(MP))
			mapRenderer.m2.rectform.setFillColor(sf::Color(115, 22, 17));
		else
			mapRenderer.m2.rectform.setFillColor(sf::Color::Black);
	}
}

void Map::click(sf::Vector2f MP, sf::Vector2f MPC, Int32& scene, sf::RenderWindow& window, bool& paused)
{
	const int tmx = (int)MPC.x / 50 + 1;
	const int tmy = (int)MPC.y / 50;
	const int tmpos = tmx + (tmy * 50) - 1;
	if (!paused)
	{
		if (!sf::FloatRect(10, 10, 200, 300).contains(MP))
		{
			if (!std::count(mapRes.v_takenPos.begin(), mapRes.v_takenPos.end(), tmpos))
			{
				if (mapRes.tilemap.checkTile(tmpos, 'h'))
				{
					bool isBuiltPro = false;
					switch(chosenBuild)
					{
					case 1: /// greenCoinMiner ID
						if ((mapRes.greencoin >= mapRes.buildings.greenCoinMiner.building.getPriceGC()) && 
							(mapRes.electropiece >= mapRes.buildings.greenCoinMiner.building.getPriceEP()))
						{
							mapRes.v_proBuildings.emplace_back(std::make_unique<Productive>(mapRes.buildings.greenCoinMiner));
							isBuiltPro = true;
						} break;
					case 2: ///electroPieceMiner ID
						if ((mapRes.greencoin >= mapRes.buildings.electroPieceMiner.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.electroPieceMiner.building.getPriceEP()))
						{
							mapRes.v_proBuildings.emplace_back(std::make_unique<Productive>(mapRes.buildings.electroPieceMiner));
							isBuiltPro = true;
						} break;
					}
					if (isBuiltPro)
					{
						// sound
						mapRes.stats.buildingsCreated++;
						mapRes.greencoin -= mapRes.v_proBuildings[mapRes.v_proBuildings.size() - 1]->building.getPriceGC();
						mapRes.electropiece -= mapRes.v_proBuildings[mapRes.v_proBuildings.size() - 1]->building.getPriceEP();
						mapRes.v_proBuildings[mapRes.v_proBuildings.size() - 1]->building.quad = &mapRes.v_vertBuildings[((tmpos % 50) + (tmpos / 50) * 50) * 4];
						mapRes.v_proBuildings[mapRes.v_proBuildings.size() - 1]->building.setPosition(tmpos);
						mapRes.v_proBuildings[mapRes.v_proBuildings.size() - 1]->building.setTexture();
						mapRes.CPU_usage += mapRes.v_proBuildings[mapRes.v_proBuildings.size() - 1]->building.getCPU_usage();
						mapRes.v_takenPos.push_back(tmpos);
					}
				} else if (mapRes.tilemap.checkTile(tmpos, '.'))
				{
					bool isBuiltTur = false;
					bool isBuiltOpt = false;
					switch(chosenBuild)
					{
					case 10: /// Defender 1.0 ID
						if ((mapRes.greencoin >= mapRes.buildings.defender1.building.getPriceGC()) && 
							(mapRes.electropiece >= mapRes.buildings.defender1.building.getPriceEP()))
						{
							mapRes.v_turBuildings.emplace_back(std::make_unique<Turret>(mapRes.buildings.defender1));
							isBuiltTur = true;
						} break;
					case 11: /// Defender 2.0 ID
						if ((mapRes.greencoin >= mapRes.buildings.defender2.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.defender2.building.getPriceEP()))
						{
							mapRes.v_turBuildings.emplace_back(std::make_unique<Turret>(mapRes.buildings.defender2));
							isBuiltTur = true;
						} break;
					case 12: /// Lag ID
						if ((mapRes.greencoin >= mapRes.buildings.lag.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.lag.building.getPriceEP()))
						{
							mapRes.v_turBuildings.emplace_back(std::make_unique<Turret>(mapRes.buildings.lag));
							isBuiltTur = true;
						} break;
					case 13: /// Hawk ID
						if ((mapRes.greencoin >= mapRes.buildings.hawk.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.hawk.building.getPriceEP()))
						{
							mapRes.v_turBuildings.emplace_back(std::make_unique<Turret>(mapRes.buildings.hawk));
							isBuiltTur = true;
						} break;
					case 14: /// Scanner ID
						if ((mapRes.greencoin >= mapRes.buildings.scanner.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.scanner.building.getPriceEP()))
						{
							mapRes.v_turBuildings.emplace_back(std::make_unique<Turret>(mapRes.buildings.scanner));
							isBuiltTur = true;
						} break;
					case 15: /// Multi ID
						if ((mapRes.greencoin >= mapRes.buildings.multi.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.multi.building.getPriceEP()))
						{
							mapRes.v_turBuildings.emplace_back(std::make_unique<Turret>(mapRes.buildings.multi));
							isBuiltTur = true;
						} break;
					case 30: /// Optimizer 1.0
						if ((mapRes.greencoin >= mapRes.buildings.optimizer1.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.optimizer1.building.getPriceEP()))
						{
							mapRes.v_optBuildings.emplace_back(std::make_unique<Optimizer>(mapRes.buildings.optimizer1));
							isBuiltOpt = true;
						} break;
					case 31: /// Optimizer 2.0
						if ((mapRes.greencoin >= mapRes.buildings.optimizer2.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.optimizer2.building.getPriceEP()))
						{
							mapRes.v_optBuildings.emplace_back(std::make_unique<Optimizer>(mapRes.buildings.optimizer2));
							isBuiltOpt = true;
						} break;
					}
					if (isBuiltTur)
					{
						// sound
						mapRes.stats.buildingsCreated++;
						mapRes.greencoin -= mapRes.v_turBuildings[mapRes.v_turBuildings.size() - 1]->building.getPriceGC();
						mapRes.electropiece -= mapRes.v_turBuildings[mapRes.v_turBuildings.size() - 1]->building.getPriceEP();
						mapRes.v_turBuildings[mapRes.v_turBuildings.size() - 1]->building.quad = &mapRes.v_vertBuildings[((tmpos % 50) + (tmpos / 50) * 50) * 4];
						mapRes.v_turBuildings[mapRes.v_turBuildings.size() - 1]->building.setPosition(tmpos);
						mapRes.v_turBuildings[mapRes.v_turBuildings.size() - 1]->building.setTexture();
						mapRes.v_turBuildings[mapRes.v_turBuildings.size() - 1]->setRadiusPosition();
						mapRes.CPU_usage += mapRes.v_turBuildings[mapRes.v_turBuildings.size() - 1]->building.getCPU_usage();
						mapRes.v_takenPos.push_back(tmpos);
					} else if (isBuiltOpt)
					{
						// sound
						mapRes.stats.buildingsCreated++;
						mapRes.greencoin -= mapRes.v_optBuildings[mapRes.v_optBuildings.size() - 1]->building.getPriceGC();
						mapRes.electropiece -= mapRes.v_optBuildings[mapRes.v_optBuildings.size() - 1]->building.getPriceEP();
						mapRes.v_optBuildings[mapRes.v_optBuildings.size() - 1]->building.quad = &mapRes.v_vertBuildings[((tmpos % 50) + (tmpos / 50) * 50) * 4];
						mapRes.v_optBuildings[mapRes.v_optBuildings.size() - 1]->building.setPosition(tmpos);
						mapRes.v_optBuildings[mapRes.v_optBuildings.size() - 1]->building.setTexture();
						mapRes.CPU_usage += mapRes.v_optBuildings[mapRes.v_optBuildings.size() - 1]->building.getCPU_usage();
						mapRes.CPU_usage -= mapRes.v_optBuildings[mapRes.v_optBuildings.size() - 1]->getOptimization();
						mapRes.v_takenPos.push_back(tmpos);
					}
				} else if (mapRes.tilemap.checkTile(tmpos, '+'))
				{
					bool isBuiltDef = false;
					switch(chosenBuild)
					{
					case 20: /// defensive (freeze)
						if ((mapRes.greencoin >= mapRes.buildings.dp1.building.getPriceGC()) && 
							(mapRes.electropiece >= mapRes.buildings.dp1.building.getPriceEP()))
						{
							mapRes.v_defBuildings.emplace_back(std::make_unique<Defensive>(mapRes.buildings.dp1));
							isBuiltDef = true;
						} break;
					case 21: /// defensive (crash)
						if ((mapRes.greencoin >= mapRes.buildings.dp2.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.dp2.building.getPriceEP()))
						{
							mapRes.v_defBuildings.emplace_back(std::make_unique<Defensive>(mapRes.buildings.dp2));
							isBuiltDef = true;
						} break;
					case 22: /// defensive (delete)
						if ((mapRes.greencoin >= mapRes.buildings.dp3.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.dp3.building.getPriceEP()))
						{
							mapRes.v_defBuildings.emplace_back(std::make_unique<Defensive>(mapRes.buildings.dp3));
							isBuiltDef = true;
						} break;
					}
					if (isBuiltDef)
					{
						// sound
						mapRes.stats.buildingsCreated++;
						mapRes.greencoin -= mapRes.v_defBuildings[mapRes.v_defBuildings.size() - 1]->building.getPriceGC();
						mapRes.electropiece -= mapRes.v_defBuildings[mapRes.v_defBuildings.size() - 1]->building.getPriceEP();
						mapRes.v_defBuildings[mapRes.v_defBuildings.size() - 1]->building.quad = &mapRes.v_vertBuildings[((tmpos % 50) + (tmpos / 50) * 50) * 4];
						mapRes.v_defBuildings[mapRes.v_defBuildings.size() - 1]->building.setPosition(tmpos);
						mapRes.v_defBuildings[mapRes.v_defBuildings.size() - 1]->building.setTexture();
						mapRes.CPU_usage += mapRes.v_defBuildings[mapRes.v_defBuildings.size() - 1]->building.getCPU_usage();
						mapRes.v_takenPos.push_back(tmpos);
					}
				}
			}
		}
		else
		{
			if (sf::FloatRect(10, 10, 50, 50).contains(MP))
			{
				chosenCategory = 1;
				chosenBuild = 0;
			}
			else if (sf::FloatRect(60, 10, 50, 50).contains(MP))
			{
				chosenCategory = 2;
				chosenBuild = 0;
			}
			else if (sf::FloatRect(110, 10, 50, 50).contains(MP))
			{
				chosenCategory = 3;
				chosenBuild = 0;
			}
			else if (sf::FloatRect(160, 10, 50, 50).contains(MP))
			{
				chosenCategory = 4;
				chosenBuild = 0;
			}
			else
				switch (chosenCategory)
				{
				case 1:
					if (sf::FloatRect(10, 80, 50, 50).contains(MP)) chosenBuild = 1;
					else if (sf::FloatRect(60, 80, 50, 50).contains(MP)) chosenBuild = 2;
					break;
				case 2:
					if (sf::FloatRect(10, 80, 50, 50).contains(MP)) chosenBuild = 10;
					else if (sf::FloatRect(60, 80, 50, 50).contains(MP)) chosenBuild = 11;
					else if (sf::FloatRect(110, 80, 50, 50).contains(MP)) chosenBuild = 12;
					else if (sf::FloatRect(160, 80, 50, 50).contains(MP)) chosenBuild = 13;
					else if (sf::FloatRect(10, 130, 50, 50).contains(MP)) chosenBuild = 14;
					else if (sf::FloatRect(60, 130, 50, 50).contains(MP)) chosenBuild = 15;
					break;
				case 3:
					if (sf::FloatRect(10, 80, 50, 50).contains(MP)) chosenBuild = 20;
					else if (sf::FloatRect(60, 80, 50, 50).contains(MP)) chosenBuild = 21;
					else if (sf::FloatRect(110, 80, 50, 50).contains(MP)) chosenBuild = 22;
					break;
				case 4:
					if (sf::FloatRect(10, 80, 50, 50).contains(MP)) chosenBuild = 30;
					else if (sf::FloatRect(60, 80, 50, 50).contains(MP)) chosenBuild = 31;
					break;
				}
		}
	} else
	{
		const sf::FloatRect button1(window.getSize().x / 2 - mapRenderer.m1.rectform.getSize().x / 2, window.getSize().y / 2 - 200, 300, 80);
		const sf::FloatRect button2(window.getSize().x / 2 - mapRenderer.m2.rectform.getSize().x / 2, window.getSize().y / 2 - 80, 300, 80);
		if (button1.contains(MP))
			paused = false;
		else if (button2.contains(MP))
		{
			mapRes.resetGame();
			paused = false;
			scene = Scenes::mainMenu;
		}
	}
}

void Map::updateCoins()
{
	std::ostringstream ss1, ss2;
	ss1 << mapRes.greencoin;
	mapRenderer.tpiece1.text.setString(ss1.str());
	ss2 << mapRes.electropiece;
	mapRenderer.tpiece2.text.setString(ss2.str());
}

void Map::updateWaveTime()
{
	float duration = mapRes.waveSystem.waveChrono.getTimeAsSeconds();
	int countdown = static_cast<int>(mapRes.rules.waveSpacing - duration);
	std::ostringstream ss;
	ss << "Next wave in " << countdown << "\nCurrent wave : " << mapRes.waveSystem.waveNumber 
		<< "\nCPU usage : " << mapRes.CPU_usage << "%";
	mapRenderer.waveInfo.text.setString(ss.str());
}

void Map::updateBuildingInfo(std::string name, int CPU_usage, int id, int damage, int range, float shootingSpeed, int gre, int ele)
{
	drawBuildInfo = true;
	static int previousID;
	std::ostringstream oss1, oss2;
	oss1 << "-" << gre;
	oss2 << "-" << ele;
	mapRenderer.buildingName.text.setString(name);
	mapRenderer.ppiece1.text.setString(oss1.str());
	mapRenderer.ppiece2.text.setString(oss2.str());
	if(previousID != id)
	{
		std::string description;
		std::ostringstream ss;
		switch (id)
		{
		case 1: //greencoin miner
			description = "Program that allows\ncryptocurrency mining\n(greencoin)."; break;
		case 2: //electro builder
			description = "Program that allows\ncryptocurrency mining\n(electropiece)."; break;
		case 10: //defender 1.0
			description = "Low cost basic\nanti-malware program,\nvery poorly optimized.\nFires small\nprojectiles at\nmalwares."; break;
		case 11: //defender 2.0
			description = "Average cost \nanti-malware program \nbetter than defender \n1.0, quite well \noptimized.\nFires small\nprojectiles at\nenemies less quickly\nbut causes more\ndamage."; break;
		case 12: //lag
			description = "Program causing delays\nin computer\ncommunications.\nSlows enemies"; break;
		case 13: //sentry
			description = "Advanced anti-malware\nprogram.\nShoot at distant\nmalwares and cause\na lot of damage."; break;
		case 14: //scanner
			description = "Program that detects\nspywares"; break;
		case 15: //decompiler
			description = "Advanced anti-malware\nprogram.\nShoot multiple\nprojectiles at\nenemies within\nrange, but does\nlittle damage."; break;
		case 20: //freeze
			description = "Program that\ncause damage\nby freezing the\nmalware.\nCan only be\nused once"; break;
		case 21: //crash
			description = "Program that\ncrash the\nmalware and cause\nbig damage.\nCan only be\nused once"; break;
		case 22: //delete
			description = "Program that\ndelete any\nmalware.\nCan only be\nused once"; break;
		case 30: //optimizer 1.0
			description = "Program that\noptimizes the\nprocessor."; break;
		case 31: //optimizer 2.0
			description = "Program that\noptimizes the\nprocessor."; break;
		}

		ss << CPU_usage;
		mapRenderer.buildingInfo.text.clear();
		mapRenderer.buildingInfo.text << sf::Text::Bold << sf::Color::Green << "Name : "
			<< sf::Text::Regular << sf::Color::White << name
			<< sf::Text::Bold << sf::Color::Green << "\nDescription :\n"
			<< sf::Text::Regular << sf::Color::White << description
			<< sf::Text::Bold << sf::Color::Red << "\nCPU usage : "
			<< sf::Text::Regular << sf::Color::White << ss.str() << "\n";
		if ((unsigned)(id - 10) <= (29 - 10))
		{
			std::ostringstream a;
			a << damage;
			mapRenderer.buildingInfo.text << sf::Text::Bold << sf::Color::Yellow << "Damage : "
				<< sf::Text::Regular << sf::Color::White << a.str() << "\n";
			std::ostringstream b;
			b << shootingSpeed;
			mapRenderer.buildingInfo.text << sf::Text::Bold << sf::Color::Yellow << "Speed : "
				<< sf::Text::Regular << sf::Color::White << b.str() << " sec" << "\n";
			std::ostringstream c;
			c << range;
			mapRenderer.buildingInfo.text << sf::Text::Bold << sf::Color::Yellow << "Range : "
				<< sf::Text::Regular << sf::Color::White << c.str() << " px" << "\n";
		}
	}
}