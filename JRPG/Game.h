#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

#include "Player.h"

struct Tile
{
	sf::Vector2i positionInTexture; 
};

class Game
{
public:
	Game();
	~Game();

	void SetTile(Tile);
	void SetMap(int,int);

	Tile GetTile(int) const;
	int GetMapCell(int,int) const;
	sf::Vector2i GetMapSize();
	sf::Vector2f GetPlayerWorldPosition();
	void SetPlayerWorldPosition(sf::Vector2f);

private:
	std::vector<Tile> tiles;
	std::vector<std::vector<int>> map;
	Player player;
};

#endif