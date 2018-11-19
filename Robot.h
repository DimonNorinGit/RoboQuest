#pragma once

#include"Terrain.h"
#include"SFML/Graphics//Sprite.hpp"
#include"RangeFinder.h"
#include<queue>
#include<map>

enum RobotState{STAND , MOVE , ROTATE};

class Robot
{

private:

	sf::Sprite* spr;

protected:

	sf::Vector2<sf::Int8> pos;

	sf::Vector2<sf::Int8> front;

	RobotState state;

	sf::Int8 velocity;

	RangeFinder rfinder;

	sf::Vector2<sf::Int8> end_point;

	std::queue<sf::Vector2<sf::Int8>> commands;

	std::map < std::string, sf::Vector2<sf::Int8>> dirs;



	
	//void measureDistance();


public:
	Robot(sf::Sprite* s);

	void setPosition(sf::Vector2<sf::Int8> p);

	void setEndPoint(sf::Vector2<sf::Int8> p);

	RobotState getState() const;

	sf::Vector2<sf::Int8> getFront() const;

	void setState(RobotState st);



	virtual void move(const tr::Surface& surf) = 0;





	~Robot();
};

