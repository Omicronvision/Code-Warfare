#include "Fonts.h"

Fonts::Fonts()
{
	if (!general.loadFromFile("data/fonts/atarian/SF Atarian System.ttf"))
		exit(1);
	if (!info.loadFromFile("data/fonts/consola.ttf"))
		exit(1);
}

Fonts::~Fonts()
{

}