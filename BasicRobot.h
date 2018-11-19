#pragma once

#include"Robot.h"

class BasicRobot : public Robot
{

private:

	//std::vector<sf::Vector2<sf::Int8>> rfinder_dir;

public:

	BasicRobot(sf::Sprite* s);

	void move(const tr::Surface& surf);

	~BasicRobot();
};

