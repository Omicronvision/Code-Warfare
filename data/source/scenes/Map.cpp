#include "Map.h"

Map::Map():
chosenCategory(1), chosenBuild(0), drawBuildInfo(false), categoryChanged(false), buildChanged(false)
{
	mapRenderer.setPosition(1280, 720, 0, 0);
}

void Map::draw(sf::RenderWindow& window)
{
	mapRenderer.render(window, chosenCategory, chosenBuild, drawBuildInfo);
}

void Map::update(Int32 x, Int32 y, Int32 width, Int32 height)
{
	if(categoryChanged)
	{
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
		categoryChanged = false;
	}
	if(buildChanged)
	{
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
		buildChanged = false;
	}
	mapRenderer.setPosition(x, y, width, height);
	if (mapRes.waveSystem.waveChrono.getTimeAsSeconds() >= mapRes.waveSystem.waveTime)
	{
		mapRes.waveSystem.resetWaveChrono();
		mapRes.waveSystem.nextWave();
		mapRes.spawning = true;
		mapRes.waveSystem.startWaveChrono();
	}
	if (mapRes.spawning)
	{

	}
}

void Map::mouseMoved(sf::Vector2f MP, sf::Vector2f MPC)
{
	const int tmx = (int)MPC.x / 50 + 1;
	const int tmy = (int)MPC.y / 50;
	const int tmpos = tmx + (tmy * 50) - 1;
	const int x = tmpos % 50;
	const int y = tmpos / 50;

	mapRenderer.selectedTile.rectform.setPosition(sf::Vector2f(50 * x, 50 * y));
}

void Map::click(sf::Vector2f MP, sf::Vector2f MPC, Int32& scene, sf::RenderWindow& window, bool paused)
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
							mapRes.v_turBuildings.emplace_back(std::make_unique<Turret>(mapRes.buildings.optimizer1));
							isBuiltOpt = true;
						} break;
					case 31: /// Optimizer 2.0
						if ((mapRes.greencoin >= mapRes.buildings.optimizer2.building.getPriceGC()) &&
							(mapRes.electropiece >= mapRes.buildings.optimizer2.building.getPriceEP()))
						{
							mapRes.v_turBuildings.emplace_back(std::make_unique<Turret>(mapRes.buildings.optimizer2));
							isBuiltOpt = true;
						} break;
					}
					if (isBuiltTur)
					{
						// sound
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
				categoryChanged = true;
			}
			else if (sf::FloatRect(60, 10, 50, 50).contains(MP))
			{
				chosenCategory = 2;
				categoryChanged = true;
			}
			else if (sf::FloatRect(110, 10, 50, 50).contains(MP))
			{
				chosenCategory = 3;
				categoryChanged = true;
			}
			else if (sf::FloatRect(160, 10, 50, 50).contains(MP))
			{
				chosenCategory = 4;
				categoryChanged = true;
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
	}
}