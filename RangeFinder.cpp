#include "RangeFinder.h"



RangeFinder::RangeFinder()
{
}


void RangeFinder::setRobotPos(sf::Vector2<sf::Int8> p) {
	this->robot_pos = p;
}

sf::Int8 RangeFinder::findRange(tr::Surface* sur , sf::Vector2<sf::Int8> direction) {

	sf::Vector2<sf::Int8> point(this->robot_pos);

	sf::Vector2<sf::Int8> s = sur->getSize();

	sf::Int8 range = 0;

	while (true) {

		if (!(point.x >= 0 && point.x < s.x &&
			point.y >= 0 && point.y < s.y)) {
			break;
		}
		tr::Block* blk = sur->getBlock(point);

		if (blk->getType() != BlockType::PLACE) break;

		++range;
	}
	return range;
}

RangeFinder::~RangeFinder()
{
}
