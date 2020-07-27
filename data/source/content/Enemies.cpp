#include "Enemies.h"

Enemies::Enemies():
adware("data/graphics/entities/malwares/adware.png", 1),
virus("data/graphics/entities/malwares/virus.png", 2),
trojan("data/graphics/entities/malwares/trojan.png", 3),
dialer("data/graphics/entities/malwares/dialer.png", 4),
dropper("data/graphics/entities/malwares/dropper.png", 5),
spyware("data/graphics/entities/malwares/spyware.png", 6)
  
{
	// ADWARE
	adware.setSpeed(0.8f);
	adware.health = 50;

	// VIRUS
	virus.setSpeed(0.5f);
	virus.health = 200;

	// TROJAN
	trojan.setSpeed(0.45f);
	trojan.health = 1500;

	// DIALER
	dialer.setSpeed(0.7f);
	dialer.health = 120;

	// DROPPER
	dropper.setSpeed(0.6f);
	dropper.health = 160;

	// SPYWARE
	spyware.setSpeed(0.7f);
	spyware.health = 150;
	spyware.visible = false;
}