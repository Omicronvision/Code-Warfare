#include "MapRes.h"

MapRes::MapRes()
{

}

void MapRes::resetGame()
{
	stats.reset();
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