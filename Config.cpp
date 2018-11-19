#include "Config.h"



//You need to add line where the error occured

Config::Config()
{

}

void Config::configError(std::string error) {
	std::cout << error << '\n';
	system("pause");
	exit(1);
}

void Config::loadResources(std::string file_name) {

	std::fstream inp_file;
	inp_file.open(file_name);

	if (!inp_file.is_open()) {
		configError("Can't open resources file");
	}

	//\\s*
	std::regex source("\\s*(\\w{1,259})_img\\s*:\\s*(\\w+.(png|jpg))\\s*");// name : "file"
	std::regex comment("\\s*\\#[\\s\\S]*");
	

	std::string line;
	std::cmatch result;

	while (!inp_file.eof()) {
		std::getline(inp_file, line);

		if (line.empty()) continue;

		if (std::regex_match(line.c_str(), result, comment)) continue;

		if (std::regex_match(line.c_str(), result, source)) {

			std::string res_name = result[1];
			std::string res_file = result[2];

			sf::Sprite* sp = new sf::Sprite();
			sf::Texture* texture = new sf::Texture();

			if (!texture->loadFromFile("tiles/" + res_file))
			{
				configError("Can't open resource");
			}
			sp->setTexture(*texture);

			this->sprites[res_name] = sp;
			this->textures[res_name] = texture;
			std::cout << line << "\n";

		}
		else {
			configError("Expected resource name , find bad line:\n" + line);
		}
	}
}



bool Config::readSurfaceBlocks(tr::Surface* sur , std::fstream& inp_file) {
	std::string line;

	sf::Vector2<sf::Int8> block_pos{0,0};

	std::map<char, BlockType> types{ {'b' , BlockType::BARRIER} ,{ 's' , BlockType::START },
							{'f' , BlockType::FINISH} ,{ 'p' , BlockType::PLACE } };

	sf::Vector2<sf::Int8> sur_s = sur->getSize();

	while (!inp_file.eof()) {

		std::getline(inp_file, line);

		if (line.empty()) return false;

		if (line == "{") continue;

		if (line == "}") {
			if (block_pos.y == sur_s.y - 1) {
				return true;
			}			
			return false;
		} 

		if (line.length() != sur_s.x) {
			configError("Surface: wrong number of  x blocks! ");
		}

		if (block_pos.y >= sur_s.y) {		
			configError("Surface: too much y blocks!");
		}

		for (auto st : line) {

			if (block_pos.x >= sur_s.x) {
				configError("Surface: too much x blocks!");
			}

			auto c_iter = this->surface_codes.find(st);

			if (c_iter == this->surface_codes.end()) {
				configError("Surface: wrong surface code!");
			}

			auto type_iter = types.find(codes_type[st]);

			if (type_iter == types.end()) {
				configError("Surface : wrong type code");
			}

			std::string bl_name = c_iter->second;
			BlockType type = type_iter->second;


			//surface must to delete blocks
			sf::Sprite* sp = new sf::Sprite(*this->sprites[bl_name]);

			tr::Block* blk = new tr::Block(sp , type);

			sur->setBlock(blk, block_pos);

			++block_pos.x;
		}

		block_pos.x = 0;
		++block_pos.y;
		
	}
}


void Config::setConfigs(tr::Surface* sur , std::string file_name) {
	std::fstream inp_file;
	inp_file.open(file_name);

	if (!inp_file.is_open()) {
		configError("Can't open config file: " + file_name);
	}

	std::regex comment("\\s*\\#[\\s\\S]*");

	std::regex param("\\s*(\\w)(\\w{1,20})\\s*:\\s*(\\S+)\\s*");

	std::regex sur_param("\\s*(\\w{1,20})\\s*:\\s*");


	std::string line;
	std::cmatch result;

	while (!inp_file.eof()) {
		std::getline(inp_file, line);

		if (line.empty()) continue;

		if (std::regex_match(line.c_str(), result, comment)) continue;

		if (std::regex_match(line.c_str(), result, param)) {

			std::string param_prefix = result[1];
			std::string param_name = result[2];
			std::string param_data = result[3];

			if (param_prefix == "d") {//data
				//check for overflow
				params[param_name] = std::atoi(param_data.c_str());
			}
			else if(param_prefix == "s"){//surface params
				if (param_data.length() != 2) {
					configError("Surface codes must be two letter terms");
				}
				surface_codes[param_data[0]] = param_name;
				codes_type[param_data[0]] = param_data[1];
			}

		}
		else if(std::regex_match(line.c_str(), result, sur_param)) {
			sf::Vector2<sf::Int8> v{ params["blocks_x"] , params["blocks_y"]};
			sur->setSize(v);
			readSurfaceBlocks(sur , inp_file);
			break;
		}
		else {
			configError("Expected config line , find: " + line);
		}

	}
}


sf::Int8 Config::getConfig(std::string config_name) {
	return this->params[config_name];
}

Config::~Config()
{
	for (auto sp : this->sprites) {
		delete sp.second;
	}
	this->sprites.clear();

	for (auto tx : this->textures) {
		delete tx.second;
	}
	this->textures.clear();
}
