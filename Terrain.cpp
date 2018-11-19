#include "Terrain.h"

using namespace tr;


Surface::Surface() {

}

Surface::Surface(sf::Vector2<sf::Int8> s)
{
	size = s;

	bloks.resize(s.x * s.y);
}


Block* Surface::getBlock(sf::Vector2<sf::Int8> pos) const {
	return this->bloks[pos.y * size.y + pos.x];
}

void Surface::setBlock(Block* b, sf::Vector2<sf::Int8> pos) {
	this->bloks[pos.y * size.y +  pos.x] = b;
}

sf::Vector2<sf::Int8> Surface::getSize()const {
	return this->size;
}

void Surface::setSize(sf::Vector2<sf::Int8> s) {
	bloks.resize(s.x * s.y);
	this->size = s;
}

Surface::~Surface()
{

}


Block::Block(sf::Sprite* s, BlockType t): sp(s) , type(t) {

}

BlockType Block::getType() const {
	return this->type;
}

void Block::setType(BlockType type) {
	this->type = type;
}

void Block::setSprite(sf::Sprite* s) {
	this->sp = s;
}

sf::Sprite* Block::getSprite() const {
	return this->sp;
}


