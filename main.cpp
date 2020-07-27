#define NOMINMAX
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "data/source/Game.h"

void hideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main()
{
	hideConsole();

	Game game;
	game.run();

	return EXIT_SUCCESS;
}