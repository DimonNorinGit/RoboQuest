#include "Robot.h"



Robot::Robot(sf::Sprite* s)
{
	this->spr = s;
	this->front = { 0 , -1};

	dirs["u"] = { 0 , -1 };
	dirs["d"] = { 0 , 1 };
	dirs["l"] = { -1 , 0 };
	dirs["r"] = { 1 , 0 };
	state = RobotState::STAND;
}

void Robot::setPosition(sf::Vector2<sf::Int8> p) {
	this->pos = p;
}

void Robot::setEndPoint(sf::Vector2<sf::Int8> p) {
	this->end_point = p;
}


RobotState Robot::getState()const {
	return this->state;
}

void Robot::setState(RobotState st) {
	this->state = st;
}

sf::Vector2<sf::Int8> Robot::getFront() const {
	return this->front;
}

Robot::~Robot()
{
}
