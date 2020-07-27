#include "Buildings.h"

Buildings::Buildings():
greenCoinMiner("Greencoin miner", 1),
electroPieceMiner("Electro miner", 2),
defender1("Defender 1.0", 10),
defender2("Defender 2.0", 11),
lag("Lag", 12),
hawk("Hawk", 13),
scanner("Scanner", 14),
multi("Multi", 15),
dp1("Freeze", 20),
dp2("Crash", 21),
dp3("Delete", 22),
optimizer1("Optimizer 1.0", 30),
optimizer2("Optimizer 2.0", 31)
{
	// Greencoin miner
	greenCoinMiner.building.priceGC = 50;
	greenCoinMiner.building.CPU_usage = 3;
	greenCoinMiner.building.texturePos = sf::Vector2f(0, 0);
	greenCoinMiner.productionTime = 2.0f;
	greenCoinMiner.prodGC = 2;

	// Electro miner
	electroPieceMiner.building.priceGC = 250;
	electroPieceMiner.building.CPU_usage = 3;
	electroPieceMiner.building.texturePos = sf::Vector2f(50, 0);
	electroPieceMiner.productionTime = 2.0f;
	electroPieceMiner.prodEP = 2;

	// Defender 1.0
	defender1.building.priceGC = 102;
	defender1.building.CPU_usage = 2;
	defender1.building.texturePos = sf::Vector2f(100, 0);
	defender1.shootingTime = 1.5f;
	defender1.damage = 25;
	defender1.radius.setRadius(125);

	// Defender 2.0
	defender2.building.priceGC = 250;
	defender2.building.priceEP = 100;
	defender2.building.CPU_usage = 1;
	defender2.building.texturePos = sf::Vector2f(150, 0);
	defender2.shootingTime = 1.8f;
	defender2.damage = 60;
	defender2.radius.setRadius(160);

	// Lag
	lag.building.priceGC = 300;
	lag.building.priceEP = 150;
	lag.building.CPU_usage = 1;
	lag.building.texturePos = sf::Vector2f(200, 0);
	lag.radius.setRadius(120);

	// Hawk
	hawk.building.priceGC = 600;
	hawk.building.priceEP = 400;
	hawk.building.CPU_usage = 1;
	hawk.building.texturePos = sf::Vector2f(250, 0);
	hawk.shootingTime = 2.0f;
	hawk.damage = 130;
	hawk.radius.setRadius(250);

	// Scanner
	scanner.building.priceGC = 200;
	scanner.building.priceEP = 200;
	scanner.building.CPU_usage = 1;
	scanner.building.texturePos = sf::Vector2f(300, 0);
	scanner.radius.setRadius(140);

	// Multi
	multi.building.priceGC = 350;
	multi.building.priceEP = 150;
	multi.building.CPU_usage = 1;
	multi.building.texturePos = sf::Vector2f(0, 50);
	multi.shootingTime = 1.0f;
	multi.damage = 6;
	multi.radius.setRadius(100);

	// dp1 (Freeze)
	dp1.building.priceGC = 125;
	dp1.building.texturePos = sf::Vector2f(350, 0);
	dp1.damage = 100;

	// dp2 (Crash)
	dp2.building.priceGC = 220;
	dp2.building.texturePos = sf::Vector2f(400, 0);
	dp2.damage = 200;

	// dp3 (Delete)
	dp3.building.priceGC = 500;
	dp3.building.texturePos = sf::Vector2f(450, 0);
	dp3.damage = 1000;

	// Optimizer 1.0
	optimizer1.building.priceGC = 50;
	optimizer1.building.priceEP = 150;
	optimizer1.building.texturePos = sf::Vector2f(50, 50);
	optimizer1.optimization = 4;

	// Optimizer 2.0
	optimizer2.building.priceGC = 100;
	optimizer2.building.priceEP = 300;
	optimizer2.building.texturePos = sf::Vector2f(100, 50);
	optimizer2.optimization = 10;
}