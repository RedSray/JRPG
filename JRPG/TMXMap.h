#ifndef TMXMAP_H
#define TMXMAP_H

#include <boost\algorithm\string.hpp>
#include <boost\lexical_cast.hpp>

#include <vector>
#include <string>
#include <iostream>

#include <SFML\System\Vector2.hpp>

struct Tile
{
	sf::Vector2i positionInTexture; 
	int textureID;
};

struct Layer
{
	std::string name;
	std::vector<std::vector<int>> data;
};

class TMXMap
{
public:
	TMXMap();
	~TMXMap();

	Tile GetTile(int) const;
	sf::Vector2i GetSize() const;
	int GetNbLayer() const;
	sf::Vector2i GetTileSize() const;
	int GetLayerCell(int,int,int) const;
	std::string GetLayerName(int) const;
	bool IsCellWalkable(sf::Vector2i) const;


	void SetTile(Tile);
	void SetSize(sf::Vector2i);
	void SetTileSize(sf::Vector2i);
	void SetLayer(std::string, std::string);

private:
	std::vector<Tile> tiles;
	std::vector<Layer> layers;
	sf::Vector2i size; //in tile
	sf::Vector2i tileSize;
	int entitiesLayer; // for physics easy reference


	
};

#endif