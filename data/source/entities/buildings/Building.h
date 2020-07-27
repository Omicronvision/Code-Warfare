#pragma once

#include <SFML/Graphics.hpp>
#include "../../framework/DataTypes.h"

using namespace dt;

class Building
{
public:
	Building(std::string name, Int32 ID);
	void setPosition(Int32 tile);
	void setTexture();
	Int32 getPriceGC();
	Int32 getPriceEP();
	Int32 getCPU_usage();
	std::string getName();
	const Int8 ID;									 //  building ID
	sf::Vertex* quad;								 //  building vertex array
	Int32 CPU_usage;							     //  cpu usage
	Int32 priceGC;                                   //  price in green coins
	Int32 priceEP;							         //  price in electro pieces
	sf::Vector2f texturePos;				      	 //  texture position

private:
	const std::string name;							 //  building name
};

