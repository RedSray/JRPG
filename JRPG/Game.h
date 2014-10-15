#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

#include "Player.h"
#include "TMXMap.h"

class Game
{
public:
	Game();
	~Game();

	Tile GetTile(int) const;
	sf::Vector2i GetMapSize() const;
	sf::Vector2f GetPlayerWorldPosition() const;
	int GetNbLayer() const;
	sf::Vector2f GetTileSize() const;
	int GetLayerCell(int,int,int) const;

	void SetTile(Tile);
	void SetPlayerWorldPosition(sf::Vector2f);
	void SetMapSize(sf::Vector2i);
	void SetTileSize(sf::Vector2f);
	void SetLayer(std::string, std::string);

private:
	TMXMap map;
	Player player;
};

#endif