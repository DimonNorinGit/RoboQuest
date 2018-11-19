#pragma once

#include"SFML/Graphics/Sprite.hpp"
#include<vector>

enum BlockType{BARRIER , PLACE , START , FINISH};

//terrain
namespace tr {

	class Block {
	private:

		sf::Sprite* sp;

		BlockType type;

	public:

		Block(sf::Sprite* s, BlockType t);

		void setSprite(sf::Sprite* s);

		sf::Sprite* getSprite() const;

		BlockType getType()const;

		void setType(BlockType type);

		//void setSpritePosition();

	};


	class Surface
	{


	private:

		sf::Vector2<sf::Int8> size;

		std::vector<Block*> bloks;
	

	public:

		Surface();

		Surface(sf::Vector2<sf::Int8> s);

		void setBlock(Block* b, sf::Vector2<sf::Int8> pos);

		Block* getBlock(sf::Vector2<sf::Int8> pos) const;

		sf::Vector2<sf::Int8> getSize()const;

		void setSize(sf::Vector2<sf::Int8> s);

		~Surface();

	};

}

