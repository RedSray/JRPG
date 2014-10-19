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

sf::Vector2i Game::GetTileSize() const
{
	return map.GetTileSize();
}

int Game::GetLayerCell(int layer, int x, int y) const	
{
	return map.GetLayerCell(layer,x,y);
}

std::string Game::GetLayerName(int l) const
{
	return map.GetLayerName(l);
}

void Game::SetTile(Tile tile)
{
	map.SetTile(tile);
}

void Game::SetPlayerWorldPosition(sf::Vector2f newPosition)
{
	player.SetWorldPosition(newPosition);
}

void Game::SetTileSize(sf::Vector2i size)
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

bool Game::IsCellWalkable(sf::Vector2f cell) const
{
	sf::Vector2i cellInt;
	cellInt.x = cell.x;
	cellInt.y = cell.y;
	return map.IsCellWalkable(cellInt);
}

sf::Vector2f Game::GetPlayerMoveGoal() const
{
	return player.GetMoveGoal();
}

sf::Vector2f Game::GetPlayerSpeed() const
{
	return player.GetSpeed();
}

void Game::InitPlayerMovement()
{
	player.InitMovement();
}

void Game::ReinitPlayerMovement()
{
	player.ReinitMovement();
}

void Game::MovePlayer(MoveDirection moveDirection)
{
	player.Move(moveDirection);
}

void Game::SetPlayerSpeed(char axe, float speed)
{
	player.SetSpeed(axe, speed);
}

int Game::GetPlayerActiveAnimFPS() const
{
	return player.GetActiveAnimFPS();
}

int Game::GetPlayerActiveAnime() const
{
	return player.GetActiveAnim();
}

int Game::GetPlayerActiveAnimeFrame() const
{
	return player.GetActiveAnimFrame();
}

void Game::PlayerNextAnimFrame()
{
	player.NextAnimFrame();
}

void Game::SetPlayerActiveAnim(int id)
{
	player.SetActiveAnim(id);
}

void Game::SetPlayerActiveAnimFrame(int id)
{
	player.SetActiveAnimFrame(id);
}

void Game::AddPlayerAnimation(Animation animation)
{
	player.AddAnimation(animation);
}

int Game::GetNbEntities() const
{
	return map.GetNbEntities();
}

std::unique_ptr<Entity>& Game::GetEntity(int id)
{
	return map.GetEntity(id);
}

void Game::SetEntity(Entity* newEntity)
{
	map.SetEntity(newEntity);
}