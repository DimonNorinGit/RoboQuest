
#include<iostream>
#include"SFML/Graphics.hpp"

#include"Config.h"

int main()
{


	Config conf;
	tr::Surface sr;

	conf.loadResources("resources.txt");

	conf.setConfigs(&sr, "game_config.txt");

	sf::Vector2<sf::Int8> size  = sr.getSize();
	sf::Int8 block_size = conf.getConfig("block_size");

	int d_width  = sf::VideoMode::getDesktopMode().width;
	int d_height = sf::VideoMode::getDesktopMode().height;
	sf::RenderWindow window(sf::VideoMode(d_width, d_height), "RoboQuest");

	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		//window.draw(*sr.getBlock({ 0,0 })->getSprite());

		for (sf::Int8 y = 0; y < size.y; ++y) {
			for (sf::Int8 x = 0; x < size.x; ++x) {
				tr::Block* blk = sr.getBlock(sf::Vector2<sf::Int8>(x, y));
				float x_pos = float(x * block_size);
				float y_pos = float(y * block_size);
				sf::Vector2f pos = {x_pos , y_pos};
				sf::Sprite* sp = blk->getSprite();
				sp->setPosition(pos);
				window.draw(*sp);
			}
		}
		

		//window.draw(sprite);
		


		//demand
		window.display();
	}

	system("pause");
	return 0;
}


/*int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
	sf::Sprite sprite;
	sf::Texture texture;
	if (!texture.loadFromFile("tiles/robot.png"))
	{
		std::cout << "Error";
	}
	sprite.setTexture(texture);


	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		window.draw(sprite);

		//std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << "\n";
		//sf::Vector2f mv(0.1, 0.1);
		//sprite.move(mv);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
	}
	return 0;
}*/


