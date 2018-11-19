#pragma once

#include"SFML//System/Utf.hpp"
#include"SFML//System/Vector2.hpp"
#include"Terrain.h"

class RangeFinder
{
private:

	sf::Vector2<sf::Int8> robot_pos;

public:
	RangeFinder();

	void setRobotPos(sf::Vector2<sf::Int8> p);

	sf::Int8 findRange(tr::Surface* sur , sf::Vector2<sf::Int8> direction);

	~RangeFinder();
};

