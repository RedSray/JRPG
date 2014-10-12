#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::SetTile(Tile tile)
{
	tiles.push_back(tile);
}

void Game::SetMap(int sizeX, int sizeY)
{
	map.resize(sizeX);
	for(int i=0; i < map.size(); ++i)
	{
		map[i].resize(sizeY);
		for(int j=0; j < map[i].size(); ++j)
		{
			if(i == 0) map[i][j] = 1;
			else if(i == map.size()-1) map[i][j] = 7;
			else if(j == 0) map[i][j] = 3;
			else if(j ==  map[i].size()-1) map[i][j] = 5;
			else map[i][j] = 4;
		}
	}

	map[0][0] = 0;
	map[map.size()-1][map[0].size()-1] = 8;
	map[map.size()-1][0] = 6;
	map[0][map[0].size()-1] = 2;
}

Tile Game::GetTile(int id) const
{
	return tiles[id];
}

int Game::GetMapCell(int x, int y) const
{
	return map[x][y];
}

sf::Vector2i Game::GetMapSize()
{
	return sf::Vector2i(map.size(),map[0].size());
}

sf::Vector2f Game::GetPlayerWorldPosition()
{
	return player.GetWorldPosition();
}

void Game::SetPlayerWorldPosition(sf::Vector2f newPosition)
{
	player.SetWorldPosition(newPosition);
}