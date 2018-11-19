#pragma once

#include<map>
#include<regex>
#include<string>
#include<fstream>
#include<iostream>

#include"SFML/Graphics/Sprite.hpp"
#include"SFML/Graphics/Texture.hpp"

#include"Terrain.h"
class Config
{

	std::map<std::string, sf::Sprite*> sprites;
	std::map<std::string, sf::Texture*> textures;

	std::map<std::string, sf::Int8> params;

	std::map<char, std::string> surface_codes;
	std::map<char, char> codes_type;


	bool readSurfaceBlocks(tr::Surface* sur , std::fstream& inp_file);

	void configError(std::string error);

public:
	Config();

	void loadResources(std::string file_name);

	void setConfigs(tr::Surface* sur , std::string file_name);

	sf::Int8 getConfig(std::string config_name);

	~Config();
};

