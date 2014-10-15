#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}



Tile Game::GetTile(int id) const
{
	return map.GetTile(id);
}

sf::Vector2f Game::GetPlayerWorldPosition() const
{
	return player.GetWorldPosition();
}

sf::Vector2i Game::GetMapSize() const
{
	return map.GetSize();
}

int Game::GetNbLayer() const
{
	return map.GetNbLayer();
}

sf::Vector2f Game::GetTileSize() const
{
	return map.GetTileSize();
}

int Game::GetLayerCell(int layer, int x, int y) const	
{
	return map.GetLayerCell(layer,x,y);
}

void Game::SetTile(Tile tile)
{
	map.SetTile(tile);
}

void Game::SetPlayerWorldPosition(sf::Vector2f newPosition)
{
	player.SetWorldPosition(newPosition);
}

void Game::SetTileSize(sf::Vector2f size)
{
	map.SetTileSize(size);
}

void Game::SetMapSize(sf::Vector2i size)
{
	map.SetSize(size);
}

void Game::SetLayer(std::string name, std::string data)
{
	std::cout << "data : \n" << data << std::endl;
	map.SetLayer(name, data);
}

