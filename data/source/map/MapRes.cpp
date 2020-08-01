#include "MapRes.h"

MapRes::MapRes()
{

}

void MapRes::resetGame()
{
	greencoin = 100;
	electropiece = 0;
	CPU_usage = 10;
	stats.reset();
	waveSystem.waveNumber = 0;
	waveSystem.resetWaveChrono();
	v_takenPos.clear();
	v_bullets.clear();
	v_enemies.clear();
	v_proBuildings.clear();
	v_turBuildings.clear();
	v_defBuildings.clear();
	v_optBuildings.clear();
	v_vertBuildings.clear();
	v_vertBuildings.resize(50 * 50 * 4);
}

void MapRes::updateBuildings()
{
	/// PRODUCTION BUILDINGS
	for (unsigned int i = 0; i < v_proBuildings.size(); i++)
	{
		switch(v_proBuildings[i]->building.ID)
		{
		case 1:
			if (v_proBuildings[i]->getTimeGreenCoin() != 0)
			{
				greencoin += v_proBuildings[i]->getTimeGreenCoin();
				v_proBuildings[i]->resetClock();
			}
			break;
		case 2:
			if (v_proBuildings[i]->getTimeElectroPiece() != 0)
			{
				electropiece += v_proBuildings[i]->getTimeElectroPiece();
				v_proBuildings[i]->resetClock();
			}
			break;
		}
	}

	/// TURRET BUILDINGS
	for (unsigned int i = 0; i < v_turBuildings.size(); i++)
	{
		switch(v_turBuildings[i]->building.ID)
		{
		case 10:
		case 11:
		case 13:
			if (v_turBuildings[i]->isTime())
			{
				for (unsigned int j = 0; j < v_enemies.size(); j++)
				{
					if ((v_turBuildings[i]->isEnemy(v_enemies[j]->getBox())) && 
						(v_enemies[j]->visible) && (v_turBuildings[i]->isTime()))
					{
						// sound
						v_bullets.emplace_back(std::make_unique<Bullet>(bullets.defenderBullet));
						v_bullets[v_bullets.size() - 1]->getEnemyPosition(v_enemies[j]->getPosition(), v_turBuildings[i]->building.quad->position, v_turBuildings[i]->getDamage());
						v_turBuildings[i]->resetClock();
					}
				}
			}
			break;
		case 12:
			for (unsigned int j = 0; j < v_enemies.size(); j++)
			{
				if (v_turBuildings[i]->isEnemy(v_enemies[j]->getBox()))
				{
					v_enemies[j]->speed = v_enemies[j]->initialSpeed;
					v_enemies[j]->speed /= 2;
				}
				else
				{
					v_enemies[j]->speed = v_enemies[j]->initialSpeed;
				}
			}
			break;
		case 14:
			for (unsigned int j = 0; j < v_enemies.size(); j++)
			{
				if ((v_turBuildings[i]->isEnemy(v_enemies[j]->getBox())) && (v_turBuildings[i]->isTime()))
				{
					if (!v_enemies[j]->visible)
						v_enemies[j]->visible = true;
				}
			}
			break;
		case 15:
			if (v_turBuildings[i]->isTime())
			{
				for (unsigned int j = 0; j < v_enemies.size(); j++)
				{
					if ((v_turBuildings[i]->isEnemy(v_enemies[j]->getBox())) && (v_enemies[j]->visible))
					{
						// sound
						v_bullets.emplace_back(std::make_unique<Bullet>(bullets.defenderBullet));
						v_bullets[v_bullets.size() - 1]->getEnemyPosition(v_enemies[j]->getPosition(), v_turBuildings[i]->building.quad->position, v_turBuildings[i]->getDamage());
						v_turBuildings[i]->resetClock();
					}
				}
			}
		}
	}

	/// DEFENSIVE BUILDINGS
	for (unsigned int i = 0; i < v_defBuildings.size(); i++)
	{
		for (unsigned int j = 0; j < v_enemies.size(); j++)
		{
			// sound
			v_enemies[j]->setHealth(v_enemies[j]->getHealth() - v_defBuildings[i]->getDamage());
			sf::Vertex* quad;
			const int opx = v_defBuildings[i]->building.quad->position.x / 50;
			const int opy = v_defBuildings[i]->building.quad->position.y / 50;
			const int op = opx + (opy * 50);
			quad = &v_vertBuildings[((op % 50) + (op / 50) * 50) * 4];
			quad[0].color = sf::Color(0, 0, 0, 0);
			quad[1].color = sf::Color(0, 0, 0, 0);
			quad[2].color = sf::Color(0, 0, 0, 0);
			quad[3].color = sf::Color(0, 0, 0, 0);
			quad[0].position = sf::Vector2f(opx * 50, opy * 50);
			quad[1].position = sf::Vector2f(opx * 50 + 50, opy * 50);
			quad[2].position = sf::Vector2f(opx * 50 + 50, opy * 50 + 50);
			quad[3].position = sf::Vector2f(opx * 50, opy * 50 + 50);
			v_animations.emplace_back(std::make_unique<AnimationSprite>(animations.animDefExplosion));
			v_animations[v_animations.size() - 1]->setPosition(sf::Vector2f(v_defBuildings[i]->building.quad->position.x - 40, v_defBuildings[i]->building.quad->position.y - 40));
			v_takenPos.erase(std::remove(v_takenPos.begin(), v_takenPos.end(), op), v_takenPos.end());
			v_defBuildings.erase(v_defBuildings.begin() + i);
		}
	}
}

void MapRes::updateEnemies()
{

}

void MapRes::updateAnimations()
{
	Animation* curEnemyExplosion = &animations.wadEnemyExplosion;
	Animation* curDefExplosion = &animations.wadDefExplosion;
	static sf::Clock frameClock;
	for (unsigned int i = 0; i < v_animations.size(); i++)
	{
		sf::Time frameTime = frameClock.getElapsedTime();
		switch (v_animations[i]->ID)
		{
		case 1:
			v_animations[i]->playAnimation(*curEnemyExplosion); break;
		case 2:
			v_animations[i]->playAnimation(*curDefExplosion); break;
		}
		v_animations[i]->update(frameTime);
		if (v_animations[i]->isPause())
			v_animations.erase(v_animations.begin() + i);
	}
	frameClock.restart();
}